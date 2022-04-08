/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmain.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:50:25 by graja             #+#    #+#             */
/*   Updated: 2022/04/08 13:27:55 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

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

	return (0);
}
