/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

#ifndef _DAP4TEST_H_
#define _DAP4TEST_H_ 1

/* Forward */
typedef struct Dap4EventHandler Dap4EventHandler;

#include "sax.h"
#include "dap4.tab.h"

struct Dap4EventHandler {
    SaxEventHandler seh; /*not pointer so we can do pseudo cast*/
    struct dap4pstate* pushparser;
    int textok;
    int accepted;
};

typedef struct dap4_keyword {
	char *name;
	int opentag;
	int closetag;
	int attrtag;
} dap4_keyword;

/* From dap4eventhandler.c */
extern Dap4EventHandler* dap4_eventhandler(const char* document);
extern void dap4_eventhandlerfree(Dap4EventHandler*);
extern int dap4_parse(Dap4EventHandler*);
extern void dap4error(Dap4EventHandler*, const char*);

/* Hash Function (keyword.c) */
extern const struct dap4_keyword* dap4_keyword_lookup(const char* s, unsigned int len);
extern void dap4_keyword_init(void);

#endif /*_DAP4TEST_H_*/
