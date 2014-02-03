/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 17:11:48 by hvillain          #+#    #+#             */
/*   Updated: 2014/01/17 18:03:13 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		r_alloc(char **buf, int size)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = *buf;
	*buf = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + size + 1));
	while (tmp[++i])
		(*buf)[i] = tmp[i];
	(*buf)[i] = '\0';
	//free(tmp);
	return (i);
}

static int		get_part(char **buf, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *buf;
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	if (tmp[i] != '\n')
		return (0);
	tmp[i] = '\0';
	*line = ft_strdup(*buf);
	*buf = ft_strdup(*buf + i + 1);
	free(tmp);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	int				i;
	int				ret;
	static char		*buf = NULL;

	ret = 1;
	if (buf == NULL)
		buf = ft_strdup("");
	while (ret)
	{
		if (get_part(&buf, line))
			return (1);
		i = r_alloc(&buf, BUF_SIZE);
		if ((ret = read(fd, buf + i, BUF_SIZE)) == -1)
			return (-1);
		buf[i + ret] = '\0';
	}
	*line = ft_strdup(buf);
	free(buf);
	return (0);
}

int				main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		ret;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("%s\n", line);
			free(line);
		}
	}
	return (0);
}
