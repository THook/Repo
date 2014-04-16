/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 21:53:30 by hvillain          #+#    #+#             */
/*   Updated: 2014/04/16 21:59:49 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/stat.h>

typedef struct			s_filelist
{
	char				*dir;
	char				*name;
	mode_t				mode;
	nlink_t				nlink;
	uid_t				uid;
	gid_t				gid;
	struct timespec		lastmodif;
	off_t				size;
	struct s_filelist	*previous;
	struct s_filelist	*next;
}						t_filelist;

typedef struct			s_dirlist
{
	char				*name;
	int					nodir;
	int					scanned;
	blkcnt_t			blocks;
	struct timespec		lastmodif;
	int					maxnlink;
	int					maxsize;
	int					maxuidlen;
	int					maxgidlen;
	struct s_filelist	*filelist;
	struct s_dirlist	*previous;
	struct s_dirlist	*next;
}						t_dirlist;

typedef struct			s_params
{
	int					opt_l;
	int					opt_rec;
	int					opt_a;
	int					opt_r;
	int					opt_t;
	int					newline;
	t_dirlist			*dirlist;
	t_filelist			*filelist;
}						t_params;

void			ft_printfile(t_dirlist *dir, t_filelist *file, t_params *params);
void			handlerecur(t_filelist *file, t_params *params);
void			ft_scandir(t_dirlist *file, t_params *params);
void			ft_printdir(t_dirlist *dir, t_params *params);
void			ft_printdirs(t_params *params);
t_params		*ft_newparams(void);
void			ft_addoption(t_params **params, char *option);
t_params		*ft_getparams(int argc, char **argv);
void			ft_uidspaces(t_dirlist *dir, t_filelist *file);
int				ft_digits(int n);
t_filelist		*ft_newfile(t_dirlist *dirlist, char *file);
void			ft_addfile(t_dirlist *dirlist, char *file, t_params *param);
void			ft_nlinkspaces(t_dirlist *dir, t_filelist *file);
void			ft_sizespaces(t_dirlist *dir, t_filelist *file);
void			ft_gidspaces(t_dirlist *dir, t_filelist *file);
void			ft_nlinkspaces(t_dirlist *dir, t_filelist *file);
void			ft_sizespaces(t_dirlist *dir, t_filelist *file);
t_dirlist		*ft_newdir(char *dir, t_params *params);
int				ft_dircmp(t_dirlist *dir, t_dirlist *dir2, t_params *param);
t_dirlist		*ft_adddir(t_params *params, char *dir);

#endif
