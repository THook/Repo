/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 09:20:35 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/23 22:57:41 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"
#include "libft.h"


static void			get_prev(t_struct *glob, t_rooms *cur)
{
	t_root		*new;
	t_root		*tmp;

	tmp = NULL;
	while (cur)
	{
		if (!(new = (t_root *)ft_memalloc(sizeof(t_root))))
			return ;
		new->room = cur;
		new->next = tmp;
		cur = cur->prev;
		tmp = new;
	}
	glob->root = new;
}

static int			scout_it(t_struct *glob, t_rooms *cur, int dis)
{
	t_pipe			*pipe;
	static int		i = 0;

	if (i == 1)
		return (0);
	pipe = cur->pipe;
	if (cur->end == 2)
	{
		i = 1;
		get_prev(glob, cur);
		return (0);
	}
	while (pipe)
	{
		if (pipe->room->vis != 1)
		{
			pipe->room->dist = dis + 1;
			pipe->room->vis = 1;
			pipe->room->prev = cur;
			scout_it(glob, pipe->room, dis + 1);
		}
		pipe = pipe->next;
	}
	return (0);
}

static int			too_much_of(t_rooms *cur, int n)
{
	int		count;

	count = 0;
	while (cur)
	{
		if (n == 2)
		{
			if (cur->end == 2)
				count++;
		}
		if (n == 1)
		{
			if (cur->start == 1)
				count++;
		}
		cur = cur->next;
	}
	return (count);
}

int					resolve(t_struct *glob)
{
	t_rooms		*cur;
	t_rooms		*end;

	cur = glob->room;
	end = glob->room;
	if (too_much_of(end, 2) > 1)
		return (-8);
	if (too_much_of(cur, 1) > 1)
		return (-9);
	while (end && end->end != 2)
		end = end->next;
	if (!end || end->end != 2)
		return (-7);
	while (cur && cur->start != 1)
		cur = cur->next;
	if (!cur || cur->start != 1)
		return (-4);
	if (!cur->pipe)
		return (-5);
	cur->prev = NULL;
	cur->vis = 1;
	return (scout_it(glob, cur, 0));
}

