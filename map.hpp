/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:28:46 by graja             #+#    #+#             */
/*   Updated: 2022/04/18 13:59:02 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <iostream>
# include <stdexcept>
# include <memory>
# include "iterator.hpp"
# include "utility.hpp"
# include "RBtree.hpp"

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
		

		//private members
		RBtree<key_type, mapped_type>	_tree;
		allocator_type			_alloc;

	public:
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = 
				allocator_type()): _tree() {}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()): _tree()
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
		bool	empty(void) const {return (_tree.empty());}

		size_type	size(void) const {return (_tree.size());}

		size_type	max_size(void) const {return (_alloc.max_size());}

/*
		//Element access
		mapped_type & operator[](const key_type & k)
		{
		}

*/
		//Modifiers
		void	insert (value_type const & val)
		{
			_tree.insert(val.first, val.second);
		}

		size_type	erase(key_type const & k)
		{
			return (_tree.erase(k));
		}

		void		clear(void)
		{
			_tree.clear();
		}

		size_type	count(key_type const & k)
		{
			if (_tree.find(k))
				return (1);
			return (0);
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
