/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:35:43 by hvillain          #+#    #+#             */
/*   Updated: 2014/06/25 20:28:31 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*ret;
	unsigned int		i;
	char				*s1;

	i = 0;
	if (s == NULL || f == NULL)
		return (0);
	s1 = (char *)ft_memalloc(ft_strlen(s) + 1);
	if (!s1)
		return (0);
	ret = s1;
	while (*s)
		*(s1++) = f(i++, *(s++));
	return (ret);
}
