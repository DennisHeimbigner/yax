#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "yax.h"

static void dumpattributes(yax_token* token);
static char* stringify(int len, char* s);
static char* getinput(char* filename);

static char* transtable[] = {
"amp","&",
"lt","<",
"gt",">",
NULL
};


int
main(int argc, char** argv)
{
    yaxstate* lexer;
    char* input;
    int i;
  
    if(argc == 1) {
      fprintf(stderr,"no input\n");
      exit(1);
    }

    input = getinput(argv[1]);

    lexer = yax_create(input);
    if(lexer == NULL) {
      fprintf(stderr,"out of memory\n");
      exit(1);
    }

    for(i=0;i<200;i++)
    {
	yax_token token;
	XLEX_TOKEN t;
	char* trans;

	t = yax(&token,lexer);
        printf("%d/%d: ",token.lineno,token.charno);
	switch(t) {
	case XLEX_ERROR:
	    printf("XLEX_ERROR: %s\n",yax_geterror(lexer));
	    goto done;
	case XLEX_EOF:
	    printf("XLEX_EOF\n");
	    goto done;
	case XLEX_OPEN:
	    printf("XLEX_OPEN: element=|%s|",
			stringify(token.name.len,token.name.name));
	    dumpattributes(&token);
	    printf("\n");
	    break;
	case XLEX_CLOSE:
	    printf("XLEX_CLOSE: element=|%s|\n",
			stringify(token.name.len,token.name.name));
	    break;
	case XLEX_OPENCLOSE:
	    printf("XLEX_OPENCLOSE: element=|%s|\n",
			stringify(token.name.len,token.name.name));
	    dumpattributes(&token);
	    printf("\n");
	    break;
	case XLEX_TEXT:
	    printf("XLEX_TEXT: text=|%s|",
			stringify(token.text.len,token.text.text));
	    trans = yax_unescape(token.text.len,token.text.text,transtable);
	    printf(" translation=|%s|\n",trans);
	    free(trans);
	    break;
	case XLEX_COMMENT:
	    printf("XLEX_COMMENT: text=|%s|\n",
			stringify(token.text.len,token.text.text));
	    break;
	default:
	    printf("unknown token type: %d\n",t);
	    break;
	}
	fflush(stdout);
    }
done:
    return 0;
}

static void
dumpattributes(yax_token* token)
{
    yax_attribute* attr = token->attributes;
    if(attr == NULL) return;
    printf(" attributes:");
    while(attr != NULL) {
	printf(" |%s|=",stringify(attr->name.len,attr->name.name));
	printf("|%s|",stringify(attr->value.len,attr->value.value));
	attr = attr->next;
    }
}


static char*
stringify(int len, char* s)
{
    static char text[1<<16];
    if(len <= 0 || s == NULL)
	text[0] = '\0';
    else {
	if(len >= sizeof(text)) len = sizeof(text)-1;
        memcpy(text,s,len);
        text[len] = '\0';
    }
    return text;
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


