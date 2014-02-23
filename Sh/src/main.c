/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 17:39:14 by hvillain          #+#    #+#             */
/*   Updated: 2014/02/02 17:19:53 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libsh.h"
#include <unistd.h>
#include <stdlib.h>

char	**path_tab(char *path)
{
	char	**tab;

	tab = NULL;
	tab = ft_strsplit(path, ':');
	return (tab);
}

char	*get_env(char *s, char **env_p)
{
	int		i;
	char	*path;
	int		s_len;

	i = 0;
	s_len = ft_strlen(s);
	while (env_p[i] && ft_strncmp(env_p[i], s, s_len))
		i++;
	if (env_p[i] == NULL)
		return (NULL);
	path = ft_strdup((&(env_p[i][s_len])));
	return (path);
}

int		fork_off(char *line, char **tab, char **env_p)
{
	pid_t		pid;
	char		**av;

	av = ft_strsplit(line, ' ');
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		execve(make_path(av[0], tab), av, env_p);
		ft_putchar('\n');
		exit(0);
	}
	else
		waitpid(pid, 0, 0);
	return (0);
}

void	curse(char **env_p, char *line)
{
	char	**tab;
	char	*path;

	if (is_it_built(env_p, line))
		return ;
	path = get_env("PATH=", env_p);
	tab = path_tab(path);
	fork_off(line, tab, env_p);
}

