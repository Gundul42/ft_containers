/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:25:31 by graja             #+#    #+#             */
/*   Updated: 2022/05/07 10:07:51 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_ITERATOR_H
# define VEC_ITERATOR_H

# include "iterator.hpp"
# include "utility.hpp"

namespace ft
{
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

		template<typename U, bool cval>
		V_iterator(const V_iterator<U, cval> & mit) : _p(mit.getPtr()) {}

		V_iterator & operator=(const V_iterator & right) {this->_p = right._p; return *this;}

		pointer	getPtr(void) const {return _p;}

		V_iterator&	operator++() {++_p;return *this;}
		V_iterator	operator++(int) {V_iterator tmp(*this); operator++(); return tmp;}
		V_iterator&	operator--() {--_p;return *this;}
		V_iterator	operator--(int) {V_iterator tmp(*this); operator--(); return tmp;}
		V_iterator &	operator+=(const size_type n) {_p = _p + n; return (*this);}
		V_iterator &	operator-=(const size_type n) {_p = _p - n; return (*this);}

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
		
		template<typename U, bool cval>
		difference_type	operator-(const V_iterator<U, cval> & rhs) const
			{return _p - rhs.getPtr();}
		
		template<typename U, bool cval>
		bool	operator==(const V_iterator<U, cval> & rhs) const
			{return _p == rhs.getPtr();}
		
		template<typename U, bool cval>
		bool	operator!=(const V_iterator<U, cval> & rhs) const
			{return _p != rhs.getPtr();}
		
		template<typename U, bool cval>
		bool	operator>(const V_iterator<U, cval> & rhs) const
			{return _p > rhs.getPtr();}
		
		template<typename U, bool cval>
		bool	operator<(const V_iterator<U, cval> & rhs) const
			{return _p < rhs.getPtr();}

		template<typename U, bool cval>
		bool	operator>=(const V_iterator<U, cval> & rhs) const
			{return _p >= rhs.getPtr();}
		
		template<typename U, bool cval>
		bool	operator<=(const V_iterator<U, cval> & rhs) const
			{return _p <= rhs.getPtr();}

		reference	operator*() {return *_p;}

		reference	operator->() {return *_p;}
		
		value_type	operator[](const size_type n) {return (*(_p + n));}

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

/*
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

		template<typename U, bool cval>
		V_reverse_iterator(const V_reverse_iterator<U, cval> & mit) : _p(mit.getPtr()) {}

		V_reverse_iterator & operator=(const V_reverse_iterator & right)
			{this->_p = right.getPtr(); return (*this);}

		V_reverse_iterator&	operator--() {++_p;return *this;}
		V_reverse_iterator&	operator++() {--_p;return *this;}
		V_reverse_iterator	operator++(int) {V_reverse_iterator tmp(*this); operator++(); return tmp;}
		V_reverse_iterator	operator--(int) {V_reverse_iterator tmp(*this); operator--(); return tmp;}
		V_reverse_iterator &	operator+=(const size_type n) {_p = _p - n; return (*this);}
		V_reverse_iterator &	operator-=(const size_type n) {_p = _p + n; return (*this);}

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

		template<typename U, bool cval>
		difference_type	operator-(const V_reverse_iterator<U, cval> & rhs) const
			{return _p - rhs.getPtr();}

		template<typename U, bool cval>
		bool	operator==(const V_reverse_iterator<U, cval> & rhs) const
			{return _p == rhs.getPtr();}

		template<typename U, bool cval>
		bool	operator!=(const V_reverse_iterator<U, cval> & rhs) const
			{return _p != rhs.getPtr();}

		template<typename U, bool cval>
		bool	operator>(const V_reverse_iterator<U, cval> & rhs) const
			{return _p > rhs.getPtr();}

		template<typename U, bool cval>
		bool	operator<(const V_reverse_iterator<U, cval> & rhs) const
			{return _p < rhs.getPtr();}

		template<typename U, bool cval>
		bool	operator>=(const V_reverse_iterator<U, cval> & rhs) const
			{return _p >= rhs.getPtr();}

		template<typename U, bool cval>
		bool	operator<=(const V_reverse_iterator<U, cval> & rhs) const
			{return _p <= rhs.getPtr();}
		value_type	operator[](const size_type n) {return (*(_p - n));}
		reference	operator*() {return *_p;}
		reference	operator->() {return *_p;}
		pointer		getPtr(void) const {return _p;}

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
*/
} //end namespace
#endif
