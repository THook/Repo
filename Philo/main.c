/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/03 04:39:53 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/04 17:09:53 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>


static void		fill_o_phils(void) // add philo_ids if NBR <= 7
{
	int			start;
	int			i;
	t_philo		*philo_head;
	t_philo		*p_head;
	t_fork		*f_head;

	start = 1;
	i = 0;
	p_head = manage_philo_list("get", NULL);
	philo_head = p_head;
	while (start || philo_head != p_head)
	{
		start = 0;
		philo_head->previous_state = 0;
		philo_head->state = 0;
		philo_head->time = 0;
		f_head->id = i++;
		philo_head->life = MAX_LIFE;
		philo_head = philo_head->next;
		f_head = f_head->next;
	}
}

void	join_lists(void)
{
	t_fork		*fork_head;
	t_fork		*f_head;
	t_philo		*philo_head;
	t_philo		*p_head;
	int			start;

	start = 0;
	f_head = manage_fork_list("get", NULL);
	p_head = manage_philo_list("get", NULL);
	fork_head = f_head;
	philo_head = p_head;
	while (start || philo_head != p_head)
	{
		start = 0;
		philo_head->fork_left = fork_head->mutex;
		if (philo_head->next == p_head)
			philo_head->fork_right = f_head->mutex;
		else
			philo_head->fork_right = fork_head->next->mutex;
		philo_head = philo_head->next;
		fork_head = fork_head->next;
	}
}

int		main(void)
{
	int		i;

	i = NBR_PHILO;
	while (i--)
	{
		if (create_fork())
			return (1);
		if (create_philo())
			return (1);
	}
	join_lists();
	fill_o_phils();
	// test id mutex
	thread_init();
	return (0);
}
