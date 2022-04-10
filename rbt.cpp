/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:50:25 by graja             #+#    #+#             */
/*   Updated: 2022/04/10 12:57:29 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.hpp"

int	main(void)
{

	ft::rbtree<int, int>	test;

	test.insert(ft::make_pair(1,1));
	test.insert(ft::make_pair(7,1));
	test.insert(ft::make_pair(9,1));
	test.insert(ft::make_pair(12,1));
	test.insert(ft::make_pair(10,1));
	/*
	test.insert(ft::make_pair(11,1));
	test.insert(ft::make_pair(0,1));
	test.insert(ft::make_pair(-50,1));
	*/
	test.print();

	return (0);
}
