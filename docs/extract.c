#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static char digits[] = "0123456789";

static int readline(FILE*);
static int startofexample(char* line, int exampleno);

static char line[4096];

static int exno = 0;

static char* examplestart[] = {
"<pre>/*xml.y*/",
NULL
};
static char* exampleend[] = {
"<pre><!--xml.y-->",
NULL
};

int
main(int argc, char** argv)
{
    FILE* f;
    int excounter, found, hasline;

    if(argc == 1) {
	fprintf(stderr,"no arg\n");
	exit(1);
    } else {
        f = fopen(argv[1],"r");
        if(f == NULL) {
	    perror("fopen:");
	    exit(1);
	}
    }    
    if(argc == 3) {
	exno = atol(argv[2]);
    } else
	exno = 1;

    /* Locate the example start */
    for(found=0;;) {
	if(readline(f))
	    break;
	found = startofexample(line,exno);
	if(found)
	    break;
    }
    if(!found) {
	fprintf(stderr,"example %d not found\n",exno);
	exit(1);
    }
    /* start processing the example */
    for(;;) {
	if(readline(f))
	    break;
	/* Is this the example end? */
	if(strcmp(exampleend[exno-1],line)==0)
	    break; /* we are done */
	/* Does this line start with 2 digits and a blank? */
        hasline = (strchr(digits,line[0])
		   && strchr(digits,line[1])
		   && line[2] == ' ') ? 1 : 0;
	if(hasline) {
	    printf("%s\n",&line[3]); /* without the leading line number and blank*/
	} /* else ignore this line */
    }	
    if(f) fclose(f);
    exit(0);
}

static int
readline(FILE* f)
{
    int c;
    int pos = 0;
    line[0] = '\0';
    for(;;) {
	c=fgetc(f);
	if(c == EOF) return 1; /* is EOF */
	if(c == '\r') continue;
	if(c == '\n') break;
	if(pos == sizeof(line)-1) {
	    fprintf(stderr,"line too long\n");
	    exit(1);
	}
	line[pos++] = (char)c;
    }
    line[pos] = '\0';
    return 0; /* !EOF */
}

static int
startofexample(char* line, int exampleno)
{
    int i;
    for(i=0;examplestart[i] != NULL;i++) {
	if(strcmp(line,examplestart[i]) ==0 && (i+1) == exampleno) {
	    return 1;	    
	}
    }
    return 0;
}
