/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_std.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:28:13 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/28 16:01:19 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <set>

void test_insert()
{
    // insert
    std::set<int> myset;
    std::set<int>::iterator it;
    std::pair<std::set<int>::iterator,bool> ret;

    // set some initial values:
    for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

    ret = myset.insert(20);               // no new element inserted

    if (ret.second==false) it=ret.first;  // "it" now points to element 20

    myset.insert (it,25);                 // max efficiency inserting
    myset.insert (it,24);                 // max efficiency inserting
    myset.insert (it,26);                 // no max efficiency inserting

    int myints[]= {5,10,15};              // 10 already in set, not inserted
    myset.insert (myints,myints+3);

    std::cout << "myset contains:";
    for (it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void test_equal_range()
{
    std::set<int> myset;

    for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

    std::pair<std::set<int>::const_iterator,std::set<int>::const_iterator> ret;
    ret = myset.equal_range(30);

    std::cout << "the lower bound points to: " << *ret.first << '\n';
    std::cout << "the upper bound points to: " << *ret.second << '\n';
}

void test_comp()
{
    // value comp
    std::set<int> myset;

    std::set<int>::value_compare mycomp = myset.value_comp();

    for (int i=0; i<=5; i++) myset.insert(i);

    std::cout << "myset contains:";

    int highest=*myset.rbegin();
    std::set<int>::iterator it=myset.begin();
    do {
        std::cout << ' ' << *it;
    } while ( mycomp(*(++it),highest) );

    std::cout << '\n';
}

int main()
{
    test_insert();
    test_equal_range();
    test_comp();
}