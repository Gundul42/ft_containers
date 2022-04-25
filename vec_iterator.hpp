/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:25:31 by graja             #+#    #+#             */
/*   Updated: 2022/04/25 18:42:40 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_ITERATOR_H
# define VEC_ITERATOR_H

# include "iterator.hpp"

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

template <typename T, bool is_const>
class V_iterator : public ft::iterator<std::random_access_iterator_tag, T>
{
	public:
		typedef	T												value_type;
		typedef	std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef	const value_type &								const_reference;
		typedef typename choose<is_const, const T &, T &>::type	reference;
		typedef typename choose<is_const, const T *, T *>::type	pointer;

	private:
		pointer	_p;

	public:
		V_iterator(void) :_p(NULL) {}
		V_iterator(pointer x) :_p(x) {}
		~V_iterator(void) {}

		V_iterator(const V_iterator & mit) : _p(mit._p) {}

		//V_iterator(const V_iterator<T, false> & copy) : _p(&(*copy._p)) {} 

		V_iterator & operator=(const V_iterator & right)
			{this->_p = right._p; return (*this);}

		pointer	getPtr(void) const {return _p;}

		V_iterator&	operator++() {++_p;return *this;}
		V_iterator	operator++(int) 
			{V_iterator tmp(*this); operator++(); return tmp;}
		V_iterator&	operator--() {--_p;return *this;}
		V_iterator	operator--(int) 
			{V_iterator tmp(*this); operator--(); return tmp;}
		V_iterator &	operator+=(const size_type n)
			{_p = _p + n; return (*this);}
		V_iterator &	operator-=(const size_type n)
			{_p = _p - n; return (*this);}
		V_iterator 	operator-(const size_type n)
			{
				V_iterator	tmp(this->_p);
				
				tmp._p = this->_p - n;
			       	return (tmp);
			}
		V_iterator 	operator+(const size_type n)
			{
				V_iterator	tmp(this->_p);
				
				tmp._p = this->_p + n;
			       	return (tmp);
			}
		difference_type	operator-(const V_iterator & right)
			{return (_p - right._p);}
		value_type	operator[](const size_type n)
			{return (*(_p + n));}
		bool	operator==(const V_iterator& rhs) const
			{return _p == rhs._p;}
		bool	operator!=(const V_iterator& rhs) const
			{return _p != rhs._p;}
		bool	operator>(const V_iterator& rhs) const
			{return _p > rhs._p;}
		bool	operator<(const V_iterator& rhs) const
			{return _p < rhs._p;}
		bool	operator>=(const V_iterator& rhs) const
			{return _p >= rhs._p;}
		bool	operator<=(const V_iterator& rhs) const
			{return _p <= rhs._p;}
		reference	operator*() {return *_p;}
		reference	operator->() {return *_p;}

		//non member overloads
		friend	V_iterator operator+(const size_type n, const V_iterator right)
		{
			V_iterator	tmp(right);

			tmp._p = right._p + n;
			return (tmp);
		}
		
		friend	V_iterator operator-(const size_type n, const V_iterator right)
		{
			V_iterator	tmp(right);

			tmp._p = right._p - n;
			return (tmp);
		}
		
};

template <typename T, bool is_const>
class V_reverse_iterator : public ft::iterator<std::random_access_iterator_tag, T>
{
	public:
		typedef	T												value_type;
		typedef	std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef	const value_type &								const_reference;
		typedef typename choose<is_const, const T &, T &>::type	reference;
		typedef typename choose<is_const, const T *, T *>::type	pointer;


	private:
		pointer	_p;

	public:
		V_reverse_iterator(void) :_p(NULL) {}
		V_reverse_iterator(pointer x) :_p(x) {}
		~V_reverse_iterator(void) {}

		V_reverse_iterator(const V_reverse_iterator & mit) : _p(mit._p) {}

		V_reverse_iterator & operator=(const V_reverse_iterator & right)
			{this->_p = right._p; return (*this);}

		V_reverse_iterator&	operator++() {--_p;return *this;}
		V_reverse_iterator	operator++(int) 
			{V_reverse_iterator tmp(*this); operator--(); return tmp;}
		V_reverse_iterator&	operator--() {++_p;return *this;}
		V_reverse_iterator	operator--(int) 
			{V_reverse_iterator tmp(*this); operator++(); return tmp;}
		V_reverse_iterator &	operator+=(const size_type n)
			{_p = _p - n; return (*this);}
		V_reverse_iterator &	operator-=(const size_type n)
			{_p = _p + n; return (*this);}
		V_reverse_iterator 	operator-(const size_type n)
			{
				V_reverse_iterator	tmp(this->_p);
				
				tmp._p = this->_p + n;
			       	return (tmp);
			}
		V_reverse_iterator 	operator+(const size_type n)
			{
				V_reverse_iterator	tmp(this->_p);
				
				tmp._p = this->_p - n;
			       	return (tmp);
			}
		difference_type	operator-(const V_reverse_iterator & right)
			{return (_p + right._p);}
		value_type	operator[](const size_type n)
			{return (*(_p - n));}
		bool	operator==(const V_reverse_iterator& rhs) const
			{return _p == rhs._p;}
		bool	operator!=(const V_reverse_iterator& rhs) const
			{return _p != rhs._p;}
		bool	operator>(const V_reverse_iterator& rhs) const
			{return _p < rhs._p;}
		bool	operator<(const V_reverse_iterator& rhs) const
			{return _p > rhs._p;}
		bool	operator>=(const V_reverse_iterator& rhs) const
			{return _p <= rhs._p;}
		bool	operator<=(const V_reverse_iterator& rhs) const
			{return _p >= rhs._p;}
		reference	operator*() {return *_p;}
		reference	operator->() {return *_p;}

		//non member overloads
		friend	V_reverse_iterator operator+(const size_type n,
				const V_reverse_iterator right)
		{
			V_reverse_iterator	tmp(right);

			tmp._p = right._p - n;
			return (tmp);
		}
		
		friend	V_reverse_iterator operator-(const size_type n,
				const V_reverse_iterator right)
		{
			V_reverse_iterator	tmp(right);

			tmp._p = right._p + n;
			return (tmp);
		}
};

} //end namespace
#endif
