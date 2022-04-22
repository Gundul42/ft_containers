/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:39:48 by graja             #+#    #+#             */
/*   Updated: 2022/04/22 14:16:04 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "vector.hpp"

namespace ft
{

template <typename T, typename Container = vector<T> >
class stack
{
	public:
			typedef T					value_type;
			typedef Container			container_type;
			typedef size_t				size_type;

	private:
			container_type		_data;

	public:
	
			stack(stack const & cpy)
			{
					typename container_type::iterator	in;
				
					in = cpy.begin();
					while (in != cpy.end())
					{
							_data.push_back(*in);
							in++;
					}
			}

			stack & operator=(stack const & right)
			{
					typename container_type::iterator	in;

					this->_data.clear();
					in = right.begin();
					while (in != right.end())
					{
							this->_data.push_back(*in);
							in++;
					}
					return (*this);
			}

			~stack(void)
			{
					_data.clear();
			}

			explicit stack(const container_type & ctr = container_type()): _data(ctr) {}

			bool	empty(void) const
			{
					return (_data.empty());
			}

			size_type	size(void) const
			{
					return (_data.size());
			}

			value_type &	top(void)
			{
					return (_data.back());
			}
			
			const value_type &	top(void) const
			{
					return (_data.back());
			}

			void	push(value_type const & val)
			{
					_data.push_back(val);
			}

			friend bool operator== (const stack & lhs, const stack & rhs)
			{
					return (lhs._data == rhs._data);
			}

			friend bool operator!= (const stack & lhs, const stack & rhs)
			{
					return (lhs._data != rhs._data);
			}

			friend bool operator<  (const stack & lhs, const stack & rhs)
			{
					return (lhs._data < rhs._data);
			}

			friend bool operator<= (const stack & lhs, const stack & rhs)
			{
					return (lhs._data <= rhs._data);
			}

			friend bool operator>  (const stack & lhs, const stack & rhs)
			{
					return (lhs._data > rhs._data);
			}

			friend bool operator>= (const stack & lhs, const stack & rhs)
			{
					return (lhs._data >= rhs._data);
			}
};

} //end namespace

#endif
