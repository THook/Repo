/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plate.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 06:46:47 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/19 23:20:27 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Plate.hpp

#include <string>
#include <vector>
#include <iostream>
#include <cstdio>

class	Plate
{
	int							size_x;
	int							size_y;
	std::vector <char>			border;
	std::vector<std::string>	map;

	public:

	Plate(std::vector<std::string> map)
	{
		int		i = -1;
		int		nbr = 0;
		
		this->size_y = map.size();
		while ((unsigned long)++i < map[0].length())
		{
			this->border.push_back('1' + nbr++);
			if (nbr == 9)nbr = 0;
		}
		this->size_x = i;
		this->map = map;
	}

/*	int		over(void)
	{
		if (!verification_end_of_game()) // private function
			return (0);
	}*/

	void	print(void)
	{
		int		i = -1;
		int		rem;

		printf("Plateau %d %d:\n", this->size_x, this->size_y);
		while ((unsigned long)++i < this->border.size())
			std::cout << this->border[i];
		std::cout << "\n";
		i = 1;
		rem = this->size_y;
		while ((rem = (rem / 10)) >= 10)
		{
			// N-W
			std::cout << "s\n";
			std::cout << " ";
		}
		i = -1;
		while ((unsigned long)++i < this->map.size())
			std::cout << this->map[i] << std::endl;
	}
};
