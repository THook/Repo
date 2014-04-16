/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 17:07:42 by tmertz            #+#    #+#             */
/*   Updated: 2014/04/16 22:43:32 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../includes/libft.h"
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <sys/stat.h>
#include <time.h>

int			ft_writemode(t_filelist *file, int mask, char c, char d)
{
	if ((file->mode & mask) == mask)
	{
		if (c)
			ft_putchar(c);
		return (1);
	}
	else
	{
		if (d)
			ft_putchar(d);
		return (0);
	}
}

void		ft_printmode(t_filelist *file)
{
	ft_writemode(file, S_IFBLK, 'b', 0);
	ft_writemode(file, S_IFCHR, 'c', 0);
	ft_writemode(file, S_IFDIR, 'd', 0);
	ft_writemode(file, S_IFLNK, 'l', 0);
	ft_writemode(file, S_IFSOCK, 's', 0);
	ft_writemode(file, S_IFIFO, 'p', 0);
	ft_writemode(file, S_IFREG, '-', 0);
	ft_writemode(file, S_IRUSR, 'r', '-');
	ft_writemode(file, S_IWUSR, 'w', '-');
	if (!ft_writemode(file, S_ISUID + S_IXUSR, 's', 0))
		if (!ft_writemode(file, S_ISUID, 'S', 0))
			ft_writemode(file, S_IXUSR, 'x', '-');
	ft_writemode(file, S_IRGRP, 'r', '-');
	ft_writemode(file, S_IWGRP, 'w', '-');
	if (!ft_writemode(file, S_ISGID + S_IXGRP, 's', 0))
		if (!ft_writemode(file, S_ISGID, 'S', 0))
			ft_writemode(file, S_IXGRP, 'x', '-');
	ft_writemode(file, S_IROTH, 'r', '-');
	ft_writemode(file, S_IWOTH, 'w', '-');
	if (!ft_writemode(file, S_ISVTX + S_IXOTH, 't', 0))
		if (!ft_writemode(file, S_ISVTX, 'T', 0))
			ft_writemode(file, S_IXOTH, 'x', '-');
}

void		ft_printfile(t_dirlist *dir, t_filelist *file, t_params *params)
{
	if (params->opt_l)
	{
		ft_printmode(file);
		ft_nlinkspaces(dir, file);
		ft_putnbr(file->nlink);
		ft_putchar(' ');
		ft_putstr(getpwuid(file->uid)->pw_name);
		ft_uidspaces(dir, file);
		ft_putstr(getgrgid(file->gid)->gr_name);
		ft_gidspaces(dir, file);
		ft_sizespaces(dir, file);
		ft_putnbr((int)file->size);
		ft_putchar(' ');
		ft_putstr(ft_strsub(ctime(&(file->lastmodif).tv_sec), 4, 12));
		ft_putchar(' ');
	}
	ft_putstr(file->name);
	ft_putchar('\n');
}
