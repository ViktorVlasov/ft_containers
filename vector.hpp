/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:27:50 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/28 17:42:20 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <utility>
#include <iostream>
#include <string.h>
#include "vector_iterator.hpp"
#include "utils.hpp"

namespace ft
{

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T																	value_type;
		typedef Alloc																allocator_type;
		typedef value_type&															reference;
		typedef const value_type&													const_reference;
		typedef value_type*															pointer;
		typedef const value_type*													const_pointer;
		typedef vector_iterator<value_type>											iterator;
		typedef vector_iterator<value_type, const value_type*, const value_type&>	const_iterator;
		typedef vector_reverse_iterator<iterator>									reverse_iterator;
		typedef vector_reverse_iterator<const_iterator>								const_reverse_iterator;
		typedef ptrdiff_t															difference_type;
		typedef size_t																size_type;
	private:
		pointer                                               _arr;
		size_type                                             _size;
		size_type                                             _capacity;
		allocator_type                                        _alloc;
	
	public:

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
		explicit vector (const allocator_type& alloc = allocator_type()) 
			: _size(0), _capacity(0), _alloc(alloc)
		{
			_arr = _alloc.allocate(_capacity);
		}
		
		explicit vector (size_type n, const value_type& val = value_type(), 
				const allocator_type& alloc = allocator_type())
			: _size(n), _capacity(n), _alloc(alloc)
		{
			_arr = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; ++i)
				_alloc.construct(_arr + i, val);
		}
		
		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0,
					const allocator_type& alloc = allocator_type())
					: _size(0), _capacity(0), _alloc(alloc)
		{
			InputIterator tmp(first);
				
			while (tmp != last)
			{
				++_size;
				++_capacity;
				++tmp;
			}
			_arr = _alloc.allocate(_capacity);
			for (size_type i = 0; first != last; ++first, ++i)
				_alloc.construct(_arr + i, *first);
		}
		
		vector (const vector& x) 
			: _size(x._size), _capacity(x._capacity), _alloc(x._alloc)
		{
			_arr = _alloc.allocate(this->_capacity);
			for (size_type i = 0; i < _size; ++i)
				_alloc.construct(this->_arr + i, x[i]);
		}

		~vector()
		{
			if (_arr)
			{
				for (iterator it = this->begin(); it != this->end(); ++it)
					_alloc.destroy(&(*it));
				_alloc.deallocate(this->_arr, this->_capacity);
			}
		}

		/* ITERATORS */

		iterator 					begin() 			{ return (iterator(_arr)); }
		const_iterator 				begin()		const	{ return (const_iterator(_arr)); }
		iterator 					end()				{ return (iterator(_arr + _size)); }
		const_iterator 				end()		const	{ return (const_iterator(_arr + _size)); }
		reverse_iterator 			rbegin() 			{ return (reverse_iterator(_arr + (_size - 1))); }
		const_reverse_iterator		rbegin()	const	{ return (const_reverse_iterator(_arr + (_size - 1))); }
		reverse_iterator 			rend()				{ return (reverse_iterator(_arr - 1)); }
		const_reverse_iterator		rend()		const	{ return (const_reverse_iterator(_arr - 1)); }

		/* CAPACITY */
		size_type size()		const	{ return (_size); }
		size_type max_size()	const	{ return (_alloc.max_size()); }
		size_type capacity()	const	{ return (_capacity); }
		bool empty()			const	{ return (_size == 0); }
		
		void reserve (size_type n)
		{
			if (n > max_size())
				throw std::length_error("vector::reserve");
			if (n > _capacity)
				_my_realloc(n);
		}
		
		void resize (size_type n, value_type val = value_type())
		{
			while (n < _size)
				pop_back();
			if (n > _capacity)
				reserve(n);
			while (n > _size)
				push_back(val);
		}
		
		private:
			void _my_realloc(size_type newCapacity)
			{
				pointer tmp = _alloc.allocate(newCapacity);
				for (size_type i = 0; i < _size; ++i)
					_alloc.construct(&tmp[i], _arr[i]);
				for (iterator it = begin(); it != end(); ++it)
					_alloc.destroy(&(*it));
				_alloc.deallocate(_arr, _capacity);
				_capacity = newCapacity;
				_arr = tmp;
			};

		/* MODIFIERS */
		public:
			template <class InputIterator>
  			void assign(InputIterator first, InputIterator last,
			  		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			{
				InputIterator tmp(first);
				if (_arr)
				{
					for (iterator it = this->begin(); it != this->end(); ++it)
						_alloc.destroy(&(*it));
					_alloc.deallocate(this->_arr, this->_capacity);
				}
				_size = 0;
				_capacity = 0;
				while (tmp != last)
				{
					++_size;
					++_capacity;
					++tmp;
				}
				_arr = _alloc.allocate(_capacity);
				for (size_type i = 0; first != last; ++first, ++i)
					_alloc.construct(_arr + i, *first);
			}

			void assign(size_type n, const value_type& val)
			{
				if (n > max_size())
					throw std::length_error("cannot create std::vector larger than max_size()");
				if (_arr)
				{
					for (iterator it = this->begin(); it != this->end(); ++it)
						_alloc.destroy(&(*it));
					_alloc.deallocate(this->_arr, this->_capacity);
				}
				_size = n;
				_capacity = n;
				_arr = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; ++i)
					_alloc.construct(_arr + i, val);
			}

			void push_back(const value_type& val) 
			{
				if (_capacity == _size)
					reserve(2 * _size);
				if (_capacity == 0)
					reserve(1);
				_alloc.construct(&_arr[_size], val);
				_size++;
			}

			void pop_back() 
			{
				if (_size)
				{
					--_size;
					_alloc.destroy(&_arr[_size - 1]);
				}
			}

			void clear()
			{
				while (_size)
					pop_back();
			};

			iterator insert(iterator position, const value_type& val)
			{
				size_type before = position - begin();
				insert(position, 1, val);
				return iterator(_arr + before);
			}

			void insert (iterator position, size_type n, const value_type& val)
			{	
				if (n == 0)
					return ;
				difference_type distance_size = end() - position;
				difference_type before = position - begin();
				if (_size + n > _capacity)
					_my_realloc(_capacity + n);
				if (_size != 0)
				{
					size_type last_elem = _size - 1;
					for (size_type i = distance_size; i > 0; --i, --last_elem)
						memmove(_arr + last_elem + n, _arr + last_elem, sizeof(value_type));
				}
				for (size_type i = 0; i < n; ++i) 
					_alloc.construct(_arr + before + i, val);
				_size += n;
			}


			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
			{
				difference_type before = position - begin();
				size_type n = 0;
				InputIterator tmp(first);
				while (tmp++ != last)
					++n;
				if (n <= 0)
					return ;
				if (_size + n > _capacity)
					_my_realloc(_capacity + n);
				iterator newPosition(_arr + before);
				for (; n > 0; --n, ++first, ++newPosition)
					insert(newPosition, *first);
			}

			iterator erase (iterator position) { return (erase(position, position + 1)); }
			iterator erase (iterator first, iterator last)
			{
				if (first == end() || first == last)
					return (first);
				
				size_type start_i = first - begin();
				size_type tmp_i = start_i;
				size_type n = last - first;

				for (; first != last; first++, start_i++)
					_alloc.destroy(&_arr[start_i]);
				_size -= n;
				memmove(_arr + tmp_i, _arr + tmp_i + n, sizeof(value_type) * (_size - tmp_i));
				return (iterator(_arr + tmp_i));
			}
			
			void swap (vector& x)
			{
				ft::swap(_arr, x._arr);
				ft::swap(_size, x._size);
				ft::swap(_capacity, x._capacity);
				ft::swap(_alloc, x._alloc);
			};

		
		// ====Element access====
		public:
			reference operator[] (size_type n) {return (_arr[n]);};
			const_reference operator[] (size_type n) const {return (_arr[n]);}
			
			reference at (size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("vector::_M_range_check: __n (which is " + 
											SSTR(n) + ") >= this->size() (which is " + 
											SSTR(_size) + ")");
				return (_arr[n]);
			};
			const_reference at (size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("vector::_M_range_check: __n (which is " + 
											SSTR(n) + ") >= this->size() (which is " + 
											SSTR(_size) + ")");
				return (_arr[n]);
			};
			
			reference front() {return (_arr[0]);};
			const_reference front() const {return (_arr[0]);};
			
			reference back() {return (_arr[_size - 1]);};
			const_reference back() const {return (_arr[_size - 1]);};

	};

	template<class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs) 
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template<class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs) {
		return (!(lhs == rhs));
	}

	template<class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs) {
		return (rhs < lhs);
	}

	template<class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs) {
		return (!(lhs < rhs));
	}

	template<class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs) {
		return (!(rhs < lhs));
	}

	template<class T, class Alloc>
	void swap(ft::vector<T, Alloc> &x, ft::vector<T, Alloc> &y) {
		x.swap(y);
	}
}
