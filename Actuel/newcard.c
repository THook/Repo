/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newcard.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 21:04:27 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/26 21:40:28 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <dirent.h>
#include <sys/types.h>

void	card(char *s, char *prev)
{
	int				i;
	struct dirent	*file;
	DIR				*ret;
	char			*tmp;

	i = 0;
	if (prev == NULL)
		prev = ft_strdup(".");
	if ((ret = opendir(rest)) == NULL)
		return ;
	if ((tmp = ft_strchr(s, '/')) != NULL)
	{
		while ((file = readdir(ret)) != NULL)
		{
			if (match(file->d_name, ft_strsub(s, 0, (tmp - s + 1)) == 1))
				return (card(tmp + 1, ft_strjoin(ft_strjoin(prev, "/"), file->d_name)));
		}
	}

}

int		main(int ac, vhar **av)
{
	if (ac)
		card(av[1], NULL);
	return (0);
}

