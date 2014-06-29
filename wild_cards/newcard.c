/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newcard.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 21:04:27 by hvillain          #+#    #+#             */
/*   Updated: 2014/06/28 02:40:43 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include <dirent.h>
#include <sys/types.h>

int		po(char *name)
{
	if (!ft_strcmp(name, ".") || !ft_strcmp(name, ".."))
		return (0);
	return (1);
}

int		is_point(char *prev)
{
	if (prev[0] == '.')
		return (1);
	return (0);
}

void	card2(char *s, char *prev)
{
	struct dirent	*file;
	DIR				*ret;
	int				i;

	i = 1;
	if (!*s && (i = 2))
		s = ft_strdup("*");
	if ((ret = opendir(prev)) == NULL)
		return ;
	while ((file = readdir(ret)) != NULL)
	{
		if (match(file->d_name, s) && !is_point(file->d_name))
			ft_putendl(file->d_name);
	}
}

void	card(char *s, char *p)
{
	struct dirent	*f;
	DIR				*ret;
	char			*t;
	int				i;

	i = 0;
	if (s[0] == '/')
		return (card(s + 1, "/"));
	if ((ret = opendir(p)) == NULL)
		return ;
	if (((t = ft_strchr(s, '/')) != NULL) && (i = 1))
	{
		while ((f = readdir(ret)) != NULL)
		{
			if ((match(f->d_name, ft_strsub(s, 0, t - s)) && !po(f->d_name)))
				return (card(t + 1, p));
		}
	}
	if (i == 0)
		return (card2(s, p));
}

void	wild_card(char *line)
{
	if (line[0] == '.' && line[1] && line[1] == '/')
	{
		opendir("./");
		card(line + 2, "./");
	}
	if (line[0] == '.' && line[1] && line[1] == '.' && line[2] 
			&& line[2] == '/')
	{
		opendir("../");
		card(line + 3, "../");
	}
	else if (line[0] == '/')
	{
		opendir("/");
		card(line + 1, "/");
	}
	else
	{
		opendir("./");
		card(line, "./");
	}
}

int		main(int ac, char **av)
{
	if (ac)
		wild_card(av[1]);
	return (0);
}

