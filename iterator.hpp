/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:36:39 by graja             #+#    #+#             */
/*   Updated: 2022/04/30 17:47:16 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_H
# define ITERATOR_H

# include <cstddef>

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
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};


// specialization takes care of pointer types
template <typename T>
struct iterator_traits<T *>
{
	typedef ptrdiff_t					difference_type;
	typedef T							value_type;
	typedef T*							pointer;
	typedef T&							reference;
	typedef random_access_iterator_tag	iterator_category;
};


// pointers to const type
template <typename T>
struct iterator_traits<const T *>
{
	typedef ptrdiff_t					difference_type;
	typedef T							value_type;
	typedef const T*					pointer;
	typedef const T&					reference;
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

template	<typename I>
class reverse_iterator
{
		public:
				typedef I												iterator_type;
				typedef iterator_traits<I>::iterator_category			iterator_category;
				typedef iterator_traits<I>::value_type					value_type;
				typedef iterator_traits<I>::difference_type				difference_type;
				typedef iterator_traits<I>::pointer						pointer;
				typedef iterator_traits<I>::reference					reference;
				
		private:
				iterator_type	_i;

		public:
				//Constructors
				reverse_iterator(void): _i(iterator_type()) {}
				explicit reverse_iterator(iterator_type it): _i(it) {}

				template <typename Iter>
				reverse_iterator(reverse_iterator<Iter> const & rev_it): _i(rev_it) {}

				//base
				iterator_type base() const {return _i}

				//operators
				reference operator*() const 
				{
						iterator_type tmp(_i);
						tmp--;
						return (*tmp);
				}
};

} //end namespace
#endif
