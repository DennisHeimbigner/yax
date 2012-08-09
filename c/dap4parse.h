/* Copyright 2009, UCAR/Unidata and OPeNDAP, Inc.
   See the COPYRIGHT file for more information. */

#ifndef D4PARSE_H
#define D4PARSE_H 1

#include "yax.h"

#include "dap4.tab.h" /* for YYSTYPE */

/* For consistency with Java parser */

typedef struct DAP4Parser {
    yax_lexer* lexer;
    int charno; /* from last token consumed */
} DAP4parser;

typedef struct yax_token* DAP4token;

#define MAX_TOKEN_LENGTH 1024

extern int dap4debug; /* global state */

/* main entry point */
extern int dap4_parse(char* input);

/* Parser action procedures */

extern void* d4group(DAP4parser*, YXlist* attrs, YXlist* decls);
extern void* d4enumdef(DAP4parser*, YXlist* attrs, YXlist* econsts);
extern void* d4enumconst(DAP4parser*, YXlist* attrs);
extern void* d4namespace(DAP4parser*, yax_token);
extern void* d4dimdef(DAP4parser*, YXlist*, YXlist*);
extern void* d4dimref(DAP4parser*, YXlist*);
extern void* d4simplevariable(DAP4parser*, yax_token, yax_token, YXlist*, yax_token);
extern void* d4structurevariable(DAP4parser*, yax_token, YXlist*);
extern void* d4variabledef(DAP4parser*, YXlist*);
extern void* d4structuredef(DAP4parser*, YXlist*);
extern void* d4mapref(DAP4parser*, yax_token);
extern void* d4attribute(DAP4parser*, YXlist*, YXlist*, YXlist*);
extern void* d4otherxml(DAP4parser*, YXlist* tokenlist);

extern YXlist* d4list(DAP4parser*, YXlist*, void* elem);
extern YXlist* d4attrlist(DAP4parser*, YXlist*, yax_token);

/* Generated Parser Entry Point */
extern int dap4parse(DAP4parser*);

/* Lexer entry points */
extern int dap4error(DAP4parser* parser, const char* msg);

#endif /*DAP4PARSE_H*/

