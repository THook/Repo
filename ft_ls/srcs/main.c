/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 21:48:59 by hvillain          #+#    #+#             */
/*   Updated: 2014/04/16 22:04:29 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				main(int argc, char **argv)
{
	t_params	*params;
	t_dirlist	*dirlist;

	params = ft_getparams(argc, argv);
	dirlist = params->dirlist;
	while (dirlist)
	{
		if (!dirlist->nodir)
			ft_scandir(dirlist, params);
		dirlist = dirlist->next;
	}
	ft_printdirs(params);
	return (0);
}
