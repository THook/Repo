/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/03 05:31:29 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/03 21:15:00 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
void	time_out(t_philo *elem)
{
	if ((!elem->state && elem->time + REST_T >= time(NULL)) ||
			(elem->state == EAT && elem->time + EAT_T >= time(NULL)) ||
			(elem->state == THINK && elem->time + THINK_T >= time(NULL)))
	{
		elem->previous_state = elem->state;
		if (elem->state == EAT)
		{
			elem->life = MAX_LIFE;
			pthread_mutex_unlock(elem->fork_left);
			pthread_mutex_unlock(elem->fork_right);
		}
		elem->state = WAIT;
		elem->time = time(NULL);
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
			elem->time = time(NULL);
		}
	}
	else
	{
		if (!pthread_mutex_trylock(elem->fork_right) && !pthread_mutex_trylock(elem->fork_left))
		{
			elem->previous_state = elem->state;
			elem->state = EAT;
			elem->time = time(NULL);
		}
		if (!pthread_mutex_trylock(elem->fork_right) || !pthread_mutex_trylock(elem->fork_left))
		{
			elem->previous_state = elem->state;
			elem->state = THINK;
			elem->time = time(NULL);
		}
	}
}

void	start_thinking(t_philo *elem)

{
	while (COMMUNITY > 0)
	{
		if (elem->life <= 0)
			elem->life = 10;
		time_out(elem);
		if (elem->state != EAT && elem->last_time + 3 >= time(NULL))
			elem->life = elem->life - 1;
		if (elem->state != EAT)
			call_to_mutex(elem);
	}
	pthread_detach(*elem->thread);
}

void	thread_init(void)
{
	t_philo		*p_head;
	t_philo		*philo_head;
	
	p_head = manage_philo_list("get", NULL);
	philo_head = p_head;
	while (philo_head->next != p_head)
	{
		pthread_create(philo_head->thread, NULL, (void *)start_thinking, (void *)philo_head);
		pthread_join(*(philo_head->thread), NULL); // Pas ici je crois
		philo_head = philo_head->next;
	}
}
