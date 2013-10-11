/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "options.h"

#include "sax.h"

#define EXPECTED_VERSION "2.00"

static char* getinput(const char* filename);
static int yyevent(SaxEventHandler* seh, SaxEvent* event);

static SaxControls testcontrols = {yyevent,NULL,NULL};

int
main(int argc, char** argv)
{
    SaxFlags flags = SXFLAG_NONE;
    char* input;
    const char* file;
    SaxEventHandler* seh;
    int ok;

    if(strcmp(EXPECTED_VERSION,saxversion()) != 0) {
	fprintf(stderr,"version mismatch: %s :: %s\n",
		EXPECTED_VERSION,saxversion());
	exit(1);
    }

    if(!options("t:d",argc,argv)) {
	fprintf(stderr,"Illegal command line option");
	exit(1);
    }

    flags = 0;
    if(optionset('t')) {
	const char* s = soption('t');
	int c;
	while((c=*s++)) {
	    switch (c) {
	    case 't': flags |= SXFLAG_TRIMTEXT; break;
	    case 'l': flags |= SXFLAG_ELIDETEXT; break;
	    case 'e': flags |= SXFLAG_ESCAPE; break;
	    case 'r': flags |= SXFLAG_NOCR; break;
	    default:
		fprintf(stderr,"unknown -t flag: %c",(char)c);
	    }
	}
    }

    file = nonoption(0);
    if(file == NULL) {
      fprintf(stderr,"no input\n");
      exit(1);
    }
	
    input = getinput(file);

    seh = (SaxEventHandler*)calloc(1,sizeof(SaxEventHandler));
    saxeventhandlerinit(input,&testcontrols,seh);
    ok = saxparse(seh);
    saxeventhandlerclear(seh);
    free(seh);

    if(ok)
	fprintf(stderr,"parse succeeded\n");
    else
	fprintf(stderr,"parse failed\n");
    exit(0);
}

static char*
getinput(const char* filename)
{
      static char data[1<<18];
      char* pos = data;
      int rem = sizeof(data);
      int fd = open(filename,0);
      if(fd < 0) {
	perror(filename);
	exit(1);
      }
      for(;;) {
	int count = read(fd,pos,rem);
	if(count < 0) {
	    perror(filename);
	    exit(1);
	}
	if(count == 0) break;
	pos += count;
	rem -= count;
      }
      *pos = '\0';
      return data;
}

static int
yyevent(SaxEventHandler* seh, SaxEvent* event)
{
    const char* trace = saxeventstring(event,seh->flags);
    printf("saxtest: %s\n", trace);
    fflush(stdout);
    return 1;
}
