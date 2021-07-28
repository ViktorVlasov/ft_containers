/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 04:50:59 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/28 01:03:59 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_ITERATOR_HPP
# define RBTREE_ITERATOR_HPP

# include "utils.hpp"

namespace ft {

    class RB_node;

    template<class T>
	class RB_base;
    
    template<class T>
	class RBT_iterator
	{
	public:
		typedef T									value_type;
	  	typedef T&									reference;
	  	typedef T*									pointer;
		typedef RBT_iterator<T>					iterator_type;
	  	typedef RB_node::RB_ptr						RB_ptr;
	  	typedef RB_base<T>*							link_type;

		RB_node* node;
		RB_node* end;
		RBT_iterator(): node(), end() { }
		explicit RBT_iterator(RB_node* x, RB_node* end): node(x), end(end) { }
	//	RBT_iterator(const iterator_type& it): node(it.node), end(it.end) { }
		
		reference operator*() const
		{
			return (*static_cast<link_type>(node)->getptr());
		}

		pointer operator->() const
		{
			return (static_cast<link_type>(node)->getptr());
		}

		iterator_type& operator++()
		{
			node = node->RB_inc(node, end);
			return (*this);
		}
		iterator_type operator++(int)
		{
			iterator_type out(*this);
			node = node->RB_inc(node, end);
			return (out);
		}
		iterator_type& operator--()
		{
			node = node->RB_dec(node, end);
			return (*this);
		}
		iterator_type operator--(int)
		{
			iterator_type out(*this);
			node = node->RB_dec(node, end);
			return (out);
		}
		friend bool operator==(const iterator_type& x, const iterator_type& y) {return (x.node == y.node);}
		friend bool operator!=(const iterator_type& x, const iterator_type& y) {return (x.node != y.node);}
	};

	template<class T>
	class RBT_reverse_iterator
	{
	public:
		typedef T									value_type;
	  	typedef T&									reference;
	  	typedef T*									pointer;
		typedef RBT_reverse_iterator<T>			iterator_type;
	  	typedef RB_node::RB_ptr						RB_ptr;
	  	typedef RB_base<T>*							link_type;

		RB_node* node;
		RB_node* end;
		RBT_reverse_iterator(): node(), end() { }
		explicit RBT_reverse_iterator(RB_node* x, RB_node* end): node(x), end(end) { }
	//	RBT_reverse_iterator(const iterator_type& it): node(it.node), end(it.end) { }
		
		
		reference operator*() const
		{
			return (*static_cast<link_type>(node)->getptr());
		}

		pointer operator->() const
		{
			return (static_cast<link_type>(node)->getptr());
		}

		iterator_type& operator--()
		{
			node = node->RB_inc(node, end);
			return (*this);
		}
		iterator_type operator--(int)
		{
			iterator_type out(*this);
			node = node->RB_inc(node, end);
			return (out);
		}
		iterator_type& operator++()
		{
			node = node->RB_dec(node, end);
			return (*this);
		}
		iterator_type operator++(int)
		{
			iterator_type out(*this);
			node = node->RB_dec(node, end);
			return (out);
		}
		friend bool operator==(const iterator_type& x, const iterator_type& y) {return (x.node == y.node);}
		friend bool operator!=(const iterator_type& x, const iterator_type& y) {return (x.node != y.node);}
	};

	template<class T>
	class RBT_const_iterator
	{
	public:
		typedef T									value_type;
	  	typedef const T&							reference;
	  	typedef const T*							pointer;
		typedef RBT_const_iterator<T>			iterator_type;
	  	typedef RB_node::RB_const_ptr				RB_ptr;
	  	typedef const RB_base<T>*					link_type;

		typedef RBT_iterator<T> 				iterator;

		const RB_node* node;
		const RB_node* end;
		RBT_const_iterator(): node(), end() { }
		explicit RBT_const_iterator(const RB_node* x, const RB_node* end): node(x), end(end) { }
	//	RBT_const_iterator(const iterator_type& it): node(it.node), end(it.end) { }
		RBT_const_iterator(const iterator& it): node(it.node), end(it.end) { }

		iterator _const_cast() const {
			return  iterator(const_cast<typename iterator::RB_ptr>(node), const_cast<typename iterator::RB_ptr>(end));
		}

		reference operator*() const
		{
			return (*static_cast<link_type>(node)->getptr());
		}

		pointer operator->() const
		{
			return (static_cast<link_type>(node)->getptr());
		}

		iterator_type& operator++()
		{
			node = node->RB_inc(node, end);
			return (*this);
		}
		iterator_type operator++(int)
		{
			iterator_type out(*this);
			node = node->RB_inc(node, end);
			return (out);
		}
		iterator_type& operator--()
		{
			node = node->RB_dec(node, end);
			return (*this);
		}
		iterator_type operator--(int)
		{
			iterator_type out(*this);
			node = node->RB_dec(node, end);
			return (out);
		}
		friend bool operator==(const iterator_type& x, const iterator_type& y) {return (x.node == y.node);}
		friend bool operator!=(const iterator_type& x, const iterator_type& y) {return (x.node != y.node);}
	};

	template<class T>
	class RBT_const_reverse_iterator
	{
	public:
		typedef T									value_type;
	  	typedef const T&							reference;
	  	typedef const T*							pointer;
		typedef RBT_const_reverse_iterator<T>	iterator_type;
	  	typedef RB_node::RB_const_ptr	            RB_ptr;
	  	typedef const RB_base<T>*					link_type;

		typedef RBT_reverse_iterator<T>			iterator;

		RB_ptr node;
		RB_ptr end;
		RBT_const_reverse_iterator(): node(), end() { }
		explicit RBT_const_reverse_iterator(RB_ptr x, RB_ptr end): node(x), end(end) { }
		RBT_const_reverse_iterator(const iterator& it): node(it.node), end(it.end) { }
		//RBT_const_reverse_iterator(const RBT_reverse_iterator<T>& it): node(it.node), end(it.end) { }
		

		iterator _const_cast() const {
			return  (iterator(const_cast<typename iterator::RB_ptr>(node), const_cast<typename iterator::RB_ptr>(end)));
		}

		reference operator*() const
		{
			return (*static_cast<link_type>(node)->getptr());
		}

		pointer operator->() const
		{
			return (static_cast<link_type>(node)->getptr());
		}

		iterator_type& operator--()
		{
			node = node->RB_inc(node, end);
			return (*this);
		}
		iterator_type operator--(int)
		{
			iterator_type out(*this);
			node = node->RB_inc(node, end);
			return (out);
		}
		iterator_type& operator++()
		{
			node = node->RB_dec(node, end);
			return (*this);
		}
		iterator_type operator++(int)
		{
			iterator_type out(*this);
			node = node->RB_dec(node, end);
			return (out);
		}
		friend bool operator==(const iterator_type& x, const iterator_type& y) {return (x.node == y.node);}
		friend bool operator!=(const iterator_type& x, const iterator_type& y) {return (x.node != y.node);}
	};
}

# include "RBtree.hpp"


#endif