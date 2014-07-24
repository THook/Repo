/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/23 20:28:56 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/24 00:05:24 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"


static int					ft_nbchar(int n)
{
	int			i;

	i = 0;
	while (n <= -10 || n >= 10)
	{
		n = n / 10;
		i++;
	}
	if (n < 0)
		return (i + 2);
	return (i + 1);
}

static char					*ft_invnb(int n)
{
	char		*str;
	int			i;

	i = 0;
	str = (char *)malloc(12 * sizeof(char));
	if (n == 0)
		str[i++] = '0';
	while (n)
	{
		str[i++] = (n % 10) + '0';
		n = n / 10;
	}
	str[i] = 0;
	return (str);
}

char						*ft_itoa(int n)
{
	char		*str;
	char		*strinv;
	int			i;
	int			j;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	str = (char *)malloc(ft_nbchar(n) * sizeof(char));
	if (n < 0)
	{
		str[i++] = '-';
		n = (-1) * n;
	}
	strinv = ft_invnb(n);
	j = ft_strlen(strinv);
	while (j > 0)
		str[i++] = strinv[--j];
	str[i] = 0;
	free(strinv);
	return (str);
}

void		operate(t_list *elem)
{
	t_list	*new;
	t_list	*begin;

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
	begin = manage_list("get", NULL, NULL);
	if (elem->prev == begin) 
		manage_list("set", NULL, new);
	//printf("%s\n", new->data);
	//free((void *)elem->next);
	//free((void *)elem->prev);
	//free((void *)elem);
}
