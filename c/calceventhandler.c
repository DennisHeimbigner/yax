/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "calctest.h"
#include "calc.tab.h"
#include "calctest.h"

#undef TRACE

/* Mnemonics */
#define YYACCEPT 0
#define YYABORT 1
#define YYNOMEM 2

static int calc_yyevent(SaxEventHandler* seh, SaxEvent* event);

static SaxControls calc_controls = {calc_yyevent,NULL,NULL};

/**************************************************/

static int
calc_yyevent(SaxEventHandler* seh, SaxEvent* event)
{
    CalcEventHandler* ceh = (CalcEventHandler*)seh;
    int parsestatus = 0;
    int ret = 0;
    const struct calc_keyword* keyword;
    SaxEventType saxtoken = event->event;
    int yytoken; /* for the parser */

    if(ceh->accepted) {
	fprintf(stderr,"yyevent called after parser has accepted");
	return 0;
    }

    if(event->name != NULL)
	keyword = calc_keyword_lookup(event->name,
					strlen(event->name));

    /* If the keyword is unknown and not an attribute, then fail */
    if(keyword == NULL && event->event != ATTRIBUTE) {
	char msg[4096];
	const char* trace = saxeventstring(event,0);
	snprintf(msg,sizeof(msg),"unknown token: %s\n",trace);
	calcerror(ceh,msg);
	yytoken = UNKNOWN_ELEMENT_;
    }

    switch(saxtoken) {

    case STARTELEMENT:
	if(keyword == NULL) {/*  undefined */
	    yytoken = UNKNOWN_ELEMENT_;
        } else {
            yytoken = keyword->opentag;
	    ceh->textok = keyword->textok;
        }
	break;

    case ENDELEMENT:
        ceh->textok = 0;
	if(keyword == NULL) {/* undefined */
	    yytoken = _UNKNOWN_ELEMENT;
        } else {
	    yytoken = keyword->closetag;
	}
        break;

    case ATTRIBUTE:
	ceh->textok = 0;
	if(keyword == NULL)
	    yytoken = UNKNOWN_ATTR;
	else
	    /* Since keyword is defined,
               this means the attribute is legal */
	    yytoken = keyword->attrtag;
	break;

     case CHARACTERS:
	if(!ceh->textok) return 1;
	yytoken = TEXT;
        break;

     case STARTDOCUMENT: /*ignore*/
	return 1;

     case ENDDOCUMENT:
        yytoken = EOF;
        break;

     default:
        fprintf(stderr,"unknown token type: %s\n", event->name);
        yytoken = EOF;
	ret = 0;
        break;
    } /* switch */

    /* Send yytoken and the event to the push parser */
    {
	YYSTYPE u;
        u.event = event;
        parsestatus = calcpush_parse(ceh->pushparser, yytoken, &u, ceh);
    }
    switch (parsestatus) {
    case YYPUSH_MORE: ret = 1; break;
    case YYACCEPT: ret = 1; ceh->accepted = 1;break;
    case YYABORT: ret = 0; break;
    case YYNOMEM:
        fprintf(stderr,"out of memory\n");
        ret = 0;
        break;
    default: abort();
    }
    return ret;
}

/**************************************************/
/* Exernal api */

CalcEventHandler*
calc_eventhandler(const char* document)
{
    CalcEventHandler* ceh;

    ceh = (CalcEventHandler*)calloc(1,sizeof(CalcEventHandler));
    saxeventhandlerinit(document,&calc_controls,&ceh->seh);

    ceh->pushparser = calcpstate_new();
    ceh->accepted = 0;
    ceh->textok = 0;
    return ceh;
}

void
calc_eventhandlerfree(CalcEventHandler* ceh)
{
    if(ceh == NULL) return;
    saxeventhandlerclear(&ceh->seh);
    if(ceh->pushparser != NULL)
	calcpstate_delete(ceh->pushparser);
    free(ceh);    
}

int
calc_parse(CalcEventHandler* ceh)
{
    int ok = saxparse((SaxEventHandler*)ceh);
    return ok;
}
