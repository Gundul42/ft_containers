/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:28:46 by graja             #+#    #+#             */
/*   Updated: 2022/04/08 10:06:35 by graja            ###   ########.fr       */
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

		pointer		parent;
		pointer		right_child;
		pointer		left_child;
		key_type	key;
		mapped_type	data;

	public:
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = 
				allocator_type()): parent(NULL), right_child(NULL),
				left_child(NULL), key(), data() {}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()): parent(NULL),
				right_child(NULL), left_child(NULL), key(), data()
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


		//Iterators
		begin(void) 
		{
		}

		end(void)
		{
		}

		rbegin(void)
		{
		}

		rend(void)
		{
		}


		//Capacity
		bool	empty(void) const
		{
		}

		size_type	size(void) const;
		{
		}

		size_type	max_size(void) const;
		{
		}


		//Element access
		mapped_type & operator[](const key_type & k)
		{
		}


};

} //end namespace

#endif
