/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/03 05:31:29 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/03 09:52:03 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	time_out(t_philo *elem)
{
	if ((!elem->state && time + REST_T >= time()) ||
			(elem->state == EAT && time + EAT_T >= time()) ||
			(elem->state == THINK && time + THINK_T >= time()))
	{
		elem->previous_state = elem->state;
		if (elem->state == EAT)
		{
			elem->life = MAX_LIFE:
			pthread_mutex_unlock(fork_left);
			pthread_mutex_unlock(fork_right);
		}
		elem->state = WAIT;
		elem->time = time();
	}
}

void	call_to_mutex(t_philo *elem)
{
	if (elem->state == THINK)
	{
		if (!pthread_mutex_lock(elem->fork_right) || !pthread_mutex_lock(elem->fork_left))
		{
			elem->state = EAT;
			elem->previous_state = THINK;
			elem->time = time();
		}
	}
	else
	{
		if (!pthread_mutex_trylock(elem->fork_right) && !pthread_mutex_trylock(elem->fork_left))
		{
			elem->previous_state = elem->state;
			elem->state = EAT;
			elem->time = time();
		}
		if (!pthread_mutex_trylock(elem->fork_right) || !pthread_mutex_trylock(elem->fork_left))
		{
			elem->previous_state = elem->state;
			elem->state = THINK;
			elem->time = time();
		}
	}
}

void	start_thinking(void *elem)

{
	while (COMMUNITY > 0)
	{
		if (elem->life <= 0)
			COMMUNITY = 0;
		time_out(elem);
		if (elem->state != EAT && elem->last_time + 1 >= time())
			elem->life = elem->life - 1;
		if (elem->state != EAT)
			call_to_mutex(elem);
	}
	pthread_detach(elem->thread);
}

void	thread_init(void)
{
	t_philo		*p_head;
	t_philo		*philo_head;
	
	p_head = manage_philo_list("get", NULL);
	philo_head = p_head;
	while (philo_head->next != p_head)
	{
		pthread_create(&elem->thread, NULL, (void *)start_thinking, (void *)philo_head);
		pthread_join(philo_head, NULL); // Pas ici je crois
		philo_head = philo_head->next;
	}
}
