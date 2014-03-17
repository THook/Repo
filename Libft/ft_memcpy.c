/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:19:45 by hvillain          #+#    #+#             */
/*   Updated: 2013/12/01 22:28:45 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		t;

	t = 1;
	while (t <= n)
	{
		(*(unsigned char *) s1) = (*(unsigned char *) s2);
		s1++;
		s2++;
		t++;
	}
	return (((unsigned char *) s1) - n);
}
