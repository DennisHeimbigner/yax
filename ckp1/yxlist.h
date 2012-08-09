/* Copyright 2009, UCAR/Unidata and OPeNDAP, Inc.
   See the COPYRIGHT file for more information. */

#ifndef YXLIST_H
#define YXLIST_H 1

/* Define the type of the elements in the list*/

typedef struct yxlist {
  unsigned int alloc;
  unsigned int length;
  void** content;
} yxlist;

extern yxlist* yxlistnew(void);
extern int yxlistfree(yxlist*);

/* Get value at position i */
extern void* yxlistget(yxlist*,int);/* Return the ith element of l */

/* Tail operations */
extern int yxlistpush(yxlist*,void*); /* Add at Tail */
extern void* yxlistpop(yxlist*);
extern void* yxlisttop(yxlist*);

/* Following are always "in-lined"*/
#define yxlistlength(l)  ((l)?(l)->length:0U)
#define yxlistappend(l,o) yxlistpush(l,o)
#endif /*YXLIST_H*/

