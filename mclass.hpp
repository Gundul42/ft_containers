/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mclass.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:03:32 by graja             #+#    #+#             */
/*   Updated: 2022/03/26 12:06:36 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MCLASS_H
# define MCLASS_H

class Mclass
{
	private:
		int	_start;
		int	_end;
		char	_flag;

	public:
		Mclass(void);
		Mclass(Mclass const & cpy);
		~Mclass(void);

		Mclass & operator=(Mclass const & right);

		int	getStart(void);
		int	getEnd(void);
		char	getFlag(void);
};

#endif
