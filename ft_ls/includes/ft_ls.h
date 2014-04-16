#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# define BUFF_SIZE 200

typedef struct	s_options
{
	int			l;
	int			r;
	int			R;
	int			a;
	int			t;
}				t_options;

typedef struct	s_file
{
	char		*name;
}				t_file;

void	free_lst(void *d, size_t s);
void	ls_options_init(t_options *options);
int		ls_options_set(int ac, char **av, t_options *options);
void	ls_error(char *path);
void	ls_print(char *path, t_options *options);
void	ls_recursion(char *path, t_list *entries, t_options *options);
char	*ls_path(char *str);
void	ls_print_short(t_list *entries, t_options *options);
void	ls_print_long(t_list *entries, char *path, t_options *options);
void	ls_print_long_counters
			(t_list* entries, char *path, t_options *options, size_t *counts);
void	ls_print_long_counters2
			(size_t *counts, struct stat *s, struct passwd *p, struct group *g);
void	ls_print_name(char *entry, char *path, struct stat *estat);
void	ls_print_permissions(struct stat *estat);
void	ls_print_user(uid_t uid, size_t length);
void	ls_print_group(gid_t gid, size_t length);
void	ls_print_time(char *str, struct stat *estat);
void	ls_print_long_line(char *entry, char *path, size_t *counts);
DIR		*ls_opendir(char *name);
t_list	*ls_get_files(char *name, t_options *options);
int		ls_closedir(DIR *dir);
int		ls_sort_alpha(t_list *lst1, t_list *lst2);
int		ls_sort_alpha_reverse(t_list *lst1, t_list *lst2);
int		ls_sort_time(t_list *lst1, t_list *lst2);
int		ls_sort_time_reverse(t_list *lst1, t_list *lst2);
int		is_hidden(char *name);
int		get_month_number(char *month);
char	*get_full_name(char *path, char *name, int prefix);
char 	*clean_path(char *path, int root_slash);

#endif
