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

#include "Libsh.h"
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void				printtab(char **tab);

int				is_pipe(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '|' && line[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int				matches(char *name, char *line)
{
	int	i;
	int	j;
	int	k;
	char	**tab;

	i = j = k = 0;
	if (!(tab = ft_strsplit(ft_strtrim(line), '*')))
		return (1);
	while (name[i] && tab[j])
	{
		
		if (name[i] == tab[j][k])
		{
			while (name[i] == tab[j][k])
			{
				k++;
				i++;
			}
			if (!(tab[j][k]))
			{
				j++;
				k = 0;
			}
		}
		else
			i++;
	}
	if (!(tab[j]))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}


int				count_matches(char *line)
{
	DIR		*dir;
	struct dirent	*cur;
	int		i;
	int		count;
	int		ret;

	count = 0;
	i = 0;
	if ((dir = opendir(".")) == 0)
		exit(0);
	while ((cur = readdir(dir)) > 0)
	{
		if ((ret = matches(cur->d_name, line)))
			count = count + ret;
	}
	closedir(dir);
	return (count);
}

static void			split_parts(char **tab, char **env)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		//trim tou ça
		if (is_wild(tab[i]))
			main_card(tab[i++], env);
		else if (is_script(tab[i]))
			execute(tab[i++], env);
		else if (is_pipe(tab[i]))
			piper(ft_strtrim(tab[i++]), env);
		else
			curse(env, tab[i++]);
	}
}

void			parse(char *line, char **env)
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

