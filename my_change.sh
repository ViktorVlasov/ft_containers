#!/bin/bash

# if $1 contains 1, then std:: replace to ft::
# else if $1 contains 0, then vice versa

# $2 is name of class, for example: vector, map, set, etc.
# $3 filepath
if [ $# -ne 3 ]; then
	echo "wrong args"
else
	if [ "$1" == "ft" ]; then
		echo "std::$2 replace to ft::$2"
		sed -i "" "s/std::$2/ft::$2/" "$3"
	elif [ "$1" == "std" ]; then
		echo "ft::$2 replace to std::$2"
		sed -i "" "s/ft::$2/std::$2/" "$3"
	fi
	clang++ "$3" -g
fi