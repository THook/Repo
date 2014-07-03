/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/03 01:13:16 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/03 07:54:36 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_fork		*manage_philo_list(char *macro, t_philo *elem) 
{
	static t_philo	*head;

	if (macro == "add")
		add_philo_list(head, elem);
	else if (macro == "get")
		return (head);
	else if (macro == "set")
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
	new->next = NULL;
	new->prev = NULL;
	new->f_left = NULL;
	new->f_right = NULL;
	manage_philo_list("add", new);
	return (0);
}

void		print_philo(t_philo *elem)
{
	ft_printf("print_philo:\n");
	ft_printf("philo: %p\n", elem);
	ft_printf("philo->state: %d\n", elem->state);
	ft_printf("philo->life: %d\n", elem->life);
	return ;
}
