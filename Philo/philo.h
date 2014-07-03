/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/03 04:44:01 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/03 16:48:24 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef	PHILO_H
#define		PHILO_H

#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

#define		MAX_LIFE	10
#define		THINK_T		3
#define		EAT_T		2
#define		NBR_PHILO	7
#define		REST_T		2
#define		COMMUNITY	0

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
	int					last_time;
}						t_philo;




t_fork		*manage_fork_list(char *macro, t_fork *elem);
t_philo		*manage_philo_list(char *macro, t_philo *elem); 
int			create_fork(void);
int			create_philo(void);
void		thread_init(void);

#endif
