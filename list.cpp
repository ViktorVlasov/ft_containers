/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:26:14 by efumiko           #+#    #+#             */
/*   Updated: 2021/04/18 20:26:35 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <list>

template < class T, class Alloc = std::allocator<T> >
class List
{
private:
    
    template<typename T>
    class Node
    {
    public:
        Node *pNext;
        //Node *pPrev;
        T data;
        
        Node(T data = T(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
        ~Node();
    };
    
    size_t size;
    Node<T> *head;
public:
    typedef T value_type;
    typedef size_t size_type;
    
    
    List();
    ~List();

    void push_back(const value_type& val);
    size_type size() const;
    size_type max_size() const;
};

template<class T, class Alloc>
List<T, Alloc>::List()
{
    size = 0;
    head = nullptr;
}

template<class T, class Alloc>
List<T, Alloc>::~List()
{
}

template<class T, class Alloc>
void List<T, Alloc>::push_back(const T& val)
{
    if (!head)
    {
        head = new Node<T>(val);
    }
    else
    {
        Node<t> *current = this->head;
        
        while (current->pNext)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }

    size++;
}


template<class T, class Alloc>
size_t List<T, Alloc>::size() const
{
    return (size)
}

template<class T, class Alloc>
size_t List<T, Alloc>::max_size() const
{
    const long pageCount = sysconf( _SC_PHYS_PAGES );
    const long pageSize = sysconf( _SC_PAGE_SIZE );
    const unsigned long long totalBytes = pageCount * pageSize;
    const unsigned long long maxPossibleObjects = bytesAvailable / sizeof(T);
    return maxPossibleObjects;
}

int main(int argc, char const *argv[])
{
    List<int> lst;
    lst.push_back(5);
    
    std::list<int> or_lst;

    return 0;
}
