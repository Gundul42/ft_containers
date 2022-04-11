/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:14:23 by graja             #+#    #+#             */
/*   Updated: 2022/04/11 14:15:43 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RBTREE_H
# define RBTREE_H

# include <iostream>
# include <memory>
# include "utility.hpp"

namespace ft
{

template <typename Key, typename T, typename Alloc = std::allocator<pair<const Key, T > > >
class	rbtree 
{
	private:
		typedef	Key						key_type;
		typedef	T						mapped_type;
		typedef	pair<const key_type, mapped_type>		value_type;
		typedef	Alloc						allocator_type;
		typedef	typename allocator_type::reference		reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef	typename allocator_type::pointer		pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef	ptrdiff_t					difference_type;
		typedef	size_t						size_type;
		
		struct	node
		{
			pointer		data;
			bool		color;
			node		*parent;
			node		*right_child;
			node		*left_child;
		};

		size_type		_size;
		node			*_tree;
		allocator_type		_alloc;
		std::allocator<node>	_node_alloc;

		node	*_add_new_child(value_type const & chl, node *prt)
		{
			node	*tmp = _node_alloc.allocate(1);

			tmp->data = _alloc.allocate(1);
			_alloc.construct(tmp->data, chl);
			tmp->right_child = NULL;
			tmp->left_child = NULL;
			tmp->parent = prt;
			if (prt == NULL)
				tmp->color = true;
			else
				tmp->color = false;
			_size++;
			return (tmp);
		}

		rbtree(rbtree const & cpy) {*this = cpy;}
		rbtree & operator=(rbtree const & right)
		{
			_size = right._size;
			_tree = right->_tree;
			return (*this);
		}

		void	_check_parent(node *nd)
		{
			node	*sibling;
			node	*granny;

			//check parent color, if black exit
			if (nd->color)
				return ;
			granny = nd->parent;
			if (granny->right_child == nd)
				sibling = granny->left_child;
			else
				sibling = granny->right_child;

			//check parent's sibling if it is NULL or black
			//then rotate and recolor
			if (sibling == NULL || sibling->color)
			{
				if (sibling)
					std::cout << sibling->color << " : " << sibling->data->first;
				std::cout << " rotate and recolor" << std::endl;
				_find_rotation(nd);
			}
			else if (sibling && !sibling->color)

			//if parents's sibling is red, recolor both 
			//and check parent of parent
			{
				sibling->color = !sibling->color;
				nd->color = !nd->color;
				granny->color = !granny->color;
				if (granny->parent != NULL)
				{
					std::cout << "recheck" << std::endl;
					_check_parent(granny->parent);
				}
				else
				{
					std::cout << "This is root" << std::endl;
					granny->color = true;
				}
			}
		}
		
		void	_find_rotation(node *nd)
		{
			node		*granny = nd->parent;
			std::string	code = "";

			if (granny->right_child == nd)
				code += "R";
			else
				code += "L";
			if (code == "R" && nd->right_child == NULL)
				code += "L";
			else if (code == "L" && nd->left_child)
				code += "L";
			else
				code += "R";
			std::cout << "turn code : " << code  << std::endl;
			if (code == "RR")
				_turn_left(nd);
			else if (code == "LL")
				_turn_right(nd);
			else if (code == "RL")
				_turn_right_left(nd);
			else if (code == "LR")
				_turn_left_right(nd);
		}

		void	_turn_right_left(node *nd)
		{
			node	*granny = nd->parent;

			granny->right_child = nd->left_child;
			nd->left_child = NULL;
			nd->parent = granny->right_child;
			granny->right_child->parent = granny;
			granny->right_child->right_child = nd;
			_turn_left(granny->right_child);
		}

		void	_turn_left_right(node *nd) //WORKS!!
		{
			node	*granny = nd->parent;

			granny->left_child = nd->right_child;
			granny->left_child->parent = granny;
			granny->left_child->left_child = nd;
			nd->right_child = NULL;
			nd->parent = granny->left_child;
			_turn_right(granny->left_child);
		}

		void	_turn_right(node *nd) //WORKS!!
		{
			node	*root;
			node	*hlp;

			root = nd->parent->parent;
			hlp = nd->right_child;
				nd->parent->parent = nd;
			if (root == NULL)
			{
			//	nd->parent->parent = nd;
				_tree = nd;
			}
			else
			{
				if (root->right_child == nd->parent)
					root->right_child = nd;
				else
					root->left_child = nd;
			}
			nd->right_child = nd->parent;
			nd->parent = root;
			nd->right_child->left_child = hlp;
			nd->color = !nd->color;
			nd->right_child->color = !nd->right_child->color;
		}

		void	_turn_left(node *nd) //WORKS!!
		{
			node	*root;
			node	*hlp;

			root = nd->parent->parent;
			hlp = nd->left_child;
				nd->parent->parent = nd;
			if (root == NULL)
			{
			//	nd->parent->parent = nd;
				_tree = nd;
			}
			else
			{
				if (root->right_child == nd->parent)
					root->right_child = nd;
				else
					root->left_child = nd;
			}
			nd->left_child = nd->parent;
			nd->parent = root;
			nd->left_child->right_child = hlp;
			nd->color = !nd->color;
			nd->left_child->color = !nd->left_child->color;
		}

	public:
		rbtree(const allocator_type& alloc = allocator_type()): _size(0), _tree(NULL) {}

		~rbtree(void) {}

		size_type	size(void) const {return (_size);}

		bool		empty(void) const {return (_size == 0);}

		void	print(node *in = NULL) const
		{
			if (in == NULL)
				in = _tree;
			if (in->color)
				std::cout << "\033[0mBLACK :: ";
			else
				std::cout << "\033[1;31m  RED :: ";
			std::cout << "Parent: ";
			if (in->parent)
				std::cout << in->parent->data->first << " -- ";
			else
				std::cout << "NULL -- ";
			std::cout << "Adress: " << in << ", value: " << in->data->first;
			if (in->right_child == NULL)
				std::cout << ", right child is NULL" << std::endl;
			else
			{
				std::cout << ", right child is " << in->right_child << std::endl;
				print(in->right_child);
			}
			if (in->color)
				std::cout << "\033[0mBLACK :: ";
			else
				std::cout << "\033[1;31m  RED :: ";
			std::cout << "Parent: ";
			if (in->parent)
				std::cout << in->parent->data->first << " -- ";
			else
				std::cout << "NULL -- ";
			std::cout << "Adress: " << in << ", value: " << in->data->first;
			if (in->left_child == NULL)
				std::cout << ", left child is NULL" << std::endl;
			else
			{
				std::cout << ", left child is " << in->left_child << std::endl;
				print(in->left_child);
			}
			std::cout << "\033[0m";
		}


		void	insert(const value_type& val)
		{
			node	*runner;
			node	*parent;

			if (!_tree)
			{
				_tree = _add_new_child(val, NULL);
				return ;
			}
			parent = NULL;
			runner = _tree;
			while (runner != NULL)
			{
				parent = runner;
				if ((val.first) < (runner->data->first))
					runner = runner->left_child;
				else
					runner = runner->right_child;
			}
			if ((val.first) < (parent->data->first))
				parent->left_child = _add_new_child(val, parent);
			else
				parent->right_child = _add_new_child(val, parent);
			_check_parent(parent);
		}
};

} //end namespace

#endif
