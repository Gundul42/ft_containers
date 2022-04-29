/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstmain.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:22:52 by graja             #+#    #+#             */
/*   Updated: 2022/04/28 19:01:17 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "vector.hpp"
#include "utility.hpp"

//#include <set>
//#include <iostream>
int	main(void)
{

	ft::vector<int>					test;
	ft::vector<int>::iterator			it;

	test.push_back(50);
	test.push_back(20);
	test.push_back(65);
	test.push_back(15);
	test.push_back(25);
	test.push_back(55);
	test.push_back(70);
	test.push_back(14);
	//test.erase(14);
	test.push_back(80);
	test.push_back(68);
	test.push_back(90);
	test.push_back(666);
	std::cout << "Size of container is " << test.size() << std::endl;
	it = test.begin();
	while (it != test.end())
	{
			std::cout << *it << ", ";
			it++;
	}
	ft::vector<int>					s1;
	s1 = test;
	//s1 = test;
	if (s1 == test)
		std::cout << std::endl << "equal" << std::endl;
	std::cout << std::endl;
	return (0);
}
