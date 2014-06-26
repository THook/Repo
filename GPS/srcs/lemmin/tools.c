/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 15:39:26 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/18 18:02:08 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int			is_nbr(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] >= '0' && line[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int			is_comment(char *line)
{
	if (ft_strlen(line) > 1 && line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

int			is_room(char *line)
{
	char		**tab;
	int			ret;

	ret = 0;
	tab = ft_strsplit(line, ' ');
	if (ft_ptrlen(tab) != 3)
		ret = 1;
	else if (tab[0][0] == 'L')
		ret = 1;
	else if ((tab[1] && is_nbr(tab[1])) || (tab[2] && is_nbr(tab[2])))
		ret = 1;
	ft_memdel((void **)&tab);
	return (ret);
}

int			is_linking(char *line)
{
	char	**tab;
	int		ret;

	ret = 0;
	tab = ft_strsplit(line, '-');
	if (ft_ptrlen(tab) != 2)
		ret = 1;
	else if (tab[0][0] == 'L')
		ret = 1;
	else if ((tab[1] && tab[1][0] == 'L') || (tab[1] && tab[1][0] == '#'))
		ret = 1;
	ft_memdel((void **)&tab);
	return (ret);
}

