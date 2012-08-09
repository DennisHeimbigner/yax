#!/bin/bash

#set -x

DATA="../shared/data"

LEXTESTS="comments d lex_test books expr"
EXPRTESTS=expr
DAPTESTS=dap4

rm -fr ${DATA}/testoutput
mkdir -p ${DATA}/testoutput

if test -f lex_test || test -f lex_test.exe ; then
for f in $LEXTESTS ; do
  echo "*** Testing lex_test: ${f}.xml"
  ./lex_test -t -e ${DATA}/testdata/${f}.xml >& ${DATA}/testoutput/${f}.lt
  if ! diff -w ${DATA}/baseline/${f}.lt ${DATA}/testoutput/${f}.lt ; then echo "*** FAIL: ${f}.xml";  fi
done
fi

if test -f expr || test -f expr.exe ; then
for f in $EXPRTESTS ; do
  echo "*** Testing expr: ${f}.xml"
  ./expr ${DATA}/testdata/${f}.xml >& ${DATA}/testoutput/${f}.expr
  if ! diff -w ${DATA}/baseline/${f}.expr  ${DATA}/testoutput/${f}.expr ; then echo "*** FAIL: ${f}.xml";  fi
done
fi
if test -f dap4 || test -f dap4.exe ; then
for f in DAP4TESTS ; do
  echo "*** Testing dap4: ${f}.xml"
  ./dap4 testdata/${f}.xml >& ${DATA}/testoutput/${f}.dap4
  if ! diff -w ${DATA}/baseline/${f}.dap4  ${DATA}/testoutput/${f}.dap4 ; then echo "*** FAIL: ${f}.xml";  fi
done
fi

echo "*** Passed all tests"

exit 0

