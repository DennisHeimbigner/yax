/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "calctest.h"
#include "calc.tab.h"

#undef PERFECTHASH

#ifdef PERFECTHASH

#include "calc_perfect.c"

void
calc_keyword_init(void)
{
}

#else /*!PERFECTHASH*/

#if 0
#define NKEYS (1<<16)
#define HASHMASK (0xFFFF)
#else
#define NKEYS (1<<8)
#define HASHMASK (0xFF)
#endif
#define PREFIXLEN 8

static int initialized = 0;
static struct calc_keyword* hashtable[NKEYS];

struct calc_keyword keywords[] = {
{"calc", CALC_, _CALC, 0, 0},
{"eq", EQ_, _EQ, 0, 0},
{"add", ADD_, _ADD, 0, 0},
{"sub", SUB_, _SUB, 0, 0},
{"mul", MUL_, _MUL, 0, 0},
{"div", DIV_, _DIV, 0, 0},
{"neg", NEG_, _NEG, 0, 0},
{"exp", EXP_, _EXP, 0, 0},
{"int", INT_, _INT, 0, 1},
{"n", 0, 0, ATTR_N, 0},
{NULL,0,0,0,0}
};
#endif /*!PERFECTHASH*/

#ifndef PERFECTHASH

unsigned int
hashfcn(int keylen, const char* key)
{
    unsigned long long h;
    int i;
    for(h=0,i=0;i<keylen;i++) {
	unsigned int c = key[i];
	h = (h) + (c) + (c<<i);
    }
    h = (h & HASHMASK); /* keep in range 0..HASHMASK-1 */
    return (unsigned int) (h & 0xFFFFFFFF);
}

#define HASH(dst,n,key) dst = hashfcn(n,key)

static int keyword_table_initialized = 0;

const struct calc_keyword*
calc_keyword_lookup(const char* key, unsigned int keylen)
{
    /* Compute hash based on the first PREFIXLEN characters */
    unsigned int hash;
    struct calc_keyword* entry;
    int n;

    if(!initialized) {
	initialized = 1;
        calc_keyword_init();
    }

    n = (keylen < PREFIXLEN ? keylen : PREFIXLEN);
    if(n == 0)
	return 0;
    HASH(hash,n,key);
    entry = hashtable[hash];
    if(entry != NULL)
	return entry;
    return NULL;
}

void
calc_keyword_init(void)
{
    int i;
    unsigned int hash;
    unsigned int keylen;
    struct calc_keyword* keys;
    struct calc_keyword* entry;

    if(keyword_table_initialized) return;
    keyword_table_initialized = 1;
    memset((void*)&hashtable,0,sizeof(hashtable));
    keys = keywords;
    for(i=0;;i++) {
	char* keyname = keys[i].name;
	if(keyname == NULL) break; /*done*/
	keylen = strlen(keyname);
	if(keylen > PREFIXLEN) keylen = PREFIXLEN;
	HASH(hash,keylen,keyname);
	entry = hashtable[hash];
	if(entry != NULL) {
	    fprintf(stderr,"calc_lexer.c: hash collision: %s :: %s\n",
		    entry->name?entry->name:"NULL",keyname?keyname:"NULL");
	    exit(1);
	}
	hashtable[hash] = &keys[i];
    }
}

void
calc_dumphashtable(void)
{
    int i;
    int empty = 1;
    for(i=0;i<NKEYS;i++) {
	struct calc_keyword* entry = hashtable[i];
	if(entry != NULL) {
	    fprintf(stderr,"[%d] {\"%s\",%d,%d,%d}\n",
		    i,entry->name,entry->opentag,entry->closetag,entry->attrtag);
	    empty = 0;
	}
    }
    if(empty)
	fprintf(stderr,"table is empty\n");
    fflush(stderr);
}
#endif /*!PERFECTHASH*/
