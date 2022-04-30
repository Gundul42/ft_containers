/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 08:47:31 by graja             #+#    #+#             */
/*   Updated: 2022/04/30 09:06:34 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
		{
	int	t = 10;
    int const i = 3;                 // i is not declared const
    const int *rci = &i;
    
	std::cout << "rci = " << rci << '\n';
    const_cast<int*>(rci) = &t; // OK: modifies i
    std::cout << "i = " << i << '\n';
	std::cout << "rci = " << rci << '\n';

}
