#!/bin/bash

# for example: ./special.sh map_ft.cpp map_std.cpp

MYFILE=$1
STDFILE=$2

clang++ -Wall -Wextra -Werror -std=c++98 -fsanitize=address $MYFILE && ./a.out > my_out
clang++ -Wall -Wextra -Werror -std=c++98 -fsanitize=address $STDFILE && ./a.out > std_out

diff my_out std_out > logs.txt
ret=$?
if [[ $ret -eq 0 ]]; then
	clang++ -Wall -Wextra -Werror -std=c++98 -fsanitize=address map_ft.cpp -o val_out
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