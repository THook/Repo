/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/24 03:03:05 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/24 03:14:28 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static t_list		*create_elem(char *data)
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
	else new->id = -1;
	return (new);
}

static void			add_elem(t_list const *new, t_list const *begin)
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
}

static t_list		*manage_list(char *cmd, char *data, t_list *elem)
{
	static t_list	*begin;
	t_list			*new;
	t_list			*rem;
	int				start = 1;

	if (!ft_strcmp(cmd, "add"))
		add_elem(begin);
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
	else if (!ft_strcmp(cmd, "get"))
		return (begin);
	else if (!ft_strcmp(cmd, "delete"))
		(void)cmd;//rm_list(begin);
	return (NULL);
}

t_list				*manage_lists(int type, char *cmd, char *data, t_list *elem)
{
	if (!type)
		return (manage_list(type, cmd, data, elem));
	return (manage_parent(type, cmd, data, elem));
}
