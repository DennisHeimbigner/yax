/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

#ifndef _CALCTEST_H_
#define _CALCTEST_H_ 1

/* Forward */
typedef struct CalcEventHandler CalcEventHandler;

#include "sax.h"
#include "calc.tab.h"

struct CalcEventHandler {
    SaxEventHandler seh; /*not pointer so we can do pseudo cast*/
    struct calcpstate* pushparser;
    int accepted;
    int textok; /* if false, then event handler should ignore TEXT */
};

typedef struct calc_keyword {
	char *name;
	int opentag;
	int closetag;
	int attrtag;
	int textok;
} calc_keyword;

/* From calceventhandler.c */
extern CalcEventHandler* calc_eventhandler(const char* document);
extern void calc_eventhandlerfree(CalcEventHandler*);
extern int calc_parse(CalcEventHandler*);
extern void calcerror(CalcEventHandler*, const char*,...);

/* Hash Function (calckeyword.c) */
extern const struct calc_keyword* calc_keyword_lookup(const char* s, unsigned int len);
extern void calc_keyword_init(void);

#endif /*_CALCTEST_H_*/
