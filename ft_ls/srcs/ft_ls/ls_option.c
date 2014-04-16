#include "ft_ls.h"

void	ls_options_init(t_options *options)
{
	options->l = 0;
	options->r = 0;
	options->R = 0;
	options->a = 0;
	options->t = 0;
}

void	ls_option_set(char *arg, t_options *options)
{
	options->l = (!options->l && ft_strchr(arg, 'l')) ? 1 : options->l;
	options->r = (!options->r && ft_strchr(arg, 'r')) ? 1 : options->r;
	options->R = (!options->R && ft_strchr(arg, 'R')) ? 1 : options->R;
	options->a = (!options->a && ft_strchr(arg, 'a')) ? 1 : options->a;
	options->t = (!options->t && ft_strchr(arg, 't')) ? 1 : options->t;
}

int		ls_options_set(int ac, char **av, t_options *options)
{
	int	i;

	if (ac == 1)
		return (0);
	i = 0;
	ls_options_init(options);
	while (i++ < ac)
	{
		if (ft_strlen(av[i]) > 1 && av[i][0] == '-' && av[i][1] != '-')
			ls_option_set(av[i], options);
		else
			return (i - 1);
	}
	return (0);
}
