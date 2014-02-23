/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 21:22:10 by hvillain          #+#    #+#             */
/*   Updated: 2014/01/27 19:41:04 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libsh.h"
#include <unistd.h>
#include <stdlib.h>

static void		setless(char **env)
{
	int		pwd;
	int		old;
	char	*swap;

	pwd = old = 0;
	while (env[pwd] && ft_strcmp("PWD", ft_strdub(env[pwd], '=')))
		pwd++;
	while (env[old] && ft_strcmp("OLDPWD", ft_strdub(env[old], '=')))
		old++;
	swap = env[pwd];
	env[pwd] = env[old];
	env[old] = swap;
	if (!(chdir(env[pwd] + 7)))
		;
	else
		ft_putstr("No way you're gun get there");
}

static void		setback(char **env)
{
	int		j;
	int		k;
	char	*path;

	j = k = 0;
	while (env[j] && ft_strcmp("PWD", ft_strdub(env[j], '=')))
		j++;
	while (env[k] && ft_strcmp("OLDPWD", ft_strdub(env[k], '=')))
		k++;
	if (!(chdir(env[j] + 4)))
	{
		env[k] = ft_strjoin("OLDPWD=", env[j] + 4);
		path = ft_strrchr(env[j], '/');
		*path = '\0';
	}
	else
		ft_putstr("No way you're gun get there");
}

static void		setgohome(char **env)
{
	int		i;
	int		j;
	int		k;

	i = j = k = 0;
	while (env[i] && ft_strcmp("HOME", ft_strdub(env[i], '=')))
		i++;
	while (env[j] && ft_strcmp("PWD", ft_strdub(env[j], '=')))
		j++;
	while (env[k] && ft_strcmp("OLDPWD", ft_strdub(env[k], '=')))
		k++;
	if (!(chdir(env[i] + 5)))
	{
		env[k] = ft_strjoin("OLDPWD=", env[j] + 4);
		env[j] = ft_strjoin("PWD=", env[i] + 5);
	}
	else
		ft_putstr("No way you're gun get there");
}

static void		setgo(char **env, char *line)
{
	int		j;
	int		k;
	char	*path;

	j = 0;
	k = 0;
	while (env[j] && ft_strcmp("PWD", ft_strdub(env[j], '=')))
		j++;
	while (env[k] && ft_strcmp("OLDPWD", ft_strdub(env[k], '=')))
		k++;
	if (!(chdir(path = ft_strjoin(env[j] + 4, line))))
	{
		env[k] = ft_strjoin("OLDPWD=", env[j] + 4);
		env[j] = ft_strjoin("PWD=", path);
		free(path);
	}
	else
		ft_putstr("No way you're gun get there");
}

void			ft_cd(char **env, char **tab)
{
	if (!(tab[1]) || (tab[1][0] == '~' && !tab[1][1]))
		setgohome(env);
	else if (tab[1][0] == '~' && tab[1][1])
		setfromhome(env, tab[1]);
	else if (tab[1][0] == '.' && tab[1][1] == '.' && !(tab[1][2]))
		setback(env);
	else if (tab[1][0] == '-' && !(tab[1][1]))
		setless(env);
	else if (tab[1][0])
		setgo(env, tab[1]);
}

