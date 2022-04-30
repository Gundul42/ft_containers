/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setmain.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:22:52 by graja             #+#    #+#             */
/*   Updated: 2022/04/30 12:47:02 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "set.hpp"
#include "utility.hpp"

//#include <set>
//#include <iostream>
int	main(void)
{

	ft::set<int>					test;
	ft::set<int>::iterator			it;
	ft::set<int>::reverse_iterator			rit;

	test.insert(50);
	test.insert(20);
	test.insert(65);
	test.insert(15);
	test.insert(25);
	test.insert(55);
	test.insert(70);
	test.insert(14);
	test.erase(14);
	test.insert(80);
	test.insert(68);
	test.insert(90);
	test.insert(666);
	std::cout << "Size of container is " << test.size() << std::endl;
	it = test.begin();
	while (it != test.end())
	{
			std::cout << (*it) << ", ";
			it++;
	}
	ft::set<int>					s1(test);
	//s1 = test;
	if (s1 == test)
		std::cout << std::endl << "equal" << std::endl;
	std::cout << std::endl;
	rit = test.rbegin();
//			std::cout << (*rit) << ", ";
			/*
	while (rit != test.rend())
	{
			std::cout << (*rit).first << ", ";
			it++;
	}*/
	return (0);
}
