/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 15:57:32 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/18 19:10:23 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"
#include <stdlib.h>
#include "libft.h"

static char			*get_fname(char *line)
{
	char	**tab;
	char	*cpy;

	tab = ft_strsplit(line, ' ');
	cpy = ft_strdup(tab[0]);
	free_tab(tab);
	return (cpy);
}

static int			same_rooms(t_struct *glob, t_rooms *new)
{
	t_rooms		*cur;

	cur = glob->room;
	while (cur)
	{
		if (!ft_strcmp(cur->name, new->name))
			return (1);
		cur = cur->next;
	}
	return (0);
}

static t_rooms		*room_init(t_struct *glob, char *line, int path)
{
	t_rooms		*new;

	new = (t_rooms *)ft_memalloc(sizeof(t_rooms));
	if ((new->name = get_fname(line)) && same_rooms(glob, new))
		return (NULL);
	if (path == 1)
	{
		new->dist = 0;
		new->start = 1;
		new->end = 0;
	}
	else if (path == 2)
	{
		new->dist = -1;
		new->end = 2;
		new->start = 0;
	}
	else if (path == 0)
	{
		new->dist = -1;
		new->end = 0;
		new->start = 0;
	}
	new->occ = 0;
	return (new);
}

int					add_room(char *line, t_struct *glob, int path)
{
	t_rooms		*cur;
	t_rooms		*tmp;

	if ((cur = room_init(glob, line, path)) == NULL)
		return (1);
	if (!(glob->room))
		glob->room = cur;
	else
	{
		tmp = glob->room;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = cur;
	}
	return (0);
}

