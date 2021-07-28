#!/bin/bash

# ./my_change.sh 
# if $1 contains ft, then std:: replace to ft::
# else if $1 contains std, then vice versa

# $2 is name of class, for example: vector, map, set, etc.
# $3 filepath
if [ $# -ne 3 ]; then
	echo "wrong args"
else
	if [ "$1" == "ft" ]; then
		sed -i "s/std::$2/ft::$2/" "$3"
		echo "std::$2 replace to ft::$2"
	elif [ "$1" == "std" ]; then
		sed -i "s/ft::$2/std::$2/" "$3"
		echo "ft::$2 replace to std::$2"
	fi
	clang++ -Wall -Wextra -Werror -std=c++98 "$3" -g
fi