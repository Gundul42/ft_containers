/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmain.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:50:25 by graja             #+#    #+#             */
/*   Updated: 2022/04/18 14:23:51 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include "utility.hpp"

int	main(void)
{

	ft::map<int, int>	test;

	std::cout << "Is test empty ? : ";
      	if (test.empty())
	       std::cout << "true";
	else
	       std::cout << "false";
	std::cout << std::endl;
	std::cout << "Max_size = " << test.max_size() << std::endl;
	test.insert(ft::make_pair(1,1));
	std::cout << "Is test empty ? : ";
      	if (test.empty())
	       std::cout << "true";
	else
	       std::cout << "false";
	std::cout << std::endl;
	test.insert(ft::make_pair(50,1));
	test.insert(ft::make_pair(20,1));
	test.insert(ft::make_pair(65,1));
	test.insert(ft::make_pair(15,1));
	test.insert(ft::make_pair(25,1));
	test.insert(ft::make_pair(55,1));
	test.insert(ft::make_pair(70,1));
	test.insert(ft::make_pair(14,1));
	test.erase(14);
	test.insert(ft::make_pair(80,1));
	test.insert(ft::make_pair(68,1));
	test.insert(ft::make_pair(90,1));
	std::cout << test.size() << std::endl;

	return (0);
}
