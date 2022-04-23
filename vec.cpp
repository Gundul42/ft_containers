/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:05:20 by graja             #+#    #+#             */
/*   Updated: 2022/04/23 13:35:04 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	ft::vector<int>		a(10, 2);
	int					i = 0;

	std::cout << "Size: " << a.size() << " Capacity: " << a.capacity() << std::endl;

	ft::vector<int>		b(10, 2);
	std::cout << "Size: " << b.size() << " Capacity: " << b.capacity() << std::endl;

	return (0);
}
