/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 16:38:15 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/24 17:19:52 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../Libft/libft.h"
#include "./g_diam.h"

void		print_lst(t_art *cur)
{
	while (cur)
	{
		if (cur->db == 1)
			;
		else
			ft_putendl(cur->name);
		cur = cur->next;
	}
}

void		supper(t_art *cur)
{
	t_art	*tmp;

	while (cur)
	{
		tmp = cur->next;
		if (tmp)
		{
			while (tmp && tmp->name && ft_strcmp(cur->name, tmp->name))
				tmp = tmp->next;
		}
		if (!tmp)
			;
		else
			tmp->db = 1;
		cur = cur->next;
	}
}

void		make_lst(char **tab, t_struct *glob)
{
	int		i;
	t_art	*cur;
	t_art	*new;
	t_art	*new2;
	char	**tab2;

	i = 0;
	while (tab[i])
	{
		new = (t_art *)malloc(sizeof(t_art));
		new2 = (t_art *)malloc(sizeof(t_art));
		tab2 = ft_strsplit(tab[i], '-');
		new->name = tab2[0];
		new2->name = tab2[1];
		new->db = 0;
		new2->db = 0;
		if (!glob->art)
			glob->art = new;
		else
		{
			cur = glob->art;
			while (cur->next)
				cur = cur->next;
			cur->next = new;
		}
		new->next = new2;
		new2->next = NULL;
		i++;
	}
	supper(glob->art);
}


int			main(int ac, char **av)
{
	t_struct	*glob;

	if (ac != 2)
		;
	else
	{
		glob = (t_struct *)malloc(sizeof(t_struct));
		glob->art = NULL;
		make_lst(ft_strsplit(av[1], ' '), glob);
		print_lst(glob->art);
	//	resolve(glob);
	}
	return (0);
}

