/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setmain.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:22:52 by graja             #+#    #+#             */
/*   Updated: 2022/04/22 13:16:28 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "set.hpp"
#include "utility.hpp"

int	main(void)
{

	ft::set<int>			test;

	std::cout << "Size of container is " << test.size() << std::endl;
	return (0);
}
