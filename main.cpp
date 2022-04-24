/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:50:25 by graja             #+#    #+#             */
/*   Updated: 2022/04/24 10:09:37 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "map"
#include "mclass.hpp"
#include <vector>
#include <map>
#include <string>
#include <utility>


int	main(void)
{
		ft::map<int, int>				test;
		ft::map<int, int>::iterator		i;
		std::map<int, int>				stest;
		std::map<int, int>::iterator	j;


		test.insert(ft::make_pair(10, 666));
		test.insert(ft::make_pair(20, 111));
		stest.insert(ft::make_pair(10, 666));
		stest.insert(ft::make_pair(20, 111));
		
		std::cout << test[0] << ", " << test[1] << std::endl;
		std::cout << stest[0] << ", " << stest[1] << std::endl;

		return (0);
}
