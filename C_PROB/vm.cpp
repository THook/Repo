/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 04:43:20 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/19 12:10:47 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Plate.hpp"
#include "Game.hpp"

using namespace std;

int		main(int ac, char **av)
{
	ifstream		main;
	string			line;
	vector<string>	map;
	Game	*game = new Game();
	
	/*if (ac == 5)
	{*/
		main.open(av[1]);
		while (getline(main, line))
			map.push_back((const string)(line));
		Plate *test = new Plate(map);
		test->simple();
	/*}
	else
		return 0;
	*/return 0;
}
