#include "ft_ls.h"

int		ls_sort_alpha(t_list *lst1, t_list *lst2)
{
	char	*name1;
	char	*name2;

	name1 = lst1->content;
	name2 = lst2->content;
	return (ft_strcmp(name1, name2));
}

int		ls_sort_alpha_reverse(t_list *lst1, t_list *lst2)
{
	return (ls_sort_alpha(lst2, lst1));
}

int		ls_sort_time(t_list *lst1, t_list *lst2)
{
	char		*name1;
	char		*name2;
	struct stat	stat1;
	struct stat	stat2;
	char		*path;

	name1 = lst1->content;
	name2 = lst2->content;
	path = get_full_name(ls_path(NULL), name1, 1);
	stat(path, &stat1);
	ft_strdel(&path);
	path = get_full_name(ls_path(NULL), name2, 1);
	stat(path, &stat2);
	ft_strdel(&path);
	if (stat1.st_mtime > stat2.st_mtime)
		return (1);
	return 0;
}

int		ls_sort_time_reverse(t_list *lst1, t_list *lst2)
{
	return (ls_sort_time(lst2, lst1));
}
