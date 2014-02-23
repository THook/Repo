#include "Libsh.h"
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

char				**go_wild(char *line, char *reg, char **tab2)
{
	int		k;
	int		count;

	if (!(*tab2))
		k = 0;
	else if (tab2)
		k = ft_ptrlen(tab2);
	if ((count = count_matches(line)) == 0)
		printf("%s: %s: No such file or directory\n", dereg(reg), line);
	else
	{
		tab2 = &(tab2[k]);
		tab2 = copy_file(line, tab2);
		k = k + count;
		tab2[k] = 0;
	}
	printtab(tab2);
	return (tab2);
}

char				**go_file(char *line, char *reg, char **tab2)
{
	int		k;

	if (!(*tab2))
		k = 0;
	else if (tab2)
		k = ft_ptrlen(tab2);
	if (check_file(line))
	{
		tab2[k] = ft_strdup(line);
		tab2[++k] = 0;
		return (tab2);
	}
	else
		printf("%s: %s: No such file or directory\n", dereg(reg), line);
	return (NULL);
}

char				**create(char **tab, char *reg, char **tab2)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (is_wild(tab[i]))
			tab2 = go_wild(tab[i++], reg, tab2);
		else
			tab2 = go_file(tab[i++], reg, tab2);
	}
	ft_putchar('a');
	printtab(tab2);
	return (tab2);
}

char				**create_tab(char **reg, char **tab, int size)
{
	int		i;
	char		**tab2;
	char		**ret;
	int		count;
	int		k;

	k = 0;
	count = 0;
	i = -1;
	tab2 = (char **)malloc(sizeof(char *) * (size + 1));
	ret = create(tab, reg[0], tab2);
	return (ret);
}

