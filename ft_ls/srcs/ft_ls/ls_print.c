#include "ft_ls.h"

void	ls_recursion(char *path, t_list *entries, t_options *options)
{
	char			*path_new;
	char			*entry;
	struct stat		estat;

	if (options->R)
		while (entries)
		{
			entry = entries->content;
			if (!ft_strequ(".", entry) && !ft_strequ("..", entry))
			{
				path_new = get_full_name(path, entry, 1);
				if (lstat(path_new, &estat) != 0)
					ls_error(path);
				if (S_ISDIR(estat.st_mode))
				{
					ft_putchar('\n');
					ft_putstr(path_new);
					ft_putendl(":");
					ls_print(path_new, options);
				}
				ft_strdel(&path_new);
			}
			entries = entries->next;
		}
}

void	ls_print(char *path, t_options *options)
{
	t_list			*entries;

	entries = (ls_path(path)) ? ls_get_files(path, options) : 0;
	if (!entries)
		return ;
	if (!options->r)
	{
		if (options->t)
			ft_lstusort(&entries, ls_sort_time);
		else
			ft_lstusort(&entries, ls_sort_alpha);
	}
	else
	{
		if (options->t)
			ft_lstusort(&entries, ls_sort_time_reverse);
		else
			ft_lstusort(&entries, ls_sort_alpha_reverse);
	}
	if (options->l)
		ls_print_long(entries, path, options);
	else
		ls_print_short(entries, options);
	ls_recursion(path, entries, options);
	ft_lstdel(&entries, free_lst);
}

char	*ls_path(char *str)
{
	static char	*path;

	if (str)
		path = str;
	return (path);
}
