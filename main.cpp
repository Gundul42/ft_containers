/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:50:25 by graja             #+#    #+#             */
/*   Updated: 2022/03/22 15:16:19 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

static
void	vprint(ft::vector<float> tmp)
{
	size_t	i = 0;

	while (i < tmp.size())
	{
		std::cout << tmp[i] << ", ";
		i++;
	}
	std::cout << std::endl;
}

int main(void)
{
	ft::vector<float>	a(2);
	ft::vector<float>	d(0);
	std::vector<float>	b(10);
	std::vector<float>	c(20);
	ft::vector<float>::iterator	it;


	std::cout << "size = " << a.size() << " -- capacity = " << a.capacity();
	std::cout << " -- empty = " << a.empty() << " -- max_size = " << a.max_size();
	std::cout << std::endl;
	a.push_back(100);
	a.push_back(11);
	a.push_back(-32511);
	it = a.begin();
	std::cout << "ITERATORS:" << std::endl;
	while (it != a.end())
	{
		std::cout << *it << " -- ";
		it++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	vprint(a);
	d = a;
	d[0] = -1213;
	std::cout << "size = " << d.size() << " -- capacity = " << d.capacity();
	std::cout << " -- empty = " << d.empty() << " -- max_size = " << d.max_size();
	std::cout << std::endl;
	vprint(d);
	d.pop_back();
	d.reserve(100);
	vprint(d);
	d.resize(1, 666);
	vprint(d);
	std::cout << "size = " << d.size() << " -- capacity = " << d.capacity();
	std::cout << " -- empty = " << d.empty() << " -- max_size = " << d.max_size();
	std::cout << std::endl;
	std::cout << "size = " << a.size() << " -- capacity = " << a.capacity();
	std::cout << " -- empty = " << a.empty() << " -- max_size = " << a.max_size();
	std::cout << std::endl;
	std::cout << d.front() << " : " << d.back() <<  " : " << d[20] << std::endl;
	d.swap(a);
	std::cout << "size = " << d.size() << " -- capacity = " << d.capacity();
	std::cout << " -- empty = " << d.empty() << " -- max_size = " << d.max_size();
	std::cout << std::endl;
	std::cout << "size = " << a.size() << " -- capacity = " << a.capacity();
	std::cout << " -- empty = " << a.empty() << " -- max_size = " << a.max_size();
	std::cout << std::endl;
	std::cout << d.front() << " : " << d.back() <<  " : " << d[1] << std::endl;
	std::cout << a.front() << " : " << a.back() <<  " : " << a[1] << std::endl;
	d.clear();
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
