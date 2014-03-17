/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:01:12 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/12 03:43:43 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void		*s;
	size_t		t;

	t = 0;
	if ((s = (void *)malloc(size)) == NULL)
		return (NULL);
	ft_memset(s, 0, size);
	return (s);
}
