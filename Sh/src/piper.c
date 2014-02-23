/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 14:11:58 by hvillain          #+#    #+#             */
/*   Updated: 2014/02/02 17:19:51 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libsh.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

char			*get_next(char **cmd, char c)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (!cmd)
		return (NULL);
	while ((*cmd)[i] != c && (*cmd)[i] != '\0')
		i++;
	if (!(ret = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	
	while (j < i)
	{
		ret[j] = **cmd;
		(*cmd)++;
		j++;
	}
	ret[j] = '\0';
	while (**cmd == ' ' || **cmd == c)
		(*cmd)++;
	return (ret);
}

int					ft_pipe(char *line, char **env)
{
	int					fd[2];
	int					pfd[2];
	char				*tmp;
	int					pid;

	fd[1] = dup(1);
	tmp = get_next(&line, '|');
	if (ft_strlen(line) <= 0)
	{
		//dup2(1, pfd[1]);
		close(pfd[1]);
		close(fd[0]);
		curse(env, tmp);
		close(pfd[0]);
	}
	if (pipe(pfd) < 0)
		exit(0);
	if (ft_strlen(line) > 0)
	{
	if ((pid = fork()) > 0)
	{
		dup2(pfd[0], 0);
		close(pfd[1]);
		waitpid(pid, 0, 0);
	}
	else
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		curse(env, tmp);
	}
	fd[0] = dup(0);
	ft_pipe(line, env);
	}
	return (0);
}

/*int				ft_pipe(char *line, char **env)
{
	int					fd[2];
	char				*tmp;
	pid_t				pid;
	int					f[2];

	dup2(f[0], 0);
	dup2(f[1], 1);
	tmp = get_next(&line, '|');
	if (ft_strlen(line) <= 0)
	{
		dup2(fd[0],f[0]);
		close(fd[1]);
		curse(env, tmp);
		dup2(f[0], fd[0]);
	//	dup2(f[0], 0);
		close(fd[0]);
		return (0);
	}
	if (pipe(fd) < 0)
		exit (0);
	if ((pid = fork()))
	{
		dup2(fd[1], f[1]);
	//	dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		curse(env, tmp);
		ft_pipe(line, env);
		wait(0);
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
	//	curse(env, tmp);
		sleep(1);
	}
	return (0);
}*/


/*int				ft_pipe(char *line, char **env)
{
	int			fd[2];
	char		*tmp;

	if (pipe(fd) < 0)
		exit (0);
	while (*line)
	{
		ft_putchar('a');
		tmp = get_next(&line, '|');
		if (!fork())
		{
			dup2(fd[1], 1);
			close(fd[0]);
			wait(0);
		}
		else
		{
			tmp = get_next(&line, '|');
			dup2(fd[0], 0);
			close(fd[0]);
			curse(env, tmp);
		}
		free(tmp);
	}
	return (0);
}*/

void			piper(char *line, char **env)
{
	if (line[0] != '<')
		ft_pipe(line, env);
	else
		ft_putstr("no");
}

