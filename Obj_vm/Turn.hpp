/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Turn.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 16:31:31 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/20 21:25:08 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class	Turn
{
	int		turning;
	int		flag_down;
	int		reading;

	public:

	Turn(){this->turning = -1; this->flag_down = 0; this->reading = 0;}

	int		private_get_turn(void)
	{
		if (this->turning == -1 && (this->flag_down = 0))
			return (this->turning = 0);
		if (this->turning == 1 && this->flag_down == 0)
			return this->turning++;
		if (this->turning == 1 && this->flag_down == 1)
			return this->turning--;
		if (!this->turning && (this->flag_down = (1 - this->flag_down)))
			return this->turning++;
		if (this->turning == 2 && (this->flag_down = (1 - this->flag_down)))
			return this->turning--;
		return (-1);
	}
	
	int		get_turn(void)
	{
		return private_get_turn();
	}

	int		read_or_print(void)
	{
		return 1 - this->reading;
	}
};
