/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envtab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 01:41:57 by hvillain          #+#    #+#             */
/*   Updated: 2014/01/27 18:34:33 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int		hml(char **env)
{
	int		i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char			**envtab(char **env, int nb, int len)
{
	int		n;
	int		i;
	int		j;
	char	**tab2;

	n = hml(env);
	i = j = 0;
	if ((tab2 = (char **)malloc(sizeof(char *) * n + 1)) == 0)
		return (NULL);
	while (i < n)
	{
		if (i == nb)
			tab2[i] = (char *)malloc(sizeof(char) * len + 1);
		else
			tab2[i] = (char *)malloc(sizeof(char) * (ft_strlen(env[i]) + 1));
		while (env[i][j] && i != nb)
		{
			tab2[i][j] = env[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	tab2[i] = 0;
	return (tab2);
}

