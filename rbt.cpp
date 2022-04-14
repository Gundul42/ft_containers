/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:50:25 by graja             #+#    #+#             */
/*   Updated: 2022/04/14 18:18:54 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBtree.hpp"
#include "mclass.hpp"

int	main(void)
{

	ft::RBtree<int, int>	test;
	int			key = 31;

	test.insert(50,1);
	test.insert(20,1);
	test.insert(65,1);
	test.insert(15,1);
	test.insert(25,1);
	test.insert(55,1);
	test.insert(70,1);
	test.insert(14,1);
	test.erase(14);
	test.insert(80,1);
	test.insert(68,1);
	test.insert(90,1);

//	test.print();
/*	
	test.insert(10,1);
	test.insert(18,1);
	test.insert(7,1);
	test.insert(15,1);
	test.insert(16,1);
	test.insert(30,1);
	test.insert(25,1);
	test.insert(40,1);
	test.insert(60,1);
	test.insert(2,1);
	test.insert(1,1);
	test.insert(70,1);
	test.insert(5,1);
	test.insert(6,1);
	test.insert(4,1);
	test.insert(21,1);
	test.insert(19,1);
	std::cout << "Size is " << test.size() << std::endl;

	test.insert(40,1);
	std::cout << "Size is " << test.size() << std::endl;

	test.erase(16);
	std::cout << "Size is " << test.size() << std::endl;
	test.insert(18, 1);
	std::cout << "Size is " << test.size() << std::endl;

	if (test.find(key))
	{
		std::cout << std::endl << ">>> Was found" << std::endl << std::endl;
		test.print(test.find(key));
	}
	else
		std::cout << std::endl << ">>> Was NOT found" << std::endl << std::endl;
	test.print();
	*/
	return (0);
}
