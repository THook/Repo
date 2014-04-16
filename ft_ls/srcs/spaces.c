/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 21:51:55 by hvillain          #+#    #+#             */
/*   Updated: 2014/04/16 22:11:43 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../includes/libft.h"
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <uuid/uuid.h>

void	ft_uidspaces(t_dirlist *dir, t_filelist *file)
{
	int		spaces;

	spaces = ft_strlen(getpwuid(file->uid)->pw_name);
	while (spaces++ <= dir->maxuidlen + 1)
		ft_putchar(' ');
}

void	ft_gidspaces(t_dirlist *dir, t_filelist *file)
{
	int		spaces;

	spaces = ft_strlen(getgrgid(file->gid)->gr_name);
	while (spaces++ <= dir->maxgidlen - 1)
		ft_putchar(' ');
}

void	ft_nlinkspaces(t_dirlist *dir, t_filelist *file)
{
	int		spaces;

	spaces = ft_digits((int)file->nlink);
	while (spaces++ <= dir->maxnlink + 1)
		ft_putchar(' ');
}

void	ft_sizespaces(t_dirlist *dir, t_filelist *file)
{
	int		spaces;

	spaces = ft_digits((int)file->size);
	while (spaces++ <= dir->maxsize + 1)
		ft_putchar(' ');
}
