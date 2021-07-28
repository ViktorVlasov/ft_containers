/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:57:27 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/28 01:59:31 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include <utility>
# include <iostream>

# include "RBtree.hpp"
# include "utils.hpp"

namespace ft
{

	template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
	public:
		typedef	Key											key_type;
		typedef	T											mapped_type;
		typedef	ft::pair<const Key, T>						value_type;
		typedef	Compare										key_compare;
		typedef	Alloc										allocator_type;
		typedef	value_type&									reference;
		typedef	const value_type&							const_reference;
		typedef	value_type*									pointer;
		typedef	const value_type*							const_pointer;
		typedef ptrdiff_t									difference_type;


	private:
		typedef RBT<Key, value_type, Select1st<value_type>, Compare>	Tree;
		Tree	tree;
	
		class val_comp: public ft::binary_function<value_type, value_type, bool>
		{
    		friend class map;
   		protected:
    		Compare comp;
			val_comp(Compare c) : comp(c) { }
   		public:
			typedef bool			result_type;
			typedef value_type		first_argument_type;
			typedef value_type		second_argument_type;
    		bool operator()(const value_type& x, const value_type& y) const 
			{
				return comp(x.first, y.first);
			}
  		};
	
	public:
		typedef	val_comp									value_compare;
		typedef	typename Tree::iterator						iterator;
		typedef	typename Tree::const_iterator				const_iterator;
		typedef	typename Tree::reverse_iterator				reverse_iterator;
		typedef	typename Tree::const_reverse_iterator		const_reverse_iterator;
		typedef	typename Tree::size_type					size_type;

	
	public:

		map(): tree() { }
		map(const map& x) : tree(x.tree) { }
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
		
		// ****ITERATORS****
		iterator				begin()				{ return (tree.begin()); }
		const_iterator			begin()		const	{ return (tree.begin()); }
		iterator				end()				{ return (tree.end()); }
		const_iterator			end()		const	{ return (tree.end()); }
		reverse_iterator		rbegin()			{ return (tree.rbegin()); }
		const_reverse_iterator	rbegin()	const	{ return (tree.rbegin()); }
		reverse_iterator 		rend() 				{ return (tree.rend()); }
		const_reverse_iterator	rend()		const	{ return (tree.rend()); }


		// ****CAPACITY****
		bool		empty()		const	{ return (tree.empty()); }
		size_type	size()		const	{ return (tree.size()); }
		size_type	max_size()	const	{ return (tree.max_size()); }
		 

		// ****ELEMENT ACCESS****
		mapped_type& operator[] (const key_type& k)
		{
			iterator it = tree.find(k);
    		if (it == end())
      			it = insert(value_type(k, mapped_type())).first;
    		return ((*it).second);
		}
		

		// ****INSERT**** 
		ft::pair<iterator, bool>	insert(const value_type& val) { return (tree.insert_unique(val)); }
		iterator					insert(iterator position, const value_type& val) { return (tree.insert_unique(position, val)); }
		template<typename InputIterator>
		void						insert(InputIterator first, InputIterator last) { tree.insert_range_unique(first, last); }


		// ****ERASE****
		void		erase(iterator position) { tree.erase(position); }
		size_type	erase(const key_type& k) { return (tree.erase(k)); }
		void		erase(iterator first, iterator last) { tree.erase(first, last); }


		// ****SWAP and CLEAR****
		void		swap(map &x)	{ tree.swap(x.tree); }
		void		clear()			{ tree.clear(); }
		
		
		// ****OBSERVERS****
		key_compare		key_comp()	const	{ return (tree.key_comp()); }
		value_compare	value_comp()	const	{ return (value_compare(tree.key_comp())); }


		// ****OPERATIONS****
		iterator		find(const key_type& k)					{ return (tree.find(k)); }
		const_iterator	find(const key_type& k)			const	{ return (tree.find(k)); }
		size_type		count(const key_type& k)		const	{ return (tree.count(k)); }
		iterator 		lower_bound (const key_type& k)			{ return (tree.lower_bound(k));}
		const_iterator	lower_bound (const key_type& k)	const	{ return (tree.lower_bound(k));}
		iterator		upper_bound (const key_type& k)			{ return (tree.upper_bound(k)); }
		const_iterator	upper_bound (const key_type& k)	const	{ return (tree.upper_bound(k)); }

		ft::pair<iterator, iterator>			equal_range	(const key_type& k)			{ return (tree.equal_range(k)); }
		ft::pair<const_iterator,const_iterator>	equal_range	(const key_type& k)	const	{ return (tree.equal_range(k)); }
	};
}
#endif