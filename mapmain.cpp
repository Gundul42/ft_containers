/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmain.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:50:25 by graja             #+#    #+#             */
/*   Updated: 2022/04/24 11:06:26 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include "utility.hpp"

int	main(void)
{

	ft::map<int, int>			test;
	ft::map<int, int>			test2;
	ft::map<int, int>::iterator		it;
	test.insert(ft::make_pair(50,1));
	test.insert(ft::make_pair(20,2));
	
	test2.insert(ft::make_pair(65,3));
	test2.insert(ft::make_pair(15,4));
	test2.insert(ft::make_pair(25,5));
	/*
	test.insert(ft::make_pair(55,6));
	test.insert(ft::make_pair(70,7));
	test.insert(ft::make_pair(14,0));
	test.erase(14);
	test.insert(ft::make_pair(80,8));
	test.insert(ft::make_pair(68,9));
	test.insert(ft::make_pair(90,10));
	*/
	
	std::cout << "----- Original -----" << std::endl;
	
	it = test.begin();
	while (it != test.end())
	{
			std::cout << (*it).first << ", " << (*it).second << std::endl;
			it++;
	}

	std::cout << "-----" << std::endl;
	it = test2.begin();
	while (it != test2.end())
	{
			std::cout << (*it).first << ", " << (*it).second << std::endl;
			it++;
	}

	test.swap(test2);
	std::cout << "----- Swapped -----" << std::endl;
	
	it = test.begin();
	while (it != test.end())
	{
			std::cout << (*it).first << ", " << (*it).second << std::endl;
			it++;
	}

	std::cout << "-----" << std::endl;
	it = test2.begin();
	while (it != test2.end())
	{
			std::cout << (*it).first << ", " << (*it).second << std::endl;
			it++;
	}
	return (0);
}
