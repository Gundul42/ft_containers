/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:30:11 by graja             #+#    #+#             */
/*   Updated: 2022/03/21 15:54:23 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <iostream>
# include <stdexcept>
# include <memory>
# include <iterator>

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
		private:
			T	*_start;
			T	*_finish;
			T	*_end_of_storage;
			Alloc	_alloc;

			typedef	std::size_t				size_type;
			typedef std::ptrdiff_t				difference_type;

			void	_realloc(size_type newsize, size_type newcapacity)
			{
				T		*_ns;
				difference_type	i = 0;

				_ns = _alloc.allocate(newcapacity);
				while (i < _finish - _start)
				{
					_ns[i] = _start[i];
					i++;
				}
				_alloc.deallocate(_start, _end_of_storage - _start);
				_start = _ns;
				_finish = _start + newsize;
				_end_of_storage = _start + newcapacity;
			}

		public:
			typedef	T					value_type;
			typedef Alloc					allocator_type;
			typedef	value_type&				reference;
			typedef	const value_type&			const_reference;
			typedef typename Alloc::pointer			pointer;
			typedef typename Alloc::const_pointer		const_pointer;
			/*
			typedef 		iterator;
			typedef 		const_iterator;
			typedef			reverse_iterator;
			typedef			const_reverse_iterator;
			*/


			vector(void): _start(_alloc.allocate(1)), _finish(_start),
					_end_of_storage(_start) {}
			vector(size_type n): _start(_alloc.allocate(n)), _finish(_start + n),
					_end_of_storage(_start + n) {}
			vector(vector<T> const & cpy): _start(_alloc.allocate(cpy.capacity() + 1)),
				       	_finish(_start + cpy.size()),
					_end_of_storage(_start + cpy.capacity()) {*this = cpy;}
			~vector(void) {_alloc.deallocate(_start, _end_of_storage - _start);}

			vector<T> & operator=(vector<T> const & right)
			{
				size_type	i = 0;
				if (this->size() < right.size())
				{
					_realloc(right.size(), right.capacity());
				}
				while (i < right.size())
				{
					*(_start + i) = *(right._start + i);
					i++;
				}
				return (*this);
			}

			size_type	size(void) const {return (_finish - _start);}
			size_type	capacity(void) const {return (_end_of_storage - _start);}
			size_type	max_size(void) const {return (_alloc.max_size());}
			bool		empty(void) const {if (!this->size()) return (true);
						else return (false);}
			void		pop_back(void) {_finish--;}
			void		push_back(T data)
			{
				if (this->capacity() == this->size())
					_realloc(this->size(), this->size() * 2);
				*_finish = data;
				_finish++;
			}
		

			// Capacity member functions	
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
				if (n < 0 || n > this->size())
					throw std::out_of_range("Index out of range");
				else
					return (_start[n]);
			}

			T const &	at(size_type n) const
			{
				if (n < 0 || n > this->size())
					throw std::out_of_range("Index out of range");
				else
					return (_start[n]);
			}

			T &		front(void) {return (*(this->_start));}
			T const &	front(void) const  {return (*(this->_start));}

			T &		back(void) {return ((_start[size() - 1]));}
			T const &	back(void) const  {return ((this[size() - 1]));}
			
	};
}

#endif
