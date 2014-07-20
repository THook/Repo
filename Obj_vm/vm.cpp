/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 04:43:20 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/20 21:27:30 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

using namespace std;

#include "game.h"

// add turn to Game class
void	printing(Game *game, Plate *map, int turn)
{
	Piece	*piece = new Piece();

	(void)turn;
	(void)game;
	(void)map;
	map->print();
	piece->get_piece();
	piece->print();
}

void	reading(Game *game, Plate *map, int turn)
{
	(void)game;
	(void)map;
	(void)turn;
	



}

void	resolve(Game *game, Plate *map)
{
	(void)map;
	int		turn;
	Turn	*turn_follower = new Turn();
	turn = turn_follower->get_turn();
	while (game->get_state())
	{
		if (turn == 1) 
			printing(game, map, turn);
		else
			reading(game, map, turn);
		turn = 1 - turn;
	}
	if (game->get_loser() == 1)
		cout << "Player 2 wins !" << endl;
	else cout << "Player 1 wins !" << endl;
}

int		main(int ac, char **av)
{
	//if (ac == 5)
	Game	*game = new Game((const char *)av[1]);

	(void)game;
	(void)ac;	
	return 0;
}
