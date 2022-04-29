/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:30:52 by graja             #+#    #+#             */
/*   Updated: 2022/04/29 18:58:23 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

# include <cstddef>

namespace ft
{

template <bool flag, class IsTrue, class IsFalse>
struct choose;

template <class IsTrue, class IsFalse>
struct choose<true, IsTrue, IsFalse> {
   typedef IsTrue type;
};

template <class IsTrue, class IsFalse>
struct choose<false, IsTrue, IsFalse> {
   typedef IsFalse type;
};

//Equal
template <typename InputIterator1, typename InputIterator2>
bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	while (first1 != last1)
	{
		if ((*first1 != *first2))
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


//utility pair -- can hold two different types

template <typename T1, typename T2>
class pair
{
	public:

	typedef	T1	first_type;
	typedef	T2	second_type;

	first_type	first;
	second_type	second;

	pair(void): first(), second() {}
	pair(const first_type & a, const second_type & b): first(a),  second(b) {}
	~pair(void) {}

	template <typename V, typename U> 
	pair (const pair<U, V>& pr): first(pr.first), second(pr.second) {}

	pair const &	operator=(pair const & right)
	{
		first = right.first;
		second = right.second;

		return (*this);
	}
};

//these must be nonmember, otherwise compiler is pissed
//because one argument too much
	template <class T1, class T2>
	inline bool operator== (const pair<T1,T2>& l, const pair<T1,T2>& r)
	{
			if ((l.first == r.first) && (l.second == r.second))
					return (true);
			return (false);
	}

	template <class T1, class T2>
	inline bool operator!= (const pair<T1,T2>& l, const pair<T1,T2>& r)
	{
			return (!(l == r));
	}
	
	template <class T1, class T2>
	inline bool operator< (const pair<T1,T2>& l, const pair<T1,T2>& r)
	{
		return l.first < r.first || (!(r.first < l.first) && l.second < r.second);
	}

	template <class T1, class T2>
	inline bool operator<= (const pair<T1,T2>& l, const pair<T1,T2>& r)
	{
			return (!(r < l));
	}
	
	template <class T1, class T2>
	inline bool operator> (const pair<T1,T2>& l, const pair<T1,T2>& r)
	{
			return (r < l);
	}

	template <class T1, class T2>
	inline bool operator>= (const pair<T1,T2>& l, const pair<T1,T2>& r)
	{
			return (!(l < r));
	}


//function template to return a pair object with two different types
//making it inline to improve code execution time

template <typename T1, typename T2>
inline pair<T1, T2> make_pair(T1 x, T2 y)
{
	return (pair<T1, T2>(x, y));
}


//enable_if implementation

template<bool Cond, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> { typedef T type; };

// is_integral implementation

template<typename> struct is_integral
{
	static const bool value = false;
};

template<> struct is_integral<bool> {static const bool value = true;};
template<> struct is_integral<char> {static const bool value = true;};
//template<> struct is_integral<char16_t> {static const bool value = true;};
//template<> struct is_integral<char32_t> {static const bool value = true;};
template<> struct is_integral<wchar_t> {static const bool value = true;};
template<> struct is_integral<signed char> {static const bool value = true;};
template<> struct is_integral<short int> {static const bool value = true;};
template<> struct is_integral<int> {static const bool value = true;};
template<> struct is_integral<long int> {static const bool value = true;};
template<> struct is_integral<long long int> {static const bool value = true;};
template<> struct is_integral<unsigned char> {static const bool value = true;};
template<> struct is_integral<unsigned short int> {static const bool value = true;};
template<> struct is_integral<unsigned int> {static const bool value = true;};
template<> struct is_integral<unsigned long int> {static const bool value = true;};
template<> struct is_integral<unsigned long long int> {static const bool value = true;};

} //end namespace

#endif
