/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:14:23 by graja             #+#    #+#             */
/*   Updated: 2022/04/12 15:56:29 by graja            ###   ########.fr       */
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

		rbtree(rbtree const & cpy) {*this = cpy;}

		rbtree & operator=(rbtree const & right)
		{
			_size = right._size;
			_tree = right->_tree;
			return (*this);
		}

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

		void	_check_parent(node *nd)
		{
			node	*sibling;
			node	*parent = nd->parent;
			node	*granny = parent->parent;

			//check parent color, if black exit
			if (parent->color)
				return ;
			
			if (granny->right_child == parent)
				sibling = granny->left_child;
			else
				sibling = granny->right_child;

			//check parent's sibling if it is NULL or black
			//then rotate aparent recolor
			if (sibling == NULL || sibling->color)
			{
				std::cout << " No sibling or it is black, rotate and recolor: "
					<< parent->data->first << std::endl;
				_find_rotation(nd);
			}
			else if (sibling && !sibling->color)

			//if parents's sibling is red, recolor both 
			//aparent check parent of parent
			{
				sibling->color = !sibling->color;
				parent->color = !parent->color;
				granny->color = !granny->color;
				if (granny->parent != NULL)
				{
					std::cout << "Is root, rechecking" << std::endl;
					_check_parent(granny);
				}
				else
				{
					std::cout << "This is root, we are done." << std::endl;
					granny->color = true;
				}
			}
		}
		
		void	_find_rotation(node *nd)
		{
			std::string	code = "";
			node		*parent = nd->parent;
			node		*granny = parent->parent;
		
			if (granny->right_child == parent)
				code += "R";
			else if (granny->left_child == parent)
				code += "L";
			if (parent->right_child == nd)
				code += "R";
			else if (parent->left_child == nd)
				code += "L";
			std::cout << "Rotation code: " << code << std::endl;
			if (code == "RL")
			{
				_turn_right(nd);
				_turn_left(nd);
				nd->color = !nd->color;
				nd->left_child->color = !nd->left_child->color;
			}
			if (code == "LR")
			{
				_turn_left(nd);
				_turn_right(nd);
				nd->color = !nd->color;
				nd->right_child->color = !nd->right_child->color;
			}
			if (code == "RR")
			{
				_turn_left(parent);
				parent->color = !parent->color;
				parent->left_child->color = !parent->left_child->color;
			}
			if (code == "LL")
			{
				_turn_right(parent);
				parent->color = !parent->color;
				parent->right_child->color = !parent->right_child->color;
			}
		}

		void	_turn_right(node *nd)
		{
			node	*root = nd->parent->parent;
			node	*hlp = nd->right_child;
		
			nd->parent->parent = nd;
			if (root == NULL)
			{
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
			if (hlp)
				hlp->parent = nd->right_child;
		}

		void	_turn_left(node *nd)
		{
			node	*root;
			node	*hlp;

			root = nd->parent->parent;
			hlp = nd->left_child;
			nd->parent->parent = nd;
			if (root == NULL)
			{
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
			if (hlp)
				hlp->parent = nd->left_child;
		}

		void		_clear(node *in = NULL)
		{
			if (_tree == NULL)
				return ;
			if (in == NULL)
				in = _tree;
			if (in->right_child)
				_clear(in->right_child);
			if (in->left_child)
				_clear(in->left_child);
			if (in->right_child == NULL && in->left_child == NULL)
			{
				std::cout << "Leaf found, deleting :" << in << std::endl;
				if (in->parent && in->parent->right_child == in)
					in->parent->right_child = NULL;
				else if (in->parent && in->parent->left_child == in)
					in->parent->left_child = NULL;
				_alloc.destroy(in->data);
				_alloc.deallocate(in->data, 1);
				_node_alloc.deallocate(in, 1);
			}
			else
				std::cout << in << ">> " << in->left_child << " -- " 
					<< in->right_child << std::endl << std::endl;
			std::cout << in << " :: " << _tree << std::endl;
			if (in == _tree)
				_tree = NULL;
		}

	public:
		rbtree(const allocator_type& alloc = allocator_type()): _size(0), _tree(NULL) {}

		~rbtree(void) {_clear();}

		size_type	size(void) const {return (_size);}

		bool		empty(void) const {return (_size == 0);}


		void	print(node *in = NULL) const
		{
			if (in == NULL)
				in = _tree;
			if (in == NULL)
				return;
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
			std::cout << "Inserted " << val.first << std::endl;
			if ((val.first) < (parent->data->first))
			{
				parent->left_child = _add_new_child(val, parent);
				_check_parent(parent->left_child);
			}
			else
			{
				parent->right_child = _add_new_child(val, parent);
				_check_parent(parent->right_child);
			}
			print();
			std::cout << std::endl;
		}
};

} //end namespace

#endif
