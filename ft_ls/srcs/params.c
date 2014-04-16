/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 21:51:30 by hvillain          #+#    #+#             */
/*   Updated: 2014/04/16 22:05:09 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../includes/libft.h"
#include <stdlib.h>

t_params		*ft_newparams(void)
{
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
	if (!params)
		return (NULL);
	params->opt_l = 0;
	params->opt_rec = 0;
	params->opt_a = 0;
	params->opt_r = 0;
	params->opt_t = 0;
	params->newline = 0;
	params->dirlist = NULL;
	params->filelist = NULL;
	return (params);
}

void			ft_addoption(t_params **params, char *option)
{
	while (*option)
	{
		if (*option == 'l')
			(*params)->opt_l = 1;
		else if (*option == 'R')
			(*params)->opt_rec = 1;
		else if (*option == 'a')
			(*params)->opt_a = 1;
		else if (*option == 'r')
			(*params)->opt_r = 1;
		else if (*option == 't')
			(*params)->opt_t = 1;
		option++;
	}
}

t_params		*ft_getparams(int argc, char **argv)
{
	t_params	*params;
	int			i;
	int			no_more_options;

	i = 1;
	no_more_options = 0;
	params = ft_newparams();
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "--"))
			no_more_options = 1;
		if (argv[i][0] == '-' && !no_more_options)
			ft_addoption(&params, argv[i] + 1);
		else
			ft_adddir(params, argv[i]);
		i++;
	}
	if (!params->dirlist)
		ft_adddir(params, ".");
	return (params);
}
