/* Copyright 2009, UCAR/Unidata and OPeNDAP, Inc.
   See the COPYRIGHT file for more information. */

#ifndef D4PARSE_H
#define D4PARSE_H 1

#include "yax.h"

#include "dap4.tab.h" /* for YYSTYPE */

/* For consistency with Java parser */

typedef struct DAP4Parser {
    yax_state* lexstate;
    int charno; /* from last token consumed */
} DAP4parser;

typedef struct yax_token* DAP4token;

#define MAX_TOKEN_LENGTH 1024

extern int dap4debug; /* global state */

/* main entry point */
extern int dap4_parse(char* input);

/* Parser action procedures */

extern void* d4group(DAP4parser*, yxlist* attrs, yxlist* decls);
extern void* d4enumdef(DAP4parser*, yxlist* attrs, yxlist* econsts);
extern void* d4enumconst(DAP4parser*, yxlist* attrs);
extern void* d4namespace(DAP4parser*, yax_token);
extern void* d4dimdef(DAP4parser*, yxlist*, yxlist*);
extern void* d4dimref(DAP4parser*, yxlist*);
extern void* d4simplevariable(DAP4parser*, yax_token, yax_token, yxlist*, yax_token);
extern void* d4structurevariable(DAP4parser*, yax_token, yxlist*);
extern void* d4variabledef(DAP4parser*, yxlist*);
extern void* d4structuredef(DAP4parser*, yxlist*);
extern void* d4mapref(DAP4parser*, yax_token);
extern void* d4attribute(DAP4parser*, yxlist*, yxlist*, yxlist*);
extern void* d4otherxml(DAP4parser*, yxlist* tokenlist);

extern yxlist* d4list(DAP4parser*, yxlist*, void* elem);
extern yxlist* d4attrlist(DAP4parser*, yxlist*, yax_token);

/* Generated Parser Entry Point */
extern int dap4parse(DAP4parser*);

/* Lexer entry points */
extern int dap4error(DAP4parser* parser, const char* msg);

#endif /*DAP4PARSE_H*/

