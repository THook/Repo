/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 14:37:50 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/12 03:50:53 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		find_char(char c)
{
	if (c == 'd')
		return (INT);
	if (c == 'c')
		return (CHR);
	if (c == 's')
		return (STR);
	if (c == 'f')
		return (FLT);
	if (c == 'p')
		return (PTR);
	if (c == 'x')
		return (HEX);
	if (c == '%')
		return (MOD);
	else
		return (0);
}

int		print_2(char c, va_list ap)
{
	unsigned long int	p;
	int					ret;

	if (c == '%')
	{
		ret = ft_nputchar(c);
		return (ret);
	}
	if (c == 'p' && (p = va_arg(ap, unsigned long int)))
	{
		ft_nputhex(p);
		return (0);
	}
	return (0);
}

int		print(char c, va_list ap)
{
	char	*str;
	int		nb;
	char	d;
	int		ret;

	if (find_char(c) == INT && (nb = va_arg(ap, int)))
	{
		ret = ft_nputnbr(nb);
		return (ret);
	}
	if (find_char(c) == CHR && (d = va_arg(ap, int)))
	{
		ret = ft_nputchar(d);
		return (ret);
	}
	if (find_char(c) == STR && (str = va_arg(ap, char *)))
	{
		ret = ft_nputstr(str);
		return (ret);
	}
	if (find_char(c) == 0)
		return (-1);
	else
		ret = print_2(c, ap);
	return (ret);
}
		
int		ft_printf(const char *s, ...)
{
	va_list		ap;
	int			ret;
	int			i;

	i = 1;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			if ((ret = print(*(s + 1), ap)) == -1)
				return (ERROR);
			s++;
			i += ret;
		}
		else
		{
			ft_nputchar(*s);
			i++;
		}
		s++;
	}
	va_end(ap);
	return (i);
}

