/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 13:02:22 by hvillain          #+#    #+#             */
/*   Updated: 2014/01/19 20:03:18 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*s1;
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	if ((s1 = (char *) ft_memalloc(len + 1)) == 0)
		return (0);
	while (i < len)
	{
		s1[i] = ((char *) s)[start++];
		i++;
	}
	s1[i] = 0;
	return (s1);
}
