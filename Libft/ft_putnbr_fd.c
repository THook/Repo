/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 18:21:06 by hvillain          #+#    #+#             */
/*   Updated: 2013/11/30 20:40:27 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0 && n != -2147483648 && n = -n)
		ft_putchar_fd('-', fd);
	if (n < 10)
		ft_putchar_fd((n + '0'), fd);
	else if (n >= 10)
	{
		ft_putchar_fd((n / 10), fd);
		ft_putchar_fd((n % 10), fd);
	else
		ft_putstr_fd("-2147483648", fd);
}
