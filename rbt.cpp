/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:50:25 by graja             #+#    #+#             */
/*   Updated: 2022/04/12 13:17:03 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.hpp"

int	main(void)
{

	ft::rbtree<int, int>	test;
	
	test.insert(ft::make_pair(14,1));
	test.insert(ft::make_pair(10,1));
	test.insert(ft::make_pair(11,1));
/* this works
	test.insert(ft::make_pair(10,1));
	test.insert(ft::make_pair(14,1));
	test.insert(ft::make_pair(11,1));
	test.insert(ft::make_pair(50,1));
	test.insert(ft::make_pair(25,1));
	test.insert(ft::make_pair(20,1));
	test.insert(ft::make_pair(16,1));
	test.insert(ft::make_pair(100,1));
	test.insert(ft::make_pair(13,1));
*/
/* This works
	test.insert(ft::make_pair(8,1));
	test.insert(ft::make_pair(7,1));
	test.insert(ft::make_pair(6,1));
	test.insert(ft::make_pair(5,1));
	test.insert(ft::make_pair(4,1));
	test.insert(ft::make_pair(3,1));
	test.insert(ft::make_pair(2,1));
	test.insert(ft::make_pair(1,1));
*/
/* This works
	test.insert(ft::make_pair(1,1));
	test.insert(ft::make_pair(2,1));
	test.insert(ft::make_pair(3,1));
	test.insert(ft::make_pair(4,1));
	test.insert(ft::make_pair(5,1));
	test.insert(ft::make_pair(6,1));
	test.insert(ft::make_pair(7,1));
	test.insert(ft::make_pair(8,1));
	test.insert(ft::make_pair(9,1));
	test.insert(ft::make_pair(10,1));
	test.insert(ft::make_pair(11,1));
	test.insert(ft::make_pair(12,1));
*/
	return (0);
}