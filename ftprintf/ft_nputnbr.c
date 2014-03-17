/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:17:52 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/12 06:31:36 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_nputstr(char *s);
int		ft_nputchar(char c);

void	ft_nputnbr(int n)
{

	if (n == -2147483648)
		ft_nputstr("-2147483648");
	else if (n < 0 && (n = -n))
		ft_nputchar('-');
	if (n >= 10)
	{
		ft_nputnbr(n / 10);
		ft_nputnbr(n % 10);
	}
	else
		ft_nputchar(n + '0');
}

