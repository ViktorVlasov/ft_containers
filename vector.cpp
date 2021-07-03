/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:20:03 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/03 13:33:57 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{

	// CONSTRUCTORS
	/*
	(1) empty container constructor (default constructor)
		Constructs an empty container, with no elements.
	(2) fill constructor
		Constructs a container with n elements. Each element is a copy of val.
	(3) range constructor
		Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
	(4) copy constructor
		Constructs a container with a copy of each of the elements in x, in the same order.
	*/

	std::vector<int> first;                                // empty vector of ints
	

	// std::vector<int> second (4,100);                       // four ints with value 100
	// std::vector<int> third (second.begin(),second.end());  // iterating through second
	// std::vector<int> fourth (third);                       // a copy of third
	
	// int myints[] = {16,2,77,29};
  	// std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  	// std::cout << "The contents of fifth are:";
  	// for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    // 	std::cout << ' ' << *it;
  	// std::cout << '\n';
	
	// return 0;
}
