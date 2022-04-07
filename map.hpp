/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:28:46 by graja             #+#    #+#             */
/*   Updated: 2022/04/07 18:42:30 by graja            ###   ########.fr       */
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

template <typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = allocator<ft::pair<const Key,T> > >
class map
{
	private:
		typedef	Key						key_type;
		typedef	T						mapped_type;
		typedef	pair<const key_type, mapped_type		value_type;
		typedef	Compare						key_compare;
	//	typedef 						value_compare;
		typedef	Alloc						allocator_type;
		typedef	allocator_type::reference			reference;
		typedef allocator_type::const_reference			const_reference;
		typedef	allocator_type::pointer				pointer;
		typedef allocator_type::const_pointer			const_pointer;
	//	typedef							iterator;
	//	typedef							const_iterator;
	//	typedef							reverse_iterator;
	//	typedef							const_reverse_iterator;
		typedef	iterator_traits<iterator>::difference_type	difference_type;
		typedef	size_t						size_type;

		pointer		parent;
		pointer		right_child;
		pointer		left_child;
		key_type	key;
		mapped_type	data;

	public:
		map(void): parent(NULL), right_child(NULL), left_child(NULL), key(), data() {}
		~map(void) {}

};

#endif
