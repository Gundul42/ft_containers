/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:02:45 by graja             #+#    #+#             */
/*   Updated: 2022/04/26 17:09:42 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_H
# define RBT_ITERATOR_H

# include "iterator.hpp"
# include "utility.hpp"

namespace ft
{

template <typename Key, typename T, bool is_const>
class RBT_iterator : public ft::iterator<std::bidirectional_iterator_tag, T>
{
	public:
		typedef	Key												key_type;
		typedef typename choose<is_const, const T , T >::type	mapped_type;
		typedef	pair<const key_type, mapped_type>				value_type;
		typedef	std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef	const value_type &								const_reference;

	private:
		typename RBtree<key_type, mapped_type>::iter	_p;

	public:
		RBT_iterator(void) :_p(NULL) {}

		RBT_iterator(typename RBtree<key_type, mapped_type>::iter in) :_p(in) {}
		~RBT_iterator(void) {}

		template<typename fst, typename U, bool cval>
		RBT_iterator(const RBT_iterator<fst, U, cval> & r) : _p(r.getPtr()) {}

		typename RBtree<key_type, T>::iter	getPtr(void) const {return _p;}

		RBT_iterator(const RBT_iterator & cpy) : _p(cpy._p) {}

		RBT_iterator & operator=(const RBT_iterator & right)
			{this->_p = right._p; return (*this);}

		RBT_iterator &	operator++() 
		{
			typename RBtree<key_type, mapped_type>::iter	tmp;
        
			if (!_p->right_child)
			{
				tmp = _p->parent;
				while (tmp && tmp->data->first < _p->data->first)
					tmp = tmp->parent;
				_p = tmp;
			}
			else if (!_p->right_child->left_child)
				_p = (_p->right_child);
			else if (_p->right_child->left_child)
			{
				tmp = _p->right_child->left_child;
				while (tmp->left_child)
					tmp = tmp->left_child;
				_p = tmp;
			}
			return (*this);
		}

		RBT_iterator	operator++(int) 
			{RBT_iterator tmp(*this); operator++(); return tmp;}

		RBT_iterator&	operator--()
		{
			typename RBtree<key_type, mapped_type>::iter	tmp;
        
			if (!_p->left_child)
			{
				tmp = _p->parent;
				while (tmp && tmp->data->first > _p->data->first)
					tmp = tmp->parent;
				_p = tmp;
			}
			else if (!_p->left_child->right_child)
				_p = (_p->left_child);
			else if (_p->left_child->right_child)
			{
				tmp = _p->left_child->right_child;
				while (tmp->right_child)
					tmp = tmp->right_child;
				_p = tmp;
			}
			return (*this);
		}
		RBT_iterator	operator--(int) 
			{RBT_iterator tmp(*this); operator--(); return tmp;}

		value_type &	operator*() 
		{
			return (*(_p->data));
		}
		
		value_type *	operator->() 
		{
			return ((_p->data));
		}

		bool	operator==(const RBT_iterator& rhs) const
			{return _p == rhs._p;}
		bool	operator!=(const RBT_iterator& rhs) const
			{return _p != rhs._p;}
};

template <typename Key, typename T, bool is_const>
class RBT_reverse_iterator : public ft::iterator<std::bidirectional_iterator_tag, T>
{
	public:
		typedef	Key												key_type;
		typedef typename choose<is_const, const T , T >::type	mapped_type;
		typedef	pair<const key_type, mapped_type>				value_type;
		typedef	std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef	const value_type &								const_reference;

	private:
		typename RBtree<key_type, mapped_type>::iter	_p;

	public:
		RBT_reverse_iterator(void) :_p(NULL) {}

		RBT_reverse_iterator(typename RBtree<key_type, mapped_type>::iter in) : _p(in) {}

		~RBT_reverse_iterator(void) {}
		
		template<typename fst, typename U, bool cval>
		RBT_reverse_iterator(const RBT_reverse_iterator<fst, U, cval> & r) : _p(r.getPtr()) {}

		typename RBtree<key_type, mapped_type>::iter	getPtr(void) const {return _p;}

		RBT_reverse_iterator & operator=(const RBT_reverse_iterator & right)
			{this->_p = right._p; return (*this);}

		RBT_reverse_iterator&	operator--() 
		{
			typename RBtree<key_type, mapped_type>::iter	tmp;
        
			if (!_p->right_child)
			{
				tmp = _p->parent;
				while (tmp && tmp->data->first < _p->data->first)
					tmp = tmp->parent;
				_p = tmp;
			}
			else if (!_p->right_child->left_child)
				_p = (_p->right_child);
			else if (_p->right_child->left_child)
			{
				tmp = _p->right_child->left_child;
				while (tmp->left_child)
					tmp = tmp->left_child;
				_p = tmp;
			}
			return (*this);
		}

		RBT_reverse_iterator	operator--(int) 
			{RBT_reverse_iterator tmp(*this); operator--(); return tmp;}

		RBT_reverse_iterator&	operator++()
		{
			typename RBtree<key_type, mapped_type>::iter	tmp;
        
			if (!_p->left_child)
			{
				tmp = _p->parent;
				while (tmp && tmp->data->first > _p->data->first)
					tmp = tmp->parent;
				_p = tmp;
			}
			else if (!_p->left_child->right_child)
				_p = (_p->left_child);
			else if (_p->left_child->right_child)
			{
				tmp = _p->left_child->right_child;
				while (tmp->right_child)
					tmp = tmp->right_child;
				_p = tmp;
			}
			return (*this);
		}

		RBT_reverse_iterator	operator++(int) 
			{RBT_reverse_iterator tmp(*this); operator++(); return tmp;}

		value_type &	operator*() 
		{
			return (*(_p->data));
		}
		
		value_type *	operator->() 
		{
			return ((_p->data));
		}

		bool	operator==(const RBT_reverse_iterator& rhs) const
			{return _p == rhs._p;}
		bool	operator!=(const RBT_reverse_iterator& rhs) const
			{return _p != rhs._p;}
};

} //end namespace

#endif
