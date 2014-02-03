/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 12:31:13 by hvillain          #+#    #+#             */
/*   Updated: 2013/12/01 22:38:31 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s1;
	char	*s2;

	if (s == NULL || f == NULL)
		return (NULL);
	s1 = (char *) ft_memalloc(ft_strlen(s) + 1);
	if (s1 == NULL)
		return (NULL);
	s2 = s1;
	while (*s)
		*(s1++) = f(*(s++));
	return (s2);
}
