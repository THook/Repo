/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Piece.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 16:28:56 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/20 00:27:15 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class	Piece
{
	vector <string>		piece1;
	vector <string>		piece2;
	vector <string>		piece3;
	int					randomizer;

	public:

	Piece()
	{
		this->randomizer = -1;
		this->piece1.push_back("...*...");
		this->piece1.push_back("...*...");
		this->piece1.push_back("...*...");
		this->piece1.push_back("..***..");

		this->piece2.push_back(".**..");
		this->piece2.push_back(".***.");
		this->piece2.push_back("..*..");
		this->piece2.push_back(".....");

		this->piece3.push_back(".****.");
		this->piece3.push_back("**....");
		this->piece3.push_back("*.....");
	}
	void				get_piece(void)
	{
		if (this->randomizer == -1)
			this->randomizer = 0;
		if (this->randomizer == 1)
			this->randomizer++;
		if (this->randomizer == 1)
			this->randomizer--;
		if (!this->randomizer)
			this->randomizer++;
		if (this->randomizer == 2)
			this->randomizer--;
	}

	void				print(void)
	{
		vector<string>::const_iterator	i;

		if (this->randomizer == 0)
		{
			i = this->piece1.begin();
			cout << "Piece 4 7\n";
			while (i != this->piece1.end())
				cout << *(i++) << endl;	
		}
		else if (this->randomizer == 1)
		{
			i = this->piece2.begin();
			cout << "Piece 4 5\n";
			while (i != this->piece2.end())
				cout << *(i++) << endl;	
		}
		else if (this->randomizer == 2)
		{
			i = this->piece3.begin();
			cout << "Piece 3 6\n";
			while (i != this->piece2.end())
				cout << *(i++) << endl;	
		}
	}
};
