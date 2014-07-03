/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/03 04:44:01 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/03 09:49:16 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef	PHILO_H
#define		PHILO_H

typedef enum			s_state
{
	REST, THINK, EAT, WAIT
}						t_state;

typedef struct			s_fork
{
		int				id;
		pthread_mutex_t	*mutex;
		struct s_fork	*next;
}						t_fork;

typedef struct			s_philo
{
	struct s_philo		*next;
	struct s_philo		*prev;
	pthread_mutex_t		*fork_left;
	pthread_mutex_t		*fork_right;
	int					previous_state;
	int					id;
	pthread_t			*thread;
	int					state;
	int					life;
	int					time;
}						t_philo;

#endif
#endif
