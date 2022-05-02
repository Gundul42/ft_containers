/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setmain.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:22:52 by graja             #+#    #+#             */
/*   Updated: 2022/05/02 12:15:00 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "set.hpp"
#include "utility.hpp"
#include <string>

//#include <set>
//#include <iostream>
int	main(void)
{

	ft::set<int>					test;
	ft::set<int>::iterator			it;
	ft::set<int>::reverse_iterator			rit;
	ft::set<int>					s1;
	ft::set<int>::iterator			s1it;

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
//	ft::set<int>					s1(test);
	s1 = test;
	if (s1 == test)
		std::cout << std::endl << "equal" << std::endl;
	std::cout << std::endl;
	rit = test.rbegin();
	while (rit != test.rend())
	{
			std::cout << (*rit) << ", ";
			rit++;
	}
	std::cout << std::endl;
	rit = test.rbegin();
	//*rit = 129;
	return (0);
}
