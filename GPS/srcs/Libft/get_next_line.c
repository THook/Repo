/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 14:36:50 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/18 17:09:04 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"

static int		r_alloc(char **buf, int size)
{
	int		i;
	char	*tmp;

	tmp = *buf;
	*buf = (char *)ft_memalloc(sizeof(char) * (ft_strlen(tmp) + size + 1));
	i = -1;
	while (tmp[++i])
		(*buf)[i] = tmp[i];
	(*buf)[i] = '\0';
	return (i);
}

static int		get_part(char **buf, char **line)
{
	int				i;
	char			*tmp;

	i = 0;
	tmp = *buf;
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	if (tmp[i] != '\n')
		return (0);
	tmp[i] = '\0';
	*line = ft_strdup(*buf);
	*buf = ft_strdup(*buf + i + 1);
	ft_memdel((void **)&tmp);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	int				ret;
	int				i;
	static char		*buf = NULL;

	ret = 1;
	if (buf == NULL)
		buf = ft_strdup("");
	while (ret)
	{
		if (get_part(&buf, line))
			return (1);
		i = r_alloc(&buf, BUF_SIZE);
		ret = read(fd, buf + i, BUF_SIZE);
		if (ret == -1)
			return (-1);
		buf[i + ret] = '\0';
	}
	*line = ft_strdup(buf);
	ft_memdel((void **)&buf);
	return (0);
}

