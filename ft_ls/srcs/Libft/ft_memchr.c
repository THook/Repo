/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:01:39 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/27 14:52:00 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*s1;
	size_t				t;

	t = 1;
	s1 = (unsigned char *)s;
	while (t <= n)
	{
		if (*s1 == (unsigned char)c)
			return (s1);
		s1++;
		t++;
	}
	return (NULL);
}
