while [ 1 ]; do
	a=$RANDOM
	echo $a
	echo $a > "${a}_test"
	sleep 5
	rm "${a}_test" 2> /dev/null
done
