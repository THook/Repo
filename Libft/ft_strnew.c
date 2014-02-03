/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:31:44 by hvillain          #+#    #+#             */
/*   Updated: 2013/12/01 22:44:36 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	size_t		t;
	char		*s;

	t = 1;
	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (t <= size)
	{
		s[t] = '\0';
		t++;
	}
	s[t] = '\0';
	return (s);
}

