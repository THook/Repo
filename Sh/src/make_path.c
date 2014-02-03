/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 01:14:01 by hvillain          #+#    #+#             */
/*   Updated: 2014/01/26 23:04:58 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int		absolute_check(char *cmd)
{
	if (access(cmd, F_OK) == 0)
		{
			if (access(cmd, X_OK) == 0)
				return (1);
			if ((access(cmd, X_OK) == -1) && (ft_putstr("access denied\n")))
				exit(0);
		}
	return (0);
}

char			*make_path(char *cmd, char **tab)
{
	int		i;
	char	*add;
	char	*sum;

	i = 0;
	add = ft_strdup("/");
	cmd = ft_strjoin(add, cmd);
	sum = NULL;
	if (absolute_check(cmd))
		return (cmd);
	while (tab[i])
	{
		sum = ft_strjoin(tab[i++], cmd);
		if (access(sum, F_OK) == 0)
		{
			if (access(sum, X_OK) == 0)
				return (sum);
			if ((access(sum, X_OK) == -1) && (ft_putstr("access denied\n")))
				exit(0);
		}
		free(sum);
	}
	ft_putstr("Command not found\n");
	exit(0);
	return (sum);
}

