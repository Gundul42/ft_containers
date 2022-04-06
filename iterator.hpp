/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:36:39 by graja             #+#    #+#             */
/*   Updated: 2022/04/06 13:55:42 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_H
# define ITERATOR_H

namespace ft
{

//defining the different iterator tags, 
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};


// Iterator_traits
template <typename Iterator>
struct iterator_traits
{
	typedef typename Iterator::difference_type	difference_type;
	typedef typename Iterator::value_type		value_type;
	typedef typename Iterator::pointer		pointer;
	typedef typename Iterator::reference		reference;
	typedef typename Iterator::iterator_category	iterator_category;
};


// specialization takes care of pointer types
template <typename T>
struct iterator_traits<T *>
{
	typedef ptrdiff_t			difference_type;
	typedef T				value_type;
	typedef T*				pointer;
	typedef T&				reference;
	typedef random_access_iterator_tag	iterator_category;
};


// pointers to const type
template <typename T>
struct iterator_traits<const T *>
{
	typedef ptrdiff_t			difference_type;
	typedef T				value_type;
	typedef const T*			pointer;
	typedef const T&			reference;
	typedef random_access_iterator_tag	iterator_category;
};

//empty Iterator base class to be derived from
template <typename Category, typename T, typename Distance = ptrdiff_t,
         typename Pointer = T*, typename Reference = T&>
 struct iterator {
   typedef T         value_type;
   typedef Distance  difference_type;
   typedef Pointer   pointer;
   typedef Reference reference;
   typedef Category  iterator_category;
};

}
#endif
