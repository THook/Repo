/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 18:43:29 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/23 22:59:40 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "glob.h"

int			cant_finish(t_struct *glob)
{
	t_root		*cur;

	cur = glob->root;
	if (!cur)
		return (1);
	else
		return (0);
}

int			error_messages(int n)
{
	if (n == -1)
		ft_putendl("Please enter a positive number");
	else if (n == -2)
		ft_putendl("Problem creating tubes");
	else if (n == -3)
		ft_putendl("Problem reading input");
	else if (n == -4)
		ft_putendl("No starting room");
	else if (n == -5)
		ft_putendl("Please pipe the starting room");
	else if (n == -6)
		ft_putendl("Please enter a positive number");
	else if (n == -7)
		ft_putendl("No ending room");
	else if (n == -8)
		ft_putendl("Too much ending rooms");
	else if (n == -9)
		ft_putendl("Too much starting rooms");
	else if (n == -10)
		ft_putendl("Please don't insert any arguments");
	else if (n == -11)
		ft_putendl("A room can't be end and start");
	else if (n == -12)
		ft_putendl("Two rooms can't have the same name");
	return (0);
}
