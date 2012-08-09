#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "yxlist.h"
#include "yax.h"
#include "dap4parse.h"
#include "options.h"

static char* getinput(char* filename);

int
main(int argc, char** argv)
{
    char* input;

    if(argc == 1) {
      fprintf(stderr,"no input\n");
      exit(1);
    }

    input = getinput(argv[1]);
    dap4debug = 1;
    if(!dap4_parse(input)) {
	fprintf(stderr,"parse failed\n");
    }
    return 0;
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
