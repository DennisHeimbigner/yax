CFLAGS=-g -O0 -Wall -Wdeclaration-after-statement

.PHONEY: tests

all: tests

clean::
	rm -f libyax.a *.o
	rm -fr expr${X} lex_test${X} xdom_test${X} parsetest${X}
	rm -fr expr.tab.c expr.output
	rm -fr dap4.tab.c dap4.tab.h dap4.output

tests:: lex_test${X} expr${X} dap4${X}
	./run_tests.sh

libyax.a: yax.c yax.h yxlist.c yxlist.h
	gcc ${CFLAGS} -I. -c yax.c yxlist.c
	ar -cr libyax.a yax.o yxlist.o

lex_test${X}: lex_test.c libyax.a
	gcc ${CFLAGS} -o lex_test${X} -I. lex_test.c libyax.a

expr${X}: expr.tab.c libyax.a
	gcc ${CFLAGS} -o expr${X} -I. expr.tab.c libyax.a

expr.tab.c: expr.y
	bison -t -v expr.y

DAP4SRC=options.c dap4perfect.c dap4.tab.c dap4parse.c dap4lexer.c 

dap4${X}: libyax.a $(DAP4SRC)
	gcc -E ${CFLAGS} -I. dap4.c ${DAP4SRC} >dap4.txt
	gcc ${CFLAGS} -I. -o dap4${X} dap4.c ${DAP4SRC} libyax.a

dap4.tab.c dap4.tab.h: dap4.y
	bison -t -d -v -pdap4 dap4.y

# Only invoke if gperf program is available
# Remove the line numbers for easier debug with gdb
perfect::
	rm -f dap4perfect.c 
	gperf dap4.gperf | sed -e '/^[#]line/d' >dap4perfect.c

