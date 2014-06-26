/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 22:34:07 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/18 17:59:08 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "glob.h"
#include "libft.h"

t_struct				*glob_init(void)
{
	t_struct	*glob;

	if (!(glob = (t_struct *)ft_memalloc(sizeof(t_struct))))
		return (NULL);
	return (glob);
}

static t_list			*list_init(char *name)
{
	t_list		*new;

	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	new->name = ft_strdup(name);
	return (new);
}

void					print_list(t_struct *glob)
{
	t_list		*cur;

	cur = glob->list;
	while (cur->next)
	{
		ft_putendl(cur->name);
		cur = cur->next;
	}
	ft_putendl(cur->name);
}

void					add_to_list(char *line, t_struct *glob)
{
	t_list		*cur;
	t_list		*tmp;

	cur = list_init(line);
	if (!(glob->list))
		glob->list = cur;
	else
	{
		tmp = glob->list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = cur;
	}
}

