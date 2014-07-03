/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/03 01:13:16 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/03 18:38:14 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void		add_philo_list(t_philo *head, t_philo *elem)
{
	t_philo		*tmp;

	if (!head)
		head = elem;
	else
	{
		tmp = head;
		while (tmp->next && tmp->next != head)
			tmp = tmp->next;
		tmp->next = elem;
		elem->next = head;
		elem->prev = tmp;
		head->prev = elem;
	}
}

t_philo		*manage_philo_list(char *macro, t_philo *elem) 
{
	static t_philo	*head;

	if (strcmp("add", macro))
		add_philo_list(head, elem);
	else if (strcmp("get", macro))
		return (head);
	else if (strcmp("set", macro))
		head = elem;
	else
		write(1, "Wrong manage_philo_list\n", 24);
	return (NULL);
}

int			create_philo(void)
{
	t_philo		*new;

	if (!(new = (t_philo *)malloc(sizeof(t_philo))))
		return (1);
	new->previous_state = -1;
	new->state = -1;
	new->life = -1;
	new->time = -1;
	new->last_time = -1;
	new->thread = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->fork_left = NULL;
	new->fork_right = NULL;
	manage_philo_list("add", new);
	return (0);
}

void		print_philo(t_philo *elem)
{
	printf("print_philo:\n");
	printf("philo: %p\n", elem);
	printf("philo->state: %d\n", elem->state);
	printf("philo->life: %d\n", elem->life);
	return ;
}
