#!/bin/bash

CONTAINER="$1"

./my_change.sh std $CONTAINER $CONTAINER.cpp && ./a.out > std_out
./my_change.sh ft $CONTAINER $CONTAINER.cpp && ./a.out > my_out

diff my_out std_out > logs.txt
ret=$?
if [[ $ret -eq 0 ]]; then
	clang++ -Wall -Wextra -Werror -std=c++98 $CONTAINER.cpp -o val_out
	valgrind ./val_out

	echo -e "===============================================================================================\n"
	echo -e "******************************✅✅✅NO differences!✅✅✅**************************************\n"
	echo -e "******************************👌👌👌   TEST: OK!   👌👌👌**************************************\n"
	echo -e "===============================================================================================\n"

	rm logs.txt my_out std_out val_out a.out
else
	echo -e "\n****************************😭😭😭TEST FAILED!😭😭😭******************************************\n "
	exit 1
fi