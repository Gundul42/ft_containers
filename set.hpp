/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:28:46 by graja             #+#    #+#             */
/*   Updated: 2022/04/28 16:17:36 by graja            ###   ########.fr       */
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
# include "RBT_set_iterator.hpp"

namespace ft
{

template <typename Key, typename Compare = std::less<Key>, 
	 typename Alloc = std::allocator<pair<const Key, bool > > >
class set
{
	public:
		typedef	Key												key_type;
		typedef	bool											mapped_type;
		typedef	pair<const key_type, mapped_type>				value_type;
		typedef	Compare											key_compare;
		typedef	Alloc											allocator_type;
		typedef	typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef	typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef	ptrdiff_t										difference_type;
		typedef	size_t											size_type;
		typedef RBT_set_iterator<Key, false>					iterator;
		typedef RBT_set_iterator<Key, true>						const_iterator;
		typedef RBT_reverse_set_iterator<Key, false>			reverse_iterator;
		typedef RBT_reverse_set_iterator<Key, true>				const_reverse_iterator;
		
	private:

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
				_tree.insert(*first);
				first++;
			}
		}

		set(set const & cpy)
		{
			iterator	in = cpy.begin();
			
			_tree.clear();
			while (in != cpy.end())
			{
				_tree.insert(*in);
				in++;
			}
		}

		set & operator=(set const & right)
		{
			iterator	in = right.begin();

			while (in != right.end())
			{
				this->_tree.insert(*in);
				in++;
			}
			return (*this);
		}

		~set(void) {}

		
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

		//Iterators
		
		//points to smallest key !
		iterator 		begin(void) {return (iterator(_tree.begin()));}
		const_iterator	begin(void) const{return (const_iterator(_tree.begin()));}
		
		iterator 		end(void){return (iterator());}
		const_iterator	end(void) const {return (const_iterator());}

		//points to largest key !!
		reverse_iterator		rbegin(void) {return (reverse_iterator(_tree.rbegin()));}
		const_reverse_iterator	rbegin(void) const {return (const_reverse_iterator(_tree.rbegin()));}
		
		reverse_iterator 		rend(void) {return (reverse_iterator());}
		const_reverse_iterator	rend(void) const {return (const_reverse_iterator());}
		
		//Modifiers
		pair<iterator, bool>	insert(key_type const & key)
		{
			value_type	val = make_pair(key, true);
			iterator	in(find(val.first));
			
			if (in != iterator())
				return (make_pair(in, false));
			in = iterator(_tree.insert(val));
			return (make_pair(in, true));
		}

		iterator insert(iterator pos, const key_type& val)
		{
			if (pos != iterator())
				return (_tree.insert(make_pair(val, true)));
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
				insert(make_pair(k, mapped_type()));
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
				return (make_pair(lower_bound(key), upper_bound(key)));
		}

		allocator_type get_allocator() const
		{
				return (_alloc);
		}

};

} //end namespace

#endif
