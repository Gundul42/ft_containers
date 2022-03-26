/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:50:25 by graja             #+#    #+#             */
/*   Updated: 2022/03/26 12:35:36 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "mclass.hpp"
#include <vector>

typedef	struct	s_lala {
	int	start;
	int	end;
	char	flag;
	char	names[1024];
}	t_lala;

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
	ft::vector<t_lala>	t;
	ft::vector<Mclass>	segf;
	ft::vector<float>	d(0);
	std::vector<float>	b(10);
	std::vector<float>	c(20);
	ft::vector<float>::iterator	it;
	t_lala			neu;
	Mclass			tes;

	neu.start = 10;
	neu.end = 20;
	neu.flag = 'P';

	//t.push_back(neu);
	segf.push_back(tes);
	std::cout << "Size of t: " << segf.size() << " value of flag : " << segf[0].getFlag() << std::endl;
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
