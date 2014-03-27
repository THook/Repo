/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str0chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:10:34 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/27 17:45:53 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_str0chr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*(char *)s)
	{
		if (*(char *)s == (char)c)
			return ((char *)s);
		s++;
	}
	return ((char *)s);
}
