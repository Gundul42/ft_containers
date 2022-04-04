/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:30:52 by graja             #+#    #+#             */
/*   Updated: 2022/04/04 17:28:01 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

namespace ft
{

//Equal
template <typename InputIterator1, typename InputIterator2>
bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	while (first1 != last1)
	{
		if (!(*first1 == *first2))
			return false;
		++first1;
		++first2;
	}
	return (true);
}


template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
		BinaryPredicate pred)
{
	while (first1 != last1)
	{
		if (!pred(*first1,*first2))
			return false;
		++first1;
		++first2;
	}
	return (true);
}


// lexicopraphical_compare :
// Returns true if the range [first1,last1) compares lexicographically
// less than the range [first2,last2).

template <typename InputIterator1, typename InputIterator2>
bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1 < *first2)
			return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}

template <typename InputIterator1, typename InputIterator2, typename Compare>
bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2, Compare comp)
{
	while (first1 != last1)
	{
		if ( first2 == last2 || comp(*first1, *first2))
			return true;
		else if (comp(*first2, *first1))
			return false;
		++first1;
		++first2;
	}
	return (false);
}

} //end namespace

#endif
