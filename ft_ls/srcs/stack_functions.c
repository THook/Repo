/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 21:52:41 by hvillain          #+#    #+#             */
/*   Updated: 2014/04/16 22:43:52 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../includes/libft.h"
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>

int				ft_digits(int n)
{
	int		i;

	i = 1;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void			setspaces(t_dirlist *dirlist, t_filelist *newfile)
{
	if (dirlist->maxnlink < ft_digits((int)newfile->nlink))
		dirlist->maxnlink = ft_digits((int)newfile->nlink);
	if (dirlist->maxsize < ft_digits((int)newfile->size))
		dirlist->maxsize = ft_digits((int)newfile->size);
	if (dirlist->maxuidlen < (int)ft_strlen(getpwuid(newfile->uid)->pw_name))
		dirlist->maxuidlen = ft_strlen(getpwuid(newfile->uid)->pw_name);
	if (dirlist->maxgidlen < (int)ft_strlen(getgrgid(newfile->gid)->gr_name))
		dirlist->maxgidlen = ft_strlen(getgrgid(newfile->gid)->gr_name);
}

t_filelist		*ft_newfile(t_dirlist *dirlist, char *file)
{
	char		*dir;
	t_filelist	*newfile;
	struct stat	*buf;

	dir = dirlist->name;
	newfile = (t_filelist *)malloc(sizeof(t_filelist));
	buf = (struct stat *)malloc(sizeof(struct stat));
	if (dir[ft_strlen(dir) + 1] != '/')
		dir = ft_strjoin(dir, "/");
	if (stat(ft_strjoin(dir, file), buf) == -1)
		perror(ft_strjoin("ls: ", file));
	newfile->dir = dir;
	newfile->name = ft_strdup(file);
	newfile->mode = buf->st_mode;
	newfile->nlink = buf->st_nlink;
	newfile->uid = buf->st_uid;
	newfile->gid = buf->st_gid;
	newfile->lastmodif = buf->st_mtimespec;
	newfile->size = buf->st_size;
	newfile->next = NULL;
	newfile->previous = NULL;
	setspaces(dirlist, newfile);
	dirlist->blocks += buf->st_blocks;
	return (newfile);
}

int				ft_filecmp(t_filelist *file, t_filelist *file2, t_params *param)
{
	int		val;
	int		result;

	val = (int)(file2->lastmodif).tv_sec;
	if (param->opt_t)
		result = val - (int)(file->lastmodif).tv_sec;
	else
		result = ft_strcmp(file->name, file2->name);
	return (result);
}

void			ft_addfile(t_dirlist *dirlist, char *file, t_params *param)
{
	t_filelist	*lastfile;
	t_filelist	*newfile;
	t_filelist	*tmpfile;

	tmpfile = NULL;
	newfile = ft_newfile(dirlist, file);
	lastfile = dirlist->filelist;
	while (lastfile && ft_filecmp(lastfile, newfile, param) < 0)
	{
		tmpfile = lastfile;
		lastfile = lastfile->next;
	}
	newfile->next = lastfile;
	if (lastfile)
		lastfile->previous = newfile;
	if (tmpfile)
	{
		tmpfile->next = newfile;
		newfile->previous = tmpfile;
	}
	else
		dirlist->filelist = newfile;
	if (S_ISDIR(newfile->mode) && param->opt_rec)
		handlerecur(newfile, param);
}
