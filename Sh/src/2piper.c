/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 14:11:58 by hvillain          #+#    #+#             */
/*   Updated: 2014/01/29 22:57:54 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <sys/wait.h>

// ne gere que les simples pipes "ls | wc", puis les pipex_style

static int		count_splits(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int				simple_pipe(char **tab, char **env)
{
	int					pfd[2];
	pid_t				pid;
	static int			i = 0;

	if (pipe(pfd) == -1)
		return (-1);
	//ft_strtrim(tab[i]);
	if (tab[i + 1])
	{
		if ((pid = fork()) < 0)
			return (-1);
		if (pid > 0)
		{
			if (tab[i + 1])
			{
				i++;
				ft_putchar('c');
				simple_pipe(tab, env);
			}
			wait(NULL);
		}
		else
		{
			close(pfd[0]);
			dup2(pfd[1], 1);
			ft_putchar('a');
			curse(env, tab[i]);
			if (tab[i + 1])
			{
				i++;
				simple_pipe(tab, env);
			}
		}
	}
	close(pfd[1]);
	dup2(pfd[0], 0);
	ft_putchar('b');
	curse(env, tab[i]);
	return (1);
}









			
			
			
			
			
			
			/*	wait(NULL);
		else
		{
			close(pfd[0]);
			dup2(pfd[1], 1);
			curse(env, tab[i]);
			if (tab[i++ + 1])
				simple_pipe(tab, env);
		}
	}
	close(pfd[1]);
	dup2(pfd[0], 0);
	curse(env, tab[i]);
	return (1);
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
			if (pid == 0)
			close(pfd[1]);
			dup2(pfd[1], 1);
			curse(env, tab[i]);
			i++;
			simple_pipe(tab, env);
		}
		else
			wait(NULL);
	}
	dup2(pfd[0], 0);
	close(pfd[1]);
	curse(env, tab[i++]);
	return (0);
}	*/

void			piper(char **tab, char **env)
{
	int		i;

	i = count_splits(tab);
	if (tab[0][0] != '<')
		simple_pipe(tab, env);
	else
		ft_putstr("no");
}

