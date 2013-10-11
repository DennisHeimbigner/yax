#!/bin/sh
#set -x
EXPORT=export
DST=$EXPORT/yax

FILES=`cat Inventory |tr -d '\r' |tr '\n' '  '`

rm -fr ${EXPORT}
mkdir -p ${DST}

for f in ${FILES} ; do
if test -f $f ; then
  DIR=`dirname $f`
  mkdir -p ${DST}/${DIR}
  cp $f $DST/$f
else
  echo "Missing file: $f" >&2
fi
done

