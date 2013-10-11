/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

#ifndef _SAX_H_
#define _SAX_H_ 1

#include <libxml/SAX.h>

#define VERSION "2.00"

#undef TRACE 

#define MAXELIDELENGTH 16

/* Define some flags to control processing */
typedef enum SaxFlags {
    SXFLAG_NONE	     = 0,
    SXFLAG_ESCAPE    = 1, /*convert \n,\r, etc to \\ form */
    SXFLAG_NOCR      = 2, /* elide \r */
    SXFLAG_ELIDETEXT = 4, /* only print the first 12 characters of text */
    SXFLAG_TRIMTEXT  = 8, /*remove leading and trailing whitespace;
                            if result is empty, then ignore */
} SaxFlags;

/* Enumerate the kinds of Sax Events received by the SaxEventHandler */
typedef enum SaxEventType {
    UNDEFINED = 0,
    STARTDOCUMENT = 1,
    ENDDOCUMENT = 2,
    STARTELEMENT = 3,
    ENDELEMENT = 4,
    ATTRIBUTE = 5,
    CHARACTERS = 6,
} SaxEventType;

typedef struct SaxEvent {
    SaxEventType event;
    char* name;
    char* fullname;
    char* namespace;
    char* value;
    char* text;
    int lineno;
    int colno;
    int user; /* allocated via SaxControls.factory */
} SaxEvent;

/*
struct _xmlSAXLocator {
    const xmlChar *(*getPublicId)	getPublicId
    const xmlChar *(*getSystemId)	getSystemId
    int(*getLineNumber)	getLineNumber
    int(*getColumnNumber)	getColumnNumber
}
Typedef unsigned char xmlChar
*/

/* Forward */
struct SaxEventHandler;

typedef struct SaxControls {
  int (*yyevent)(struct SaxEventHandler*, struct SaxEvent*);
  SaxEvent* (*eventfactory)(struct SaxEventHandler*, SaxEventType);
  void (*eventfree)(struct SaxEventHandler*, SaxEvent*);
} SaxControls;

typedef struct SaxEventHandler {
    SaxControls* controls;
    SaxFlags flags;
    char* document;
    char* publicid;
    char* systemid;
    xmlSAXLocator* xmlsaxlocator;
    xmlSAXHandler xmlsaxhandler;
} SaxEventHandler;

extern int saxeventhandlerinit(const char*, SaxControls*, SaxEventHandler*);
extern void saxeventhandlerclear(SaxEventHandler*);
extern void saxeventhandlerflag(SaxEventHandler*, SaxFlags);
extern void saxeventfree(SaxEventHandler*,SaxEvent* event);
extern int saxparse(SaxEventHandler*);
extern const char* saxeventstring(SaxEvent*,int);
extern const char* saxeventtypename(SaxEventType);
extern const char* saxversion(void);
#endif /*_SAX_H_*/
