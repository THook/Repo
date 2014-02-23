/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 20:03:26 by hvillain          #+#    #+#             */
/*   Updated: 2014/01/30 17:08:47 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libsh.h"
#include <stdlib.h>

char	*ft_strdub(char *s, char c)
{
	int		i;
	char	*s1;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != c)
		i++;
	if (!(s1 = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
