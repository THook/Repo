/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 22:40:55 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/23 22:54:39 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_H
# define GLOB_H

typedef struct			s_list
{
		char			*name;
		struct s_list	*next;
}						t_list;

typedef struct			s_pipe
{
		struct s_pipe	*next;
		struct s_rooms	*room;
}						t_pipe;

typedef struct			s_rooms
{
		char			*name;
		struct s_rooms	*next;
		struct s_rooms	*prev;
		int				start;
		int				end;
		int				vis;
		int				occ;
		int				dist;
		t_pipe			*pipe;
}						t_rooms;

typedef struct			s_root
{
		struct s_root	*next;
		t_rooms			*room;
}						t_root;

typedef struct			s_ant
{
		int				id;
		t_root			*pos;
		int				done;
}						t_ant;

typedef struct			s_struct
{
		int				ant_nbr;
		t_list			*list;
		t_rooms			*room;
		t_root			*root;
		t_ant			**ants;
}						t_struct;

t_struct			*glob_init(void);
void				add_to_list(char *line, t_struct *glob);
void				print_list(t_struct *glob);
void				print_rooms(t_struct *glob);
int					is_linking(char *line);
int					is_comment(char *line);
int					is_nbr(char *line);
int					is_linking(char *line);
int					add_room(char *line, t_struct *glob, int path);
int					is_room(char *line);
void				make_tab_room(char *name, t_struct *glob);
int					add_pipe(char *line, t_struct *glob);
int					resolve(t_struct *glob);
int					error_messages(int n);
void				lets_lem(t_struct *glob);
void				create_lemtab(t_struct *glob);
int					cant_finish(t_struct *glob);

# endif /* GLOB_H */

