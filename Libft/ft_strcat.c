/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:59:43 by hvillain          #+#    #+#             */
/*   Updated: 2013/12/01 22:31:43 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t		i;

	i = ft_strlen(s1);
	while (*s2)
		*(s1 + i++) = *(s2++);
	s1[i] = 0;
	return (s1);
}
