

#ifndef 	ALFLONG_H
# define	ALFLONG_H

typedef struct			s_alf
{
		char			*name;
		struct s_alf	*next;
		int				len;
		int				done;
}						t_alf;

typedef struct			s_struct
{
		t_alf			*alf;
}						t_struct;

# endif
