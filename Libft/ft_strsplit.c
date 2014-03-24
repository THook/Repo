/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 07:10:15 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/24 17:20:48 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count(const char *line, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (line[i] == c)
	{
		while (line[i] == c)
			i++;
	}
	while (line[i])
	{
		if (line[i] != c)
		{
			count++;
			while (line[i] && line[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char		**ft_strsplit(const char *s, char c)
{
	char		**tab;
	int			i;
	int			j;
	char		*tmp;

	i = 0;
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (count(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		j = 0;
		if (*s == c)
			s++;
		else if (*s != c) 
		{
			if ((tmp = ft_strchr(s, c)) || (tmp = ft_strchr(s, '\0')))
			{
				if (!(tab[i++] = (char *)ft_memalloc((tmp - s) / sizeof(char) + 1)))
					return (NULL);
				while (s != tmp)
					tab[i - 1][j++] = *(s++);
			}
		}
	}
	return (tab);
}

