/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 09:25:24 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/27 06:01:00 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP
#include <iterator>
#include <limits>
#include <iostream>
#include <vector>

#include "utils.hpp"

namespace ft {
    
	enum Color
	{
		RED = false,
		BLACK = true
	};

	class RB_node
	{
	public:
		typedef RB_node*			RB_ptr;
		typedef const RB_node*		RB_const_ptr;
	  	
		Color		color;
	  	RB_node*		parent;
	  	RB_node* 		left;
	  	RB_node* 		right;
		
	  	RB_node() {}
	  	RB_node(RB_node* node)
		{
	    	color = RED;
	    	parent = node->parent;
	    	left = node->left;
	    	right = node->right;
	  	}
	  	RB_node* s_minimum(RB_node* x, RB_node* end)
		{
			while (x->left != end)
		  		x = x->left;
			return (x);
	  	}
	  	const RB_node* s_minimum(const RB_node* x, const RB_node* end) const
	  	{
			while (x->left != end)
		  		x = x->left;
			return (x);
	  	}
	  	RB_node* s_maximum(RB_node* x, RB_node* end)
		{
			while (x->right != end)
		  		x = x->right;
			return (x);
	  	}
	  	const RB_node* s_maximum(const RB_node* x, const RB_node* end) const 
	  	{
			while (x->right != end)
		  		x = x->right;
			return (x);
	  	}
		RB_node* RB_inc(RB_node* x, RB_node* end)
		{
			if (x->right != end)
				return (s_minimum(x->right, end));
			RB_node* y = x->parent;
			while (y != end && x == y->right)
			{
				x = y;
				y = y->parent;
  			}
  			return (y);
		}
		const RB_node* RB_inc(const RB_node* x, const RB_node* end) const
		{
			if (x->right != end)
				return (s_minimum(x->right, end));
			RB_node* y = x->parent;
			while (y != end && x == y->right)
			{
				x = y;
				y = y->parent;
  			}
  			return (y);
		}
		RB_node* RB_dec(RB_node* x, RB_node* end)
		{
			if (x == end)
				return (end->right);
  			if (x->left != end)
				return (s_maximum(x->left, end));
  			RB_node* y = x->parent;
  			while (y != end && x == y->left)
			{
				x = y;
				y = y->parent;
  			}
			return (y);
		}
		const RB_node* RB_dec(const RB_node* x, const RB_node* end) const
		{
			if (x == end)
				return (end->right);
  			if (x->left != end)
				return (s_maximum(x->left, end));
  			RB_node* y = x->parent;
  			while (y != end && x == y->left)
			{
				x = y;
				y = y->parent;
  			}
			return (y);
		}
	};

	class RB_head
	{
	public:
		RB_node 			header;
		std::size_t			node_count;
		
		RB_head() : header()
		{
			header.color = BLACK;
			reset();
		}
		void reset()
		{
			header.parent = &header;
			header.left = &header;
			header.right = &header;
			node_count = 0;
		}
	};

	template<class T>
	class RB_base : public RB_node
	{
	public:
		typedef RB_base<T>*		link_type;
		RB_base(T value) : RB_node(), value_type(value) {}
		RB_base(T value, RB_node* node) : RB_node(node), value_type(value) {}
		T* getptr() { return (__builtin_addressof(value_type)); }
		const T* getptr() const { return (__builtin_addressof(value_type)); }
	private:
		T 								value_type;
	};

    template<class T>
    class RBT_iterator;

    template<class T>
    class RBT_const_iterator;

    template<class T>
    class RBT_reverse_iterator;

    template<class T>
    class RBT_const_reverse_iterator;

	template<class key_type, class value_type, class key_val, class compare>
	class RBT
	{
	public:
	  	typedef RB_base<value_type>*				    link_type;
	  	typedef const RB_base<value_type>*			    const_link_type;
	  	typedef const value_type&					    const_reference;
	  	typedef size_t								    size_type;
		typedef RBT_iterator<value_type>				iterator;
	  	typedef RBT_const_iterator<value_type>			const_iterator;
	  	typedef RBT_reverse_iterator<value_type>		reverse_iterator;
	  	typedef RBT_const_reverse_iterator<value_type>	const_reverse_iterator;

		RB_head			*head;
	  	compare			key_compare;
		
		protected:
		link_type _begin() { return (static_cast<link_type>(head->header.parent)); }
		const_link_type _begin() const { return (static_cast<const_link_type>(head->header.parent)); }
		RB_node* _end(){ return (&head->header); }
		const RB_node* _end() const { return (&head->header); }
		const key_type& _s_key(const_link_type x) const { return (key_val()(*x->getptr())); }
		const key_type& _s_key(const RB_node* x) const { return (_s_key(static_cast<const_link_type>(x))); }
		link_type _s_left(RB_node* x) { return (static_cast<link_type>(x->left)); }
		const_link_type _s_left(const RB_node* x) const { return (static_cast<const_link_type>(x->left)); }
		link_type _s_right(RB_node* x) { return (static_cast<link_type>(x->right)); }
		const_link_type _s_right(const RB_node* x) const  { return (static_cast<const_link_type>(x->right)); }

		public:
		void _leftRotate(RB_node* x)
	  	{
			RB_node* y = x->right;
			x->right = y->left;
			if (y->left != _end())
		  		y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == _end())
		 		head->header.parent = y;
			else if (x == x->parent->left)
		  		x->parent->left = y;
			else
		  		x->parent->right = y;
			y->left = x;
			x->parent = y;
	  	}
		void _rightRotate(RB_node* x)
		{
			RB_node* y = x->left;
			x->left = y->right;
			if (y->right != _end())
		  		y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == _end())
		  		head->header.parent = y;
			else if (x == x->parent->right)
		  		x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
	  	}
		void _insertFixUp(RB_node* z)
	  	{
			while (z->parent->color == RED)
		  	{
				if (z->parent == z->parent->parent->left)
				{
					RB_node* y = z->parent->parent->right;
					if (y->color == RED)
					{
						z->parent->color = BLACK;
						y->color = BLACK;
						z->parent->parent->color = RED;
						z = z->parent->parent;
					}
					else
					{
			  			if (z == z->parent->right)
						{
							z = z->parent;
							_leftRotate(z);
						}
						z->parent->color = BLACK;
						z->parent->parent->color = RED;
						_rightRotate(z->parent->parent);
					}	
		  		}
				else
				{
					RB_node* y = z->parent->parent->left;
					if (y->color == RED)
					{
			  			z->parent->color = BLACK;
			  			y->color = BLACK;
			  			z->parent->parent->color = RED;
			  			z = z->parent->parent;
					}
					else
					{
			  			if (z == z->parent->left)
						{
							z = z->parent;
							_rightRotate(z);
			  			}
			  			z->parent->color = BLACK;
			  			z->parent->parent->color = RED;
			  			_leftRotate(z->parent->parent);
					}
		  		}
			}
			head->header.parent->color = BLACK;
	  	}

		ft::pair<iterator, bool> _insert_unique(RB_node* n)
		{
			RB_node* y = _end();
			RB_node* temp = head->header.parent;
			while (temp != _end())
			{
		  		y = temp;
		  		if (key_compare(_s_key(n), _s_key(temp)))
					temp = temp->left;
		  		else if (key_compare(_s_key(temp), _s_key(n)))
					temp = temp->right;
		  		else
				{
					return (ft::pair<iterator, bool>(iterator(temp, _end()), false));
		  		}
			}
			n->parent = y;
			if (y == _end())
		  		head->header.parent = n;
			else if (key_compare(_s_key(n), _s_key(y)))
		  		y->left = n;
			else
		  		y->right = n;
			n->left = _end();
			n->right = _end();
			head->node_count++;
			_insertFixUp(n);
			return (ft::pair<iterator, bool>(iterator(n, _end()), true));
	  	}
		
		void _insert_equal(RB_node* n)
		{
			RB_node* y = _end();
			RB_node* temp = head->header.parent;
			while (temp != _end())
			{
				y = temp;
				if (key_compare(_s_key(n), _s_key(temp)))
					temp = temp->left;
		  		else
					temp = temp->right;
			}
			n->parent = y;
			if (y == _end())
		  		head->header.parent = n;
			else if (key_compare(_s_key(n), _s_key(y)))
		  		y->left = n;
			else
		  		y->right = n;
			n->left = _end();
			n->right = _end();
			head->node_count++;
			_insertFixUp(n);
	  	}

		void _transplant(RB_node* u, RB_node* v)
		{
			if (u->parent == _end())
		  		head->header.parent = v;
			else if (u == u->parent->left)
		  		u->parent->left = v;
			else
		  		u->parent->right = v;
			if (v->parent != head->header.parent)
		  		v->parent = u->parent;
		}

		void _deleteFixUp(RB_node* x)
		{
			while (x != head->header.parent && x->color == BLACK)
			{
		  		if (x == x->parent->left)
				{
					RB_node* w = x->parent->right;
					if (w->color == RED)
					{
			  			w->color = BLACK;
						x->parent->color = RED;
			  			_leftRotate(x->parent);
			  			w = x->parent->right;
					}
					if (w->left->color == BLACK && w->right->color == BLACK)
					{
			  			w->color = RED;
			  			x = x->parent;
					}
					else
					{
			  			if (w->right->color == BLACK)
			  			{
							w->left->color = BLACK;
							w->color = RED;
							_rightRotate(w);
							w = x->parent->right;
			  			}
			  			w->color = x->parent->color;
			  			x->parent->color = BLACK;
			  			w->right->color = BLACK;
			  			_leftRotate(x->parent);
			  			x = head->header.parent;
					}
		  		}
				else
				{
					RB_node* w = x->parent->left;
					if (w->color == RED)
					{
			  			w->color = BLACK;
			  			x->parent->color = RED;
			  			_rightRotate(x->parent);
			  			w = x->parent->left;
					}
					if (w->left->color == BLACK && w->right->color == BLACK)
					{
			  			w->color = RED;
			  			x = x->parent;
					}
					else
					{
			  			if (w->left->color == BLACK)
			  			{
							w->right->color = BLACK;
							w->color = RED;
							_leftRotate(w);
							w = x->parent->left;
			  			}
			  			w->color = x->parent->color;
			  			x->parent->color = BLACK;
			  			w->left->color = BLACK;
			  			_rightRotate(x->parent);
			  			x = head->header.parent;
					}
		  		}
			}
			x->color = BLACK;
	  	}

		void _delete(RB_node* z)
	  	{
			RB_node* y = z;
			RB_node* x;
			Color y_original_color = y->color;
			if (z->left == _end())
			{
		  		x = z->right;
		  		_transplant(z, z->right);
			}
			else if (z->right == _end())
			{
		  		x = z->left;
		  		_transplant(z, z->left);
			}
			else
			{
		  		y = z->right->s_minimum(z->right, _end());
		  		x = y->right;
		  		y_original_color = y->color;
				if (y->parent == z)
				{
					if (x->parent != head->header.parent)
			  			x->parent = y;
		  		}
				else
				{
					_transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
		  		}
		  		if (x == _end())
		    		x = y;
		  		_transplant(z, y);
		  		y->left = z->left;
		  		y->left->parent = y;
		  		y->color = z->color;
			}
			if (y_original_color == BLACK)
				_deleteFixUp(x);
		}
		
		iterator _lower_bound(link_type x, RB_node* y, const key_type& k)
		{
			while (x != _end())
			{
				if (!key_compare(_s_key(x), k))
				{
					y = x;
					x = _s_left(x);
				}
				else
				{
					x = _s_right(x);
				}
			}
			return iterator(y, _end());
		}
		
		const_iterator _lower_bound(const_link_type x, const RB_node* y, const key_type& k) const
		{
			while (x != _end())
			{
				if (!key_compare(_s_key(x), k))
				{
					y = x;
					x = _s_left(x);
				}
				else
				{
					x = _s_right(x);
				}
			}
			return const_iterator(y, _end());
		}
		
		iterator _upper_bound(link_type x, RB_node* y, const key_type& k)
		{
			while (x != _end())
			{
				if (key_compare(k, _s_key(x)))
				{
					y = x;
					x = _s_left(x);
				}
				else
				{
					x = _s_right(x);
				}
			}
			return iterator(y, _end());
		}
		
		const_iterator _upper_bound(const_link_type x, const RB_node* y, const key_type& k) const
		{
			while (x != _end())
			{
				if (key_compare(k, _s_key(x)))
				{
					y = x;
					x = _s_left(x);
				}
				else
				{
					x = _s_right(x);
				}
			}
			return const_iterator(y, _end());
		}

		RBT() : head(new RB_head) { }
		RBT(const compare& comp) : head(new RB_head), key_compare(comp) { }
		RBT(const RBT& x) : head(new RB_head)
		{
			const_iterator begin = x.begin();
			const_iterator end = x.end();
			while (begin != end)
			{
				insert_equal(*begin);
				begin++;
			}
		}
		
		void del(link_type x)
		{
			if (x != _end())
			{
				del(_s_left(x));
				del(_s_right(x));
				delete x;
			}
		}
		
		~RBT()
		{
			del(_begin());
			delete head;
		}
		
		RBT& operator=(const RBT& x)
		{
			if (this == &x)
				return (*this);
			clear();
			const_iterator begin = x.begin();
			const_iterator end = x.end();
			while (begin != end)
			{
				insert_equal(*begin);
				begin++;
			}
			return (*this);
		}
		
		compare key_comp() const { return (key_compare); }
		
		iterator begin() { return (iterator(head->header.left, _end())); }
		const_iterator begin() const { return (const_iterator(head->header.left, _end())); }
		iterator end() { return (iterator(_end(), _end())); }
		const_iterator end() const { return (const_iterator(_end(), _end())); }
		reverse_iterator rbegin() { return (++reverse_iterator(_end(), _end())); }
		const_reverse_iterator rbegin() const { return (++const_reverse_iterator(_end(), _end())); }
		reverse_iterator rend() { return (reverse_iterator (head->header.left, _end()));}
		const_reverse_iterator rend() const { return (const_reverse_iterator (head->header.left, _end()));}
		
		bool empty() const { return (head->node_count == 0); }
		
		size_type size() const { return (head->node_count); }
		
		size_type max_size() const  { 
		return (std::numeric_limits<size_type>::max() / sizeof(RB_base<value_type>)); }
		
		void swap(RBT &t)
		{
			ft::swap(head, t.head);
			ft::swap(key_compare, t.key_compare);
		}
		
		ft::pair<iterator, bool> insert_unique(const_reference value)
		{
			link_type node = new RB_base<value_type>(value);
			node->parent = _end();
			node->left = _end();
			node->right = _end();
			node->color = RED;
			ft::pair<iterator, bool> ret = _insert_unique(node);
			if (ret.second == false)
			{
				delete node;
				return (ret);
			}
			else
			{
				if (head->header.left == _end() || key_compare(_s_key(node), _s_key(head->header.left)))
				{
					head->header.left = node;
				}
				if (head->header.right == _end() || key_compare(_s_key(head->header.right), _s_key(node)))
				{
					head->header.right = node;
				}
		  		return (ft::pair<iterator, bool>(iterator(node, _end()), true));
			}
		}
		
		iterator insert_equal(const_reference x)
		{
			link_type node = new RB_base<value_type>(x);
			node->parent = _end();
			node->left = _end();
			node->right = _end();
			node->color = RED;
			_insert_equal(node);
			if (head->header.left == _end() || key_compare(_s_key(node), _s_key(head->header.left)))
			{
				head->header.left = node;
			}
			if (head->header.right == _end() || key_compare(_s_key(head->header.right), _s_key(node)) || (!key_compare(_s_key(head->header.right), _s_key(node)) && !key_compare(_s_key(node),_s_key(head->header.right))))
			{
				head->header.right = node;
			}
			return iterator(node, _end());
		}
		
		iterator insert_unique(iterator position, const_reference x) { 
			(void) position;
			return (insert_unique(x).first);
		}
		
		iterator insert_equal(iterator position, const_reference x) { 
			(void) position;
			return (insert_equal(x));
		}
		
		template<typename InputIterator>
		void insert_range_unique(InputIterator first, InputIterator last)
		{
			for (; first != last; ++first)
				insert_unique(*first);
		}
		
		template<typename InputIterator>
		void insert_range_equal(InputIterator first, InputIterator last)
		{
			for (; first != last; ++first)
				insert_equal(*first);
		}
		
		void erase(iterator pos)
		{
			iterator tmp;
			if (head->header.left == pos.node)
			{
				tmp = pos;
				++tmp;
				head->header.left = tmp.node;
			}
			if (head->header.right == pos.node)
			{
				tmp = pos;
				--tmp;
				head->header.right = tmp.node;
			}
			head->node_count--;
			_delete(pos.node);
			delete static_cast<link_type>(pos.node);
		}
		
		void erase(const_iterator pos) { erase(pos._const_cast()); }
		
		size_type erase(const key_type &x)
		{
			ft::pair<iterator, iterator> range = equal_range(x);
			size_type n = 0;
			iterator first = range.first;
			iterator last = range.second;
			while (first != last)
			{
				iterator tmp = first++;
				erase(tmp);
				n++;
			}
			return n;
		}
		
		void erase(iterator first, iterator last)
		{
			while (first != last)
			{
				iterator tmp = first++;
				erase(tmp);
			}
		}
		
		void erase(const_iterator first, const_iterator last)
		{
			erase(first._const_cast(), last._const_cast());
		}
		
		void clear()
		{
			del(_begin());
			head->header.parent = &head->header;
			head->header.right = &head->header;
			head->header.left = &head->header;
			head->node_count = 0;
		}
		
		iterator find(const key_type& k)
		{
			iterator j = lower_bound(k);
			if (j == end() || key_compare(k, _s_key(j.node)))
				return (end());
			return (j);
		}
		
		const_iterator find(const key_type& k) const
		{
			const_iterator j = lower_bound(k);
			if (j == end() || key_compare(k, _s_key(j.node)))
				return (end());
			return (j);
		}
		
		size_type count(const key_type& k) const
		{
			ft::pair<const_iterator, const_iterator> p = equal_range(k);
			const_iterator first = p.first;
			const_iterator last = p.second;
			size_type n = 0;
			for (; first != last ; ++first)
				n++;
			return (n);
		}
		
		iterator lower_bound(const key_type& k) { return (_lower_bound(_begin(), _end(), k)); }
		const_iterator lower_bound(const key_type& k) const { return (_lower_bound(_begin(), _end(), k)); }
		iterator upper_bound(const key_type& k) { return (_upper_bound(_begin(), _end(), k)); }
		const_iterator upper_bound(const key_type& k) const { return (_upper_bound(_begin(), _end(), k)); }

		ft::pair<iterator, iterator> equal_range(const key_type& k)
		{
			link_type x = _begin();
			RB_node* y = _end();
			while (x != _end())
			{
				if (key_compare(_s_key(x), k))
				{
					x = _s_right(x);
				}
				else if (key_compare(k, _s_key(x)))
				{
					y = x;
					x = _s_left(x);
				}
				else
				{
					link_type xu = x;
					RB_node* yu = y;
					y = x;
					x = _s_left(x);
					xu = _s_right(xu);
					return (ft::pair<iterator, iterator>(_lower_bound(x, y, k), _upper_bound(xu, yu, k)));
				}
			}
			return (ft::pair<iterator, iterator>(iterator(y, _end()), iterator(y, _end())));
		}
		
		ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const
		{
			const_link_type x = _begin();
			const RB_node* y = _end();
			while (x != _end())
			{
				if (key_compare(_s_key(x), k))
				{
					x = _s_right(x);
				}
				else if (key_compare(k, _s_key(x)))
				{
					y = x;
					x = _s_left(x);
				}
				else
				{
					const_link_type xu = x;
					const RB_node* yu = y;
					y = x;
					x = _s_left(x);
					xu = _s_right(xu);
					return (ft::pair<const_iterator, const_iterator>(_lower_bound(x, y, k), _upper_bound(xu, yu, k)));
				}
			}
			return (ft::pair<const_iterator, const_iterator>(const_iterator(y, _end()), const_iterator(y, _end())));
		}
	
	};

}

#endif