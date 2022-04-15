/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:50:25 by graja             #+#    #+#             */
/*   Updated: 2022/04/15 13:49:03 by graja            ###   ########.fr       */
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

	test.erase(55);
	test.print();
	test.erase(20);
	test.print();
	test.erase(90);
	test.print();
	test.erase(80);
	test.print();
	return (0);
}
