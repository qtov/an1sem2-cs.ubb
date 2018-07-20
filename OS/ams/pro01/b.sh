#!/bin/bash

while read -p "User: " user; do

	if [[ $user =~ ^[0-9]+$ ]] || [ "$user" == "" ]; then
		echo -e "Invalid username.\n"
		continue
	fi

	if ! getent -- passwd $user > /dev/null; then
		echo -e "Invalid username.\n"
		continue
	fi

	echo "Nume: `grep ^$user: /etc/passwd | cut -d: -f 5`"
	echo `ps -u $user --no-headers | wc -l` "procese."
	w --no-header $user
	
	echo
done
