/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 18:57:27 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/26 20:46:23 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <utility>
#include <iostream>

#include "tree.hpp"
#include "utils.hpp"


namespace ft
{
	template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> >> 
	class map
	{
	private:
		class val_comp: public ft::binary_function<ft::pair<const Key, T>, ft::pair<const Key, T>, bool>
		{
    		friend class map<Key, T, Compare, Alloc>;
   		protected:
    		Compare comp;
			val_comp(Compare c) : comp(c) { }
   		public:
			typedef bool						result_type;
			typedef ft::pair<const Key, T>		first_argument_type;
			typedef ft::pair<const Key, T>		second_argument_type;
    		bool operator()(const ft::pair<const Key, T>& x, const ft::pair<const Key, T>& y) const {return comp(x.first, y.first);}
  		};

	public:
		typedef	Key											key_type;
		typedef	T											mapped_type;
		typedef	ft::pair<const key_type, mapped_type>		value_type;
		typedef	Compare										key_compare;
		typedef	val_comp									value_compare;
		typedef	Alloc										allocator_type;
		typedef	value_type&									reference;
		typedef	const value_type&							const_reference;
		typedef	value_type*									pointer;
		typedef	const value_type*							const_pointer;
		
		typedef	typename Tree::iterator						iterator;
		typedef	typename Tree::const_iterator				const_iterator;
		typedef	typename Tree::reverse_iterator				reverse_iterator;
		typedef	typename Tree::const_reverse_iterator		const_reverse_iterator;
		typedef	typename Tree::size_type					size_type;

	private:
		
		typedef AVLTree<key_type, mapped_type, value_type, key_compare>	Tree;
		Tree tree;
		
	public: 
		map(): tree() {}
		map(const map& x) : tree(x.tree) {}
		explicit map(const Compare& comp): tree(comp) { }
		
		template<typename InputIter>
		map(InputIter first, InputIter last) : tree()
		{ tree.insert_range_unique(first, last); }
		
		template<typename InputIter>
		map(InputIter first, InputIter last, const Compare& comp): tree(comp)
		{ tree.insert_range_unique(first, last); }

		map& operator=(const map& x)
		{
			tree = x.tree;
			return (*this);
		}
		
	};
}