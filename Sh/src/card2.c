#include "Libsh.h"
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

char				**copy_file(char *name, char **tab, int k)
{
	DIR				*dir;
	struct dirent	*cur;
	size_t			j;

	j = 0;
	dir = opendir(".");
	while ((cur = readdir(dir)) > 0)
	{
		if (matches(cur->d_name, name))
		{
			if (!(tab[k] = (char *)malloc(sizeof(char) * ft_strlen(cur->d_name) + 1)))
				return (0);
			while (j < ft_strlen(cur->d_name))
			{
				tab[k][j] = cur->d_name[j];
				j++;
			}
			j = 0;
			k++;
		}
	}
	closedir(dir);
	tab[k] = 0;
	return (tab);
}

int				check_file(char *line)
{
	DIR		*dir;
	struct dirent	*cur;

	if (!(dir = opendir(".")))
		return (0);
	while ((cur = readdir(dir)) > 0)
	{
		if (!(ft_strcmp(cur->d_name, line)))
			return (1);
	}
	closedir(dir);
	return (0);
}

char				*dereg(char *line)
{
	int		i;
	int		j;
	char		*cmd;

	i = 0;
	while (line[i])
		i++;
	j = i - 1;
	while (line[j] != '/')
		j--;
	cmd = ft_strsub(line, (j + 1), (i - j));
	return (cmd);
}

char				**melt(char **tab, char **tab2)
{
	int		i;
	char		**ntab;
	int		j;
	int		k;

	k = 0;
	j = 0;
	i = ft_ptrlen(tab) + ft_ptrlen(tab2);
	if (!(ntab = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	while (tab[j])
	{
		ntab[j] = ft_strdup(tab[j]);
		free(tab[j]);
		j++;
	}
	while (tab2[k])
	{
		ntab[j] = ft_strdup(tab2[k]);
		free(tab2[k]);
		j++;
		k++;
	}
	ntab[j] = 0;
	return (ntab);
}

void				card(char **tab, char **env)
{
	pid_t		pid;

	pid = fork(); // à protéger
	if (pid == 0)
	{
		execve(tab[0], tab, env);
		//ft_putchar('\n');
		exit(0);
	}
	else
		waitpid(pid, 0, 0);
}

