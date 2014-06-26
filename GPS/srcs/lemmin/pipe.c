/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 17:40:45 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/18 18:01:20 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "glob.h"
#include "libft.h"
#include <stdio.h>

static int			create_pipe(t_rooms *cur, t_pipe **new, char *line)
{
	t_pipe		*tmp;

	while (cur)
	{
		if (!ft_strcmp(cur->name, line))
		{
			(*new)->room = cur;
			if (!cur->pipe)
				cur->pipe = *new;
			else
			{
				tmp = cur->pipe;
				while (tmp->next)
					tmp = tmp->next;
				tmp->next = *new;
			}
			break ;
		}
			else if (cur->next)
				cur = cur->next;
			else
				return (-1);
	}
	return (0);
}

static int			add_room_to_pipe(t_rooms *cur, t_pipe **new, char *line)
{
	while (cur)
	{
		if (!ft_strcmp(cur->name, line))
		{
			(*new)->room = cur;
			break ;
		}
		else if (cur->next)
			cur = cur->next;
		else
			return (-1);
	}
	return (0);
}

int					add_pipe(char *line, t_struct *glob)
{
	t_pipe		*new;
	t_pipe		*new2;
	char		**tab;
	int			i;

	i = 0;
	tab = ft_strsplit(line, '-');
	if (!(new = (t_pipe *)ft_memalloc(sizeof(t_pipe))))
		return (-1);
	if (!(new2 = (t_pipe *)ft_memalloc(sizeof(t_pipe))))
		return (-1);
	if ((create_pipe(glob->room, &new, tab[0]) == -1))
		return (-1);
	if ((create_pipe(glob->room, &new2, tab[1]) == -1))
		return (-1);
	if ((add_room_to_pipe(glob->room, &new, tab[1]) == -1))
		return (-1);
	if ((add_room_to_pipe(glob->room, &new2, tab[0]) == -1))
		return (-1);
	free_tab(tab);
	return (0);
}

