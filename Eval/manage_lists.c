/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/24 03:03:05 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/25 01:08:34 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

t_list			*create_elem(char *data)
{
	t_list		*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->data = ft_strdup(data);
	new->next = NULL;
	new->prev = NULL;
	if (data[0] <= '9' && data[0] >= '0')
		new->id = 0;
	else if (data[0] == '(' || data[0] == ')')
		new->id = 1;
	else if (data[0] == '*' || data[0] == '/')
		new->id = 2;
	else if (data[0] == '-' || data[0] == '+')
		new->id = 3;
	//else new->id = -1;
	return (new);
}

t_list				*add_elem(char *data,  t_list *begin)
{
	t_list			*rem;
	t_list			*new;

	new = create_elem(data);
	if (!begin)
	{
		begin = new;
		begin->next = begin;
	}
	else
	{
		rem = begin;
		while (rem->next && rem->next != begin)
			rem = rem->next;
		rem->next = new;
		new->prev = rem;
		new->next = begin;
		begin->prev = new;
	}
	return (begin);
}

t_list				*manage_list(char *cmd, char *data, t_list *elem)
{
	static t_list	*begin = NULL;
	t_list			*rem;
	int				start = 1;

	(void)data;
	if (!ft_strcmp(cmd, "add"))
		begin = add_elem(data, begin);
	else if (!ft_strcmp(cmd, "set"))
		begin = elem;
	else if (!ft_strcmp(cmd, "print"))
	{
		rem = begin;
		while (start || rem != begin)
		{
			start = 0;
			printf("%s\n", rem->data);
			rem = rem->next;
		}
	}
	else if (!ft_strcmp(cmd, "set_begin"))
		begin = elem;
	else if (!ft_strcmp(cmd, "get"))
		return (begin);
	else if (!ft_strcmp(cmd, "delete"))
		(void)cmd;//rm_list(begin);
	return (NULL);
}

t_list				*manage_lists(int type, char *cmd, char *data, t_list *elem)
{
	if (!type)
		return (manage_list(cmd, data, elem));
	return (manage_parent(cmd, data, elem));
}
