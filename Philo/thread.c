/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/03 05:31:29 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/03 07:54:32 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int		time_out(int *time, int *state)
{
	if ((!state && time + REST_T >= time()) ||
			(state == EAT && time + EAT_T >= time()) ||
			(state == THINK && time + THINK_T >= time()))
	{
		*state = WAIT
		*time = time();
		return (0);
	}
	return (1);
}









void	call_to_mutex(t_philo *elem)
{
	if (!phtread_mutex_lock(elem->fork_left))
	{
		if (elem->state == THINK)
		{
			elem->state = EAT;
			elem->previous_state = THINK;
			elem->time = time();
		}
		else




	}
	if (!pthread_mutex_lock(elem->fork_right))




}



void	start_thinking(void *elem)

{
	while (elem->life > 0)
	{
		if (time_out(&elem->time, &elem->state))
			elem->previous_state = elem->state;
		if (elem->state != EAT)
		{
			call_to_mutex(elem);
			if (!pthread_mutex_lock(elem->fork_left))
			{
				if (elem->state == 1)
				{
					elem->state = 2;
					elem->previous_state = 1;
				}	
			}
			pthread_mutex_lock(elem->fork_right); 
		}
	}




}

void	thread_init(void)
{
	t_philo		*p_head;
	t_philo		*philo_head;
	
	p_head = manage_philo_list("get", NULL);
	philo_head = p_head;
	while (philo_head->next != p_head)
	{
		pthread_create(&philo_head, NULL, (void *)start_thinking, (void *)philo_head);
		pthread_join(philo_head, NULL); // Pas ici je crois
		philo_head = philo_head->next;
	}
}
