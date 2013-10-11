/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "dap4test.h"
#include "dap4.tab.h"
#include "dap4test.h"

#undef TRACE

/* Mnemonics */
#define YYACCEPT 0
#define YYABORT 1
#define YYNOMEM 2

static int dap4_yyevent(SaxEventHandler* seh, SaxEvent* event);

static SaxControls dap4_controls = {dap4_yyevent,NULL,NULL};

/**************************************************/

static int
dap4_yyevent(SaxEventHandler* seh, SaxEvent* event)
{
    Dap4EventHandler* deh = (Dap4EventHandler*)seh;
    int parsestatus = 0;
    int ret = 0;
    const struct dap4_keyword* keyword;
    SaxEventType saxtoken = event->event;
    int yytoken; /* for the parser */

    if(deh->accepted) {
	fprintf(stderr,"yyevent called after parser has accepted");
	return 0;
    }
#ifdef TRACE
    {
	char* trace = yax_trace(parser->yaxlexer,yaxtoken);
	printf("yylex: charno=%d token: %s\n",yaxtoken->charno,trace);
	fflush(stdout);
	if(trace) free(trace);
    }
#endif

    if(event->name != NULL)
	keyword = dap4_keyword_lookup(event->name,
					strlen(event->name));
    else
	keyword = NULL;

    /* If the keyword is unknown and not an attribute, then fail */
    if(keyword == NULL && event->event != ATTRIBUTE) {
	char msg[4096];
	const char* trace = saxeventstring(event,SXFLAG_NONE);
	snprintf(msg,sizeof(msg),"unknown token: %s\n",trace);
	dap4error(deh,msg);
	yytoken = UNEXPECTED;
	goto done;
    }

    switch(saxtoken) {

    case STARTELEMENT:
	if(keyword == NULL) {/*  undefined */
	    yytoken = UNKNOWN_ELEMENT_;
        } else {
            yytoken = keyword->opentag;
            /* Check for the special case of <Value> */
            if(yytoken == VALUE_)
		deh->textok = 1;
        }
	break;

    case ENDELEMENT:
	if(keyword == NULL) {/* undefined */
	    yytoken = _UNKNOWN_ELEMENT;
        } else {
	    yytoken = keyword->closetag;
	    deh->textok = 0;
	}
        break;

    case ATTRIBUTE:
	if(keyword == NULL)
	    yytoken = UNKNOWN_ATTR;
	else
	    /* Since keyword is defined,
		this means the attribute is legal */
	    yytoken = keyword->attrtag;
	break;

     case CHARACTERS:
	if(!deh->textok) return 1;
	yytoken = TEXT;
        break;

     case STARTDOCUMENT:
	return 1; /* ignore */

     case ENDDOCUMENT:
        yytoken = EOF;
        break;

     default:
        fprintf(stderr,"unknown token type: %s\n", event->name);
        yytoken = ERROR;
        break;
    } /* switch */

    /* Send yytoken and the event to the push parser */
    parsestatus = dap4push_parse(deh->pushparser, yytoken, &event, deh);
    switch (parsestatus) {
    case YYPUSH_MORE:
	ret = 1;
	break;
    case YYACCEPT:
	ret = 1;
	deh->accepted = 1;
	break;
    case YYABORT:
	ret = 0;
	break;
    case YYNOMEM:
	fprintf(stderr,"out of memory\n");
	ret = 0;
	break;
    default: abort();
    }
done:
    return ret;
}

/**************************************************/
/* Exernal api */

Dap4EventHandler*
dap4_eventhandler(const char* document)
{
    Dap4EventHandler* deh;

    deh = (Dap4EventHandler*)calloc(1,sizeof(Dap4EventHandler));
    saxeventhandlerinit(document,&dap4_controls,&deh->seh);

    deh->pushparser = dap4pstate_new();
    deh->textok = 0;
    deh->accepted = 0;
    return deh;
}

void
dap4_eventhandlerfree(Dap4EventHandler* deh)
{
    if(deh == NULL) return;
    saxeventhandlerclear(&deh->seh);
    if(deh->pushparser != NULL)
	dap4pstate_delete(deh->pushparser);
    free(deh);    
}

int
dap4_parse(Dap4EventHandler* deh)
{
    int ok = saxparse((SaxEventHandler*)deh);
    return ok;
}
