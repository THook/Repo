/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libsh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:51:43 by hvillain          #+#    #+#             */
/*   Updated: 2014/01/30 17:26:08 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#ifndef LIBSH_H
# define LIBSH_H

# define BUF_SIZE 32

typedef struct		s_pipe
{
	struct s_parse	*next;
	struct s_parse	*CL;
	struct s_parse	*CR;
	char		*line;
}			t_pipe;

typedef struct		s_list
{
	void		*content;
	size_t		content_size;
	struct s_list	*next;
}			t_list;

int	check_file(char *line);
char	**copy_file(char *line, char **tab, int k);
char	*dereg(char *reg);
int	is_wild(char *line);
char	**create_tab(char **reg, char **tab, int count);
char	**melt(char **reg, char **tab);
void	printtab(char **tab);
int	count_matches(char *line);
char	**make_regular(char **tab, char *line);
int	matches(char *line, char *line2);
void	main_card(char *line, char **env);
int	is_wild(char *line);
void	parse(char *line, char **env);
int	is_script(char *line);
int	execute(char *line, char **env);
int	ft_ptrlen(char **tab);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(const char *s, char c);
void	ft_putchar(char c);
int	ft_putstr(char const *s);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int	ft_atoi(const char *s);
int	ft_isdigit(int c);
int	ft_isprint(int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdub(char *s, char c);
char	*ft_upper_case(char *s);
void	ft_env(char **env, char **tab);
int	fork_off(char *line, char **tab, char **env_p);
void	ft_setenv(char **tab, const char *nam, const char *value, int o);
void	ft_unsetenv(char **tab, const char *name);
int	is_it_built(char **env, char *line);
void	build_it(char **env, char *line, int n);
void	curse(char **env_p, char *line);
char	**new_tab(char **tab, int n, int len);
void	ft_new_cdtab(char **tab, char *value);
char	**new_tab2(char **tab, char **tab2, int n, int len);
void	ft_cd(char **env, char **tab);
char	**copy_env(char **env);
char	**envtab(char **env, int nb, int len);
char	**path_tab(char *path);
char	*get_env(char *path, char **env);
void	setfromhome(char **env, char *line);
void	piper(char *line, char **env);
char	*ft_putnbr(int n);
void	ft_signal(int sig);
void	course(char **env);
void	ft_putstr_fd(char *str, int fd);
char	*ft_itoa(int n);

int	get_next_line(int fd, char **line);

char	*make_path(char *cmd, char **tab);

#endif
