/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:50:22 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/03 19:26:14 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iterator>

namespace ft 
{
	template <class T, class Pointer = T*, class Reference = T&,
		class Distance = ptrdiff_t, class Category = std::random_access_iterator_tag>
  	class vector_iterator 
	{
	public:
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	
	private:
		pointer _curr;
	
	public:
		/* default-constructible, param-constructible, copy-constructible, copy-assignable and destructible */
		vector_iterator() : _curr(0) {};
		vector_iterator(pointer p) : _curr(p) {}
		vector_iterator(const vector_iterator<T>& copy) {*this = copy;}
		~vector_iterator() {}

		/* operators */
		vector_iterator	&operator=(const vector_iterator& other) {
			_curr = other._curr;
			return (*this);
		}

		vector_iterator &operator++()
		{
			++_curr;
			return (*this);
		}

		vector_iterator	operator++(int)
		{
			vector_iterator tmp(*this);
			++_curr;
			return (tmp);
		}

		vector_iterator &operator--()
		{
			--_curr;
			return (*this);
		}
		
		vector_iterator operator--(int)
		{
			vector_iterator tmp(*this);
			--_curr;
			return (tmp);
		}

		difference_type	operator-(vector_iterator b) const {
			return (_curr - b._curr);
		}

		difference_type	operator+(vector_iterator b) const { // надо затестить, точно ли нужен оператор?
			return (_curr + b._curr);
		}

		vector_iterator	operator-(difference_type n) const {
			vector_iterator tmp(*this);
			tmp._curr -= n;
			return (tmp);
		}

		vector_iterator	operator+(difference_type n) const {
			vector_iterator tmp(*this);
			tmp._curr += n;
			return (tmp);
		}

		vector_iterator	&operator+=(difference_type n) {
			_curr += n;
			return (*this);
		}
		vector_iterator	&operator-=(difference_type n) {
			_curr -= n;
			return (*this);
		}

		reference	operator*() const { return (*_curr); }
		pointer		operator->() const { return (_curr); }
		reference	operator[](difference_type n) const { return (*(_curr + n)); }

		friend bool operator==(const vector_iterator& lhs, const vector_iterator& rhs) { return (lhs._curr == rhs._curr);}		
		friend bool operator!=(const vector_iterator& lhs, const vector_iterator& rhs) { return (lhs._curr != lhs._curr); }
		friend bool operator<(const vector_iterator& lhs, const vector_iterator& rhs) { return (lhs._curr < rhs._curr);}
		friend bool operator>(const vector_iterator& lhs, const vector_iterator& rhs) { return (lhs._curr > rhs._curr); }
		friend bool operator<=(const vector_iterator& lhs, const vector_iterator& rhs) { return (lhs._curr <= rhs._curr); }
		friend bool operator>=(const vector_iterator& lhs, const vector_iterator& rhs) { return (lhs._curr >= rhs._curr); }
	};


	// template <class T, class Pointer = T*, class Reference = T&,
	// 	class Distance = ptrdiff_t, class Category = std::random_access_iterator_tag>
  	// class vector_iterator 
	// {
	// public:
	// 	typedef T         value_type;
	// 	typedef Distance  difference_type;
	// 	typedef Pointer   pointer;
	// 	typedef Reference reference;
	// 	typedef Category  iterator_category;
	
	// private:
	// 	pointer _curr;
	
	// public:
	// 	/* default-constructible, param-constructible, copy-constructible, copy-assignable and destructible */
	// 	vector_iterator() : _curr(0) {};
	// 	vector_iterator(pointer p) : _curr(p) {}
	// 	vector_iterator(const vector_iterator<T>& copy) {*this = copy;}
	// 	~vector_iterator() {}

	// 	/* operators */
	// 	vector_iterator	&operator=(const vector_iterator& other) {
	// 		_curr = other._curr;
	// 		return (*this);
	// 	}

	// 	vector_iterator &operator++()
	// 	{
	// 		++_curr;
	// 		return (*this);
	// 	}

	// 	vector_iterator	operator++(int)
	// 	{
	// 		vector_iterator tmp(*this);
	// 		++_curr;
	// 		return (tmp);
	// 	}

	// 	vector_iterator &operator--()
	// 	{
	// 		--_curr;
	// 		return (*this);
	// 	}
		
	// 	vector_iterator operator--(int)
	// 	{
	// 		vector_iterator tmp(*this);
	// 		--_curr;
	// 		return (tmp);
	// 	}

	// 	difference_type	operator-(vector_iterator b) const {
	// 		return (_curr - b._curr);
	// 	}

	// 	difference_type	operator+(vector_iterator b) const { // надо затестить, точно ли нужен оператор?
	// 		return (_curr + b._curr);
	// 	}

	// 	vector_iterator	operator-(difference_type n) const {
	// 		vector_iterator tmp(*this);
	// 		tmp._curr -= n;
	// 		return (tmp);
	// 	}

	// 	vector_iterator	operator+(difference_type n) const {
	// 		vector_iterator tmp(*this);
	// 		tmp._curr += n;
	// 		return (tmp);
	// 	}

	// 	vector_iterator	&operator+=(difference_type n) {
	// 		_curr += n;
	// 		return (*this);
	// 	}
	// 	vector_iterator	&operator-=(difference_type n) {
	// 		_curr -= n;
	// 		return (*this);
	// 	}

	// 	reference	operator*() const { return (*_curr); }
	// 	pointer		operator->() const { return (_curr); }
	// 	reference	operator[](difference_type n) const { return (*(_curr + n)); }

	// 	friend bool operator==(const vector_iterator& lhs, const vector_iterator& rhs) { return (lhs._curr == rhs._curr);}		
	// 	friend bool operator!=(const vector_iterator& lhs, const vector_iterator& rhs) { return (lhs._curr != lhs._curr); }
	// 	friend bool operator<(const vector_iterator& lhs, const vector_iterator& rhs) { return (lhs._curr < rhs._curr);}
	// 	friend bool operator>(const vector_iterator& lhs, const vector_iterator& rhs) { return (lhs._curr > rhs._curr); }
	// 	friend bool operator<=(const vector_iterator& lhs, const vector_iterator& rhs) { return (lhs._curr <= rhs._curr); }
	// 	friend bool operator>=(const vector_iterator& lhs, const vector_iterator& rhs) { return (lhs._curr >= rhs._curr); }
	// };
}