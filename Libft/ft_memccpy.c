/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:25:57 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/27 14:51:34 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t		t;

	t = 0;
	if (!s1 && !s2 && n == 0)
		return (0);
	while (t < n)
	{
		((char *)s1)[t] = ((char *)s2)[t];
		if (((unsigned char *)s2)[t++] == (unsigned char)c)
			return (s1 + t);
	}
	return (NULL);
}
