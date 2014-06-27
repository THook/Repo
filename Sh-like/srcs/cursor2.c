#include <cursor.h>

void			ft_delchar(char *line, int *i)
{
	int			j;

	if (*i <= 0)
		return ;
	tputs(tgetstr("le", NULL), 1, tputs_putchar);
	tputs(tgetstr("dc", NULL), 1, tputs_putchar);
	*i -= 1;
	j = *i;
	while ((line)[j])
	{
		(line)[j] = (line)[j + 1];
		if (line[j])
			j++;
	}
}

char			*ft_insertchar(char c, char *line, int *i)
{
	int			j;
	char		*line2;

	ft_putchar(c);
	j = ft_strlen(line);
	line2 = ft_strnew(j + 2);
	ft_strcpy(line2, line);
	free(line);
	while (j > *i)
	{
		line2[j] = line2[j - 1];
		j--;
	}
	line2[(*i)++] = c;
	return (line2);
}
