#!/bin/bash

#set -x
 
while getopts ":ive:p:" opt; do
  case $opt in
    v) VG=1 ;;
    p) PROG="$OPTARG" ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      exit 1
      ;;
    :)
      echo "Option -$OPTARG requires an argument." >&2
      exit 1
      ;;
  esac
done

if test "x$PROG" = x ; then
  echo "missing program name or extension"
  exit 1
fi

# Remaining arguments are the test cases
CASES=${@:$OPTIND}

case $PROG in
saxtest) EXT="sax" ;;
dap4test) EXT="parse" ;;
calctest) EXT="parse" ;;
esac

DATA="./data"

if ! test -f ${DATA}/testoutput ; then
  mkdir -p ${DATA}/testoutput
fi

for f in $CASES ; do
  echo "*** Testing dap4_test: ${f}"
  rm -f ./tmp
  echo "test=./${PROG} -dte ${DATA}/testinput/${f}.xml"
  if test "x$VG" = x ; then
    ./${PROG} -dte ${DATA}/testinput/${f}.xml >& ./tmp
    # Remove the (line xxx) to make this insensitive to minor changes to .y file
    sed -e 's/(line [0-9][0-9]*)//' <./tmp >${DATA}/testoutput/${f}.${EXT}
    echo diff ${DATA}/baseline/${f}.dap4 ${DATA}/testoutput/${f}.dap4
    if ! diff -w ${DATA}/baseline/${f}.${EXT} ${DATA}/testoutput/${f}.${EXT}; then echo "*** FAIL: ${f}";  fi
  else
    $VG ./dap4test -dte ${DATA}/testinput/${f}.xml >/dev/null
  fi
done

echo "*** Passed all tests"

exit 0

