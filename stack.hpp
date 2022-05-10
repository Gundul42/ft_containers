/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:39:48 by graja             #+#    #+#             */
/*   Updated: 2022/05/10 09:44:58 by graja            ###   ########.fr       */
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
				*this = cpy;
			}

			stack & operator=(stack const & right)
			{
					size_type	i = 0;

					this->c.clear();
					while (i < right.size())
					{
							this->c.push_back(right.c[i]);
							i++;
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
			
			void	pop(void)
			{
					c.pop_back();
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

			friend bool operator< (const stack & lhs, const stack & rhs)
			{
					return (lhs.c < rhs.c);
			}

			friend bool operator> (const stack & lhs, const stack & rhs)
			{
					return !(operator<(lhs, rhs));
			}

			friend bool operator>= (const stack & lhs, const stack & rhs)
			{
					return (lhs.c >= rhs.c);
			}

			friend bool operator<= (const stack & lhs, const stack & rhs)
			{
					return (!(operator<(rhs.c, lhs.c)));
			}

};
} //end namespace

#endif
