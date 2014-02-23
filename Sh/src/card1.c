#include "Libsh.h"
#include <stdlib.h>

void				free_tab(char **tab);
void				card(char **tab, char **env);

static char			**verif(char **tab, char **reg)
{
	int		i;
	int		count;
	int		j;
	char		**f_tab;

	j = 0;
	i = 0;
	while (--j > i)
	{
		if (is_wild(tab[j]))
			count = count + count_matches(tab[j]);
		else
			count++;
	}
	f_tab = create_tab(reg, tab, count);
	return (melt(reg, f_tab));
}

static char			*make_cmd(char *line, char **env)
{
	char		*cmd;
	char		*path;
	char		**tab;
	char		**tab2;

	tab2 = ft_strsplit(ft_strtrim(line), ' ');
	path = get_env("PATH=", env);
	tab = path_tab(path);
	cmd = make_path(tab2[0], tab);
	free(path);
	free_tab(tab);
	free_tab(tab2);
	return (cmd);
}

static int			regular(char *line, int i)
{
	if (i == 0)
		return (1); // tester si la ligne ne contient pas d'étoile
	if (line[0] == '-')
		return (1);
	else
		return (0);
}

char			**make_regular(char **tab, char *cmd)
{
	int		i;
	int		j;
	char		**reg;

	i = 0;
	j = 0;
	if (!(regular(tab[i], i)))
		ft_putstr("error"); // ?
	while (regular(tab[i], i))
		i++;
	reg = (char **)malloc(sizeof(char *) * (i + 1));
	reg[j++] = ft_strdup(cmd);
	free(cmd);
	while (j < i)
	{
		reg[j] = ft_strdup(tab[j]);
		j++;
	}
	reg[j] = 0;
	//free_tab(tab);
	return (reg);
}

void				main_card(char *line, char **env)
{
	char		*cmd;
	char		**reg;
	char		**tab;
	char		**tab2;

	cmd = make_cmd(line, env);
	tab = ft_strsplit(ft_strtrim(line), ' ');
	reg = make_regular(tab, cmd);
	tab2 = verif(tab, reg);
	card(tab2, env);
}

