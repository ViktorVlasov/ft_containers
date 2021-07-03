/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:27:50 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/03 19:48:44 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <utility>
#include <iostream>
#include "vector_iterator.hpp"

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
		//typedef VectorReverseIterator<iterator>										reverse_iterator;
		//typedef VectorReverseConstIterator<const_iterator>							const_reverse_iterator;
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
                 const allocator_type& alloc = allocator_type())
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
				alloc_.construct(this->array_ + i, x[i]);
		}

		~vector()
		{
			if (_arr)
			{
				for (iterator it = this->begin(); it != this->end(); ++it)
					alloc_.destroy(&(*it));
				alloc_.deallocate(this->array_, this->capacity_);
			}
		}

		/* ITERATORS */

		iterator 				begin() 		{ return (iterator(_arr)); };
		const_iterator 			begin()	const	{ return (const_iterator(_arr)); };
		iterator 				end()			{ return (iterator(_arr + _size)); };
		const_iterator 			end()	const	{ return (const_iterator(_arr + _size)); };
		//reverse_iterator 		rbegin() { return (reverse_iterator(_arr + _size));};
		//const_reverse_iterator	rbegin() const {return (const_reverse_iterator(_arr + _size));};
		//reverse_iterator 		rend() {return (reverse_iterator(_arr));};
		//const_reverse_iterator	rend() const {return (const_reverse_iterator(_arr));};

		/* CAPACITY */
		size_type size()		const	{ return (_size); };
		size_type max_size()	const	{ return (_alloc.max_size()); };
		size_type capacity()	const	{ return (_capacity); };
		bool empty()			const	{ return (_size == 0); };
		
		void reserve (size_type n)
		{
			if (n > max_size())
				throw std::length_error("vector");
			if (n > _capacity)
				realloc(n);
		};
		
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
			void realloc(size_type newCapacity)
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
		void push_back (const value_type& val) 
		{
			
		}
	};
}