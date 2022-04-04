/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:30:11 by graja             #+#    #+#             */
/*   Updated: 2022/04/04 09:28:42 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <iostream>
# include <stdexcept>
# include <memory>
# include "iterator.hpp"

namespace ft
{

template <typename T, typename Alloc = std::allocator<T> >
class vector
{
	private:
		typedef	T					value_type;
		typedef	std::size_t				size_type;
		typedef std::ptrdiff_t				difference_type;
		typedef Alloc					allocator_type;
		typedef	value_type&				reference;
		typedef	const value_type&			const_reference;
		typedef typename Alloc::pointer			pointer;
		typedef typename Alloc::const_pointer		const_pointer;

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

		explicit vector(const allocator_type& alloc = allocator_type()): 
			_start(_alloc.allocate(0)), _size(0), _end_of_storage(0) {}

		explicit vector(size_type n, const value_type & val = value_type(),
				const allocator_type & alloc = allocator_type()):
				_start(_alloc.allocate(n)), _size(n),
				_end_of_storage(n) 
		{
			size_type	i = 0;

			while (i < n)
			{
				_alloc.construct(&_start[i], val);
				i++;
			}
		}

		vector(vector const & cpy): _start(_alloc.allocate(cpy.capacity())),
			       	_size(cpy.size()),
				_end_of_storage(cpy.capacity()) {*this = cpy;}
		~vector(void) 
		{
			size_type	i = 0;
			
			while (i < size())
			{
				_alloc.destroy(_start + i);
				i++;
			}
			_alloc.deallocate(_start, capacity());
		}

		vector<T> & operator=(vector<T> const & right)
		{
			size_type	i = 0;
			std::cout << "Copy construction" << std::endl;
			std::cout << "This: " << this->size() << "   right: " << right.size() << std::endl;
			if (this->size() < right.size())
			{
				_realloc(right.size(), right.capacity());
			}
			std::cout << std::endl;
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

			std::cout << "!!!>>> resize: " << size() << ", newsize: " << n << std::endl;

			if (n < size())
			{
				_realloc(n, n);
				return ;
			}
			else if (n > capacity())
				_realloc(size(), n);
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
		T &	operator[](size_type n)
		{
			return (*(this->_start + n));
		}
		
		T const &	operator[](size_type n) const
		{
			return (*(this->_start + n));
		}

		T &	at(size_type n)
		{
			if (!size() || n > (this->size() - 1))
				throw std::out_of_range("Index out of range");
			else
				return (_start[n]);
		}

		T const &	at(size_type n) const
		{
			if (!size() || n > (this->size() - 1))
				throw std::out_of_range("Index out of range");
			else
				return (_start[n]);
		}

		T &		front(void) {return (*(this->_start));}
		T const &	front(void) const  {return (*(this->_start));}

		T &		back(void) {return ((_start[size() - 1]));}
		T const &	back(void) const  {return ((_start[size() - 1]));}


		//Modifiers member functions	
		void		pop_back(void) 
		{
			_alloc.destroy(_start + _size - 1);
			_size--;
		}

		void		push_back(const value_type & data)
		{

			if (this->capacity() == this->size())
				_realloc(this->size(), 1 + this->size() * 2);
			_alloc.construct(_start + _size,  data);
			_size++;
		}

		void		swap(vector<T> & swp)
		{
			vector<T>	tmp(*this);

			*this = swp;
			swp = tmp;
		}
		void		clear(void) {_realloc(0,0);}


		//Allocator member function
		allocator_type	get_allocator() const {return (_alloc);}


		//Iterators

		class iterator : public ft::iterator<std::random_access_iterator_tag, value_type>
		{
			private:
				value_type	*_p;

			public:
				iterator(void) :_p(NULL) {}
				iterator(value_type *x) :_p(x) {}
				~iterator(void) {}

				iterator(const iterator & mit) : _p(mit._p) {}

				iterator & operator=(const iterator & right)
					{this->_p = right._p; return (*this);}

				iterator&	operator++() {++_p;return *this;}
				iterator	operator++(int) 
					{iterator tmp(*this); operator++(); return tmp;}
				iterator&	operator--() {--_p;return *this;}
				iterator	operator--(int) 
					{iterator tmp(*this); operator--(); return tmp;}
				iterator &	operator+=(const size_type n)
					{_p = _p + n; return (*this);}
				iterator &	operator-=(const size_type n)
					{_p = _p - n; return (*this);}
				iterator 	operator-(const size_type n)
					{
						iterator	tmp(this->_p);
						
						tmp._p = this->_p - n;
					       	return (tmp);
					}
				iterator 	operator+(const size_type n)
					{
						iterator	tmp(this->_p);
						
						tmp._p = this->_p + n;
					       	return (tmp);
					}
				difference_type	operator-(const iterator & right)
					{return (_p - right._p);}
				value_type	operator[](const size_type n)
					{return (*(_p + n));}
				bool	operator==(const iterator& rhs) const
					{return _p == rhs._p;}
				bool	operator!=(const iterator& rhs) const
					{return _p != rhs._p;}
				bool	operator>(const iterator& rhs) const
					{return _p > rhs._p;}
				bool	operator<(const iterator& rhs) const
					{return _p < rhs._p;}
				bool	operator>=(const iterator& rhs) const
					{return _p >= rhs._p;}
				bool	operator<=(const iterator& rhs) const
					{return _p <= rhs._p;}
				T &	operator*() {return *_p;}
				T &	operator->() {return *_p;}

				//non member overloads
				friend	iterator operator+(const size_type n, const iterator right)
				{
					iterator	tmp(right);

					tmp._p = right._p + n;
					return (tmp);
				}
				
				friend	iterator operator-(const size_type n, const iterator right)
				{
					iterator	tmp(right);

					tmp._p = right._p - n;
					return (tmp);
				}
				
		};

		iterator	begin(void) {return (iterator(_start));}
		iterator	end(void) {return (iterator(_start + _size));}

		//Modifiers member functions with iterators
		iterator	erase(iterator pos)
		{
			iterator	tmp = pos + 1;

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
				_realloc(this->size(), n + this->size() * 2);
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
		}

		template <typename InputIterator>
		void insert (iterator pos, InputIterator ifirst, InputIterator ilast)
		{
			size_type	n = ilast - ifirst;
			iterator	last;
			size_type	stp = pos - begin();
			size_type	i = 0;
			
			if (this->capacity() < this->size() + n)
				_realloc(this->size(), n + this->size() * 2);
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
				_alloc.construct(&(*(begin() + stp + i)), ifirst);
				ifirst++;
				i++;
			}
			_size += n;
		}


}; //end class


} //end namespace

#endif
