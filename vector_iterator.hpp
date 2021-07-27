/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:50:22 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/27 04:31:22 by efumiko          ###   ########.fr       */
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
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	
	private:
		pointer _curr;
	
	public:
		/* default-constructible, param-constructible, copy-constructible, copy-assignable and destructible */
		vector_iterator() : _curr(0) {};
		vector_iterator(pointer p) : _curr(p) {}
		vector_iterator(vector_iterator<T> const &copy) : _curr(copy.base()) {}
		~vector_iterator() {}

		pointer base() const
		{
			return (this->_curr);
		}

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
			vector_iterator old(*this);
			++_curr;
			return (old);
		}

		vector_iterator &operator--()
		{
			--_curr;
			return (*this);
		}
		
		vector_iterator operator--(int)
		{
			vector_iterator old(*this);
			--_curr;
			return (old);
		}

		difference_type	operator-(vector_iterator b) const {
			return (_curr - b._curr);
		}

		difference_type	operator+(vector_iterator b) const {
			return (_curr + b._curr);
		}

		vector_iterator	operator-(difference_type n) const {
			vector_iterator old(*this);
			old._curr -= n;
			return (old);
		}

		vector_iterator	operator+(difference_type n) const {
			vector_iterator old(*this);
			old._curr += n;
			return (old);
		}
		friend vector_iterator operator+(difference_type lhs, const vector_iterator& rhs) {
			vector_iterator old(rhs);
			old._curr += lhs;
			return (old);
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
		friend bool operator!=(const vector_iterator& lhs, const vector_iterator& rhs) { return (lhs._curr != rhs._curr); }
		friend bool operator<(const vector_iterator& lhs, const vector_iterator& rhs) { return (lhs._curr < rhs._curr);}
		friend bool operator>(const vector_iterator& lhs, const vector_iterator& rhs) { return (lhs._curr > rhs._curr); }
		friend bool operator<=(const vector_iterator& lhs, const vector_iterator& rhs) { return (lhs._curr <= rhs._curr); }
		friend bool operator>=(const vector_iterator& lhs, const vector_iterator& rhs) { return (lhs._curr >= rhs._curr); }
	};


	template <class iterator>
  	class vector_reverse_iterator 
	{
	public:
		typedef				vector_reverse_iterator<iterator>	iterator_type;
		typedef typename	iterator::reference					reference;
		typedef typename	iterator::pointer					pointer;
		typedef typename	iterator::difference_type			difference_type;
		typedef	typename	iterator::iterator_category			iterator_category;
	private:
		iterator _curr;
	
	public:
		/* default-constructible, param-constructible, copy-constructible, copy-assignable and destructible */
		vector_reverse_iterator() : _curr(0) {};
		vector_reverse_iterator(pointer p) : _curr(p) {}
		vector_reverse_iterator(const iterator& it) : _curr(it) {} 
		vector_reverse_iterator(const vector_reverse_iterator<iterator>& it) : _curr(it._curr) {}

		~vector_reverse_iterator() {}

		/* operators */
		iterator_type &operator++()
		{
			--_curr;
			return (*this);
		}

		iterator_type	operator++(int)
		{
			vector_reverse_iterator tmp(*this);
			--_curr;
			return (tmp);
		}

		iterator_type &operator--()
		{
			++_curr;
			return (*this);
		}
		
		iterator_type operator--(int)
		{
			vector_reverse_iterator tmp(*this);
			++_curr;
			return (tmp);
		}

		// difference_type	operator-(vector_iterator b) const {
		// 	return (_curr - b._curr);
		// }

		// difference_type	operator+(vector_iterator b) const { // надо затестить, точно ли нужен оператор?
		// 	return (_curr + b._curr);
		// }

		iterator_type operator-(difference_type n) const {
			return (iterator_type(_curr + n));
		}

		iterator_type operator+(difference_type n) const {
			return (iterator_type(_curr - n));
		}

		iterator_type	&operator+=(difference_type n) {
			_curr -= n;
			return (*this);
		}
		iterator_type	&operator-=(difference_type n) {
			_curr += n;
			return (*this);
		}

		reference	operator*() const { return (*_curr); }
		pointer		operator->() const { return (_curr); }
		reference	operator[](difference_type n) const { return *(*this + n); }

		friend bool operator==(const iterator_type& lhs, const iterator_type& rhs) { return (lhs._curr == rhs._curr);}		
		friend bool operator!=(const iterator_type& lhs, const iterator_type& rhs) { return (lhs._curr != rhs._curr); }
		friend bool operator<(const iterator_type& lhs, const iterator_type& rhs) { return (lhs._curr > rhs._curr);}
		friend bool operator>(const iterator_type& lhs, const iterator_type& rhs) { return (lhs._curr < rhs._curr); }
		friend bool operator<=(const iterator_type& lhs, const iterator_type& rhs) { return (lhs._curr >= rhs._curr); }
		friend bool operator>=(const iterator_type& lhs, const iterator_type& rhs) { return (lhs._curr <= rhs._curr); }
	};
}