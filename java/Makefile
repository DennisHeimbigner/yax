# Makefile is used instead of build.xml because
# IMO, ant's lack of looping or functional map capability,
# and lack of controllable file comparison (e.g. diff)
# makes it too hard to use. Your mileage may vary.

# Define the path separator
S=;
#S=:

# Paths of interest
SRCDIR=src/yax
TESTDIR=src/yax/test
TESTDATA=./data

TESTINPUTS=${TESTDATA}/testinput
TESTOUTPUTS=${TESTDATA}/testoutput
TESTBASELINE=${TESTDATA}/baseline

BUILD=./out

GRAMMARS=dap4.y calc.y

SRC= \
src/yax/Lexeme.java \
src/yax/LexException.java \
src/yax/SaxEvent.java \
src/yax/SaxEventHandler.java \
src/yax/SaxEventType.java \
src/yax/KeyWordMap.java \
src/yax/Util.java

JAR=yax.jar

CLI=libs/commons-cli-1.2.jar

CP=${BUILD}${S}${CLI}

SAXSRC=src/yax/test/SaxTest.java src/yax/test/TestOptions.java
SAXTESTS=books comments d expr lextest

DAP4SRC=\
src/yax/test/Dap4Test.java \
src/yax/test/Dap4EventHandler.java \
src/yax/test/Dap4Parser.java \
src/yax/test/TestOptions.java

DAP4TESTS=dap4

CALCSRC=\
src/yax/test/CalcTest.java \
src/yax/test/CalcEventHandler.java \
src/yax/test/CalcParser.java \
src/yax/test/TestOptions.java

CALCTESTS=calc

XMLSRC=\
src/yax/test/XmlTest.java \
src/yax/test/XmlEventHandler.java \
src/yax/test/XmlParser.java \
src/yax/test/TestOptions.java

XMLTESTS=books comments d expr lextest

.PHONEY: check action action0 action1 saxtest dap4test calctest xmltest

all: ${JAR}

clean:: testclean
	rm -fr ${JAR} ${BUILD}

testclean::
	rm -fr ${TESTOUTPUTS}

${JAR}: ${SRC} ${BUILD}
	javac -classpath "${CP}" -d ${BUILD} ${SRC} 
	jar cf ${JAR} -C ${BUILD} yax

${BUILD}:
	mkdir -p ${BUILD}

${TESTOUTPUTS}:
	mkdir -p ${TESTOUTPUTS}

TESTSETS=saxtest calctest dap4test xmltest

check:: ${TESTSETS}

saxtest: ${JAR} ${SAXSRC}
	@javac -classpath "${CP}" -d ${BUILD} ${SAXSRC}
	@for t in ${SAXTESTS} ; do ${MAKE} TEST=Sax CASE=$$t  FLAGS="-t -xe" action ; done

dap4test: ${JAR} ${DAP4SRC}
	@javac -classpath "${CP}" -d ${BUILD} ${DAP4SRC}
	@for t in ${DAP4TESTS} ; do ${MAKE} TEST=Dap4 CASE=$$t  FLAGS="-t -xe" action; done

calctest: ${JAR} ${CALCSRC}
	@javac -classpath "${CP}" -d ${BUILD} ${CALCSRC}
	@for t in ${CALCTESTS} ; do ${MAKE} TEST=Calc CASE=$$t FLAGS="-t -xe" action ; done

xmltest: ${JAR} ${XMLSRC}
	@javac -classpath "${CP}" -d ${BUILD} ${XMLSRC}
	@for t in ${XMLTESTS} ; do ${MAKE} TEST=Xml CASE=$$t FLAGS="" action ; done

action: ${TESTOUTPUTS}
	@rm -f tmp1 tmp2
	java -cp "${CP}" yax.test.${TEST}Test ${FLAGS}  ${TESTINPUTS}/${CASE}.xml >& tmp1
	@sed -e 's/(line [0-9][0-9]*)//' < tmp1 > tmp2
	@LOWER=`echo ${TEST} | tr '[:upper:]' '[:lower:]'` ; \
	cp tmp2 ${TESTOUTPUTS}/${CASE}.$$LOWER ; \
	if diff -wBb ${TESTBASELINE}/${CASE}.$$LOWER ${TESTOUTPUTS}/${CASE}.$$LOWER;\
	then echo "Passed: ${TEST}" ; else echo "Failed: ${TEST}" ; fi

generate::
	bison -Ljava -t -v -pDap4 -o ${TESTDIR}/Dap4Parser.java ${TESTDIR}/dap4.y
	bison -Ljava -t -v -pCalc -o ${TESTDIR}/CalcParser.java ${TESTDIR}/calc.y
	bison -Ljava -t -v -pXml -o ${TESTDIR}/XmlParser.java ${TESTDIR}/xml.y

init::
	rm -f ${TESTBASELINE}/*
	cp -f ${TESTOUTPUTS}/* ${TESTBASELINE}

