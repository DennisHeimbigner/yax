#!/bin/bash

#set -x

EXT="trace"

if test "x$1" = "x1" ; then INIT=1; else INIT=0 ; fi
if test "x$2" = "x1" ; then
  VG="valgrind --leak-check=full"
#  VG="${VG} --show-reachable=yes"
else
  VG=""
fi

DATA="./data"

CASES="dap4"

if ! test -f ${DATA}/testoutput ; then
  mkdir -p ${DATA}/testoutput
fi

for f in $CASES ; do
  echo "*** Testing dap4_test: ${f}"
  rm -f ./tmp
  echo "test=./dap4test -dte ${DATA}/testinput/${f}.xml"
  if test "x$VG" = x ; then
    ./dap4test -dte ${DATA}/testinput/${f}.xml >& ./tmp
    # Remove the (line xxx) to make this insensitive to minor changes to .y file
    sed -e 's/(line [0-9][0-9]*)//' <./tmp >${DATA}/testoutput/${f}.${EXT}
    if test "x${INIT}" = x1 ; then
      cp ${DATA}/testoutput/${f}.${EXT} ${DATA}/baseline/${f}.${EXT}
    else
      echo diff ${DATA}/baseline/${f}.dap4 ${DATA}/testoutput/${f}.dap4
      if ! diff -w ${DATA}/baseline/${f}.${EXT} ${DATA}/testoutput/${f}.${EXT}; then echo "*** FAIL: ${f}";  fi
    fi
  else
    $VG ./dap4test -dte ${DATA}/testinput/${f}.xml >/dev/null
  fi
done

echo "*** Passed all tests"

exit 0

