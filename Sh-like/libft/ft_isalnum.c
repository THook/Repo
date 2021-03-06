/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:20:15 by tmertz            #+#    #+#             */
/*   Updated: 2014/03/27 06:41:33 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isalnum(int c)
{
	if (c != 0)
	{
		if (ft_isdigit(c) == 1 || ft_isalpha(c) == 1)
		{
			return (1);
		}
		return (0);
	}
	return (0);
}
