/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 22:50:25 by hvillain          #+#    #+#             */
/*   Updated: 2014/01/28 14:11:16 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_env(char **env, char **tab)
{
	int		i;
	char	**tab2;

	i = 0;
	if (tab[1])
	{
		tab2 = path_tab(get_env("PATH=", env));
		fork_off(tab[1], tab2, env);
	}
	else
	{
		while (env[i])
		{
			ft_putstr(env[i++]);
			ft_putchar('\n');
		}
	}
}

char			**copy_env(char **env)
{
	int		i;
	int		j;
	char	**tab;

	i = j = 0;
	while (env[i])
		i++;
	if ((tab = (char **)malloc(sizeof(char *) * (i + 1))) == 0)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if ((tab[i] = (char *)malloc(sizeof(char) * \
			(ft_strlen(env[i]) + 1))) == 0)
			return (NULL);
		while (env[i][j])
		{
			tab[i][j] = env[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	tab[i] = 0;
	return (tab);
}

void			ft_setenv(char **tab, const char *nam, const char *value, int o)
{
	int			i;
	char		*dup;

	i = 0;
	while (tab[i] && ft_strcmp(nam, ft_strdub(tab[i], '=')))
		i++;
	if (tab[i] && o != 0)
		dup = ft_strjoin(ft_strjoin(nam, "="), ft_strjoin(":", value));
	else if (tab[i] && o == 0)
		dup = ft_strjoin(tab[i], ft_strjoin(":", value));
	else
		return ;
	free(tab[i]);
	tab[i] = ft_strdup(dup);
	free(dup);
}

static char		**ft_unsetab(char **tab, int n)
{
	int		i;
	int		j;
	int		k;
	char	**tab2;

	i = j = k = 0;
	if (!(tab2 = (char **)malloc(sizeof(char *) * 30)))
		return (NULL);
	while (tab[j])
	{
		if (i == n)
			j++;
		tab2[i] = (char *)malloc(sizeof(char) * (ft_strlen(tab[j]) + 1));
		while (tab[j][k])
		{
			tab2[i][k] = tab[j][k];
			k++;
		}
		tab2[i][k] = '\0';
		k = 0;
		i++;
		j++;
	}
	tab2[i] = 0;
	return (tab2);
}

void			ft_unsetenv(char **tab, const char *name)
{
	int		i;

	i = 0;
	while (tab[i] && ft_strcmp(ft_strdub(tab[i], '='), name))
		i++;
	if (tab[i])
	{
		free(tab[i]);
		ft_unsetab(tab, i);
	}
}

