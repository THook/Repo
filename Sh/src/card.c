
#include "Libsh.h"
#include <stdlib.h>

void				free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

void				printtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		i++;
	}
}

int				is_wild(char *line)
{
	int             i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '*')
			return (1);
		i++;
	}
	return (0);
}

