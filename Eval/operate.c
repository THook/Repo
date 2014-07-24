/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/23 20:28:56 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/24 18:35:11 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

void		operate(t_list *elem)
{
	t_list	*new;

	new = create_elem("prov");
	if (!ft_strcmp(elem->data, "-"))
		new->data = ft_itoa(atoi(elem->prev->data) - atoi(elem->next->data));
	else if (!ft_strcmp(elem->data, "+"))
		new->data = ft_itoa(atoi(elem->prev->data) + atoi(elem->next->data));
	else if (!ft_strcmp(elem->data, "*"))
		new->data = ft_itoa(atoi(elem->prev->data) * atoi(elem->next->data));
	else if (!ft_strcmp(elem->data, "/"))
		new->data = ft_itoa(atoi(elem->prev->data) / atoi(elem->next->data));
	else if (!ft_strcmp(elem->data, "%"))
		new->data = ft_itoa(atoi(elem->prev->data) % atoi(elem->next->data));
	new->id = 0;
	new->next = elem->next->next;
	new->prev = elem->prev->prev;
	elem->next->next->prev = new;
	elem->prev->prev->next = new;
	if (elem->prev == manage_list("get", NULL, NULL))
		manage_list("set", NULL, new);
	//printf("%s\n", new->data);
	//free((void *)elem->next);
	//free((void *)elem->prev);
	//free((void *)elem);
}
