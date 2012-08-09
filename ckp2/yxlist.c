/* Copyright 2009, UCAR/Unidata and OPeNDAP, Inc.
   See the COPYRIGHT file for more information. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "yxlist.h"

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#define DEFAULTALLOC 16
#define ALLOCINCR 16

yxlist* yxlistnew(void)
{
  yxlist* l;
  l = (yxlist*)malloc(sizeof(yxlist));
  if(l) {
    l->alloc=0;
    l->length=0;
    l->content=NULL;
  }
  return l;
}

int
yxlistfree(yxlist* l)
{
  if(l) {
    l->alloc = 0;
    if(l->content != NULL) {free(l->content); l->content = NULL;}
    free(l);
  }
  return TRUE;
}

static int
yxlistsetalloc(yxlist* l, unsigned int sz)
{
  void** newcontent;
  if(l == NULL) return FALSE;
  if(sz <= 0) {sz = (l->length?2*l->length:DEFAULTALLOC);}
  if(l->alloc >= sz) {return TRUE;}
  newcontent=(void**)calloc(sz,sizeof(void*));
  if(l->alloc > 0 && l->length > 0 && l->content != NULL) {
    memcpy((void*)newcontent,(void*)l->content,sizeof(void*)*l->length);
    free(l->content);
  }
  l->content=newcontent;
  l->alloc=sz;
  return TRUE;
}

void*
yxlistget(yxlist* l, int index)
{
  if(l == NULL || l->length == 0) return NULL;
  if(index < 0 || index >= l->length) return NULL;
  return l->content[index];
}

int
yxlistpush(yxlist* l, void* elem)
{
  if(l == NULL) return FALSE;
  if(l->length >= l->alloc) yxlistsetalloc(l,0);
  l->content[l->length] = elem;
  l->length++;
  return TRUE;
}

void*
yxlistpop(yxlist* l)
{
  if(l == NULL || l->length == 0) return NULL;
  l->length--;  
  return l->content[l->length];
}

void*
yxlisttop(yxlist* l)
{
  if(l == NULL || l->length == 0) return NULL;
  return l->content[l->length - 1];
}
