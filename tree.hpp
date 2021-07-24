/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 19:03:17 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/25 00:17:12 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
	enum Color
	{
		RED = false,
		BLACK = true
	};

	
	template <class Key, class Value>
	class RBNode 
	{
	public:
		typedef RBNode			node;
		typedef node*			node_ptr;
		typedef const node_ptr	node_const_ptr;
		typedef Key				key_type;
		typedef Value			value_type;

		key_type key;
		value_type value;
		node_ptr parent;
		node_ptr left;
		node_ptr right;
		Color color;

		
		RBNode() {}

		RBNode(key_type key, value_type val, node_ptr fa, node_ptr lch, node_ptr rch, Color color) 
			: key(k), value(val), parent(fa),
		 	left(lch), right(rch), color(color) {}

		
		RBNode(const node& other) 
			: key(other.key), value(other.value), parent(other.parent),
			left(other.left), right(other.right), color(other.color) {}

		// Copy constructor is more optimal here...
		
		// RedBlackNode(RB_ptr node) : color()
		// {
		// 	color = RED;
		// 	parent = node->parent;
		// 	left = node->left;
		// 	right = node->right;
		// }

		// int blackNum;   // Maybe it can be useful :/ 
	};

	template<class Key, class Value> 
	class RBHead
	{
	public:
		RBNode<Key, Value>			header;
		std::size_t					node_count;
		
		RB_head() : header()
		{
			header.color = BLACK;
			reset();
		}
		// void reset()
		// {
		// 	header.parent = &header;
		// 	header.left = &header;
		// 	header.right = &header;
		// 	node_count = 0;
		// }
	};
	
	template<typename key_type, typename value_type, typename key_val, typename compare>
	class RBTree
	{
	public:
		typedef RBNode<key_type, value_type>*			RBNode_ptr;
		// typedef const RB_node*						RB_const_ptr;
		// typedef RB_base<val_type>*					link;
		// typedef const RB_base<val_type>*				const_link;

		// typedef val_type*							pointer;
		// typedef const val_type*						const_pointer;
		// typedef val_type&							reference;
		// typedef const val_type&						const_reference;

		// typedef size_t								size_type;
		
		// typedef RB_tree_iterator<value_type>					iterator;
		// typedef RB_tree_const_iterator<value_type>			const_iterator;
		// typedef RB_tree_reverse_iterator<value_type>			reverse_iterator;
		// typedef RB_tree_const_reverse_iterator<value_type>	const_reverse_iterator;

	private:
		RBNode_ptr *root;
	
	
	public:
		RBTree();
		~RBTree();

		bool isRBT();

	

	}
}