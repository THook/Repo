/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plate.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 06:46:47 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/19 12:28:29 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Plate.hpp

#include <string>
#include <vector>
#include <iostream>
#include <cstdio>

//commenter les lignes  a  enleve tout segfault
//et la map saffiche correctement.
//non commentees, ces lignes creent un segfault a la ligne this->map = test

class	Plate
{
	int							size_x;
	int							size_y;
	std::string					border;
	std::vector<std::string> map;

	public:

	Plate(std::vector<std::string> map)
	{
		int		i;
		int		nbr;
		std::vector<std::string>	test;
		
		i = 0;
		this->size_y = map.size();
		while (i < map[0].length())
		{
			this->border[i] = nbr;
			nbr++;
			if (nbr == 9)
				nbr = 0;
			i++;
		}
		this->size_x = i;
		test = map;
		std::cout << "a\n";
		this->map = test;
		std::cout << "a\n";
	}

	void	simple(void)
	{
		//std::cout << "s\n";
		for (int i = 0;i<this->map.size();i++)
			std::cout << this->map[i] << std::endl;
	}

	void	print(void)
	{
		int		i;
		int		rem;

		std::cout << "z\n";
		printf("Plateau %d %d :\n", this->size_x, this->size_y);
		//std::cout << "Plateau "  this->size_x + " " + this->size_y + ":" << std::endl;
		i = 1;
		rem = this->size_y;
		std::cout << "x\n";
		while ((rem = (rem / 10)) >= 10)
		{
			std::cout << "s\n";
			std::cout << " ";
		}
		std::cout << this->border << std::endl;
		i = 0;
		while (i < this->map.size())
		{
			std::cout << this->map[i] << std::endl;
			i++;
		}
	}
};
