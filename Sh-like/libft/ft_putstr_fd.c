/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:26:59 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/03 17:27:00 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_fd(const char *str, int fd)
{
	if (str != NULL)
	{
		while (*str != '\0')
		{
			ft_putchar_fd(*str, fd);
			str++;
		}
	}
}
