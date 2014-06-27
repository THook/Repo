#include "../includes/ft_env.h"
#include <stdlib.h>

void		ft_cpy_pwd(t_sh *sh)
{
	int		i;
	char	*stock;

	i = -1;
	while (sh->env[++i])
	{
		if (!ft_strncmp("PWD=", sh->env[i], 4))
			stock = sh->env[i];
	}
	sh->pwd = ft_strdup(stock);
	i = -1;
	while (sh->env[++i])
	{
		if (!ft_strncmp("OLDPWD=", sh->env[i], 7))
			stock = sh->env[i];
	}
	sh->oldpwd = ft_strdup(stock);
	i = -1;
	while (sh->env[++i])
	{
		if (!ft_strncmp("HOME=", sh->env[i], 5))
			stock = sh->env[i];
	}
	sh->home = ft_strdup(stock);
}

void		ft_set_loc(t_sh *sh)
{
	sh->fd = (int **)malloc(sizeof(int *) * 2);
	sh->fd[0] = (int *)malloc(sizeof(int));
	sh->fd[1] = (int *)malloc(sizeof(int));
	sh->fd[0][0] = 0;
	sh->fd[1][0] = 0;
}
