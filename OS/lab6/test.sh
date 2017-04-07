#!/bin/bash

for i in $*; do
	sum=0
	cat $i
	for j in `cat $i | sed -r "s/([0-9])/ \1/gi"`; do
		sum=$((sum + $j))
	done
	echo "Suma: "$sum
done
