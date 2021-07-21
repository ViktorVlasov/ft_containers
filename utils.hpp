/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:23:45 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/20 19:00:59 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {

    template <typename T, T _value>
    struct integral_constant 
    {
        static const T value = _value;
    };

    struct true_type : public integral_constant<bool, true> {};
    struct false_type : public integral_constant<bool, false> {};

	template <class> struct is_integral : public false_type {};
	template<> struct is_integral<bool> : public true_type {};
    template<> struct is_integral<char> : public true_type {};
    template<> struct is_integral<wchar_t> : public true_type {};
    template<> struct is_integral<signed char> : public true_type {};
    template<> struct is_integral<unsigned char> : public true_type {};

    template<> struct is_integral<int> : public true_type {};
    template<> struct is_integral<unsigned int> : public true_type {};
    
    template<> struct is_integral<short int> : public true_type {};
    template<> struct is_integral<unsigned short int> : public true_type {};
    
    template<> struct is_integral<long int> : public true_type {};
    template<> struct is_integral<unsigned long int> : public true_type {};
    
	template<> struct is_integral<long long int> : public true_type {};
	template<> struct is_integral<unsigned long long int> : public true_type {};
	
    template <bool, typename T = void>
    struct enable_if {};

    template <typename T>
    struct enable_if <true, T> 
    {
        typedef T type;
    };

    template <class A, class B>
	class pair
	{
	public:
		typedef pair<A, B> 			pair_type;
		typedef A 					first_type;
		typedef B 					second_type;

		first_type first;
		second_type second;

		pair() : first(), second(){};

		template <class C, class D>
		pair(const pair<C, D> &other) : first(other.first), second(other.second) {}

		pair(const pair_type &other) : first(other.first), second(other.second) {}

		pair(const first_type &a, const second_type &b) : first(a), second(b) {}

		pair &operator=(const pair_type &other)
		{
			if (this == &other)
				return (*this);
			first = other.first;
			second = other.second;
			return (*this);
		}
	};
}