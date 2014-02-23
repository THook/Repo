/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 13:36:49 by hvillain          #+#    #+#             */
/*   Updated: 2014/01/26 23:13:08 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libsh.h"
#include <stdlib.h>

static int		is_it_built2(char **env, char **tab)
{
	if (!(ft_strcmp(tab[0], "exit")))
		exit(0);
	if (!(ft_strcmp(tab[0], "env")))
	{
		ft_env(env, tab);
		return (1);
	}
	if (!(ft_strcmp(tab[0], "cd")))
	{
		ft_cd(env, tab);
		return (1);
	}
	return (0);
}

int				is_it_built(char **env, char *line)
{
	char	**tab;

	tab = ft_strsplit((char const *)line, ' ');
	if (!(ft_strcmp(tab[0], "unsetenv")))
	{
		if (!(tab[1]))
			ft_putstr("unsetenv takes 1(one) argument\n");
		else
			ft_unsetenv(env, tab[1]);
		return (1);
	}
	else if (!(ft_strcmp(tab[0], "setenv")))
	{
		if (!(tab[1]) || !(tab[2]) || !(tab[3]))
			ft_putstr("setenv takes 3(three) arguments\n");
		else
			ft_setenv(env, tab[1], tab[2], ft_atoi(tab[3]));
		return (1);
	}
	if (is_it_built2(env, tab))
		return (1);
	return (0);
}

