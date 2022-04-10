/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:14:23 by graja             #+#    #+#             */
/*   Updated: 2022/04/10 12:59:36 by graja            ###   ########.fr       */
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
				std::cout << "rotate and recolor" << std::endl;
			else

			//if parents's sibling is red, recolor both 
			//and check parent of parent
			{
				sibling->color = !sibling->color;
				nd->color = !nd->color;
				granny->color = !granny->color;
				if (granny->parent != NULL)
				{
					std::cout << "recolor and recheck" << std::endl;
					_check_parent(nd->parent);
				}
				else
				{
					std::cout << "This is root" << std::endl;
					granny->color = true;
				}
			}
		}

		void	_turn_left(node *med)
		{
			node	*root;

			root = med->parent->parent;
			if (root == NULL)
				_tree = med;
			else
				root->right_child = med;
			med->left_child = med->parent;
			med->parent = root;
			med->left_child->right->child = NULL;
			med->color = !med->color;
			med->left_child->color = !med->left_child->color;
		}

		void	_turn_right(node *med)
		{
			node	*root;

			root = med->parent->parent;
			if (root == NULL)
				_tree = med;
			else
				root->left_child = med;
			med->right_child = med->parent;
			med->parent = root;
			med->right_child->left->child = NULL;
			med->color = !med->color;
			med->right_child->color = !med->right_child->color;
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
				std::cout << "BLACK :: ";
			else
				std::cout << "  RED :: ";
			std::cout << "Adress: " << in << ", value: " << in->data->first;
			if (in->right_child == NULL)
				std::cout << ", right child is NULL" << std::endl;
			else
			{
				std::cout << ", right child is " << in->right_child << std::endl;
				print(in->right_child);
			}
			if (in->color)
				std::cout << "BLACK :: ";
			else
				std::cout << "  RED :: ";
			std::cout << "Adress: " << in << ", value: " << in->data->first;
			if (in->left_child == NULL)
				std::cout << ", left child is NULL" << std::endl;
			else
			{
				std::cout << ", left child is " << in->left_child << std::endl;
				print(in->left_child);
			}
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
