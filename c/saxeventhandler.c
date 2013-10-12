/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "sax.h"

#ifdef TRACE
#define trace(event,flags) trace_event(event,flags)
#else
#define trace(event,flags)
#endif

/* Forward */
static void sax_startdocument(void* state);
static void sax_enddocument(void* state);
static void sax_startelement(void* state, const xmlChar* fullname, const xmlChar** attrs);
static void sax_endelement(void* state, const xmlChar* name);
static void sax_characters(void* state, const xmlChar* ch, int len);
static xmlEntityPtr sax_getentity(void* state, const xmlChar* name);
static void sax_fatalerror(void* state, const char* msg, ...);
static void sax_error(void* state, const char* msg, ...);
static void sax_warning(void* state, const char* msg, ...);
static void sax_setdocumentlocator(void* state, xmlSAXLocatorPtr loc);
static void splitfullname(const char* fullname, char** nsp, char** namep);
static SaxEvent* saxevent(SaxEventHandler*, SaxEventType);
static char* text_process(char* input, int len, SaxFlags flags);
static void addtext(char* dst, const char* txt, int flags);
static void unescape(const char*, char*, int);
#ifdef TRACE
static void trace_event(SaxEvent*,int);
#endif

const char* DEFAULTTRANSTABLE[] = {
"amp", "&", "lt", "<", "gt", ">", "quot", "\"", "apos", "'",NULL
};

#define MAXTEXT 16


/*************************************************/
/* DefaultHandler Overrides */

/*
The key thing to note is that we map the Sax Event
into a subset based on yax.lex.DomEventType. This means
we feed only a subset of the possible events into
the subclass handler. This can be changed by
overriding the suppressing event handler below.
*/

static void
sax_startdocument(void* state)
{
    SaxEventHandler* seh = (SaxEventHandler*)state;
    SaxEvent* event = saxevent(seh,STARTDOCUMENT);
    trace(event,seh->flags);
    seh->controls->yyevent(seh,event);
    saxeventfree(seh,event);
}

static void
sax_enddocument(void* state)
{
    SaxEventHandler* seh = (SaxEventHandler*)state;
    SaxEvent* event = saxevent(seh,ENDDOCUMENT);
    trace(event,seh->flags);
    seh->controls->yyevent(seh,event);
    saxeventfree(seh,event);
}

static void
sax_startelement(void* state, const xmlChar* fullname, const xmlChar** attrs)
{
    SaxEventHandler* seh = (SaxEventHandler*)state;
    SaxEvent* event;
    event = saxevent(seh,STARTELEMENT);
    event->fullname = strdup((char*)fullname);
    splitfullname(event->fullname,&event->namespace,&event->name);
    trace(event,seh->flags);
    seh->controls->yyevent(seh,event);
    saxeventfree(seh,event);

    /* Now pass the attributes as pseudo-events */
    if(attrs != NULL) {
        while(*attrs != NULL) {
            const char* aname = (char*)attrs[0];
            const char* avalue = (char*)attrs[1];
            attrs += 2;
            event = saxevent(seh,ATTRIBUTE);
            event->fullname = strdup(aname);
            splitfullname(event->fullname,&event->namespace,&event->name);
            event->value = strdup(avalue);
            trace(event,seh->flags);
            seh->controls->yyevent(seh,event);
            saxeventfree(seh,event);
	}
    }
}

static void
sax_endelement(void* state, const xmlChar* name)
{
    SaxEventHandler* seh = (SaxEventHandler*)state;
    SaxEvent* event = saxevent(seh,ENDELEMENT);
    event->fullname = strdup((char*)name);
    splitfullname(event->fullname,&event->namespace,&event->name);
    trace(event,seh->flags);
    seh->controls->yyevent(seh,event);
    saxeventfree(seh,event);
}

static void
sax_characters(void* state, const xmlChar* ch, int len)
{
    SaxEventHandler* seh = (SaxEventHandler*)state;
    SaxEvent* event = saxevent(seh,CHARACTERS);
    event->text = text_process((char*)ch,len,seh->flags);
    trace(event,seh->flags);
    seh->controls->yyevent(seh,event);
    saxeventfree(seh,event);
}

/*************************************************/
/* Entity resolution */

static xmlEntityPtr
sax_getentity(void* state, const xmlChar* name)
{
    return xmlGetPredefinedEntity(name);
}

/*************************************************/
/* Error handling Events */

static void
sax_fatalerror(void* state, const char* msg, ...)
{
    va_list args;
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    va_end(args);
}   

static void
sax_error(void* state, const char* msg, ...)
{
    va_list args;
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    va_end(args);
}   

static void
sax_warning(void* state, const char* msg, ...)
{
    va_list args;
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    va_end(args);
}   

/**************************************************/
/* Locator */

static void
sax_setdocumentlocator(void* state, xmlSAXLocatorPtr loc)
{
    SaxEventHandler* seh = (SaxEventHandler*)state;
    const char* publicid;
    const char* systemid;
    seh->xmlsaxlocator = loc;
    publicid = (char*)loc->getPublicId(loc);
    systemid = (char*)loc->getSystemId(loc);
    if(publicid != NULL)
	seh->publicid = strdup(publicid);
    if(systemid != NULL)
	seh->systemid = strdup(systemid);
}


/**************************************************/
/* Utilities */

static void
splitfullname(const char* fullname, char** nsp, char** namep)
{
    /* Extract out the short name */
    const char* p = fullname;
    char* q = NULL;
    while(*p) {
	if(p[0] == ':' && p[1] == ':') {
	    p = p+2;
	    q = (char*)p;
	} else
	    p++;
    }
    if(namep) {
	if(q == NULL)
	    *namep = strdup(fullname);
	else if(*q)
	    *namep = NULL;
	else
	    *namep = strdup(q);
    }
    if(nsp) {
	if(q == NULL || *fullname == '\0')
	    *nsp = NULL;
	else
	    *nsp = strndup(q,((q - fullname) - 2));
    }
}

#ifdef TRACE
static void
trace_event(SaxEvent* event, int flags)
{
    fprintf(stderr,"event.%s: %s\n",
			saxeventtypename(event->event),
			saxeventprintable(event,flags));
}
#endif

static SaxEvent*
saxevent(SaxEventHandler* seh, SaxEventType set)
{
    SaxEvent* event;
    if(seh->controls->eventfactory != NULL) {
	event = seh->controls->eventfactory(seh,set);
	if(event != NULL) {
	    event->event = set;
	    event->user = 1;
	}
    } else {
        event = (SaxEvent*)calloc(1,sizeof(SaxEvent));
	if(event != NULL) {
	    event->event = set;
	    event->user = 0;
	}
    }
    return event;
}

/* Process a piece of text using the specified flags */
static char*
text_process(char* input, int inputlen, SaxFlags flags)
{
    char* text;
    char* p;
    char* q;
    int c;
    char* nonwhite;
    int len,i;

    text = (char*)malloc(3*inputlen+1+3); /* max space needed */
    if(text == NULL) return NULL;

    nonwhite = NULL;
    p=input;
    q=text;
    for(i=0;i<inputlen;i++,p++) {
        c=*p;
	if(c == '\t' || c == ' ') {
	    if(nonwhite != NULL || ((flags & SXFLAG_TRIMTEXT) == 0))
		*q++ = (char)c;
	    /* else ignore */
	} else if(c == '\r' && (flags & SXFLAG_NOCR)) {
	    /* ignore */
	} else if(c < ' ' && (flags & SXFLAG_ESCAPE)) {
	    *q++ = '\\';
	    switch (c) {
	    case '\r': c = 'r'; break;
	    case '\n': c = 'n'; break;
	    case '\t': c = 't'; break;
	    case '\f': c = 'f'; break;
	    case '\v': c = 'v'; break;
	    default: {/* dump as octal */
	        char c1 = ((c >> 6) & 0x7) + '0';
	        char c2 = ((c >> 3) & 0x7) + '0';
	        char c3 = ((c) & 0x7) + '0';
		*q++ = c1;
		*q++ = c2;
		*q++ = c3;
		} break;
	    }
	} else {
	    nonwhite = p; /* track the last non-whitespace character */
	    *q++ = (char)c;
	}
    }
    *q = '\0';
    if(nonwhite != NULL && flags & SXFLAG_TRIMTEXT)
        *nonwhite = '\0'; /* Elide trailing whitespace */
    len = strlen(text);
    if(len > MAXELIDELENGTH) {
	text[MAXELIDELENGTH] = '\0';
	strcat(text,"...");
    }
    return text;
}

const char*
saxeventstring(SaxEvent* event, int flags)
{
    static char result[4096]; /*unsafe*/
    char trans[4096];

    sprintf(result,"[%s]",saxeventtypename(event->event));
    switch (event->event) {
    case STARTELEMENT:
    case ENDELEMENT:
	sprintf(result+strlen(result),": element=|%s|",
		event->name);
	break;
    case CHARACTERS:
	strcat(result," text=");
	addtext(result, event->text, flags);
	unescape(event->text,trans,sizeof(trans));
        strcat(result," translation=");
	addtext(result, trans, flags);
	break;
    case ATTRIBUTE:
	strcat(result,": name=");
	addtext(result, event->name, flags);
	strcat(result," value=");
	addtext(result, event->value, flags);
	break;
    case STARTDOCUMENT:
   	break;
    case ENDDOCUMENT:
	break;
    default:
        fprintf(stderr,"unknown event type: %s\n",
		saxeventtypename(event->event));
	return 0;
    }
    return result;
}

const char*
saxeventtypename(SaxEventType set)
{
    switch (set) {
    case STARTDOCUMENT: return "STARTDOCUMENT";
    case ENDDOCUMENT: return "ENDDOCUMENT";
    case STARTELEMENT: return "STARTELEMENT";
    case ENDELEMENT: return "ENDELEMENT";
    case ATTRIBUTE: return "ATTRIBUTE";
    case CHARACTERS: return "CHARACTERS";
    default: break;
    }
    return "UNDEFINED";
}

static void
addtext(char* dst, const char* txt, int flags)
{
    int len,shortened,i;
    char ch[2];

    shortened = 0;

    if(txt == NULL) {
	strcat(dst,"null");
	return;
    }

    len = strlen(txt);

    if((flags & SXFLAG_TRIMTEXT) != 0) {
	const char* p = txt;
	while(*p == ' ' || *p == '\t') {p++; len--;}
	txt = p;
	p = p + len;
	for(i=len-1;i>=0;i--) {
	    if(p[i] != ' ' && *p != '\t') break;
	}
	len = i;
    }

    if((flags & SXFLAG_ELIDETEXT) != 0 && len > MAXTEXT) {
	len = MAXTEXT;
	shortened = 1;
    }
    strcat(dst,"|");
    ch[1] = '\0';
    for(i = 0;i < len;i++) {
	char c = txt[i];
	if((flags & SXFLAG_NOCR) != 0 && c == '\r') {
	    /* ignore */
        } else if((flags & SXFLAG_ESCAPE) != 0 && c < ' ') {
	    strcat(dst,"\\");
	    switch (c) {
	    case '\n':
		strcat(dst,"n");
		break;
	    case '\r':
		strcat(dst,"r");
		break;
	    case '\t':
		strcat(dst,"t");
		break;
	    case '\f':
		strcat(dst,"f");
		break;
	    default: {/*convert to octal */
		int uc = c;
		char oct[4];;
		oct[0] = (char)((uc >> 6) & 07);
		oct[1] = (char)((uc >> 3) & 07);
		oct[2] = (char)((uc) & 07);
		oct[3] = '\0';
		strcat(dst,oct);
	        }; break;
	    }
	} else {
	    ch[0] = c;
	    strcat(dst,ch);
	}
    }
    if(shortened) {
        strcat(dst,"...");
    }
    strcat(dst,"|");
}


static void
unescape(const char* s, char* dst, int dlen)
{
    int c, i;
    const char* p; /* walk s */
    char* q; /* insertion point into dst */
    const char** translations = DEFAULTTRANSTABLE;

    dst[0] = '\0';
    if(s == NULL || *s == '\0') return;

    for(q=dst,p=s;(c = *p++);) {
	if(c == '&') {/* see if this is a legitimate entity */
	    for(i=0;translations[i];i++) {
		if(strncmp(p,translations[i],strlen(translations[i]))==0)
		    break;
	    }
	    if(translations[i]) {
		strcat(dst,translations[i+1]);
		p += strlen(translations[i]);
		q += strlen(translations[i+1]);
		continue;
	    }
	    /* else not a legitimate entity; skip */
	}
	*q++ = c;	
    }
    *q = '\0';
}

/**************************************************/
/* External API */

const char*
saxversion(void)
{
    return VERSION;
}

int
saxeventhandlerinit(const char* document,
		    SaxControls* controls,
		    SaxEventHandler* seh)
{
    xmlSAXHandler* xsh;

    seh->document = strdup(document);
    seh->controls = controls;

    xsh = &seh->xmlsaxhandler;
    xsh->startDocument = sax_startdocument;
    xsh->endDocument = sax_enddocument;
    xsh->startElement = sax_startelement;
    xsh->endElement = sax_endelement;
    xsh->characters = sax_characters;
    xsh->getEntity = sax_getentity;
    xsh->warning = sax_warning;
    xsh->error = sax_error;
    xsh->fatalError = sax_fatalerror;
    xsh->setDocumentLocator = sax_setdocumentlocator;
    return 1;
}

void
saxeventhandlerclear(SaxEventHandler* seh)
{
    if(seh == NULL) return;
    /* Clear the handler, but do not free */
    if(seh->document) free(seh->document);
    if(seh->publicid != NULL) free(seh->publicid);
    if(seh->systemid != NULL) free(seh->systemid);
    memset(seh,0,sizeof(SaxEventHandler));
}

void
saxeventfree(SaxEventHandler* seh, SaxEvent* event)
{
    if(event == NULL) return;
    if(event->name != NULL) free(event->name);
    if(event->fullname != NULL) free(event->fullname);
    if(event->namespace != NULL) free(event->namespace);
    if(event->value != NULL) free(event->value);
    if(event->text != NULL) free(event->text);
    if(event->user && seh->controls->eventfree != NULL)
        seh->controls->eventfree(seh,event);
    else
	free(event);
}

int
saxparse(SaxEventHandler* seh)
{
    int ret;
    xmlParserCtxtPtr cxt;

    cxt = xmlCreatePushParserCtxt(&seh->xmlsaxhandler, (void*)seh,
				   seh->document,strlen(seh->document),NULL);
    ret = xmlParseChunk(cxt, NULL, 0, 1);
    xmlFreeParserCtxt(cxt);
    return (ret == 0 ? 1 : 0);
}

void
saxeventhandlerflag(SaxEventHandler* seh, SaxFlags flags)
{
    seh->flags = flags;
}
