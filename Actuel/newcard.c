/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newcard.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 21:04:27 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/27 20:01:23 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

void	wild_card(char *line);

int		is_point(char *prev)
{
	if (prev[0] == '.')
		return (1);
	return (0);
}

int		end_point(char *prev)
{
	int		i;

	i = 0;
	while (prev[i])
		i++;
	i--;
	while (i >= 0 && prev[i] != '/' && prev[i] != '.')
		i--;
	if (i == 0 || prev[i] == '/')
		return (1);
	return (0);
}

void	card2(char *s, char *prev, int type, t_list *tokens)
{
	struct dirent	*file;
	DIR				*ret;

	if (!*s && type == 1)
	{
		if (prev[ft_strlen(prev) - 1] != '.' && end_point(prev))
			ft_create_token(tokens, ft_strdup(prev), 0);
		return ;
	}
	if ((ret = opendir(prev)) == NULL)
		return ;
	while ((file = readdir(ret)) != NULL)
	{
		if (match(file->d_name, s) && !is_point(file->d_name))
		{
			if (prev[ft_strlen(prev) - 1] != '/')
				prev = ft_strjoin(prev, "/");
			if (ft_strncmp(prev, "././", 4))
				ft_create_token(tokens, ft_strjoin(prev, file->d_name), 0);
		}
	}
	closedir(ret);
}

void	card(char *s, char *p, int type, t_list *tokens)
{
	struct dirent	*f;
	DIR				*ret;
	char			*t;
	int				i;

	i = 0;
	if (s[0] == '/')
		return (card(s + 1, "/", type, tokens));
	if ((ret = opendir(p)) == NULL)
		return ;
	if (((t = ft_strchr(s, '/')) != NULL))
	{
		while ((f = readdir(ret)) != NULL)
		{
			if ((match(f->d_name, ft_strsub(s, 0, t - s), tokens)))
			{
				card(t + 1, ft_strjoin(p, f->d_name), type, tokens);
				i = 1;
			}
		}
	}
	if (i == 0)
		card2(s, p, type, tokens);
	closedir(ret);
}

void	wild_card(char *line, t_list *tokens)
{
	int		type;

	if (line[ft_strlen(line) - 1] == '/')
		type = 1;
	else
		type = 2;
	if (line[0] == '.' && line[1] && line[1] == '/')
	{
		opendir("./");
		card(line + 2, "./", type, tokens);
	}
	if (line[0] == '.' && line[1] && line[1] == '.' && line[2] 
			&& line[2] == '/')
	{
		opendir("../");
		card(line + 3, "../", type, tokens);
	}
	else if (line[0] == '/')
	{
		opendir("/");
		card(line + 1, "/", type, tokens);
	}
	else
		card(line, "./", type, tokens);
}
