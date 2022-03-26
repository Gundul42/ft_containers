/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mclass.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:06:55 by graja             #+#    #+#             */
/*   Updated: 2022/03/26 12:11:42 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mclass.hpp"

Mclass::Mclass(void): _start(0), _end(50), _flag('P')
{}

Mclass::Mclass(Mclass const & cpy)
{
	*this = cpy;
}

Mclass::~Mclass(void)
{}


Mclass & Mclass::operator=(Mclass const & right)
{
	_start = right._start;
	_end = right._end;
	_flag = right._flag;
	return (*this);
}

int	Mclass::getStart(void)
{
	return (_start);
}

int	Mclass::getEnd(void)
{
	return (_end);
}

char	Mclass::getFlag(void)
{
	return (_flag);
}
