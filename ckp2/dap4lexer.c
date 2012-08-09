/* Copyright 2009, UCAR/Unidata and OPeNDAP, Inc.
   See the COPYRIGHT file for more information. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "yxlist.h"
#include "yax.h"
#include "dap4parse.h"
#include "dap4.tab.h"

#define TRACE

struct dap4_keyword { char *name; int opentag ; int closetag; };

/* Interface to the perfect hash function */
const struct dap4_keyword* dap4_keyword_lookup(const char*,unsigned int);


/*Forward*/
static yax_err otherxml(DAP4parser*, yax_token*, yxlist**);
static void freeotherxml(yxlist* list);

/**************************************************/

int
dap4lex(YYSTYPE *lvalp, DAP4parser* parser)
{
    yax_err err = YAX_OK;
    yax_token* tokenstate = &lvalp->token;
    const struct dap4_keyword* keyword;
    int yytoken = UNKNOWN;
    char* p;

    while(yytoken == UNKNOWN) {
	err = yax(parser->lexstate,tokenstate);
	if(err) goto done;

#ifdef TRACE
	{
	char* trace = yax_trace(parser->lexstate,tokenstate);
	printf("yylex: charno=%d token: %s\n",tokenstate->charno,trace);
	fflush(stdout);
	if(trace) free(trace);
	}
#endif

	/* Remove any leading namespace except xmlns */
	if((p=strchr(tokenstate->name,':')) != NULL) {
	    if(strncmp(tokenstate->name,"xmlns:",7)!=0) {
		tokenstate->name = p+1;
	    }
	}

	if(tokenstate->name != NULL)
	    keyword = dap4_keyword_lookup(tokenstate->name,
					  strlen(tokenstate->name));

	/* If the keyword is unknown and not an attribute, then fail */
	if(keyword == NULL && tokenstate->tokentype != YAX_ATTRIBUTE) {
	    char msg[1024];
	    strcpy(msg,"unknown token: |");
	    strncat(msg,tokenstate->name,16);
	    strcat(msg,"...|\n");
	    dap4error(parser,msg);
	    yytoken = UNEXPECTED;
	    goto done;
	}

	switch(tokenstate->tokentype) {

	case YAX_OPEN: /* Handle otherxml separately */
	    if(keyword->opentag == OTHERXML) {
		yxlist* list = NULL;
		yytoken = keyword->opentag;
		if((err=otherxml(parser,tokenstate,&list))) {
		    yytoken = ERROR;
		    freeotherxml(list);
		    list = NULL;
		}
	        lvalp->list = list;
	    } else {
	        /* Since keyword is defined, this means the opentag is legal */
		yytoken = keyword->opentag;
	    }
	    break;

	case YAX_EMPTYCLOSE:
	case YAX_CLOSE:
	    /* Since keyword is defined, this means the closetag is legal */
	    yytoken = keyword->closetag;
	    break;

	case YAX_ATTRIBUTE:
	    if(keyword == NULL)
		yytoken = UNKNOWN_ATTR;
	    else
	        /* Since keyword is defined,
                   this means the attribute is legal */
	        yytoken = keyword->opentag;
	    break;

	case YAX_EOF:
	    yytoken = 0;
	    break;

	case YAX_TEXT:
	    break;

	default: {
	    char msg[1024];
	    snprintf(msg,sizeof(msg),"unknown token type: %d\n",tokenstate->tokentype);
	    dap4error(parser,msg);
	    yytoken = ERROR;
	    } break;
	}
    }

done:
    parser->charno = tokenstate->charno;
    if(err) {
	dap4error(parser,yax_errstring(err));
	return ERROR;
    }
    return yytoken;
}

static yax_err
otherxml(DAP4parser* parser, yax_token* tokenstate, yxlist** listp)
{
    yxlist* xml = NULL;
    yax_err err = YAX_OK;
    
    xml = yxlistnew();
    /* basically collect everything upto the closing </OtherXML> */
    for(;;) {
	yax_token* t;
	if((err = yax(parser->lexstate,tokenstate))) goto done;
	if(tokenstate->tokentype == YAX_CLOSE
	   && strcmp(tokenstate->name,"OtherXML") == 0) break;
	t = (yax_token*)calloc(1,sizeof(yax_token));
	*t = *tokenstate;		
	yxlistpush(xml,(void*)t);
    }

done:
    if(err && xml){
	/* cleanup */
	freeotherxml(xml);
	xml = NULL;
    }
    if(listp) *listp = xml;
    return err;
}

static void
freeotherxml(yxlist* list)
{
    if(list != NULL) {
	while(yxlistlength(list) > 0) {
	    yax_token* t = (yax_token*)yxlistpop(list);
	    if(t) free(t);
	}
	yxlistfree(list);
    }
}

#if 0
#define whitespace(c) ((c) > '\0' && (c) <= ' ')

static int
allwhitespace(const char* text)
{
    int c;
    const char* p = text;
    if(p != NULL) {
        while((c=*p++)) {if(!whitespace(c)) return 0;}
    }
    return 1;
}
#endif

int
dap4error(DAP4parser* parser, const char* msg)
{
    fprintf(stderr,"%d: %s\n",parser->charno,msg);
    return 0;
}

