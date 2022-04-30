/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:28:46 by graja             #+#    #+#             */
/*   Updated: 2022/04/30 15:12:14 by graja            ###   ########.fr       */
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
# include "RBT_iterator.hpp"

namespace ft
{

template <typename Key, typename T, typename Compare = std::less<Key>, 
	 typename Alloc = std::allocator<ft::pair<const Key, T > > >
class map
{
	public:
		typedef	Key											key_type;
		typedef	T											mapped_type;
		typedef	ft::pair<const key_type, mapped_type>		value_type;
		typedef	Compare										key_compare;
		typedef	Alloc										allocator_type;
		typedef	typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef	typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef	ptrdiff_t									difference_type;
		typedef	size_t										size_type;
		typedef RBT_iterator<Key, T, false>					iterator;
		typedef RBT_iterator<Key, T, true>					const_iterator;
		typedef RBT_reverse_iterator<Key, T, false>			reverse_iterator;
		typedef RBT_reverse_iterator<Key, T, true>			const_reverse_iterator;
		
	private:

		//private members
		RBtree<key_type, mapped_type>	_tree;
		allocator_type					_alloc;
		key_compare						_comp;

	public:

		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = 
				allocator_type()): _tree()
		{
				_alloc = alloc;
				_comp = comp;
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()): _tree()
		{
			_alloc = alloc;
			_comp = comp;

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

		
		class value_compare
		{
			friend class map;

			protected:
				key_compare	comp;
				value_compare(Compare c) : comp(c) {}

			public:
				typedef bool 		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;

				bool operator()(const value_type & x, const value_type & y) const
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
		ft::pair<iterator, bool>	insert(value_type const & val)
		{
			iterator	in(find(val.first));
			
			if (in != iterator())
				return (ft::make_pair(in, false));
			in = iterator(_tree.insert(val));
			return (ft::make_pair(in, true));
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
		
			scd.clear();
			scd = *this;
			this->clear();
			*this = tmp;
		}

		void		clear(void) 
		{
			_tree.clear();
		}

		//Capacity
		bool		empty(void) const {return (_tree.empty());}

		size_type	size(void) const {return (_tree.size());}

		size_type	max_size(void) const {return (_tree.max_size());}

		//Element Access
		mapped_type & operator[](const key_type & k)
		{
			iterator	it = find(k);

			if (it == end())
			{
				insert(ft::make_pair(k, mapped_type()));
				it = find(k);
			}
			return ((*it).second);
		}

		//Observers
		key_compare	key_comp() const { return _comp;}

		value_compare	value_comp() const {return value_compare(_comp);}

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
			iterator	it = begin();

			while (it != end() && _comp((*it).first, key))
				it++;
			return (it);
		}

		iterator	upper_bound(key_type const & key)
		{
			iterator	it = begin();

			while (it != end() && !_comp(key, (*it).first))
				it++;
			return (it);
		}

		ft::pair<iterator, iterator>	equal_range(key_type const & key)
		{
				return (ft::make_pair(lower_bound(key), upper_bound(key)));
		}

		allocator_type get_allocator() const
		{
				return (_alloc);
		}

		//nonmember relational operators
		template <class U, class V, class C, class A>
		friend bool operator== ( const map<U,V,C,A>& lhs, const map<U,V,C,A>& rhs )
		{
//			map<U,V,C,A>	lcpy(lhs);
//			map<U,V,C,A>	rcpy(rhs);

		if (lhs.size() != rhs.size())
			return (false);
		return (equal(lhs.begin(), lhs.end(), rhs.begin()));
		}
		
		template <class U, class V, class C, class A>
		friend bool operator!= ( const map<U,V,C,A>& lhs, const map<U,V,C,A>& rhs )
		{
		return (!(lhs == rhs));
		}
	
		template <class U, class V, class C, class A>
		friend bool operator< ( const map<U,V,C,A>& lhs, const map<U,V,C,A>& rhs )
		{
		//	map<U,V,C,A>	lcpy(lhs);
		//	map<U,V,C,A>	rcpy(rhs);

			return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template <class U, class V, class C, class A>
		friend bool operator> ( const map<U,V,C,A>& lhs, const map<U,V,C,A>& rhs )
		{
			return (!(lhs <= rhs));
		}
		
		template <class U, class V, class C, class A>
		friend bool operator>=( const map<U,V,C,A>& lhs, const map<U,V,C,A>& rhs )
		{
				return (rhs < lhs);
		}
		
		template <class U, class V, class C, class A>
		friend bool operator<=( const map<U,V,C,A>& lhs, const map<U,V,C,A>& rhs )
		{
		//	map<U,V,C,A>	lcpy(lhs);
		//	map<U,V,C,A>	rcpy(rhs);

			if (equal(lhs.begin(), lhs.end(), rhs.begin()))
				return (true);
			return (lexicographical_compare(lhs.begin(), lhs.end(),
						rhs.begin(), rhs.end()));
		}
};

} //end namespace

#endif
