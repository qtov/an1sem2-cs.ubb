#!/bin/bash

first_arg=1
# daca trebuie sa citim primul argument

for arg in $@; do
	if [ $first_arg -eq 1 ]; then
		first_arg=0
		fis=$arg
		continue
	fi

	num=$arg
	first_arg=1

	# daca nu e fisier primul argument
	if [ ! -f $fis ]; then
		echo "$fis - fisier inexistent."
		continue
	fi

	# daca nu e numar al doilea argument sau e 0
	if [[ ! $num =~ ^[0-9]+$ ]] || [ $num -eq 0 ]; then
		echo "$num nu este un numar valid."
		continue
	fi

	echo "Fisier: $fis; Numar: $num"

	while read line; do
		echo $line | cut -d ' ' -f $num
	done < $fis

	echo
done

