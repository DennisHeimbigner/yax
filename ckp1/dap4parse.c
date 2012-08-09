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
	
    xerr = yax_create(input, YXFLAGS, &parser->lexstate);
    if(xerr) {
	fprintf(stderr, "%s\n", yax_errstring(xerr));
	goto fail;
    }
    result = dap4parse(parser) == 0 ? 1 : 0; /* invert */
    yax_free(parser->lexstate);
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
d4group(DAP4parser* parser, yxlist* attrs, yxlist* decls)
{
    return NULL;
}

void*
d4enumdef(DAP4parser* parser, yxlist* attrs, yxlist* econsts)
{
    return NULL;
}

void*
d4enumconst(DAP4parser* parser, yxlist* attrs)
{
    return NULL;
}

void*
d4namespace(DAP4parser* parser, yax_token token)
{
    return NULL;
}

void*
d4dimdef(DAP4parser* parser, yxlist* l, yxlist* l2)
{
    return NULL;
}

void*
d4dimref(DAP4parser* parser, yxlist* l)
{
    return NULL;
}

void*
d4simplevariable(DAP4parser* parser, yax_token token1, yax_token token2, yxlist* l, yax_token token3)
{
    return NULL;
}

void*
d4structurevariable(DAP4parser* parser, yax_token token, yxlist* l)
{
    return NULL;
}

void*
d4variabledef(DAP4parser* parser, yxlist* l)
{
    return NULL;
}

void*
d4structuredef(DAP4parser* parser, yxlist* l)
{
    return NULL;
}

void*
d4mapref(DAP4parser* parser, yax_token token)
{
    return NULL;
}

void*
d4attribute(DAP4parser* parser, yxlist* l, yxlist* l2, yxlist* l3)
{
    return NULL;
}

void*
d4otherxml(DAP4parser* parser, yxlist* tokenlist)
{
    return NULL;
}

/* Parser utilities */

yxlist*
d4list(DAP4parser* parser, yxlist* l, void* elem)
{
    return NULL;
}

yxlist*
d4attrlist(DAP4parser* parser, yxlist* l, yax_token token)
{
    return NULL;
}

