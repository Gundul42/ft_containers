/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:50:25 by graja             #+#    #+#             */
/*   Updated: 2022/04/12 18:45:48 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.hpp"
#include "mclass.hpp"

int	main(void)
{

	ft::rbtree<int, int>	test;
	Mclass			lolo;
	ft::rbtree<int, Mclass> lulu;
	
	test.insert(ft::make_pair(10,1));
	test.insert(ft::make_pair(18,1));
	test.insert(ft::make_pair(7,1));
	test.insert(ft::make_pair(15,1));
	test.insert(ft::make_pair(16,1));
	test.insert(ft::make_pair(30,1));
	test.insert(ft::make_pair(25,1));
	test.insert(ft::make_pair(40,1));
	test.insert(ft::make_pair(60,1));
	test.insert(ft::make_pair(2,1));
	test.insert(ft::make_pair(1,1));
	test.insert(70,1);
	lulu.insert(20, lolo);
	lulu.insert(100, lolo);
	return (0);
}
