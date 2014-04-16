/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 12:50:43 by hvillain          #+#    #+#             */
/*   Updated: 2013/12/28 17:01:59 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define INT 1
# define CHR 2
# define STR 3
# define FLT 4
# define PTR 5
# define HEX 6
# define MOD 7
# define ERROR -1

int		ft_nputchar(char c);
int		ft_nputnbr(int nb);
int		ft_nputhex(unsigned long int n);
int		ft_nputstr(char *s);
int		ft_printf(const char *s, ...) __attribute__((format(printf, 1, 2)));

#endif
