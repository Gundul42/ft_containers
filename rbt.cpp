/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:50:25 by graja             #+#    #+#             */
/*   Updated: 2022/04/10 19:06:38 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.hpp"

int	main(void)
{

	ft::rbtree<int, int>	test;

	test.insert(ft::make_pair(1,1));
	test.insert(ft::make_pair(2,1));
	test.insert(ft::make_pair(3,1));
	test.insert(ft::make_pair(4,1));
	test.insert(ft::make_pair(5,1));
	test.insert(ft::make_pair(6,1));
	test.insert(ft::make_pair(7,1));
	/*
	test.insert(ft::make_pair(-50,1));
	*/
	test.print();

	return (0);
}
