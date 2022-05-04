/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:02:45 by graja             #+#    #+#             */
/*   Updated: 2022/05/04 15:27:24 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_H
# define RBT_ITERATOR_H

# include "iterator.hpp"
# include "RBtree.hpp"
# include "utility.hpp"

namespace ft
{

template <typename Key, typename T, bool is_const>
class RBT_iterator : public ft::iterator<std::bidirectional_iterator_tag, T>
{
	public:
		typedef	Key												key_type;
		typedef T												mapped_type;
		typedef	pair<const key_type, mapped_type>				value_type;
		typedef	std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef	const value_type &								const_reference;

	private:
		typedef typename RBtree<key_type, mapped_type>::iter		RBnode;
		typedef typename RBtree<key_type, mapped_type>::const_iter	cRBnode;
		typedef typename choose<is_const, cRBnode , RBnode >::type	RB_type;
		
		RB_type	_p;

	public:
		RBT_iterator(void) :_p(NULL) {}

		RBT_iterator(RB_type in) :_p(in) {}
		~RBT_iterator(void) {}

		template<typename fst, typename U, bool cval>
		RBT_iterator(const RBT_iterator<fst, U, cval> & r) : _p(r.getPtr()) {}

		RB_type	getPtr(void) const {return _p;}

		RBT_iterator(const RBT_iterator & cpy) : _p(cpy._p) {}

		RBT_iterator & operator=(const RBT_iterator & right)
			{this->_p = right._p; return (*this);}

		RBT_iterator &	operator++() 
		{
			RB_type	tmp;
       		
			if (!_p)
					return (*this);
			else if (!_p->right_child)
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
			RB_type	tmp;
   
			if (!_p)
			{
				return (*this);
			}
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

};

		template <typename L, typename U, bool is_const>
		bool	operator==(const RBT_iterator<L, U, is_const> & lhs, 
						const RBT_iterator<L, U, is_const> & rhs)
			{return lhs.getPtr() == rhs.getPtr();}

		template <typename L, typename U, bool is_const>
		bool	operator!=(const RBT_iterator<L, U, is_const> & lhs, 
						const RBT_iterator<L, U, is_const> & rhs)
			{return lhs.getPtr() != rhs.getPtr();}
} //end namespace

#endif
