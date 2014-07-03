/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/03 04:39:53 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/03 22:21:13 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	fill_lists(void)
{
	t_fork		*fork_head;
	t_philo		*philo_head;
	t_philo		*p_head;

	fork_head = manage_fork_list("get", NULL);
	p_head = manage_philo_list("get", NULL);
	philo_head = p_head;
	while (philo_head->next != p_head)
	{
		philo_head->previous_state = 0;
		philo_head->state = 0;
		philo_head->time = 0;
		philo_head->life = MAX_LIFE;
		philo_head = philo_head->next;
		fork_head = fork_head->next;
	}
}

void	join_lists(void)
{
	t_fork		*fork_head;
	t_philo		*philo_head;
	t_philo		*p_head;

	fork_head = manage_fork_list("get", NULL);
	p_head = manage_philo_list("get", NULL);
	philo_head = p_head;
	while (philo_head->next != p_head)
	{
		philo_head->fork_left = fork_head->mutex;
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
	/*join_lists();
	fill_lists();
	thread_init();
	*/return (0);
}
