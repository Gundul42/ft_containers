/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecmain.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:12:42 by graja             #+#    #+#             */
/*   Updated: 2022/04/26 10:22:15 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.hpp"

int	main(int argc,char **argv)
{
	long			n;
	long			nbr;
	int			max;
	int			i;
	char			*chk;
	int			flag;
	time_t	start, end;
	ft::vector<long>					delme;
	ft::vector<long>::iterator			it;
	ft::vector<long>::const_iterator	cit;

	i = 0;
	srandom(time(NULL));
	if (argc < 3)
	{
		printf("\nUSE: rnd <n element> <max value> <-1|0|1>\n\n");
		return (0);
	}
	n = atoi(argv[1]);
	max = atoi(argv[2]);
	if (n > max)
	{
		printf("\nERROR: n is larger than max possible value\n\n");
		return (0);
	}
	if (argv[3])
		flag = atoi(argv[3]);
	else
		flag = 0;
	chk = (char *)calloc(max * 2 + 1, sizeof(char));
	if (!chk)
		return (0);

	// init time
	time(&start);
	while (n > 0 && i < n)
	{
		nbr = random() % max;
		if (flag == -1)
			nbr += 1;
		if (((random() % 2) && !flag) || (flag == -1))
			nbr *= -1;
		if ((nbr < 0 && !chk[nbr * -1]) || (nbr >= 0 && !chk[max + nbr]))
		{
			//printf("%ld ", nbr);
			delme.push_back(nbr);
			i++;
			if (nbr < 0)
				chk[nbr * -1] = 1;
			else
				chk[max + nbr] = 1;
		}
	}
	free(chk);
	std::cout << delme.size() << std::endl;
	time(&end);
	double diff = difftime(end, start);
	int	tme = static_cast<int> (diff);
	it = delme.begin();
	cit = delme.begin();
	while (cit != delme.end())
	{
			std::cout << *cit << ", ";
			cit++;
	}
	std::cout << std::endl;
	std::cout << "Executed in " << tme << " seconds" << std::endl;
	return (0);
}
