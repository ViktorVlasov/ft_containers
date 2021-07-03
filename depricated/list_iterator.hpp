/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:35:53 by efumiko           #+#    #+#             */
/*   Updated: 2021/06/27 17:15:04 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"

namespace ft {

	template<class T, class Node, class Pointer = T*, class Reference = T&>
	class list_iterator
	{

	public:
		//typedef std::bidirectional_iterator_tag                        iterator_category;
		typedef T                                                      value_type;
		typedef Pointer                                                pointer;
		typedef Reference                                              reference;
		//typedef ptrdiff_t                                              difference_type;
		//typedef size_t                                                 size_type;
		typedef Node                                                   *node_ptr;

	private:
		node_ptr                                                       _node;

	public:

		node_ptr getNode() const
		{
			return (this->_node);
		}

		list_iterator(node_ptr node = 0) :_node(node) {}
		list_iterator(list_iterator<T, Node, T*, T&> const &copy) :_node(copy.getNode()) {}
		~list_iterator() {}

		list_iterator    &operator=(const list_iterator &other)
		{
			if (&other != this)
				_node = other._node;
			return (*this);
		}

		reference        operator*() const
		{
			return (_node->data);
		} 

		pointer          operator->() const
		{
			return &(_node->data);
		}

		list_iterator    &operator++()
		{
			_node = _node->next;
			return (*this);
		}

		list_iterator    operator++(int)
		{
			list_iterator tmp = *this;
			_node = _node->next;
			return (tmp);
		}

		list_iterator    &operator--()
		{
			_node = _node->prev;
			return (*this);
		}

		list_iterator    operator--(int)
		{
			list_iterator tmp = *this;
			_node = _node->prev;
			return (tmp);
		}

	};

	template<class tL, class nL, class ptrL, class refL, class tR, class nR, class ptrR, class refR>
	bool operator==(const list_iterator<tL, nL, ptrL, refL> &lhs, const list_iterator<tR, nR, ptrR, refR> &rhs)
	{
		return (lhs.getNode() == rhs.getNode());
	}

	template<class tL, class nL, class ptrL, class refL, class tR, class nR, class ptrR, class refR>
	bool operator!=(const list_iterator<tL, nL, ptrL, refL> &lhs, const list_iterator<tR, nR, ptrR, refR> &rhs)
	{
		return !(lhs.getNode() == rhs.getNode());
	}


}
