/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:20:03 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/10 23:04:25 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"


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
int test_constructors()
{
	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second (4, 100);                       // four ints with value 100
	std::vector<int> third (second.begin(),second.end());  // iterating through second
	std::vector<int> fourth (third);                       // a copy of third
	
	//std::cout << "fill and range with double" << std::endl;
	std::vector<double> fill_with_double(5, 100.1);                       // four ints with value 100
	std::vector<double> range_with_double(fill_with_double.begin(),fill_with_double.end());  // iterating through second

	std::cout << "capacity: " << std::endl;
	std::cout << first.capacity() << std::endl;
	std::cout << second.capacity() << std::endl;
	std::cout << third.capacity() << std::endl;
	std::cout << fourth.capacity() << std::endl;

	std::cout << fill_with_double.capacity() << std::endl;
	std::cout << range_with_double.capacity() << std::endl;

	std::cout << "size: " << std::endl;
	std::cout << first.size() << std::endl;
	std::cout << second.size() << std::endl;
	std::cout << third.size() << std::endl;
	std::cout << fourth.size() << std::endl;
	
	std::cout << fill_with_double.size() << std::endl;
	std::cout << range_with_double.size() << std::endl;
	
	int myints[] = {16,2,77,29};
  	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  	std::cout << "The contents of fifth are:";
  	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
      	std::cout << ' ' << *it;
  	std::cout << '\n';
	return (1);
}

int test_iterators()
{
	// ==================================================================
	std::cout << "test .begin() and .end() with empty vector" << std::endl;
	std::vector<int> empty;

	if (empty.begin() == empty.end())
		std::cout << "===WOW, they are equal, but dereference iterators leads to segfault===\n" << std::endl;


	// ==================================================================
	std::cout << "test .begin() and .end() with fill vector" << std::endl;

	std::vector<int> test (4, 44);
	*test.begin() = 10;
	*(--test.end()) = 50;
	
	std::cout << "The contents of test:";
	for (std::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n' << std::endl;

	// test valid expressions
	std::vector<int>::iterator first_iter = test.begin();
	std::vector<int>::iterator second_iter = first_iter + 2;
	std::cout << *first_iter << " " << *second_iter << std::endl;
	
	// ==================================================================
	std::cout << "CONSTRUCTORS OF ITERATORS, equality/inequality (== and !=)" << std::endl;
	std::vector<int>::iterator default_iter;
	std::vector<int>::iterator copy_iterator(first_iter);
	if (copy_iterator == first_iter)
		std::cout << "copy_iterator == first_iter is true" << std::endl;
	std::vector<int>::iterator assign_iter = second_iter;
	if (assign_iter == second_iter)
		std::cout << "assign_iter == second_iter is true" << std::endl;
	if (first_iter != second_iter)
		std::cout << "first_iter != second_iter is true\n" << std::endl;

	// ==================================================================
	std::cout << "increment and decrement, offset dereference operator []";
	first_iter[2] = 20;
	std::cout << "*(++first_iter): " << *(first_iter++) << std::endl;
	std::cout << "*(++first_iter): " << *first_iter++ << std::endl;
	std::cout << "*(++first_iter): " << *(++first_iter) << std::endl;
	std::cout << "*(first_iter--): " << *(first_iter--) << std::endl;
	std::cout << "*first_iter--: " << *first_iter-- << std::endl;
	std::cout << "*(--first_iter): " << *(--first_iter) << std::endl;

	// ==================================================================
	std::vector<int>::iterator third_iter = 2 + first_iter;
	std::cout << "*third_iter after =#=third_iter = 2 + first_iter=#=: " << *third_iter << std::endl;
	std::cout << "third_iter - first_iter: " << third_iter - first_iter << std::endl;
	std::cout << "*(third_iter - 2): " << *(third_iter - 2) << std::endl;
	
	// ==================================================================
	std::cout << std::endl;
	std::cout << "(<, >, <= and >=)" << std::endl;
	if (first_iter < third_iter)
		std::cout << "first_iter < third_iter is true" << std::endl;
	if (third_iter > first_iter)
		std::cout << "third_iter > first_iter is true" << std::endl;
	if (first_iter <= first_iter)
		std::cout << "first_iter <= first_iter is true" << std::endl;
	if (third_iter >= third_iter)
		std::cout << "third_iter >= third_iter is true" << std::endl;
		
	// ==================================================================
	std::cout << std::endl;
	std::cout << "(+=, -=)" << std::endl;
	first_iter += 3;
	third_iter -= 1;
	std::cout << "first_iter += 3: " << *first_iter << std::endl;
	std::cout << "third_iter -= 1: " << *third_iter << std::endl;
	return (1);
}

int test_reverse_iterators()
{
	
}

int main(int argc, char const *argv[])
{
	test_constructors();
	test_iterators();

}
