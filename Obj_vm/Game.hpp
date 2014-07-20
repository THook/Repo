/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 06:46:25 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/20 21:24:33 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Game.hpp

using namespace std;

class	Game
{
	int		over;
	int		loser;
	int		turning;
	int		reading;
	Plate	*plate;
	Piece	*piece;
	Turn	*turn;

	public:

	Game(const char *file)
	{
		ifstream		main;
		const string	line;
		vector<string>	map;
		over = 1; loser = -1;
		turning = -1;

		main.open(file);
		while (getline(main, file))
			map.push_back(line);
		this->plate = new Plate(map);
		this->piece = new Piece();
		this->turn = new Turn();
	}

	void		resolve(void)
	{
		int		turn = -1;
		int		last_turn = turn;

		while (get_state())
		{
			turn = this->turn->get_turn();
			if (turn)
				print_game(turn);
			else
				read_game(last_turn);
			last_turn = turn;
		}
		if (get_loser() == 1)
			cout << "Player 2 wins !" << endl;
		else cout << "Player 1 wins !" << endl;
	}

	void		print_game(int turn)
	{
		(void)turn;
		print_plate();
		this->piece->get_piece();
		print_plate();
	}








	// Calls to plate
	//
	void	print_plate(void)
	{
		this->plate->print(); // ?
	}



	// Calls to piece
	//
	void	print_piece(void)
	{
		this->piece->print();
	}

	// Calls to turn
	//
	void	get_turn(void)
	{
		this->turning = this->turn->get_turn();
	}

	void	read_or_print(void)
	{
		this->reading = this->turn->read_or_print();
	}

	// Game needs
	//
	void	set_game(int player)
	{
		this->over = 1 - this->over;
		this->loser = player;
	}

	void	read_game(int turn)
	{
		(void)turn;
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
