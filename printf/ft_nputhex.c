/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:17:52 by hvillain          #+#    #+#             */
/*   Updated: 2014/06/27 17:56:23 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* n series just return number of characters */
int		ft_nputhex(unsigned long int n)
{
	ft_nputhex(n >> 4);
	if ((n & 0xf) < 10 )
		ft_nputchar((n & 0xf) + '0');
	else
		ft_nputchar((n & 0xf) + 'a');
	return (5);
}

