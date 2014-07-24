/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/23 18:29:36 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/24 18:00:21 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

int			ft_strlen(char *line)
{
	int		i = 0;

	while (line[i])
		i++;
	return (i);
}

char		*ft_strdup(char *line)
{
	char	*new;
	int		i = -1;

	if (!(new = (char *)malloc(ft_strlen(line) + 1)))
		return (NULL);
	while (line[++i])
		new[i] = line[i];
	new[i] = 0;
	return (new);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != 0 || s2[i] != 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else
			i++;
	}
	return (0);
}
