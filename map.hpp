/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:28:46 by graja             #+#    #+#             */
/*   Updated: 2022/04/20 15:51:45 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <iostream>
# include <stdexcept>
# include <memory>
# include "iterator.hpp"
# include "utility.hpp"
# include "RBtree.hpp"

namespace ft
{

template <typename Key, typename T, typename Compare = std::less<Key>, 
	 typename Alloc = std::allocator<pair<const Key, T > > >
class map
{
	private:
		typedef	Key						key_type;
		typedef	T						mapped_type;
		typedef	pair<const key_type, mapped_type>		value_type;
		typedef	Compare						key_compare;
	//	typedef 						value_compare;
		typedef	Alloc						allocator_type;
		typedef	typename allocator_type::reference		reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef	typename allocator_type::pointer		pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
	//	typedef typename map<key_type, mapped_type>::iterator	iterator;
	//	typedef							const_iterator;
	//	typedef							reverse_iterator;
	//	typedef							const_reverse_iterator;
		typedef	ptrdiff_t					difference_type;
		typedef	size_t						size_type;
		

		//private members
		RBtree<key_type, mapped_type>	_tree;
		allocator_type			_alloc;

	public:

		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = 
				allocator_type()): _tree() {}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()): _tree()
		{
			while (first != last)
			{
				_tree.insert(*first);
				first++;
			}
		}

		map(map const & cpy)
		{
			iterator	in = cpy.begin();
			
			_tree.clear();
			while (in != cpy.end())
			{
				_tree.insert(*in);
				in++;
			}
		}

		map & operator=(map const & right)
		{
			iterator	in = right.begin();

			while (in != right.end())
			{
				this->_tree.insert(*in);
				in++;
			}
			return (*this);
		}

		~map(void) {}

		//Iterators

		class iterator : public ft::iterator<std::bidirectional_iterator_tag, value_type>
		{
			private:
				typename RBtree<key_type, mapped_type>::iter	_p;

			public:
				iterator(void) :_p(NULL) {}

				iterator(typename RBtree<key_type, mapped_type>::iter in) :_p(in) {}
				~iterator(void) {}

				iterator(const iterator & mit) : _p(mit._p) {}

				iterator & operator=(const iterator & right)
					{this->_p = right._p; return (*this);}

				iterator&	operator++() 
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
				}

				iterator	operator++(int) 
					{iterator tmp(*this); operator++(); return tmp;}

				iterator&	operator--()
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
				}
				iterator	operator--(int) 
					{iterator tmp(*this); operator--(); return tmp;}

				value_type &	operator*() 
				{
					return (*(_p->data));
				}
				
				value_type &	operator->() 
				{
					return (*(_p->data));
				}

				bool	operator==(const iterator& rhs) const
					{return _p == rhs._p;}
				bool	operator!=(const iterator& rhs) const
					{return _p != rhs._p;}
		};
		
		class reverse_iterator : public ft::iterator<std::bidirectional_iterator_tag,
			value_type>
		{
			private:
				typename RBtree<key_type, mapped_type>::iter	_p;

			public:
				reverse_iterator(void) :_p(NULL) {}

				reverse_iterator(typename RBtree<key_type, mapped_type>::iter in) :
					_p(in) {}
				~reverse_iterator(void) {}

				reverse_iterator(const reverse_iterator & mit) : _p(mit._p) {}

				reverse_iterator & operator=(const reverse_iterator & right)
					{this->_p = right._p; return (*this);}

				reverse_iterator&	operator--() 
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
				}

				reverse_iterator	operator--(int) 
					{reverse_iterator tmp(*this); operator--(); return tmp;}

				reverse_iterator&	operator++()
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
				}

				reverse_iterator	operator++(int) 
					{reverse_iterator tmp(*this); operator++(); return tmp;}

				value_type &	operator*() 
				{
					return (*(_p->data));
				}
				
				value_type &	operator->() 
				{
					return (*(_p->data));
				}

				bool	operator==(const reverse_iterator& rhs) const
					{return _p == rhs._p;}
				bool	operator!=(const reverse_iterator& rhs) const
					{return _p != rhs._p;}
		};
		
		class value_compare
		{
			friend class map;

			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}

			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;

				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		};

		//Iterators
		
		//points to smallest key !
		iterator begin(void) const
		{
		return (iterator(_tree.begin()));
		}

		iterator end(void) const
		{
			return (iterator());
		}

		//points to largest key !!
		reverse_iterator rbegin(void) const
		{
			return (reverse_iterator(_tree.rbegin()));
		}

		reverse_iterator rend(void) const
		{
			return (reverse_iterator());
		}
		
		//Modifiers
		pair<iterator, bool>	insert(value_type const & val)
		{
			iterator	in(find(val.first));
			
			if (in != iterator())
				return (make_pair(in, false));
			in = iterator(_tree.insert(val));
			return (make_pair(in, true));
		}

		iterator insert(iterator pos, const value_type& val)
		{
			if (pos != iterator())
				return (_tree.insert(val));
			return (iterator());
		}
		
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_tree.insert(*first);
				first++;
			}
		}

		size_type	erase(key_type const & k)
		{
			return (_tree.erase(k));
		}

		void		erase(iterator pos)
		{
			_tree.erase((*pos).first);
		}

		void		erase(iterator first, iterator last)
		{
			while (first != last)
			{
				_tree.erase((*first).first);
				first++;
			}
		}

		void swap(map & scd)
		{
			map<key_type, mapped_type, key_compare, allocator_type>	tmp(scd);

			scd = *this;
			*this = tmp;
		}

		void		clear(void) 
		{
			_tree.clear();
		}

		//Capacity
		bool		empty(void) const {return (_tree.empty());}

		size_type	size(void) const {return (_tree.size());}

		size_type	max_size(void) const {return (_alloc.max_size());}

		//Element Access
		mapped_type & operator[](const key_type & k)
		{
			iterator	it = find(k);

			if (it != end())
				return ((*it).second);
			insert(make_pair(k, mapped_type()));	
		}

		//Observers
		key_compare	key_comp() const {}

		value_compare	value_comp() const {}

		//operations
		iterator	find(key_type const & key)
		{
			return (iterator(_tree.find(key)));
		}
		
		size_type	count(key_type const & k)
		{
			if (_tree.find(k))
				return (1);
			return (0);
		}

		iterator	lower_bound(key_type const & key)
		{
			//to be finished !!
			_tree.key_comp();
		}
};

} //end namespace

#endif
