/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:50:25 by graja             #+#    #+#             */
/*   Updated: 2022/04/13 12:16:40 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.hpp"
#include "mclass.hpp"

int	main(void)
{

	ft::rbtree<int, int>	test;
	int			key = 31;
	
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

	if (test.find(key))
	{
		std::cout << std::endl << ">>> Was found" << std::endl << std::endl;
		test.print(test.find(key));
	}
	else
		std::cout << std::endl << ">>> Was NOT found" << std::endl << std::endl;
	return (0);
}
