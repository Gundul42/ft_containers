/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:39:48 by graja             #+#    #+#             */
/*   Updated: 2022/04/22 13:25:58 by graja            ###   ########.fr       */
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
	private:
			typedef T					value_type;
			typedef Container			container_type;
			typedef size_t				size_type;

			container_type		_data;

	public:
			
			//stack(void): _data() {}

			~stack(void)
			{
					_data.clear();
			}

			explicit stack(const container_type & ctnr = container_type()): _data(ctnr) {}

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
					_data.push(val);
			}

			template <class U, class Conti>
			friend bool operator== (const stack<U,Conti>& lhs, const stack<U,Conti>& rhs)
			{
					return (lhs._data == rhs._data);
			}

			template <class U, class Conti>
			friend bool operator!= (const stack<U,Conti>& lhs, const stack<U,Conti>& rhs)
			{
					return (lhs._data != rhs._data);
			}

			template <class U, class Conti>
			friend bool operator<  (const stack<U,Conti>& lhs, const stack<U,Conti>& rhs)
			{
					return (lhs._data < rhs._data);
			}

			template <class U, class Conti>
			friend bool operator<= (const stack<U,Conti>& lhs, const stack<U,Conti>& rhs)
			{
					return (lhs._data <= rhs._data);
			}

			template <class U, class Conti>
			friend bool operator>  (const stack<U,Conti>& lhs, const stack<U,Conti>& rhs)
			{
					return (lhs._data > rhs._data);
			}

			template <class U, class Conti>
			friend bool operator>= (const stack<U,Conti>& lhs, const stack<U,Conti>& rhs)
			{
					return (lhs._data >= rhs._data);
			}
};

} //end namespace

#endif
