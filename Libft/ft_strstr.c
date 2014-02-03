/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:40:57 by hvillain          #+#    #+#             */
/*   Updated: 2013/12/01 22:33:15 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		i1;
	size_t		i2;

	i1 = 0;
	i2 = 0;
	if (*s2 == 0)
		return ((char *) s1);
	while (s1[i1] != 0)
	{
		i2 = 0;
		while (s1[i1 + i2] == s2[i2])
			if (!s2[++i2])
				return ((char *) s1 + i1);
		i1++;
	}
	return (0);
}
