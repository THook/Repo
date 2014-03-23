
#include "Libft/libft.h"
#include <dirent.h>

void		make_tab(char *s, char *dir, int n)
{
	int				i;
	struct dirent	*file;
	DIR				*ret;
	char			**tab;

	i = 0;
	if ((ret = opendir(dir)) == NULL)
		return ;
	tab = (char **)ft_memalloc(sizeof(char *) * (n + 1));
	while ((file = readdir(ret)) != NULL)
	{
		j = -1;
		if (match(file->d_name, ft_strsub(s, 0, i)) == 1)
		{
			tab[i] = (char *)ft_memalloc(sizeof(char) * (ft_strlen(file->d_name) + 1));
			while (++j < ft_strlen(file->d_name))
				tab[i][j] = file->d_name[j];
			tab[i][j] = '\0';
			i++;
		}
	}
	closedir(ret);
}

void		card2(char *s, char *dir)
{
	struct dirent	*file;
	DIR				*ret;

	if ((ret = opendir(dir)) == NULL)
		return ;
	if (ft_strchr(s, '*') != NULL)
	{
		while ((file = readdir(ret)) != NULL)
		{
			if (match(file->d_name, ft_strsub(s, 0, i)) == 1)
				count++;
		}
	}
	else
		count = 1;
	make_tab(s, dir, count);
	closedir(ret);
}

void		card(char *s, char *dir)
{
	int				i;
	struct dirent	*file;
	DIR				*ret;

	i = 0;
	if (dir == NULL)
		dir = ft_strdup(".");
	if ((ret = opendir(dir)) == NULL)
		return ;
	if (ft_strchr(s, '/') != NULL)
	{
		if (s[0] == '/')
			return (card(s + 1, (dir = "/")));
		}
		while (s[i] != '/')
			i++;
		while ((file = readdir(ret)) != NULL)
		{
			if (match(file->d_name, ft_strsub(s, 0, i)) == 1)
				return (card((s + i + 1), (dir = (file_d_name))));
		}
	}
	card2(s, dir);
	closedir(ret);
}

int			main(int ac, char **av)
{
	if (ac)
		card(av[1], av[2]);
	return (0);
}

