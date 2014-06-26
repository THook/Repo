/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_lem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 18:04:18 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/18 19:12:58 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "glob.h"
#include "libft.h"

static void			set_pos(t_ant *ant)
{
	ant->pos->next->room->occ = 1;
	ant->pos->room->occ = 0;
	ant->pos = ant->pos->next;
	ft_putstr("L");
	ft_putnbr(ant->id);
	ft_putstr("-");
	ft_putstr(ant->pos->room->name);
	ft_putchar(' ');
}

void				lets_lem(t_struct *glob)
{
	int			i;
	int			n;

	n = glob->ant_nbr;
	i = 0;
	ft_putchar('\n');
	while (n > 0)
	{
		while (glob->ants[i]->done == 1)
			i++;
		while (i < glob->ant_nbr)
		{
			if (glob->ants[i]->pos->room->end == 2 && (n--))
			{
				glob->ants[i]->pos->room ->occ = 0;
				glob->ants[i]->done = 1;
			}
			else if (glob->ants[i]->pos->next->room->occ != 1)
				set_pos(glob->ants[i]);
			i++;
		}
		if (n > 0)
			ft_putchar('\n');
		i = 0;
	}
}

void				create_lemtab(t_struct *glob)
{
	t_ant		**new;
	int			i;
	int			n;

	i = 0;
	n = glob->ant_nbr;
	new = (t_ant **)ft_memalloc(sizeof(t_ant *) * n + 1);
	while (i < n)
	{
		new[i] = (t_ant *)ft_memalloc(sizeof(t_ant));
		new[i]->id = i + 1;
		new[i]->pos = glob->root;
		new[i]->done = 0;
		i++;
	}
	new[i] = 0;
	glob->ants = &new[0];
}

