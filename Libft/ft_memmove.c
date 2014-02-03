/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:10:45 by hvillain          #+#    #+#             */
/*   Updated: 2013/12/01 22:29:26 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*dest;
	char	*src;

	if (!s1 || !s2 || n == 0)
		return (s1);
	if (s1 <= s2)
		return (ft_memcpy(s1, s2, n));
	dest = (char *) s1 + n;
	src = (char *) s2 + n;
	while (n-- > 0)
		*--dest = *--src;
	return (dest);
}
