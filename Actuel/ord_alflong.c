

#include "alflong.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int			is_nbr(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return (0);
	else
		return (1);
}

char		*dupdup(char *s, int n)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

t_alf		*init_new(int n)
{
	t_alf	*new;

	if (!(new = (t_alf *)malloc(sizeof(t_alf))))
		return (NULL);
	new->done = 0;
	new->len = n;
	new->name = NULL;
	return (new);
}

void		copy_str(char *str, t_struct *glob, int n)
{
	t_alf	*new;

	new = init_new(n);
	new->name = dupdup(str, n);
	if (glob->alf)
		new->next = glob->alf;
	else
		new->next = NULL;
	glob->alf = new;
}

void		get_struct(char *line, t_struct *glob)
{
	int		i;
	int		j;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t' || line[i] == ' ')
			;
		else if (!is_nbr(line[i]))
		{
			j = i;
			while (!is_nbr(line[j]) && line[j] != '\0')
				j++;
			copy_str(&line[i], glob, j - i);
			i = j - 1;
		}
		i++;
	}
}

void		print_lst(t_struct *glob)
{
	t_alf		*cur;

	cur = glob->alf;
	while (cur)
	{
		ft_putstr(cur->name);
		ft_putchar('\n');
		cur = cur->next;
	}
}

void		ord_long(t_struct *glob)
{
	t_alf		*cur;
	t_alf		*tmp;
	char		*s;
	int			i;

	cur = glob->alf;
	while (cur)
	{
		tmp = cur->next;
		if (tmp)
		{
			while (tmp)
			{
				if (tmp->len < cur->len)
				{
					s = tmp->name;
					tmp->name = cur->name;
					cur->name = s;
					i = tmp->len;
					tmp->len = cur->len;
					cur->len = i;
				}
				tmp = tmp->next;
			}
		}
		cur = cur->next;
	}
}

int			s_comp(char *s, char *s2)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] != s2[i])
			return (s[i] - s2[i]);
		i++;
	}
	return (0);
}

void		ord_cmp(t_struct *glob)
{
	t_alf		*cur;
	t_alf		*tmp;
	char		*s;

	cur = glob->alf;
	while (cur)
	{
		tmp = cur->next;
		if (tmp)
		{
			while (tmp && tmp->len == cur->len)
			{
				if (s_comp(cur->name, tmp->name) > 0)
				{
					s = tmp->name;
					tmp->name = cur->name;
					cur->name = s;
				}
				tmp = tmp->next;
			}
		}
		cur = cur->next;
	}
}

void		print_cmp(t_struct *glob)
{
	t_alf		*cur;

	cur = glob->alf;
	while (cur)
	{
		ft_putstr(cur->name);
		if (cur->next && cur->next->len == cur->len)
			ft_putchar(' ');
		else
			ft_putchar('\n');
		cur = cur->next;
	}
}

int			main(int ac, char **av)
{
	t_struct	*new;

	if (!(new = (t_struct *)malloc(sizeof(t_struct))))
		return (1);
	new->alf = NULL;
	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	get_struct(av[1], new);
	ord_long(new);
	ord_cmp(new);
	print_cmp(new);
	return (0);
}
