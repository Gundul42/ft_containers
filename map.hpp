/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:28:46 by graja             #+#    #+#             */
/*   Updated: 2022/04/08 17:47:49 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <iostream>
# include <stdexcept>
# include <memory>
# include "iterator.hpp"
# include "utility.hpp"

namespace ft
{

template <typename Key, typename T, typename Compare = std::less<Key>, 
	 typename Alloc = std::allocator<pair<const Key, T > > >
class map
{
	private:
		typedef	Key						key_type;
		typedef	T						mapped_type;
		typedef	pair<const key_type, mapped_type>		value_type;
		typedef	Compare						key_compare;
	//	typedef 						value_compare;
		typedef	Alloc						allocator_type;
		typedef	typename allocator_type::reference		reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef	typename allocator_type::pointer		pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
	//	typedef							iterator;
	//	typedef							const_iterator;
	//	typedef							reverse_iterator;
	//	typedef							const_reverse_iterator;
		typedef	ptrdiff_t					difference_type;
		typedef	size_t						size_type;
		
		struct	node
		{
			value_type	*data;
			node		*parent;
			node		*right_child;
			node		*left_child;
		};

		node	*_add_new_child(value_type const & chl, node *prt)
		{
			node	*tmp = _node_alloc.allocate(1);

			tmp->data = _alloc.allocate(1);
			_alloc.construct(tmp->data, chl);
			tmp->right_child = NULL;
			tmp->left_child = NULL;
			tmp->parent = prt;
			_size++;
			return (tmp);
		}

		size_type		_size;
		node			*_tree;
		allocator_type		_alloc;
		std::allocator<node>	_node_alloc;

	public:
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = 
				allocator_type()): _size(0), _tree(NULL) {}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()): _size(0),
				_tree(NULL)
		{
			//declare here
		}

		map(map const & cpy)
		{
			*this = cpy;
		}

		map & operator=(map const & right)
		{
			//implement here
		}

		~map(void) {}

/*
		//Iterators
		begin(void) 
		{
		//points to smallest key !
		}

		end(void)
		{
		}

		rbegin(void)
		{
		//points to largest key !!
		}

		rend(void)
		{
		}
*/

		//Capacity
		bool	empty(void) const {return (_size == 0);}

		size_type	size(void) const {return (_size);}

		size_type	max_size(void) const {return (_alloc.max_size());}

/*
		//Element access
		mapped_type & operator[](const key_type & k)
		{
		}

*/
		//Modifiers
		//pair<iterator,bool> insert (const value_type& val)
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

		//Iterators

		class iterator : public ft::iterator<std::bidirectional_iterator_tag, value_type>
		{
			private:
				value_type	*_p;

			public:
				iterator(void) :_p(NULL) {}
				iterator(value_type *x) :_p(x) {}
				~iterator(void) {}

				iterator(const iterator & mit) : _p(mit._p) {}

				iterator & operator=(const iterator & right)
					{this->_p = right._p; return (*this);}

				iterator&	operator++() {++_p;return *this;}
				iterator	operator++(int) 
					{iterator tmp(*this); operator++(); return tmp;}
				iterator&	operator--() {--_p;return *this;}
				iterator	operator--(int) 
					{iterator tmp(*this); operator--(); return tmp;}
				reference	operator*() {return *_p;}
				reference	operator->() {return *_p;}
				bool	operator==(const iterator& rhs) const
					{return _p == rhs._p;}
				bool	operator!=(const iterator& rhs) const
					{return _p != rhs._p;}
		};
};

} //end namespace

#endif
