/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:20:03 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/24 11:54:52 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"

class A {
	private:
		int _num;
	public:
		A() { _num = 42; }
		A(int num) { _num = num; }
		~A() {}
		int getNum() { return _num; }
		void setNum(int num) { _num = num; }	
};


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
	ft::vector<int> first;                                // empty vector of ints
	ft::vector<int> second (4, 100);                       // four ints with value 100
	ft::vector<int> third (second.begin(),second.end());  // iterating through second
	ft::vector<int> fourth (third);                       // a copy of third
	
	//std::cout << "fill and range with double" << std::endl;
	ft::vector<double> fill_with_double(5, 100.1);                       // four ints with value 100
	ft::vector<double> range_with_double(fill_with_double.begin(),fill_with_double.end());  // iterating through second

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
  	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  	std::cout << "The contents of fifth are:";
  	for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
      	std::cout << ' ' << *it;
  	std::cout << '\n';
	return (1);
}

int test_iterators()
{
	// ==================================================================
	std::cout << "test .begin() and .end() with empty vector" << std::endl;
	ft::vector<int> empty;

	if (empty.begin() == empty.end())
		std::cout << "===WOW, they are equal, but dereference iterators leads to segfault===\n" << std::endl;


	// ==================================================================
	std::cout << "test .begin() and .end() with fill vector" << std::endl;

	ft::vector<int> test (4, 44);
	*test.begin() = 10;
	*(--test.end()) = 50;
	
	std::cout << "The contents of test:";
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n' << std::endl;

	// test valid expressions
	ft::vector<int>::iterator first_iter = test.begin();
	ft::vector<int>::iterator second_iter = first_iter + 2;
	std::cout << *first_iter << " " << *second_iter << std::endl;
	
	// ==================================================================
	std::cout << "CONSTRUCTORS OF ITERATORS, equality/inequality (== and !=)" << std::endl;
	ft::vector<int>::iterator default_iter;
	ft::vector<int>::iterator copy_iterator(first_iter);
	if (copy_iterator == first_iter)
		std::cout << "copy_iterator == first_iter is true" << std::endl;
	ft::vector<int>::iterator assign_iter = second_iter;
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
	ft::vector<int>::iterator third_iter = 2 + first_iter;
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

	// ==================================================================
	std::cout << std::endl;
	std::cout << "->" << std::endl;

	A test_1;
	A test_2(21);
	ft::vector<A> vector_A;
	vector_A.push_back(test_1);
	vector_A.push_back(test_2);

	ft::vector<A>::iterator it_a = vector_A.begin();
	std::cout << it_a->getNum() << std::endl;
	return (1);
}

int test_const_iterators()
{
	ft::vector<int> test;
	test.push_back(10);
	test.push_back(20);
	test.push_back(30);
	ft::vector<int>::const_iterator first_iter = test.begin();
	ft::vector<int>::const_iterator second_iter = --(test.end());

	ft::vector<int>::const_iterator default_iter;
	ft::vector<int>::const_iterator copy_iterator(first_iter);
	if (copy_iterator == first_iter)
		std::cout << "copy_iterator == first_iter is true" << std::endl;
	ft::vector<int>::const_iterator assign_iter = first_iter;
	if (assign_iter == first_iter)
		std::cout << "assign_iter == first_iter is true" << std::endl;
	if (first_iter != second_iter)
		std::cout << "first_iter != second_iter is true\n" << std::endl;	
	return (1);

	// *first_iter = 100; - unavailable, because iterator is const
}

int test_reverse_iterators()
{
	ft::vector<int> test;
	test.push_back(10);
	test.push_back(20);
	test.push_back(30);

	std::cout << "myvector contains:";
  	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	ft::vector<int>::reverse_iterator it = test.rbegin();
	std::cout << "reverse output from rbegin to rend:";
	for (; it != test.rend(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	// =======================================================

	ft::vector<int>::reverse_iterator rit_begin = test.rbegin();
	ft::vector<int>::reverse_iterator rit_end = --test.rend();
	std::cout << "test.rbegin(): " << *rit_begin << std::endl;
	std::cout << "--test.rend(): " << *rit_end << std::endl;

	// =======================================================
	std::cout << std::endl;
	std::cout << "=====Member functions=====\n" << std::endl;

	std::cout << "Addition operator: " << *(rit_begin + 1) << std::endl;
	std::cout << "Increment iterator position: " << *(rit_begin++) << std::endl;
	std::cout << "Subtraction operator: " << *(rit_end - 1) << std::endl;
	std::cout << "Decrease iterator position: " << *(rit_end--) << std::endl;
	std::cout << "Dereference iterator with offset: " << rit_begin[0] << std::endl;
	
	std::cout << "Advance iterator: "; 
	rit_begin += 1;
	std::cout << *rit_begin << std::endl;
	std::cout << "Retrocede iterator: "; 
	rit_begin -= 1;
	std::cout << *rit_end << std::endl;

	std::cout << std::endl;
	std::cout << "=====relational operators=====\n" << std::endl;

	rit_begin = test.rbegin();
	rit_end = --test.rend();
	
	std::cout << "(<, >, <= and >=)" << std::endl;
	if (rit_begin < rit_end)
		std::cout << "rit_begin < rit_end is true" << std::endl;
	if (rit_end > rit_begin)
		std::cout << "rit_begin > rit_end is true" << std::endl;
	 if (rit_begin <= rit_begin)
		std::cout << "first_iter <= first_iter is true" << std::endl;
	if (rit_end >= rit_end)
		std::cout << "third_iter >= third_iter is true" << std::endl;
	
	return (1);
}

int test_element_access()
{
	ft::vector<int> test;
	test.push_back(10);
	test.push_back(20);
	test.push_back(30);
	std::cout << "operator[]: " << test[1] << std::endl;	 

	const ft::vector<int> test_const(4, 100);
	std::cout << "const operator[]: " << test_const[1] << std::endl;	 

	std::cout << "method .at()" << std::endl;
	try
	{
		std::cout << test.at(10) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "front() and back()" << std::endl;
	std::cout << test.front() << std::endl;
	std::cout << test.back() << std::endl;
	
	std::cout << "const front() and back()" << std::endl;
	std::cout << test_const.front() << std::endl;
	std::cout << test_const.back() << std::endl;
	return (1);
}

int test_capacity()
{
	ft::vector<int> test;
	test.push_back(10);
	test.push_back(20);
	test.push_back(30);

	ft::vector<A> test_2(8, 20);
	test_2.push_back(A(10));

	ft::vector<int> test_empty;
	
	std::cout << "test.size(): " << test.size() << std::endl;
	std::cout << "test_2.size(): " << test_2.size() << std::endl;

	std::cout << "test.max_size(): " << test.max_size() << std::endl;
	std::cout << "test_2.max_size(): " << test_2.max_size() << std::endl;

	std::cout << "test.capacity(): " << test.capacity() << std::endl;
	std::cout << "test_2.capacity(): " << test_2.capacity() << std::endl;

	if (test_empty.empty()) 
		std::cout << "test_empty.empty(): true" << std::endl;
	
	ft::vector<int> test_reserv;
	std::cout << "test_reserv.capacity() before .reserve(10): " 
				<< test_reserv.capacity() << std::endl;
	test_reserv.reserve(10);
	std::cout << "test_reserv.capacity() after .reserve(10): " 
				<< test_reserv.capacity() << std::endl;
	try
	{
		std::cout << "try reserve(__n) with __n > max_size(): " << std::endl;
		test_reserv.reserve(2305843009213693955);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "==test .resize()==" << std::endl;  
	ft::vector<int> myvector;

	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8, 100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (int i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	
	return (1);
}

int	test_modifiers_assign()
{
	std::cout << "==assign()==" << std::endl;

	ft::vector<int> first(7, 100);
	std::cout << "before assign first vector contains:";
	for (int i=0;i<first.size();i++)
		std::cout << ' ' << first[i];
	std::cout << '\n';
	std::cout << "before assign first vector size:" << first.size() << std::endl;
	std::cout << "before assign first vector capacity:" << first.capacity() << std::endl;

	try
	{
		std::cout << std::endl;
		std::cout << "try assign(__n, 100) with __n > max_size(): " << std::endl;
		first.assign(2305843009213693955,100);             // 7 ints with a value of 100
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
	std::cout << "use assign(21, 42)" << std::endl;
	first.assign(21, 42);
	
	std::cout << "after assign first vector contains:";
	for (int i=0; i < first.size(); i++)
		std::cout << ' ' << first[i];
	std::cout << '\n';
	std::cout << "after assign first vector size:" << first.size() << std::endl;
	std::cout << "after assign first vector capacity:" << first.capacity() << std::endl;

	std::cout << std::endl;  
	std::cout << "==assign() with iterators==" << std::endl;

	ft::vector<int> second;
  	ft::vector<int> third;
	ft::vector<int>::iterator it;
	it = first.begin() + 1;

	second.assign(it, first.end() - 1); // the 5 central values of first

	int myints[] = {1776, 7, 4};
	third.assign(myints, myints + 2);   // assigning from array.

	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';

	return 1;
}

int test_modifiers_insert()
{
	ft::vector<int> myvector (3,100);
	ft::vector<int>::iterator it;
	ft::vector<int>::iterator start;


	it = myvector.begin();
	it = myvector.insert(it, 200);

	myvector.insert(it,2,300);
	
	// // "it" no longer valid, get a new one:
	it = myvector.begin();

	ft::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it = myvector.begin(); it < myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	return (1);
}

void test_relational_operators()
{
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (2,200);   // two ints with a value of 200

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

void test_swap()
{
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';

	ft::swap(foo, bar);
	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';

}

void test_erase()
{
  ft::vector<int> myvector;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  myvector.erase (myvector.begin()+5);

  // erase the first 3 elements:
  myvector.erase (myvector.begin(),myvector.begin()+3);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}



//  Написать тесты для реверс итератора

//  17.07
//  Modifiers - assign, insert, swap, clear
//  relational operations

int main(int argc, char const *argv[])
{
	//test_constructors();
	//test_iterators();
	//test_const_iterators();
	test_reverse_iterators();
	//test_element_access();
	//test_capacity();
	//test_modifiers_assign();
	//test_modifiers_insert();
	//test_relational_operators();
	//test_swap();
	//test_erase();
}

