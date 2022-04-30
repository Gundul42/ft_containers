/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:30:11 by graja             #+#    #+#             */
/*   Updated: 2022/04/30 16:03:54 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <iostream>
# include <stdexcept>
# include <memory>
# include "utility.hpp"
# include "vec_iterator.hpp"

namespace ft
{

template <typename T, typename Alloc = std::allocator<T> >
class vector
{
	public:
		typedef	T										value_type;
		typedef	std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef Alloc									allocator_type;
		typedef	value_type&								reference;
		typedef	const value_type&						const_reference;
		typedef typename Alloc::pointer					pointer;
		typedef typename Alloc::const_pointer			const_pointer;
		typedef V_iterator<value_type, false>			iterator;
		typedef V_iterator<value_type, true>			const_iterator;
		typedef V_reverse_iterator<value_type, false>	reverse_iterator;
		typedef V_reverse_iterator<value_type, true>	const_reverse_iterator;

	private:

		pointer		_start;
		size_type	_size;
		size_type	_end_of_storage;
		allocator_type	_alloc;

		void	_realloc(size_type newsize, size_type newcapacity)
		{
			pointer		_ns;
			size_type 	i = 0;

			_ns = _alloc.allocate(newcapacity);
			while (i < _size)
			{
				if (i < newsize)
					_alloc.construct(&_ns[i], _start[i]);
				_alloc.destroy(&_start[i]);
				i++;
			}
			_alloc.deallocate(_start, capacity());
			_start = _ns;
			_size = newsize;
			_end_of_storage = newcapacity;
		}

	public:


		explicit vector(const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			_start = _alloc.allocate(0);
			_size = 0;
			_end_of_storage = 0;
		}

		explicit vector(size_type n, const value_type & val = value_type(),
				const allocator_type & alloc = allocator_type())
		{
			_alloc = alloc;
			_start = _alloc.allocate(n);
			_size = n;
			_end_of_storage = n;

			size_type	i = 0;
			std::cout << "FILLER" << std::endl;

			while (i < n)
			{
				_alloc.construct(&_start[i], val);
				i++;
			}
		}

		template <class InputIterator>
         vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type())
		 {
			 _alloc = alloc;
			_start = _alloc.allocate(0);
			_size = 0;
			_end_of_storage = 0;

			this->insert(begin(), first, last);
		 }

		vector(vector const & cpy)
		{
				_alloc = cpy._alloc;
				_start = _alloc.allocate(cpy.size());
				_size = 0;
				_end_of_storage = 0;
				size_type	i = 0;
				
				reserve(cpy.size());
				while (i < cpy.size())
				{
						push_back(cpy[i]);
						i++;
				}
		}

		//destructor
		~vector(void) 
		{
			clear();
			_alloc.deallocate(_start, capacity());
		}

		vector & operator=(vector const & right)
		{
			size_type	i = 0;
			
			_realloc(right.size(), right.size());
			_size = right.size();
			while (i < right.size())
			{
				*(_start + i) = *(right._start + i);
				i++;
			}
			return (*this);
		}

		//Capacity member functions
		size_type	size(void) const {return (_size);}
		size_type	max_size(void) const {return (_alloc.max_size());}
		void		resize(size_type n, value_type val = value_type())
	       	{
			size_type	i = size();

			if (n < size())
			{
				_realloc(n, capacity());
				return ;
			}
			else if (n > capacity())
			{
					if (n > size() * 2)
						_realloc(n, n);
					else
						_realloc(n, size() * 2);
			}
			_size = n;
			while (i < n)
			{
				_alloc.construct(&_start[i], val);
				i++;
			}
		}
		size_type	capacity(void) const {return (_end_of_storage);}
		bool		empty(void) const {return (size() == 0);}
		void		reserve(size_type n)
		{
			if (!n || n <= capacity())
				return ;
			if (n > max_size())
				throw std::length_error("Out of bounds");
			_realloc(size(), n);
		}
	

		// Element access member functions
		reference	operator[](size_type n)
		{
			return (*(this->_start + n));
		}
		
		const_reference	operator[](size_type n) const
		{
			return (*(this->_start + n));
		}

		reference	at(size_type n)
		{
			if (!size() || n > (this->size() - 1))
				throw std::out_of_range("Index out of range");
			else
				return (_start[n]);
		}

		const_reference	at(size_type n) const
		{
			if (!size() || n > (this->size() - 1))
				throw std::out_of_range("Index out of range");
			else
				return (_start[n]);
		}

		reference		front(void) {return (*(this->_start));}
		const_reference	front(void) const  {return (*(this->_start));}

		reference		back(void) {return ((_start[size() - 1]));}
		const_reference	back(void) const  {return ((_start[size() - 1]));}


		//Modifiers member functions	
		void		pop_back(void) 
		{
			_alloc.destroy(_start + _size - 1);
			_size--;
		}

		void		push_back(const value_type & data)
		{
			size_type		newsize = size();

			if (newsize == 0)
					newsize = 1;
			else
					newsize *= 2;
			if (this->capacity() == this->size())
				_realloc(this->size(), newsize);
			_alloc.construct(_start + _size,  data);
			_size++;
		}

		void		swap(vector<T> & swp)
		{
			vector<T>	tmp(*this);

			*this = swp;
			swp = tmp;
		}

		void		clear(void) {_realloc(0, capacity());}


		//Allocator member function
		allocator_type	get_allocator() const {return (_alloc);}


		iterator		begin(void) {return (iterator(_start));}
		const_iterator	begin(void) const {return (const_iterator(_start));}

		iterator			end(void) {return (iterator(_start + _size));}
		const_iterator		end(void) const {return (const_iterator(_start + _size));}

		reverse_iterator	rbegin(void) {return (reverse_iterator(_start + _size - 1));}
		const_reverse_iterator	rbegin(void) const 
			{return (const_reverse_iterator(_start + _size - 1));}
		
		reverse_iterator	rend(void) {return (reverse_iterator(_start - 1));}
		const_reverse_iterator	rend(void) const {return (const_reverse_iterator(_start - 1));}

		//Modifiers member functions with iterators
		iterator	erase(iterator pos)
		{
			iterator	tmp(pos);

			_alloc.destroy(&(*pos));
			while ((pos + 1) != end())
			{
				_alloc.construct(&(*pos), *(pos + 1));
				_alloc.destroy(&(*(pos + 1)));
				pos++;
			}
			_size--;
			return (tmp);
		}

		iterator	erase(iterator first, iterator last)
		{
			iterator	start = first;
			iterator	fin = last;

			while (first != last)
			{
				_alloc.destroy(&(*first));
				first++;
			}
			first = start;
			while (last != end())
			{
				_alloc.construct(&(*first), *last);
				first++;
				last++;
			}
			_size -= fin - start;
			return (fin);
		}

		iterator	insert(iterator pos, const value_type& val)
		{
			size_type	n = pos - begin();
			insert (pos, 1, val);
			return (begin() + n);
		}

		void	insert(iterator pos, size_type n, const value_type& val)
		{
			iterator	last;
			size_type	stp = pos - begin();
			size_type	i = 0;

			if (this->capacity() < this->size() + n)
				_realloc(size(), n + 1 );
			last = this->end();
			while (last != (begin() + stp))
			{
				_alloc.construct(&(*(last + n)), *last);
				_alloc.destroy(&(*last));
				last--;
			}
			_alloc.construct(&(*(last + n)), *last);
			while (i < n)
			{
				_alloc.construct(&(*(begin() + stp + i)), val);
				i++;
			}
			_size += n;
			_end_of_storage--;	
		}

		template <typename InputIterator>
		void insert (iterator pos, InputIterator ifirst, InputIterator ilast, 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
		{
			size_type	n = ilast - ifirst;
			iterator	last;
			size_type	stp = pos - begin();
			size_type	i = 0;
			size_type	newsize = this->size();

			if (newsize == 0)
					newsize = n;
			else
					newsize += n;
			if (this->capacity() < stp + n)
				_realloc(this->size(), newsize);
			last = this->end();
			while (last != (begin() + stp))
			{
				_alloc.construct(&(*(last + n)), *last);
				_alloc.destroy(&(*last));
				last--;
			}
			_alloc.construct(&(*(last + n)), *last);
			while (i < n)
			{
				_alloc.construct(&(*(begin() + stp + i)), *ifirst);
				ifirst++;
				i++;
			}
			_size += n;
		}

		void	assign (size_type n, const value_type& val)
		{
			size_type	i = 0;

			_realloc(n, n * 2);
			while (i < n)
			{
				_alloc.construct(_start + i, val);
				i++;
			}
		}

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
		{
			size_type	n = last - first;
			size_type	i = 0;

			_realloc(n, n * 2);
			while (first != last)
			{
				_alloc.construct(_start + i, *first);
				i++;
				first++;
			}
		}

}; //end class
	
		//nonmember relational operators
		template <typename U, typename A>
		bool	operator== (const vector<U,A> & lhs, const vector<U,A> & rhs)
		{
		//	vector<T>	lcpy(lhs);
		//	vector<T>	rcpy(rhs);

		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}
		
		template <typename U, typename A>
		bool	operator!= (const vector<U,A> & lhs, const vector<U,A> & rhs)
		{
		return (!(lhs == rhs));
		}
	
		template <typename U, typename A>
		bool	operator<(const vector<U,A> & lhs, const vector<U,A> & rhs)
		{
			//vector<T>	lcpy(lhs);
			//vector<T>	rcpy(rhs);

			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template <typename U, typename A>
		bool	operator>(const vector<U,A> & lhs, const vector<U,A> & rhs)
		{
			return (!(lhs <= rhs));
		}
		
		template <typename U, typename A>
		bool	operator>=(const vector<U,A> & lhs, const vector<U,A> & rhs)
		{
				return (rhs < lhs);
		}
		
		template <typename U, typename A>
		bool 	operator<= (const vector<U,A> & lhs, const vector<U,A> & rhs)
                {
			//vector<T>	lcpy(lhs);
			//vector<T>	rcpy(rhs);

			if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
				return (true);
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
						rhs.begin(), rhs.end()));
		}
	


} //end namespace

#endif
