/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:13:36 by hvillain          #+#    #+#             */
/*   Updated: 2013/12/01 22:32:12 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len;
	size_t		ret;

	ret = ft_strlen(src);
	if ((len = ft_strlen(dst)) >= size)
		return (size + ret);
	i = len;
	while (*src && size-- > len + 1)
		dst[i++] = *(src++);
	if (!*src || size == len)
		dst[i] = 0;
	return (len + ret);
}
