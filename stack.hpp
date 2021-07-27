/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 12:46:26 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/27 15:29:51 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T 			value_type;
		typedef Container 	container_type;
		typedef size_t 		size_type;
	
		explicit			stack(const container_type& ctnr = container_type()): _c(ctnr) {}	
		bool				empty()	const 				{ return (_c.empty());  }
		size_type			size()	const 				{ return (_c.size()); }
		value_type&			top()						{ return (_c.back()); }
		const value_type&	top()	const				{ return (_c.back()); }
		void				push(const value_type& val) { _c.push_back(val); }
		void				pop() 						{ _c.pop_back(); }

		template <class T_type, class Container_type>
		friend bool operator==(const stack<T_type, Container_type>& lhs, const stack<T_type, Container_type>& rhs);
		
		template <class T_type, class Container_type>
		friend bool operator<(const stack<T_type, Container_type>& lhs, const stack<T_type, Container_type>& rhs);
	
	private:
		container_type 		_c;
	
	};

	template <class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs._c == rhs._c); }

	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return !(lhs == rhs); }

	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs._c < rhs._c); }

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return !(lhs > rhs); }

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (rhs < lhs); }

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return !(lhs < rhs); }

};
#endif