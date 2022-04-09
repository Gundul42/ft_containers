/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:50:25 by graja             #+#    #+#             */
/*   Updated: 2022/04/09 15:59:57 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.hpp"

int	main(void)
{

	ft::rbtree<int, int>	test;

	std::cout << "Is test empty ? : ";
      	if (test.empty())
	       std::cout << "true";
	else
	       std::cout << "false";
	std::cout << std::endl;
	test.insert(ft::make_pair(1,1));
	std::cout << "Is test empty ? : ";
      	if (test.empty())
	       std::cout << "true";
	else
	       std::cout << "false";
	std::cout << std::endl;
	test.insert(ft::make_pair(7,1));
	std::cout << "Size is : " << test.size() << std::endl;
	test.insert(ft::make_pair(9,1));
	std::cout << "Size is : " << test.size() << std::endl;
	test.insert(ft::make_pair(12,1));
	std::cout << "Size is : " << test.size() << std::endl;
	test.insert(ft::make_pair(10,1));
	std::cout << "Size is : " << test.size() << std::endl;
	test.insert(ft::make_pair(11,1));
	std::cout << "Size is : " << test.size() << std::endl;
	test.insert(ft::make_pair(0,1));
	std::cout << "Size is : " << test.size() << std::endl;
	test.insert(ft::make_pair(-50,1));
	std::cout << "Size is : " << test.size() << std::endl;

	return (0);
}
