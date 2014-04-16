/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scandir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 21:50:05 by hvillain          #+#    #+#             */
/*   Updated: 2014/04/16 22:53:22 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../includes/libft.h"
#include <dirent.h>
#include <errno.h>
#include <stdio.h>

void					handlerecur(t_filelist *file, t_params *params)
{
	t_dirlist	*newdir;

	newdir = ft_adddir(params, file->name);
	if (!newdir)
		return ;
	ft_scandir(newdir, params);
}

void					ft_scandir(t_dirlist *file, t_params *params)
{
	char				*name;
	DIR					*dir;
	struct dirent		*dirent;

	if (file->scanned)
		return ;
	name = file->name;
	dir = opendir(name);
	if (!dir)
	{
		perror(ft_strjoin("ls: ", name));
		return ;
	}
	while ((dirent = readdir(dir)))
	{
		if (dirent->d_name[0] != '.' || params->opt_a)
			ft_addfile(file, dirent->d_name, params);
	}
	if (closedir(dir) == -1)
	{
		perror(NULL);
		return ;
	}
	file->scanned = 1;
}

void					ft_nameandblks(t_dirlist *dir, t_params *params)
{
	if (params->newline && !dir->nodir)
		ft_putchar('\n');
	params->newline = 1;
	if ((params->dirlist)->next && !dir->nodir)
	{
		ft_putstr(dir->name);
		ft_putstr(":\n");
	}
	if (params->opt_l && !dir->nodir)
	{
		ft_putstr("total ");
		ft_putnbr((int)dir->blocks);
		ft_putchar('\n');
	}
}

void					ft_printdir(t_dirlist *dir, t_params *params)
{
	t_filelist	*file;
	t_filelist	*last;

	ft_nameandblks(dir, params);
	file = dir->filelist;
	while (file)
	{
		if (!params->opt_r)
			ft_printfile(dir, file, params);
		last = file;
		file = file->next;
	}
	file = last;
	while (file && params->opt_r)
	{
		ft_printfile(dir, file, params);
		file = file->previous;
	}
}

void					ft_printdirs(t_params *params)
{
	t_dirlist	*dir;
	t_dirlist	*last;

	dir = params->dirlist;
	while (dir)
	{
		if (!params->opt_r)
			ft_printdir(dir, params);
		last = dir;
		dir = dir->next;
	}
	dir = last;
	while (dir && params->opt_r)
	{
		ft_printdir(dir, params);
		dir = dir->previous;
	}
}
