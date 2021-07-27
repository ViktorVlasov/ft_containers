/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:23:45 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/27 18:29:07 by efumiko          ###   ########.fr       */
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


	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1!=last1)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1; ++first2;
		}
		return (true);
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

	template <typename A>
	void swap(A& a, A&b)
	{
		A tmp = a;
		a = b;
		b = tmp;
	};

	template <class T1, class T2>
	class pair
	{
		public:
			typedef T1				first_type;
			typedef T2 				second_type;

			first_type	first;
			second_type	second;

			pair() : first(), second(){};

			template <class U, class V>
			pair(const pair<U, V> &other) : first(other.first), second(other.second) {}

			pair(const pair<T1, T2> &other) : first(other.first), second(other.second) {}

			pair(const first_type &a, const second_type &b) : first(a), second(b) {}

			pair &operator=(const pair<first_type, second_type>  &other)
			{
				if (this == &other)
					return (*this);
				first = other.first;
				second = other.second;
				return (*this);
			}
	};

	template <class A, class B>
	pair<A, B> make_pair(A x, B y)
	{
		return (pair<A, B>(x, y));
	}

	template <class Arg1, class Arg2, class Result>
	struct binary_function {
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	template <class T> struct less : ft::binary_function<T,T, bool> {
		bool operator() (const T& x, const T& y) const { return x<y; }
	};

	template<typename _Arg, typename _Result>
	struct unary_function
	{
		typedef _Arg 		argument_type;   
		typedef _Result 	result_type;  
	};

	template <class Pair>
	struct Select1st : public ft::unary_function<Pair, typename Pair::first_type>
	{
		typename Pair::first_type& operator()(Pair& __x) const { return (__x.first); }
		const typename Pair::first_type& operator()(const Pair& __x) const { return (__x.first); }
	};
	
	template<typename Tp>
	struct Identity : public ft::unary_function<Tp, Tp>
	{
		Tp& operator()(Tp& x) const { return (x); }
		const Tp& operator()(const Tp& x) const { return x; }
	};

}