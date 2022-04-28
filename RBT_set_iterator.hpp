/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_set_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:46:41 by graja             #+#    #+#             */
/*   Updated: 2022/04/28 13:18:42 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_SET_ITERATOR_H
# define RBT_SET_ITERATOR_H

# include "iterator.hpp"
# include "utility.hpp"

namespace ft
{

template <typename Key, bool is_const>
class RBT_set_iterator : public ft::iterator<std::bidirectional_iterator_tag, Key>
{
	public:
		typedef	Key												key_type;
		typedef	key_type										value_type;
		typedef	std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef	const value_type &								const_reference;

	private:
		typedef typename RBtree<key_type, bool>::iter			RBnode;
		typedef typename RBtree<key_type, bool>::const_iter		cRBnode;
		typedef typename choose<is_const, cRBnode , RBnode >::type	RB_type;
		
		RB_type	_p;

	public:
		RBT_set_iterator(void) :_p(NULL) {}

		RBT_set_iterator(RB_type in) :_p(in) {}
		~RBT_set_iterator(void) {}

		template<typename fst, bool cval>
		RBT_set_iterator(const RBT_set_iterator<fst, cval> & r) : _p(r.getPtr()) {}

		RB_type	getPtr(void) const {return _p;}

		RBT_set_iterator(const RBT_set_iterator & cpy) : _p(cpy._p) {}

		RBT_set_iterator & operator=(const RBT_set_iterator & right)
			{this->_p = right._p; return (*this);}

		RBT_set_iterator &	operator++() 
		{
			RB_type	tmp;
        
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

		RBT_set_iterator	operator++(int) 
			{RBT_set_iterator tmp(*this); operator++(); return tmp;}

		RBT_set_iterator&	operator--()
		{
			RB_type	tmp;
        
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
		RBT_set_iterator	operator--(int) 
			{RBT_set_iterator tmp(*this); operator--(); return tmp;}

		const value_type &	operator*() const 
		{
			return ((*(_p->data)).first);
		}
		
		const value_type &	operator->() const 
		{
			return ((*(_p->data)).first);
		}

		bool	operator==(const RBT_set_iterator& rhs) const
			{return _p == rhs._p;}
		bool	operator!=(const RBT_set_iterator& rhs) const
			{return _p != rhs._p;}
};

template <typename Key, bool is_const>
class RBT_reverse_set_iterator : public ft::iterator<std::bidirectional_iterator_tag, Key>
{
	public:
		typedef	Key												key_type;
		typedef	key_type										value_type;
		typedef	std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef	const value_type &								const_reference;
		typedef typename RBtree<key_type, bool>::iter			RBnode;
		typedef typename RBtree<key_type, bool>::const_iter		cRBnode;
		typedef typename choose<is_const, cRBnode , RBnode >::type	RB_type;

	private:
		RB_type	_p;

	public:
		RBT_reverse_set_iterator(void) :_p(NULL) {}

		RBT_reverse_set_iterator(RB_type in) :_p(in) {}
		~RBT_reverse_set_iterator(void) {}

		template<typename fst, bool cval>
		RBT_reverse_set_iterator(const RBT_reverse_set_iterator<fst, cval> & r) : _p(r.getPtr()) {}

		RB_type	getPtr(void) const {return _p;}

		RBT_reverse_set_iterator(const RBT_reverse_set_iterator & cpy) : _p(cpy._p) {}

		RBT_reverse_set_iterator & operator=(const RBT_reverse_set_iterator & right)
			{this->_p = right._p; return (*this);}

		RBT_reverse_set_iterator &	operator++() 
		{
			RB_type	tmp;
        
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

		RBT_reverse_set_iterator	operator++(int) 
			{RBT_reverse_set_iterator tmp(*this); operator--(); return tmp;}

		RBT_reverse_set_iterator&	operator--()
		{
			RB_type	tmp;
        
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
		RBT_reverse_set_iterator	operator--(int) 
			{RBT_reverse_set_iterator tmp(*this); operator++(); return tmp;}

		value_type &	operator*() 
		{
			return (*(_p->data));
		}
		
		value_type *	operator->() 
		{
			return ((_p->data));
		}

		bool	operator==(const RBT_reverse_set_iterator& rhs) const
			{return _p == rhs._p;}
		bool	operator!=(const RBT_reverse_set_iterator& rhs) const
			{return _p != rhs._p;}
};


} //end namespace

#endif
