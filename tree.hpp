/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 19:03:17 by efumiko           #+#    #+#             */
/*   Updated: 2021/07/25 23:13:01 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
	class AVLNode // структура для представления узлов дерева
	{	
		public:
			typedef AVLNode* node_ptr;

			int key;
			unsigned char height;
			node_ptr left;
			node_ptr right;
			
			AVLNode(int k) { 
				key = k; 
				left = nullptr;
				right = nullptr; 
				height = 1; 
			}
	};

	class AVLTree {
		public:
			typedef AVLNode* node_ptr;
		
			node_ptr root;


			// возможно эти три функции должны быть в классе ноды
			unsigned char height(node_ptr p) { return p ? p->height : 0; }
			int bfactor(node_ptr p) { return height(p->right) - height(p->left); }
			void fixheight(node_ptr p)
			{
				unsigned char hl = height(p->left);
				unsigned char hr = height(p->right);
				p->height = (hl>hr?hl:hr)+1;
			}

			node_ptr rotateright(node_ptr p) // правый поворот вокруг p
			{
				node_ptr q = p->left;
				p->left = q->right;
				q->right = p;
				fixheight(p);
				fixheight(q);
				return q;
			}

			node_ptr rotateleft(node_ptr q) // левый поворот вокруг q
			{
				node_ptr p = q->right;
				q->right = p->left;
				p->left = q;
				fixheight(q);
				fixheight(p);
				return p;
			}

			node_ptr balance(node_ptr p) // балансировка узла p
			{
				fixheight(p);
				if( bfactor(p) == 2 )
				{
					if( bfactor(p->right) < 0 )
						p->right = rotateright(p->right);
					return rotateleft(p);
				}
				if( bfactor(p) ==-2 )
				{
					if( bfactor(p->left) > 0  )
						p->left = rotateleft(p->left);
					return rotateright(p);
				}
				return p; // балансировка не нужна
			}

			node_ptr insert(node_ptr p, int k) // вставка ключа k в дерево с корнем p
			{
				if( !p ) return new AVLNode(k);
				if( k < p->key )
					p->left = insert(p->left, k);
				else
					p->right = insert(p->right, k);
				return balance(p);
			}


	};



}