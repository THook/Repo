/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:10:03 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/27 14:51:09 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while (n != 0)
	{
		if (*((char *)s1) != *((char *)s2))
			return (*((char *)s1) - *((char *)s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}
