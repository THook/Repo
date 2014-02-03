/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 17:53:47 by hvillain          #+#    #+#             */
/*   Updated: 2014/01/31 15:32:16 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*int				is_pipe(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '|' && line[i + 1]) // ? faire une sortie a -1 en le cas inverse pour que ls| ne rentre pas dans curse.
			return (1);
		i++;
	}
	return (0);
}*/

static void			split_parts(char **tab, char **env)
{
	int		i;

	i = 0;
	while (tab[i])
		piper(ft_strtrim(tab[i++]), env);
}

static void			parse(char *line, char **env)
{
	char	**tab;

	tab = ft_strsplit(line, ';');
	split_parts(tab, env);
}

void			course(char **env) //static
{
	char	*line;

	while (1)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		line = ft_strtrim(line);
		if (!line || !(*line))
			course(env);
		parse(line, env);
	}
}

int					main(int ac, char **av, char **env)
{
	char	**tab;

	tab = copy_env(env);
	if (ac == 2)
	{
		if (av[1][0] == '.' && av[1][1] == '/' && !av[1][2])
			ft_setenv(tab, "PATH", "./", 0);
	}
	course(tab);
	return (0);
}

