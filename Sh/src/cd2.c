/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 19:33:24 by hvillain          #+#    #+#             */
/*   Updated: 2014/01/27 19:43:46 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libsh.h"
#include <stdlib.h>
#include <unistd.h>

void		setfromhome(char **env, char *line)
{
	int     j;
	int     k;
	int		l;
	char    *path;

	j = 0;
	k = 0;
	l = 0;
	while (env[j] && ft_strcmp("PWD", ft_strdub(env[j], '=')))
		j++;
	while (env[k] && ft_strcmp("OLDPWD", ft_strdub(env[k], '=')))
		k++;
	while (env[l] && ft_strcmp("HOME", ft_strdub(env[l], '=')))
		l++;
	path = ft_strjoin(env[l] + 5, line + 1);
	ft_putstr(path);
	
	if (!(chdir(path = ft_strjoin(env[l] + 5, line + 1))))
	{
		env[k] = ft_strjoin("OLDPWD=", env[j] + 4);
		env[j] = ft_strjoin("PWD=", path);
		free(path);
	}
	else
		ft_putstr("No way you're gun get there");
}

