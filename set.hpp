/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 09:44:15 by graja             #+#    #+#             */
/*   Updated: 2022/04/30 15:05:30 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SET_H
# define SET_H

# include <iostream>
# include <stdexcept>
# include <memory>
# include "iterator.hpp"
# include "utility.hpp"
# include "RBtree.hpp"
//# include "RBT_iterator.hpp"
# include "RBTs_iterator.hpp"

namespace ft
{

template <typename Key, typename Compare = std::less<Key>,
		 typename Alloc = std::allocator<pair<const Key, bool > > >
class set
{
	public:
		typedef	Key												key_type;
		typedef	bool											mapped_type;
		typedef	Key /*pair<const key_type, mapped_type>*/		value_type;
		typedef	Compare											key_compare;
		typedef Compare											value_compare;
		typedef	Alloc											allocator_type;
		typedef	typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef	typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef	ptrdiff_t										difference_type;
		typedef	size_t											size_type;
		typedef RBTs_iterator<Key, false>						iterator;
		typedef RBTs_iterator<Key, true>						const_iterator;
		typedef RBTs_reverse_iterator<Key, false>				reverse_iterator;
		typedef RBTs_reverse_iterator<Key, true>				const_reverse_iterator;

	private:

		//private members
		RBtree<key_type, mapped_type>	_tree;
		allocator_type					_alloc;
		key_compare						_comp;

	public:

		explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = 
				allocator_type()): _tree()
		{
				_alloc = alloc;
				_comp = comp;
		}

		template <class InputIterator>
		set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()): _tree()
		{
			_alloc = alloc;
			_comp = comp;

			while (first != last)
			{
				_tree.insert(ft::make_pair(*first, true));
				first++;
			}
		}

		set(set const & cpy)
		{
			iterator	in = cpy.begin();
			
			_tree.clear();
			while (in != cpy.end())
			{
				_tree.insert(ft::make_pair(*in, true));
				in++;
			}
		}

		set & operator=(set const & right)
		{
			iterator	in = right.begin();

			while (in != right.end())
			{
				this->_tree.insert(ft::make_pair(*in, true));
				in++;
			}
			return (*this);
		}

		~set(void) {}

	/*	
		class value_compare
		{
			friend class set;

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
*/
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
			iterator	in(find(val));
			
			if (in != iterator())
				return (ft::make_pair(in, false));
			in = iterator(_tree.insert(ft::make_pair(val, true)));
			return (ft::make_pair(in, true));
		}

		iterator insert(iterator pos, const value_type& val)
		{
			if (pos != iterator())
				return (_tree.insert(ft::make_pair(val, true)));
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

		void swap(set & scd)
		{
			set<key_type, key_compare, allocator_type>	tmp(scd);
		
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

		pair<iterator, iterator>	equal_range(key_type const & key)
		{
				return (ft::make_pair(lower_bound(key), upper_bound(key)));
		}

		allocator_type get_allocator() const
		{
				return (_alloc);
		}

};

		//nonmember relational operators
		template <class U, class C, class A>
		 bool operator== ( const set<U,C,A>& lhs, const set<U,C,A>& rhs )
		{
		if (lhs.size() != rhs.size())
			return (false);
		return (equal(lhs.begin(), lhs.end(), rhs.begin()));
		}
		
		template <class U, class C, class A>
		 bool operator!= ( const set<U,C,A>& lhs, const set<U,C,A>& rhs )
		{
		return (!(lhs == rhs));
		}
	
		template <class U, class C, class A>
		 bool operator< ( const set<U,C,A>& lhs, const set<U,C,A>& rhs )
		{
			return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template <class U, class C, class A>
		 bool operator> ( const set<U,C,A>& lhs, const set<U,C,A>& rhs )
		{
			return (!(lhs <= rhs));
		}
		
		template <class U, class C, class A>
		 bool operator>=( const set<U,C,A>& lhs, const set<U,C,A>& rhs )
		{
				return (rhs < lhs);
		}
		
		template <class U, class C, class A>
		 bool operator<=( const set<U,C,A>& lhs, const set<U,C,A>& rhs )
		{
			if (equal(lhs.begin(), lhs.end(), rhs.begin()))
				return (true);
			return (lexicographical_compare(lhs.begin(), lhs.end(),
						rhs.begin(), rhs.end()));
		}
} //end namespace

#endif
