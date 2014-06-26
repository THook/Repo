/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 19:09:45 by hvillain          #+#    #+#             */
/*   Updated: 2014/06/26 11:28:58 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "glob.h"

static int		ft_parse_three(t_struct *glob, char *first)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_strdup(first);
	ft_memdel((void **)&first);
	while (line || get_next_line(0, &line) > 0)
	{
		if (i == 1)
			add_to_list(line, glob);
		i = 1;
		if (line[0] == '#')
			;
		else if (is_linking(line))
		{
			ft_memdel((void **)&line);
			return (resolve(glob));
		}
		else
			if (add_pipe(line, glob) == -1)
				return (-2);
		ft_memdel((void **)&line);
	}
	return (resolve(glob));
}

static int		ft_parse_two(t_struct *glob)
{
	char	*line;
	int		flag;

	while (get_next_line(0, &line) > 0)
	{
		add_to_list(line, glob);
		if (!ft_strcmp(line, "##start"))
			flag = 1;
		else if (!ft_strcmp(line, "##end"))
			flag = 2;
		else if (line[0] == '#')
			;
		else if (is_room(line))
			return (ft_parse_three(glob, line));
		else
		{
			if (add_room(line, glob, flag) == 1)
				return (-12);
			flag = 0;
		}
		ft_memdel((void **)&line);
	}
	return (0);
}

static int		parser(t_struct *glob)
{
	char		*line;

	while (get_next_line(0, &line) > 0)
	{
		add_to_list(line, glob);
		if (line[0] == '#')
			continue ;
		else if (is_nbr(ft_strtrim(line)) || ft_atoi(ft_strtrim(line)) == 0)
			return (-1);
		else
		{
			glob->ant_nbr = ft_atoi(ft_strtrim(line));
			ft_memdel((void **)&line);
			break ;
		}
		ft_memdel((void **)&line);
	}
	return (ft_parse_two(glob));
}

int				main(int ac, char **av)
{
	t_struct	*glob;
	int			ret;

	if (ac != 1)
	{
		av = av + 10;
		error_messages(-10);
		return (0);
	}
	glob = glob_init();
	if ((ret = parser(glob)) < 0)
		return (error_messages(ret));
	if (cant_finish(glob))
	{
		ft_putendl("can't finish !");
		return (0);
	}
	print_list(glob);
	create_lemtab(glob);
	lets_lem(glob);
	return (0);
}

