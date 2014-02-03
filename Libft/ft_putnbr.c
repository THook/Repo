/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:17:52 by hvillain          #+#    #+#             */
/*   Updated: 2013/12/01 17:15:22 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char const *s);

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	if (n < 0 && (n != -2147483648 && (n = -n)))
		ft_putchar('-');
	if (n < 10)
		ft_putchar(n + '0');
	else if (n >= 10)
	{
		ft_putchar(n / 10);
		ft_putchar(n % 10);
	}
}
