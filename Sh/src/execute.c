#include "Libsh.h"
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>





static void		read_script(char *file, char **env)
{
	int		fd;
	char		*line;

	fd = open(file, O_RDONLY);
	while ((get_next_line(fd, &line) > 0))
	{
		parse(line, env);
		free(line);
	}
}

int			execute(char *line, char **env)
{
	char		**tab;
	DIR		*dir;
	struct dirent	*cur;

	tab = ft_strsplit(line, ' ');
	if ((dir = opendir(".")) == 0)
		exit(0);
	while ((cur = readdir(dir)) > 0)
	{
		if (!(ft_strcmp(cur->d_name, tab[1])))
		{
			read_script(cur->d_name, env);
			return (0);
		}
	}
	ft_putstr("no such file here");
	return (0);
}

int			is_script(char *line)
{
	if (line[0] == 's' && line[1] == 'h')
		return (1);
	else
		return (0);
}

