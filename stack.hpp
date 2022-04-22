/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:39:48 by graja             #+#    #+#             */
/*   Updated: 2022/04/22 14:37:24 by graja            ###   ########.fr       */
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

	protected:
			container_type		c;

	public:
	
			stack(stack const & cpy)
			{
					typename container_type::iterator	in;
				
					in = cpy.begin();
					while (in != cpy.end())
					{
							c.push_back(*in);
							in++;
					}
			}

			stack & operator=(stack const & right)
			{
					typename container_type::iterator	in;

					this->c.clear();
					in = right.begin();
					while (in != right.end())
					{
							this->c.push_back(*in);
							in++;
					}
					return (*this);
			}

			~stack(void)
			{
					c.clear();
			}

			explicit stack(const container_type & ctr = container_type()): c(ctr) {}

			bool	empty(void) const
			{
					return (c.empty());
			}

			size_type	size(void) const
			{
					return (c.size());
			}

			value_type &	top(void)
			{
					return (c.back());
			}
			
			const value_type &	top(void) const
			{
					return (c.back());
			}

			void	push(value_type const & val)
			{
					c.push_back(val);
			}

			friend bool operator== (const stack & lhs, const stack & rhs)
			{
					return (lhs.c == rhs.c);
			}

			friend bool operator!= (const stack & lhs, const stack & rhs)
			{
					return (lhs.c != rhs.c);
			}

			friend bool operator<  (const stack & lhs, const stack & rhs)
			{
					return (lhs.c < rhs.c);
			}

			friend bool operator<= (const stack & lhs, const stack & rhs)
			{
					return (lhs.c <= rhs.c);
			}

			friend bool operator>  (const stack & lhs, const stack & rhs)
			{
					return (lhs.c > rhs.c);
			}

			friend bool operator>= (const stack & lhs, const stack & rhs)
			{
					return (lhs.c >= rhs.c);
			}
};

} //end namespace

#endif
