/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:26:14 by efumiko           #+#    #+#             */
/*   Updated: 2021/06/27 18:28:48 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <list>
#include "list.hpp"


int main(int argc, char const *argv[])
{
	List<int> lst;
	lst.push_back(5);
	
	std::list<int> or_lst;

	return 0;
}
