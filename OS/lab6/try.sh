#!/bin/bash

for l in $*; do
	sum=0
	i=`cat $l | sed "s/[^0-9]/0/gi"`
	cat $l
	for ((j=0;j<${#i};j++)); do
		o=$((10#${i:$j:1}))
		sum=`expr $sum + $o`
	done
	echo "Suma: "$sum
done
