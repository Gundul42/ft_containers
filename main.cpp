/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:50:25 by graja             #+#    #+#             */
/*   Updated: 2022/04/01 11:17:10 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "mclass.hpp"
#include <vector>

typedef	struct	s_lala {
	int	start;
	int	end;
	char	flag;
	char	names[100];
}	t_lala;

static
void	vprint(ft::vector<float> tmp)
{
	ft::vector<float>::iterator	it;

	it = tmp.begin();
	while (it != tmp.end())
	{
		std::cout << *it << ", ";
		it++;
	}
	std::cout << std::endl;
}

int main(void)
{
	/*
	ft::vector<t_lala>	a(2);
	t_lala			lala;
	Mclass			test;
	ft::vector<Mclass>	yeah(1);

	yeah.push_back(test);

	lala.start = 10;
	lala.end = 20;
	lala.flag = 'd';

	std::cout << test.getStart() << ", " << test.getEnd() << ", " << test.getFlag() << std::endl;
	std::cout << yeah[1].getStart() << ", " << yeah[1].getEnd() << ", " << yeah[1].getFlag() << std::endl;
	std::cout << "size is " << a.size() << std::endl;
	a[0] = lala;

	a.push_back(lala);

	std::cout << "size is " << a.size() << std::endl;
	std::cout << "Flag is " << a[2].flag << std::endl;


	*/
	ft::vector<float>	a(2,10.10);
	ft::vector<float>	d;
	ft::vector<t_lala>	t(1);
	Mclass			tes;
	ft::vector<Mclass>	segf(2);
	//ft::vector<float>	d(0);
	//std::vector<float>	b(10);
	//std::vector<float>	c(20);
	ft::vector<float>::iterator	it;
	
	t_lala			neu;

	neu.start = 100;
	neu.end = 200;
	neu.flag = 'R';

	t.push_back(neu);
	segf.push_back(tes);
	std::cout << "Size of segf: " << segf.size() << " value of flag : " << segf[0].getFlag() << std::endl;
	std::cout << "size = " << a.size() << " -- capacity = " << a.capacity();
	std::cout << " -- empty = " << a.empty() << " -- max_size = " << a.max_size();
	std::cout << std::endl;
	
	std::cout << "size = " << d.size() << " -- capacity = " << d.capacity();
	std::cout << " -- empty = " << d.empty() << " -- max_size = " << d.max_size();
	std::cout << std::endl;

	a.push_back(100);
	a.push_back(11);
	a.push_back(-32511);
	
	it = a.begin();
	std::cout << "ITERATORS:" << std::endl;
	while (it != a.end())
	{
		std::cout << *it << " -- ";
		it = 1 + it;
	}
	std::cout << std::endl;
	it = a.begin();
	std::cout << "by [] overload #4 : " << it[4] << std::endl;
	std::cout << std::endl;
	
	//vprint(a);
	d = a;
	d[0] = -1213;
	std::cout << "size = " << d.size() << " -- capacity = " << d.capacity();
	std::cout << " -- empty = " << d.empty() << " -- max_size = " << d.max_size();
	std::cout << std::endl;
	//vprint(d);
	d.pop_back();
	d.reserve(100);
	//vprint(d);
	d.resize(20, 666);
	//vprint(d);
	std::cout << "size = " << d.size() << " -- capacity = " << d.capacity();
	std::cout << " -- empty = " << d.empty() << " -- max_size = " << d.max_size();
	std::cout << std::endl;
	std::cout << "size = " << a.size() << " -- capacity = " << a.capacity();
	std::cout << " -- empty = " << a.empty() << " -- max_size = " << a.max_size();
	std::cout << std::endl;
	/*
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
