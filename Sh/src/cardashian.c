#include <stdio.h>
#include "Libsh.h"
#include <stdlib.h>
#include <unistd.h>

char					**go_file(char *line, char *reg, char **tab, int k);
char					**maketoob(char **reg, char **tab2, char **tab, int i);

char					**create_tab(char **reg, char **tab, int size)
{
	char		**tab2;
	int			count;
	int			k;
	int			i;

	count = i = k = 0;
	tab2 = (char **)malloc(sizeof(char *) * (size + 1));
	while (reg[i])
		tab2[i] = ft_strdup(reg[i++]);
	i = ft_ptrlen(tab) - 1;
	tab2 = maketoob(reg, tab2, tab, i);
	return (tab2);
}

char					**maketoob(char **reg, char **tab2, char **tab, int i)
{
	int			count;
	int			k;

	k = 0;
	while (i >= ft_ptrlen(reg))
	{
		if (is_wild(tab[i]))
		{
			if ((count = count_matches(tab[i])) == 0)
				printf("%s: %s: No such file or directory\n", dereg(reg[0]), tab[i]);
			else
			{
				if ((tab2 = copy_file(tab[i], tab2, k)) && (k = k + count))
					tab2[k] = 0;
			}
			i--;
		}
		else
			tab2[k++] = ft_strdup(tab[i--]);
	}
	tab2[k] = 0;
	return (tab2);
}

