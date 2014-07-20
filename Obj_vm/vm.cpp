/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 04:43:20 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/20 00:26:37 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Plate.hpp"
#include "Game.hpp"
#include "Turn.hpp"
#include "Piece.hpp"
#include <stdio.h>

using namespace std;

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
	ifstream		main;
	string			line;
	vector<string>	map;
	Game			*game = new Game();
	
	(void)ac;
	main.open(av[1]);
	while (getline(main, line))
		map.push_back((const string)(line));
	Plate *mappy = new Plate(map);
	resolve(game, mappy);
	return 0;
}
