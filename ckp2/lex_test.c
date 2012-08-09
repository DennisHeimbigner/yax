#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <getopt.h>

#include "yax.h"

static char* getinput(char* filename);

/* getopt flags */
static int trimoption = 0;
static int elideoption = 0;

int
main(int argc, char** argv)
{
    yax_err err = YAX_OK;
    yax_state* lexer;
    yax_token token;
    int flags = YXFLAG_NONE;

    char* input;
    int i,c;
  
    while ((c = getopt(argc, argv, "te")) != EOF) {
      switch(c) {
	case 'e':
	  elideoption = 1;	  
	  break;
	case 't':
	  trimoption = 1;	  
	  break;
	case '?':
	  fprintf(stderr,"unknown option\n");
	  exit(1);
      }
    }
    argc -= optind;
    argv += optind;

    if(argc == 0) {
      fprintf(stderr,"no input\n");
      exit(1);
    }

    input = getinput(argv[0]);

    if(trimoption)
	flags |= YXFLAG_TRIMTEXT;
    if(elideoption)
	flags |= YXFLAG_ELIDETEXT;

    err = yax_create(input,flags,&lexer);
    if(err) {
      fprintf(stderr,"%s\n",yax_errstring(err));
      exit(1);
    }

    memset((void*)&token,0,sizeof(token));

    for(i=0;i<200;i++)
    {
	char* trace = NULL;
	err = yax(lexer,&token);
	if(err)
	    break;
	trace = yax_trace(lexer,&token); printf("%s\n",trace); fflush(stdout); if(trace) free(trace);
	if(token.tokentype == YAX_EOF)
	    break;
    }
    printf("%s\n",yax_errstring(err)); fflush(stdout);
    exit(0);
}

static char*
getinput(char* filename)
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


