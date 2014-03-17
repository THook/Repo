/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <rkorimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:25:46 by rkorimba          #+#    #+#             */
/*   Updated: 2013/12/01 22:42:10 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*s2 == 0)
		return ((char *) s1);
	while (s1[i] != 0 && i < n)
	{
		j = 0;
		while ((s1[i + j] == s2[j] || s2[j] == 0) && (i + j) <= n)
		{
			if (s2[j] == 0)
				return ((char *) s1 + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
