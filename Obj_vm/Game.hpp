/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 06:46:25 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/20 00:19:43 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Game.hpp

class	Game
{
	int		over;
	int		loser;

	public:

	Game(){over = 1; loser = -1;}

	void	set_game(int player)
	{
		this->over = 1 - this->over;
		this->loser = player;
	}

	int		get_state(void)
	{
		return this->over;
	}

	int		get_loser(void)
	{
		return this->loser;
	}
};
