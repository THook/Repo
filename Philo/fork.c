/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/03 04:24:42 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/04 17:09:51 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <unistd.h> // pour le write;
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int				ft_strcmp(char *s1, char *s2);

static t_fork		*add_fork_list(t_fork *head, t_fork *elem)
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
	return (head);
}

t_fork				*manage_fork_list(char *macro, t_fork *elem)
{
	static t_fork		*head;

	if (!ft_strcmp("add", macro))
		head = add_fork_list(head, elem);
	else if (!ft_strcmp("get", macro))
		return (head);
	else
		write(1, "Error\n", 6);
	return (NULL);
}

int					create_fork(void)
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

void		print_fork(t_fork *elem)
{
	printf("print_fork:\n");
	printf("fork: %p\n", elem);
	printf("fork->id: %d\n", elem->id);
	return ;
}
