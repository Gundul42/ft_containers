/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:14:23 by graja             #+#    #+#             */
/*   Updated: 2022/04/09 16:00:44 by graja            ###   ########.fr       */
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


	public:
		rbtree(const allocator_type& alloc = allocator_type()): _size(0), _tree(NULL) {}

		~rbtree(void) {}

		size_type	size(void) const {return (_size);}

		bool		empty(void) const {return (_size == 0);}

		void	insert (const value_type& val)
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
		}
};

} //end namespace

#endif
