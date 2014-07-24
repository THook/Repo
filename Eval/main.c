/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/23 17:43:10 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/24 03:02:12 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

char	*ft_str0chr(char *line)
{
	while (*line && *line <= '9' && *line >= '0')
		line++;
	return (line);
}

char	*ft_strsub(char *s, int start, int len)
{
	char		*s1;
	int			i;

	i = -1;
	if (!s)
		return (0);
	if (!(s1 = (char *)malloc(len + 1)))
		return (0);
	while (++i < len)
		s1[i] = ((char *)s)[start++];
	s1[i] = 0;
	return (s1);
}

void	ft_strsplit_ints(char *line)
{
	char	*next;

	while (*line)
	{
		if (*line <= '9' && *line >= '0')
		{
			next = ft_str0chr(line);
			manage_list("add", ft_strsub(line, 0, (next - line)), NULL);
			line = next;
		}
		else if (*line != ' ' && *line != '\0')
		{
			manage_list("add", ft_strsub(line, 0, 1), NULL);
			line++;
		}
		else
			line++;
	}
}

static int		ft_check_operand(t_list *elem, int priority)
{
	t_list		*rem;
	int			start = 0;

	rem = elem;
	while (start || rem != elem)
	{
		start = 0;
		if (rem->id == priority)
			return (1);
		rem = rem->next;
	}
	return (0);
}

int		resolve(void)
{
	t_list		*elem, *begin;
	int			priority = 0;

	begin = manage_lists(0, "get", NULL, NULL);
	elem = begin;
	while (elem != elem->next)
	{
		if (!ft_check_operand(manage_lists(0, "get", NULL, NULL), priority))
			priority++;
		if (!ft_strcmp(elem->data, "("))
		{
			manage_lists(1, "set", NULL, elem);
			elem = manage_lists(1, "get", NULL, NULL);
			manage_lists(1, "reset", resolve_parent(), NULL);
		}
		else if (elem->id==priority && elem->next != manage_lists(0, "get", NULL, NULL))
		{
			operate(elem);
			elem = manage_lists(0, "get", NULL, NULL);
		}
		elem = elem->next;
	}
	return (atoi(elem->data));
}

int		main(int ac, char **av)
{
	int		ret;

	ret = 1;
	(void)ret;
	if (ac == 2)
	{
		ft_strsplit_ints(av[1]);
		ret = resolve("get");
		//manage_list("delete", NULL);
		printf("RESULTAT: %d\n", ret);
	}
	return (0);
}
