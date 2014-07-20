/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Turn.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 16:31:31 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/20 00:29:12 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Turn
{
	int		turning;
	int		flag_down;
	int		reading;

	public:

	Turn(){this->turning = -1; this->flag_down = 1; this->reading = 0;}

	int		get_turn(void)
	{
		if (this->turning == -1 && (this->flag_down = 1))
			return (this->turning = 0);
		if (this->turning == 1 && this->flag_down == 0)
			return this->turning++;
		if (this->turning == 1 && this->flag_down == 1)
			return this->turning--;
		if (!this->turning && (this->flag_down = 1 - this->flag_down))
			return this->turning++;
		if (this->turning == 2 && (this->flag_down = 1 - this->flag_down))
			return this->turning--;
		return (-1);
	}

	int		read_or_print(void)
	{
		return 1 - this->reading;
	}
};
