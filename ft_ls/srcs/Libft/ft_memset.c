/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:15:49 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/27 14:52:56 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memset(void *b, int c, size_t len)
{
	size_t		t;

	t = 0;
	while (t < len)
		((unsigned char *)b)[t++] = (unsigned char)c;
	return ((void *)b);
}
