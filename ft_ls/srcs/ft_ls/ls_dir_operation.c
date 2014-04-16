#include "ft_ls.h"

int		ls_closedir(DIR *dir)
{
	if (closedir(dir) != 0)
		return (0);
	return (1);
}

DIR		*ls_opendir(char *name)
{
	DIR	*dir;

	if ((dir = opendir(name)))
		return (dir);
	return (NULL);
}

t_list	*ls_get_files(char *path, t_options *options)
{
	t_list			*entries;
	struct dirent	*entity;
	DIR				*dir;

	dir = ls_opendir(path);
	if ((entries = NULL) == NULL && !dir)
	{
		ls_error(path);
		return (NULL);
	}
	while ((entity = readdir(dir)))
	{
		if (is_hidden(entity->d_name) && !options->R && !options->a)
			continue ;
		if (!entries)
			entries = ft_lstnew(entity->d_name, sizeof(*entity));
		else
			ft_lstadd(&entries, ft_lstnew(entity->d_name, sizeof(*entity)));
	}
	if (!ls_closedir(dir))
	{
		ls_error(path);
		return (NULL);
	}
	return (entries);
}
