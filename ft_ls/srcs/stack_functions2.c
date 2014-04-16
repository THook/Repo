/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 21:52:59 by hvillain          #+#    #+#             */
/*   Updated: 2014/04/16 22:12:43 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

void			dirinit(t_dirlist *newdir)
{
	newdir->nodir = 0;
	newdir->scanned = 0;
	newdir->blocks = 0;
	newdir->maxnlink = 0;
	newdir->maxsize = 0;
	newdir->maxuidlen = 0;
	newdir->maxgidlen = 0;
	newdir->filelist = NULL;
	newdir->previous = NULL;
	newdir->next = NULL;
}

t_dirlist		*ft_newdir(char *dir, t_params *params)
{
	t_dirlist		*newdir;
	struct stat		*buf;
	mode_t			mode;

	params = NULL;
	buf = (struct stat *)malloc(sizeof(struct stat));
	newdir = (t_dirlist *)malloc(sizeof(t_dirlist));
	if (stat(dir, buf) == -1 || !buf || !newdir)
	{
		if (buf && newdir)
			perror(ft_strjoin("ls: ", dir));
		return (NULL);
	}
	dirinit(newdir);
	mode = buf->st_mode;
	newdir->name = ft_strdup(dir);
	newdir->lastmodif = buf->st_mtimespec;
	if (!S_ISDIR(mode))
	{
		newdir->name = ".";
		newdir->nodir = 1;
		ft_addfile(newdir, dir, params);
	}
	return (newdir);
}

int				ft_dircmp(t_dirlist *dir, t_dirlist *dir2, t_params *param)
{
	int		val;
	int		result;

	val = (int)(dir2->lastmodif).tv_sec;
	if (param->opt_t)
		result = val - (int)(dir->lastmodif).tv_sec;
	else
		result = ft_strcmp(dir->name, dir2->name);
	return (result);
}

t_dirlist		*ft_adddir(t_params *params, char *dir)
{
	t_dirlist	*lastdir;
	t_dirlist	*newdir;
	t_dirlist	*tmpdir;

	tmpdir = NULL;
	newdir = ft_newdir(dir, params);
	if (!newdir)
		return (NULL);
	lastdir = params->dirlist;
	while (lastdir && ft_dircmp(lastdir, newdir, params) < 0)
	{
		tmpdir = lastdir;
		lastdir = lastdir->next;
	}
	newdir->next = lastdir;
	if (lastdir)
		lastdir->previous = newdir;
	if (tmpdir)
	{
		tmpdir->next = newdir;
		newdir->previous = tmpdir;
	}
	else
		params->dirlist = newdir;
	return (newdir);
}
