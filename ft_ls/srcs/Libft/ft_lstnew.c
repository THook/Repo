/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:49:40 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/27 14:50:07 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;

	if (!content)
		content_size = 0;
	if (!(new = (t_list *)ft_memalloc(sizeof(content_size))))
		return (NULL);
	return (new);
}
