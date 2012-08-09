#!/bin/bash

#set -x

LEXTESTS="comments d lex_test books expr"
EXPRTESTS=expr
DAPTESTS=dap4

rm -fr testoutput
mkdir -p testoutput

for f in $LEXTESTS ; do
  echo "*** Testing lex_test: ${f}.xml"
  ./lex_test -t -e testdata/${f}.xml >&testoutput/${f}.lt
  if ! diff -w baseline/${f}.lt testoutput/${f}.lt ; then echo "*** FAIL: ${f}.xml";  fi
done
for f in $EXPRTESTS ; do
  echo "*** Testing expr: ${f}.xml"
  ./expr testdata/${f}.xml >&testoutput/${f}.expr
  if ! diff -w baseline/${f}.expr testoutput/${f}.expr ; then echo "*** FAIL: ${f}.xml";  fi
done
for f in DAP4TESTS ; do
  echo "*** Testing dap4: ${f}.xml"
  ./dap4 testdata/${f}.xml >&testoutput/${f}.dap4
  if ! diff -w baseline/${f}.dap4 testoutput/${f}.dap4 ; then echo "*** FAIL: ${f}.xml";  fi
done

echo "*** Passed all tests"

exit 0

