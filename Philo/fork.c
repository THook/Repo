/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/03 04:24:42 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/03 21:14:59 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <unistd.h> // pour le write;
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void		add_fork_list(t_fork *head, t_fork *elem)
{
	t_fork		*tmp;

	if (!head)
		head = elem;
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
}

t_fork		*manage_fork_list(char *macro, t_fork *elem)
{
	static t_fork		*head;

	if (strcmp("add", macro))
		add_fork_list(head, elem);
	else if (strcmp("set", macro))
		head = elem;
	else if (strcmp("get", macro))
		return (head);
	else
		write(1, "Error\n", 6);
	return (NULL);
}

int			create_fork(void)
{
	t_fork				*new;
	pthread_mutex_t		mutex;

	if (!(new = (t_fork *)malloc(sizeof(t_fork))))
		return (1);
	pthread_mutex_init(&mutex, NULL);
	new->id = -1;
	new->mutex = &mutex;
	new->next = NULL;
	manage_fork_list("add", new);
	return (0);
}

/*
void		print_fork(t_fork *elem)
{
	ft_printf("print_fork:\n");
	ft_printf("fork: %p\n", elem);
	ft_printf("fork->id: %d\n", elem->id);
	return ;
}*/
