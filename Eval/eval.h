/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/23 17:39:20 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/24 18:32:43 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		EVAL_H
# define	EVAL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_list
{
		int		id;
		char	*data;
		struct	s_list	*prev;
		struct	s_list	*next;
}				t_list;

t_list		*manage_lists(int type, char *cmd, char *data, t_list *elem);
int			ft_strcmp(const char *s1, const char *s2);
t_list		*manage_list(char *cmd, char *data, t_list *elem);
t_list		*create_elem(char *data);
void		operate(t_list *elem);
char		*ft_strdup(char *s);
int			ft_strlen(char *s);
char		*ft_itoa(int n);
t_list		*manage_parent(char *cmd, char *data, t_list *elem);

#endif

