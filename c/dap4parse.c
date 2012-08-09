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

#define YXFLAGS (YXFLAG_ESCAPE|YXFLAG_TRIMTEXT|YXFLAG_ELIDETEXT)

/*Parser main entry */

int
dap4_parse(char* input)
{
    yax_err xerr = YAX_OK;
    int result;
    DAP4parser* parser;

    parser = (DAP4parser*)calloc(1, sizeof(DAP4parser));
    if(parser == NULL) {
	fprintf(stderr, "out of memory\n");
	goto fail;     
    }
	
    xerr = yax_create(input, YXFLAGS, &parser->lexer);
    if(xerr) {
	fprintf(stderr, "%s\n", yax_errstring(xerr));
	goto fail;
    }
    result = dap4parse(parser) == 0 ? 1 : 0; /* invert */
    yax_free(parser->lexer);
    free(parser);
    return 1;
fail:
    return 0;
}

/**************************************************/
/* Parser action procedures */

/* Currently the actions do nothing; the only goal
   is to show how to process the parser actions
*/

void*
d4group(DAP4parser* parser, YXlist* attrs, YXlist* decls)
{
    return NULL;
}

void*
d4enumdef(DAP4parser* parser, YXlist* attrs, YXlist* econsts)
{
    return NULL;
}

void*
d4enumconst(DAP4parser* parser, YXlist* attrs)
{
    return NULL;
}

void*
d4namespace(DAP4parser* parser, yax_token token)
{
    return NULL;
}

void*
d4dimdef(DAP4parser* parser, YXlist* l, YXlist* l2)
{
    return NULL;
}

void*
d4dimref(DAP4parser* parser, YXlist* l)
{
    return NULL;
}

void*
d4simplevariable(DAP4parser* parser, yax_token token1, yax_token token2, YXlist* l, yax_token token3)
{
    return NULL;
}

void*
d4structurevariable(DAP4parser* parser, yax_token token, YXlist* l)
{
    return NULL;
}

void*
d4variabledef(DAP4parser* parser, YXlist* l)
{
    return NULL;
}

void*
d4structuredef(DAP4parser* parser, YXlist* l)
{
    return NULL;
}

void*
d4mapref(DAP4parser* parser, yax_token token)
{
    return NULL;
}

void*
d4attribute(DAP4parser* parser, YXlist* l, YXlist* l2, YXlist* l3)
{
    return NULL;
}

void*
d4otherxml(DAP4parser* parser, YXlist* tokenlist)
{
    return NULL;
}

/* Parser utilities */

YXlist*
d4list(DAP4parser* parser, YXlist* l, void* elem)
{
    return NULL;
}

YXlist*
d4attrlist(DAP4parser* parser, YXlist* l, yax_token token)
{
    return NULL;
}

