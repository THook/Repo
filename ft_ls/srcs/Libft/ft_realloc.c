/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 07:53:57 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/27 14:56:12 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_realloc(void **ptr, size_t size)
{
	void		*tmp;
	void		*tmp2;
	int			n;

	if (!(*ptr))
		n = 1;
	else
		n = ft_strlen((*(char **)ptr));
	tmp = *ptr;
	if (!(*ptr = ft_memalloc(n + size + 1)))
		return (-1);
	tmp2 = *ptr;
	while ((*(char *)tmp))
		(*(char *)tmp2++) = (*(char *)tmp++);
	ft_memdel((void **)&tmp);
	return (ft_strlen(*ptr));
}
