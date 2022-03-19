/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:30:11 by graja             #+#    #+#             */
/*   Updated: 2022/03/19 18:55:47 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <iostream>
# include <stdexcept>
# include <memory>

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

		public:
			vector(void): _start(_alloc.allocate(1)), _finish(_start),
					_end_of_storage(_start) {}
			vector(size_t n): _start(_alloc.allocate(n)), _finish(_start + n),
					_end_of_storage(_start + n) {}
			vector(vector<T> const & cpy): _start(_alloc.allocate(cpy.capacity() + 1)),
				       	_finish(_start + cpy.size()),
					_end_of_storage(_start + cpy.capacity()) {*this = cpy;}
			~vector(void) {_alloc.deallocate(_start, _end_of_storage - _start);}

			vector<T> & operator=(vector<T> const & right)
			{
				size_t	i = 0;
				if (this->size() < right.size())
				{
					std::cout << "Realloc needed" << std::endl;
					return (*this);
				}
				while (i < right.size())
				{
					*(_start + i) = *(right._start + i);
					i++;
				}
				return (*this);
			}

			size_t	size(void) const {return (_finish - _start);}
			size_t	capacity(void) const {return (_end_of_storage - _start);}
			size_t	max_size(void) const {return (_alloc.max_size());}
			bool	empty(void) const {if (!this->size()) return (true);
					else return (false);}
			void	pop_back(void) {_finish--;}
			void	push_back(T data)
			{
				if (this->capacity() > this->size())
				{
					*_finish = data;
					_finish++;
				}
				else
					std::cout << "Realloc needed!" << std::endl;
			}

	};
}

#endif
