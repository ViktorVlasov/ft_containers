/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:23:45 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/09 21:21:12 by efumiko          ###   ########.fr       */
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
}