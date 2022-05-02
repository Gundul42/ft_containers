/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTs_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:02:45 by graja             #+#    #+#             */
/*   Updated: 2022/05/02 14:51:49 by graja            ###   ########.fr       */
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
		typedef	Key /*pair<const key_type, mapped_type>	*/		value_type;
		typedef	std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef	const value_type &								const_reference;

	private:
		typedef typename RBtree<key_type, mapped_type>::iter			RBsnode;
		typedef typename RBtree<key_type, mapped_type>::const_iter		cRBsnode;
		typedef typename choose<is_const, cRBsnode , RBsnode >::type	RBs_type;
		
		RBs_type	_p;

	public:
		RBTs_iterator(void) :_p(NULL) {}

		RBTs_iterator(RBs_type in) :_p(in) {}
		~RBTs_iterator(void) {}

		template<typename fst, bool cval>
		RBTs_iterator(const RBTs_iterator<fst, cval> & r) : _p(r.getPtr()) {}

		RBs_type	getPtr(void) const {return _p;}

		RBTs_iterator(const RBTs_iterator & cpy) : _p(cpy._p) {}

		RBTs_iterator & operator=(const RBTs_iterator & right)
			{this->_p = right._p; return (*this);}

		RBTs_iterator &	operator++() 
		{
			RBs_type	tmp;
        
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

		RBTs_iterator	operator++(int) 
			{RBTs_iterator tmp(*this); operator++(); return tmp;}

		RBTs_iterator&	operator--()
		{
			RBs_type	tmp;
        
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

/*
template <typename Key, bool is_const>
class RBTs_reverse_iterator : public ft::iterator<std::bidirectional_iterator_tag, bool>
{
	public:
		typedef	Key												key_type;
		typedef bool											mapped_type;
		typedef	pair<const key_type, mapped_type>				value_type;
		typedef	std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef	const value_type &								const_reference;

	private:
		typedef typename RBtree<key_type, mapped_type>::iter			RBsnode;
		typedef typename RBtree<key_type, mapped_type>::const_iter		cRBsnode;
		typedef typename choose<is_const, cRBsnode , RBsnode >::type	RBs_type;
		
		RBs_type	_p;

	public:
		RBTs_reverse_iterator(void) :_p(NULL) {}

		RBTs_reverse_iterator(RBs_type in) :_p(in) {}
		~RBTs_reverse_iterator(void) {}

		template<typename fst, bool cval>
		RBTs_reverse_iterator(const RBTs_reverse_iterator<fst, cval> & r) : _p(r.getPtr()) {}

		RBs_type	getPtr(void) const {return _p;}

		RBTs_reverse_iterator(const RBTs_reverse_iterator & cpy) : _p(cpy._p) {}

		RBTs_reverse_iterator & operator=(const RBTs_reverse_iterator & right)
			{this->_p = right._p; return (*this);}

		RBTs_reverse_iterator &	operator--() 
		{
			RBs_type	tmp;
        
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

		RBTs_reverse_iterator	operator++(int) 
			{RBTs_reverse_iterator tmp(*this); operator--(); return tmp;}

		RBTs_reverse_iterator&	operator++()
		{
			RBs_type	tmp;
        
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
		RBTs_reverse_iterator	operator--(int) 
			{RBTs_reverse_iterator tmp(*this); operator++(); return tmp;}
		
		key_type const 	operator*() 
		{
			return ((_p->data->first));
		}
		
		key_type const	operator->() 
		{
			return ((_p->data).first);
		}

		bool	operator==(const RBTs_reverse_iterator& rhs) const
			{return _p == rhs._p;}
		bool	operator!=(const RBTs_reverse_iterator& rhs) const
			{return _p != rhs._p;}
};
*/

template <typename Key, bool is_const>
class RBTs_reverse_iterator : public ft::iterator<std::bidirectional_iterator_tag, Key>
{
	public:
		typedef	Key												key_type;
		typedef bool											mapped_type;
		typedef	Key /*pair<const key_type, mapped_type>*/		value_type;
		typedef	std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef	const value_type &								const_reference;

	private:
		typedef typename RBtree<key_type, mapped_type>::iter	RBsnode;
		typedef typename RBtree<key_type, mapped_type>::const_iter	cRBsnode;
		typedef typename choose<is_const, cRBsnode , RBsnode >::type	RBs_type;

		RBs_type	_p;

	public:
		RBTs_reverse_iterator(void) :_p(NULL) {}

		RBTs_reverse_iterator(RBs_type in) :_p(in) {}
		~RBTs_reverse_iterator(void) {}

		template<typename fst, typename U, bool cval>
		RBTs_reverse_iterator(const RBTs_reverse_iterator<fst, cval> & r) : _p(r.getPtr()) {}

		RBs_type	getPtr(void) const {return _p;}

		RBTs_reverse_iterator(const RBTs_reverse_iterator & cpy) : _p(cpy._p) {}

		RBTs_reverse_iterator & operator=(const RBTs_reverse_iterator & right)
			{this->_p = right._p; return (*this);}

		RBTs_reverse_iterator &	operator--() 
		{
			RBs_type	tmp;
        
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

		RBTs_reverse_iterator	operator++(int) 
			{RBTs_reverse_iterator tmp(*this); operator++(); return tmp;}

		RBTs_reverse_iterator&	operator++()
		{
			RBs_type	tmp;
        
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
		RBTs_reverse_iterator	operator--(int) 
			{RBTs_reverse_iterator tmp(*this); operator--(); return tmp;}

		key_type const	operator*() 
		{
			return ((_p->data->first));
		}
		
		key_type const operator->() 
		{
			return ((_p->data->first));
		}

		bool	operator==(const RBTs_reverse_iterator& rhs) const
			{return _p == rhs._p;}
		bool	operator!=(const RBTs_reverse_iterator& rhs) const
			{return _p != rhs._p;}
};
} //end namespace

#endif
