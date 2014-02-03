/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 03:32:04 by hvillain          #+#    #+#             */
/*   Updated: 2014/01/21 13:59:25 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countsplit(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
			{
				i++;
			}
		}
	}
	return (count);
}

char			**ft_strsplit(const char *s, char c)
{
	int		j;
	int		size;
	char	**tab;

	size = 0;
	if (!s)
		return (NULL);
	j = ft_countsplit(s, c);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (j + 1))))
		return (NULL);
	if (!j)
		return (tab);
	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (s[size] && s[size] != c)
			size++;
		tab[j++] = ft_strsub(s, 0, size);
		s = s + size;
		size = 0;
	}
	return (tab);
}

