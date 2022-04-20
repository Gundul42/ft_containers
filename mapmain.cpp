/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmain.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:50:25 by graja             #+#    #+#             */
/*   Updated: 2022/04/20 14:43:28 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include "utility.hpp"

int	main(void)
{

	ft::map<int, int>			test;
	ft::map<int, int>::iterator		it;
	ft::map<int, int>::reverse_iterator	itr;
	int					j = 0;

	std::cout << "Is test empty ? : ";
      	if (test.empty())
	       std::cout << "true";
	else
	       std::cout << "false";
	std::cout << std::endl;
	std::cout << "Max_size = " << test.max_size() << std::endl;
	//test.insert(ft::make_pair(1,11));
	std::cout << "Is test empty ? : ";
      	if (test.empty())
	       std::cout << "true";
	else
	       std::cout << "false";
	std::cout << std::endl;
	test.insert(ft::make_pair(50,1));
	test.insert(ft::make_pair(20,2));
	test.insert(ft::make_pair(65,3));
	test.insert(ft::make_pair(15,4));
	test.insert(ft::make_pair(25,5));
	test.insert(ft::make_pair(55,6));
	test.insert(ft::make_pair(70,7));
	test.insert(ft::make_pair(14,0));
	test.erase(14);
	test.insert(ft::make_pair(80,8));
	test.insert(ft::make_pair(68,9));
	test.insert(ft::make_pair(90,10));
	std::cout << test.size() << std::endl;
	it = test.begin();
	while (it != test.end())
	{
		std::cout << ++j << ") Value in iterator is : " << (*it).second << std::endl;
		it++;
	}
	j = test.size();
	itr = test.rbegin();
	while (itr != test.rend())
	{
		std::cout << j-- << ") Value in iterator is : " << (*itr).second << std::endl;
		itr++;
	}
	ft::map<int, int>		cpyme;
	cpyme = test;
	std::cout << "The copied container is of size : " << cpyme.size() << std::endl;
	it = cpyme.begin();
	while (it != cpyme.end())
	{
		std::cout << "Key : " << (*it).first << ", Value: " << (*it).second << std::endl;
		it++;
	}
	cpyme.swap(test);
	cpyme[90] = 666;
	cpyme[112];
	it = cpyme.begin();
	while (it != cpyme.end())
	{
		std::cout << "Key : " << (*it).first << ", Value: " << (*it).second << std::endl;
		it++;
	}
	return (0);
}
