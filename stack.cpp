/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 13:40:32 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/28 18:07:58 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <vector>
#include <deque>

#include "stack.hpp"

void test_constructors()
{
	ft::stack<int> first;
	
	ft::stack<int,std::vector<int> > second;
	
	ft::vector<int> myvector (2,200);
	ft::stack<int,ft::vector<int> > third(myvector);
	
	ft::stack<int, std::deque<int> > fourth;

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';
}

void test_empty()
{
	ft::stack<int> my_stack;
	int sum (0);

	for (int i=1;i<=10;i++) my_stack.push(i);

	while (!my_stack.empty())
	{
		sum += my_stack.top();
		my_stack.pop();
	}

	std::cout << "total: " << sum << '\n';
}

void test_size()
{
	ft::stack<int> my_stack;
	std::cout << "0. size: " << my_stack.size() << '\n';

	for (int i=0; i<5; i++) my_stack.push(i);
	std::cout << "1. size: " << my_stack.size() << '\n';

	my_stack.pop();
	std::cout << "2. size: " << my_stack.size() << '\n';
}

void test_top()
{
	ft::stack<int> my_stack;

	my_stack.push(10);
	my_stack.push(20);

	my_stack.top() -= 5;

	std::cout << "my_stack.top() is now " << my_stack.top() << '\n';
}

void test_push_pop()
{
	ft::stack<int> my_stack;

	for (int i=0; i<5; ++i) my_stack.push(i);

	std::cout << "Popping out elements...";
	while (!my_stack.empty())
	{
		std::cout << ' ' << my_stack.top();
		my_stack.pop();
	}
	std::cout << '\n';
}

void test_relational_operators()
{
	ft::stack<int> my_stack1;
	my_stack1.push(10);
	my_stack1.push(20);	

	ft::stack<int> my_stack2;
	my_stack2.push(10);
	my_stack2.push(30);
	
	ft::stack<int> equal1;
	equal1.push(10);
	equal1.push(20);	
	
	if (my_stack2 > my_stack1) std::cout << "my_stack2 > my_stack1" << "\n";
	if (my_stack1 < my_stack2) std::cout << "my_stack1 < my_stack1" << "\n";
	if (my_stack1 == equal1) std::cout << "my_stack1 == equal1" << "\n";
	if (my_stack2 != my_stack1) std::cout << "my_stack2 != my_stack1" << "\n";
	if (my_stack2 >= my_stack1) std::cout << "my_stack2 >= my_stack1" << "\n";
	if (my_stack1 <= equal1) std::cout << "my_stack1 <= equal1" << "\n";
}


int main ()
{
	test_constructors();
	test_empty();
	test_size();
	test_top();
	test_push_pop();
	test_relational_operators();
	return 0;
}