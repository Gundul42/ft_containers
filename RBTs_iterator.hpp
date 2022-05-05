/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTs_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:02:45 by graja             #+#    #+#             */
/*   Updated: 2022/05/05 15:03:55 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTS_ITERATOR_H
# define RBTS_ITERATOR_H

# include "iterator.hpp"
# include "utility.hpp"

namespace ft
{

template <typename Key, bool is_const>
class RBTs_iterator : public ft::iterator<std::bidirectional_iterator_tag, Key>
{
	public:
		typedef	Key												key_type;
		typedef bool											mapped_type;
		typedef	Key 											value_type;
		typedef	std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef	const value_type &								const_reference;

	private:
		typedef typename RBtree<key_type, mapped_type>::iter			RBsnode;
		typedef typename RBtree<key_type, mapped_type>::const_iter		cRBsnode;
		typedef typename choose<is_const, cRBsnode , RBsnode >::type	RBs_type;
		
		RBs_type	_p;
		RBs_type	_first;
		RBs_type	_last;

	public:
		RBTs_iterator(void) :_p(NULL) {}

		RBTs_iterator(RBs_type in, RBs_type f = NULL, RBs_type l = NULL) :
				_p(in), _first(f), _last(l) {}

		~RBTs_iterator(void) {}

		template<typename fst, bool cval>
		RBTs_iterator(const RBTs_iterator<fst, cval> & r) : _p(r.getPtr()) {}

		RBs_type	getPtr(void) const {return _p;}
		RBs_type	getf(void) const {return _first;}
		RBs_type	getl(void) const {return _last;}

		RBTs_iterator(const RBTs_iterator & cpy) : _p(cpy._p), _first(cpy._first), _last(cpy._last) {}

		RBTs_iterator & operator=(const RBTs_iterator & right)
			{
					this->_p = right._p; 
					this->_first = right._first; 
					this->_last = right._last; 
					return (*this);
			}

		RBTs_iterator &	operator++() 
		{
			RBs_type	tmp;
        
			if (!_p)
					_p = _first;
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

		RBTs_iterator	operator++(int) 
			{RBTs_iterator tmp(*this); operator++(); return tmp;}

		RBTs_iterator&	operator--()
		{
			RBs_type	tmp;
        
			if (!_p)
					_p = _last;
			else if (!_p->left_child)
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

		RBTs_iterator	operator--(int) 
			{RBTs_iterator tmp(*this); operator--(); return tmp;}

		key_type const 	operator*() 
		{
			return ((_p->data->first));
		}
		
		key_type const	operator->() 
		{
			return ((_p->data).first);
		}

		bool	operator==(const RBTs_iterator& rhs) const
			{return _p == rhs._p;}
		bool	operator!=(const RBTs_iterator& rhs) const
			{return _p != rhs._p;}
};

} //end namespace

#endif
