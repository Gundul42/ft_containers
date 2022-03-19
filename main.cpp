/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:50:25 by graja             #+#    #+#             */
/*   Updated: 2022/03/19 18:55:29 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

int main(void)
{
	ft::vector<float>	a(2);
	ft::vector<float>	d(a);
	std::vector<float>	b(10);
	std::vector<float>	c(20);
	std::vector<float>::iterator	it;


	std::cout << "size = " << a.size() << " -- capacity = " << a.capacity();
	std::cout << " -- empty = " << a.empty() << " -- max_size = " << a.max_size();
	std::cout << std::endl;
	a.push_back(100);
	//d = a;
	std::cout << "size = " << d.size() << " -- capacity = " << d.capacity();
	std::cout << " -- empty = " << d.empty() << " -- max_size = " << d.max_size();
	std::cout << std::endl;
	/*
	std::cout << "size = " << b.size() << " -- capacity = " << b.capacity();
	std::cout << " -- empty = " << b.empty() << " -- max_size = " << b.max_size();
	std::cout << std::endl;
	b.push_back(-120);
	std::cout << "size = " << b.size() << " -- capacity = " << b.capacity();
	std::cout << " -- empty = " << b.empty() << " -- max_size = " << b.max_size();
	std::cout << std::endl;
	std::cout << "size = " << c.size() << " -- capacity = " << c.capacity();
	std::cout << " -- empty = " << c.empty() << " -- max_size = " << c.max_size();
	std::cout << std::endl;
	c = b;
	std::cout << "size = " << c.size() << " -- capacity = " << c.capacity();
	std::cout << " -- empty = " << c.empty() << " -- max_size = " << c.max_size();
	std::cout << std::endl;
	it = b.begin();
	while ( it != b.end())
	{
		std::cout << *it << std::endl;
		it++;
	}*/
	return (0);
}
