/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dap4test.h"
#include "dap4.tab.h"

#undef PERFECTHASH

#ifdef PERFECTHASH

#include "dap4_perfect.c"

void
dap4_keyword_init(void)
{
}

#else /*!PERFECTHASH*/

/* Choose # keys; must be >= # keywords  and large enough for no collisions */
#define NKEYS (1<<8)
#define HASHMASK (NKEYS-1)

#define HASHFCN(h,c,i) {h = (h) + (c<<i);}

#define PREFIXLEN 8

static int initialized = 0;
static struct dap4_keyword* hashtable[NKEYS];

struct dap4_keyword keywords[] = {
{"Attribute", ATTRIBUTE_, _ATTRIBUTE, 0},
{"Dataset", DATASET_, _DATASET, 0},
{"Dim", DIM_, _DIM, 0},
{"Dimension", DIMENSION_, _DIMENSION, 0},
{"EnumConst", ENUMCONST_, _ENUMCONST, 0},
{"Enumeration", ENUMERATION_, _ENUMERATION, 0},
{"Group", GROUP_, _GROUP, 0},
{"Map", MAP_, _MAP, 0},
{"Namespace", NAMESPACE_, _NAMESPACE, 0},
{"Structure", STRUCTURE_, _STRUCTURE, 0},
{"Value", VALUE_, _VALUE, 0},
{"Char", CHAR_, _CHAR, 0},
{"Byte", BYTE_, _BYTE, 0},
{"Int8", INT8_, _INT8, 0},
{"UInt8", UINT8_, _UINT8, 0},
{"Int16", INT16_, _INT16, 0},
{"UInt16", UINT16_, _UINT16, 0},
{"Int32", INT32_, _INT32, 0},
{"UInt32", UINT32_, _UINT32, 0},
{"Int64", INT64_, _INT64, 0},
{"UInt64", UINT64_, _UINT64, 0},
{"Float32", FLOAT32_, _FLOAT32, 0},
{"Float64", FLOAT64_, _FLOAT64, 0},
{"String", STRING_, _STRING, 0},
{"URL", URL_, _URL, 0},
{"Opaque", OPAQUE_, _OPAQUE, 0},
{"Enum", ENUM_, _ENUM, 0},
{"base", 0, 0, ATTR_BASE},
{"basetype", 0, 0, ATTR_BASETYPE,},
{"dapVersion", 0, 0, ATTR_DAPVERSION},
{"ddxVersion", 0, 0, ATTR_DDXVERSION},
{"enum", 0, 0, ATTR_ENUM},
{"href", 0, 0, ATTR_HREF},
{"name", 0, 0, ATTR_NAME},
{"ns", 0, 0, ATTR_NS},
{"size", 0, 0, ATTR_SIZE},
{"type", 0, 0, ATTR_TYPE},
{"value", 0, 0, ATTR_VALUE},
{"xmlns", 0, 0, ATTR_XMLNS},
{NULL,0,0,0}
};

unsigned int
hashfor(int keylen, const char* key)
{
    unsigned long long h;
    int i;
    for(h=0,i=0;i<keylen;i++) {
	unsigned int c = key[i];
	HASHFCN(h,c,i);
    }
    h = (h & HASHMASK); /* keep in range 0..HASHMASK-1 */
    return (unsigned int) (h & 0xFFFFFFFF);
}

#define HASH(dst,n,key) dst = hashfor(n,key)

static int keyword_table_initialized = 0;

const struct dap4_keyword*
dap4_keyword_lookup(const char* key, unsigned int keylen)
{
    /* Compute hash based on the first PREFIXLEN characters */
    unsigned int hash;
    struct dap4_keyword* entry;
    int n;

    if(!initialized) {
	initialized = 1;
        dap4_keyword_init();
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
dap4_keyword_init(void)
{
    int i;
    unsigned int hash;
    unsigned int keylen;
    struct dap4_keyword* keys;
    struct dap4_keyword* entry;

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
	    fprintf(stderr,"dap4_lexer.c: hash collision: %s :: %s\n",
		    entry->name?entry->name:"NULL",keyname?keyname:"NULL");
	    exit(1);
	}
	hashtable[hash] = &keys[i];
    }
}

void
dap4_dumphashtable(void)
{
    int i;
    int empty = 1;
    for(i=0;i<NKEYS;i++) {
	struct dap4_keyword* entry = hashtable[i];
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
