/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/24 00:46:20 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/25 01:10:15 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"
// lost = element apres )
// begin = element apres (
// element avant ) pointe sur begin
//
// element avant ( doit mettre son next a NULL
// le resultat des parentheses doit etre cree a la suite de element avant (
// puis chaine a lost


t_list		*manage_parent(char *cmd, char *data, t_list *elem)
{
	static t_list	*begin;
	static t_list	*lost;
	t_list			*rem;
	int				count = 1, start = 1;
	static int		i = 1;

	(void)data;
	if (!ft_strcmp("set", cmd))
	{
		rem = begin = elem->next;
		while (start || (rem != begin && (count % 2)))
		{
			start = 0;
			if (rem->data[0] == '(')
				count++;
			else if (rem->data[0] == ')')
			{
				count--;
				lost = rem->next;
			}
			if (count)
				rem = rem->next;
		}
		lost->prev = NULL;
		begin->prev->prev->next = NULL;
		rem->next = begin;
		if (elem == manage_list("get", NULL, NULL))
			manage_list("set_begin", NULL, begin);

		if (i)
		{
			manage_list("print", NULL, NULL);
			printf("\n");
			manage_parent("print", NULL, NULL);
			i = 0;
		}
		//free((void *)begin->prev);
		//free((void *)rem);
	}
	if (!ft_strcmp("print", cmd))
	{
		start = 1;
		rem = begin;
		while (start || begin != rem)
		{
			start = 0;
			printf("%s\n", rem->data);
			rem = rem->next;
		}
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
