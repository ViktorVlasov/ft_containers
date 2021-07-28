/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_std.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:19:06 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/28 14:47:07 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

void test_insert()
{
	{
		std::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert(std::pair<char,int>('a',100));
		mymap.insert(std::pair<char,int>('z',200));

		std::pair<std::map<char,int>::iterator,bool> ret;
		ret = mymap.insert(std::pair<char,int>('z',500));
		if (ret.second==false) {
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		std::map<char,int>::iterator it = mymap.begin();
		mymap.insert(it, std::pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert(it, std::pair<char,int>('c',400));  // no max efficiency inserting

		// third insert function version (range insertion):
		std::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
}



void test_comp()
{
	{
		std::map<char,int> mymap;

		std::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;

		std::cout << "mymap contains:\n";

		char highest = mymap.rbegin()->first;     // key value of last element

		std::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );

		std::cout << '\n';
	}

	{
		std::map<char,int> mymap;

		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;

		std::cout << "mymap contains:\n";

		std::pair<char,int> highest = *mymap.rbegin();          // last element

		std::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
	}
}

void test_equal_range() 
{
	std::cout << "EQUAL_RANGE:\n";
	std::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
}



int main()
{
	test_insert();
	test_comp();
	test_equal_range();
}