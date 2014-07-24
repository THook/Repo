/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/24 00:46:20 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/24 03:02:12 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

t_list		*manage_parent(char *cmd, char *data, t_list *elem)
{
	static t_list	*begin;
	static t_list	*lost;
	t_list			*rem;
	int				count = 1;

	(void)data;
	if (!ft_strcmp("set", cmd))
	{
		rem = begin = elem->next;
		while (count % 2)
		{
			if (rem->data[0] == '(')
				count++;
			else if (rem->data[0] == ')' && (count--))
				lost = rem->next;
			if (count)
				rem = rem->next;
		}
		rem->prev->next = begin;
		//begin->prev->next = rem->next; // prepare la separation de '('
		begin->prev->next = NULL;
		free((void *)begin->prev);
		free((void *)rem);
	}
	if (!ft_strcmp("get", cmd))
		return (begin);
	if (!ft_strcmp("reset", cmd))
	{
		rem = manage_list("get", NULL, NULL);
		while (rem->next)
			rem = rem->next;
		rem->next = create_elem(data);
		elem->next = lost;
	}
	return (NULL);
}

// mettre a null next de ce qui precede (
// quand il ne reste qu un elem, reprendre de begin_list 
