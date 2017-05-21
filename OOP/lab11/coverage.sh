#!/bin/bash

make cov
export GCOV_PREFIX="`pwd`/coverage"
export GCOV_PREFIX_STRIP=`echo $GCOV_PREFIX | grep -o '/' | wc -l`
#export GCOV_PREFIX_STRIP=`echo $GCOV_PREFIX | tr -cd '/' | wc -c`
./t
mv *.gcno coverage
cd coverage
lcov -t "result" -o ex_test.info -c -d .
genhtml -o res ex_test.info
cd res
chromium index.html
