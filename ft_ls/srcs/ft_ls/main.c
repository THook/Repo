/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:15:43 by amaurer           #+#    #+#             */
/*   Updated: 2013/12/13 07:33:08 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av)
{
	t_options	options;
	int			o_entered;
	int			i;

	o_entered = ls_options_set(ac, av, &options);
	if (ac - o_entered == 1)
		ls_print(".", &options);
	else
	{
		i = 1 + o_entered;
		while (i < ac)
		{
			ls_print(av[i], &options);
			i++;
		}
	}
	return (0);
}
