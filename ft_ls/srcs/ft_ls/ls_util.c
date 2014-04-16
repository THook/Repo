#include "libft.h"
#include <stdlib.h>

int		get_month_number(char *month)
{
	if (ft_strequ(month, "Jan"))
		return (1);
	else if (ft_strequ(month, "Feb"))
		return (2);
	else if (ft_strequ(month, "Mar"))
		return (3);
	else if (ft_strequ(month, "Apr"))
		return (4);
	else if (ft_strequ(month, "May"))
		return (5);
	else if (ft_strequ(month, "Jun"))
		return (6);
	else if (ft_strequ(month, "Jul"))
		return (7);
	else if (ft_strequ(month, "Aug"))
		return (8);
	else if (ft_strequ(month, "Sep"))
		return (9);
	else if (ft_strequ(month, "Oct"))
		return (10);
	else if (ft_strequ(month, "Nov"))
		return (11);
	else if (ft_strequ(month, "Dec"))
		return (12);
	return (-1);
}

int		is_hidden(char *name)
{
	if (name[0] == '.')
		return (1);
	return (0);
}

char	*clean_path(char *path, int root_slash)
{
	char	*new;
	int		i;
	int		count;

	i = 0;
	count = (path[0] == '/' && !root_slash) ? 1 : 0;
	while (path[i])
	{
		if (path[i] == '/' && path[i + 1] == '/')
			count++;
		i++;
	}
	new = (char*)malloc(sizeof(*new) * (ft_strlen(path) - count));
	i = 0;
	if (path[0] == '/' && !root_slash)
		path += 2;
	while (*path)
	{
		new[i] = *path;
		while (*path == '/' && *(path + 1) == '/')
			path++;
		i++;
		path++;
	}
	return (new);
}

char	*get_full_name(char *path, char *name, int prefix)
{
	char	*out;
	char	*tmp;

	out = ft_strjoin(path, "/");
	tmp = out;
	out = ft_strjoin(out, name);
	ft_strdel(&tmp);
	if (!prefix && ft_strnequ("./", out, 2))
	{
		tmp = out;
		out = ft_strsub(out, 2, ft_strlen(out));
		ft_strdel(&tmp);
	}
	return (out);
}
