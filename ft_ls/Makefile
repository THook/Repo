# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    make                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/16 22:24:24 by hvillain          #+#    #+#              #
#    Updated: 2014/04/16 22:30:23 by hvillain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = srcs/main.c \
	   srcs/params.c \
	   srcs/ft_scandir.c \
	   srcs/stack_functions.c \
	   srcs/ft_printfile.c \
	   srcs/spaces.c \
	   srcs/stack_functions2.c

OBJS =	$(SRCS:.c=.o)

FLAGS =	-Wall -Wextra -Werror -g3

LIBFT = ./srcs/Libft/libft.a

all: $(LIBFT) $(NAME)

%.o: %.c srcs/libft/libft.a
	cc $(FLAGS) -o $@ -c $< -I ./includes

$(NAME): $(LIBFT) $(OBJS)
	cc $(FLAGS) -o $(NAME) $^ -I ./includes/

$(LIBFT):
	make -C ./srcs/Libft/ all

clean:
	/bin/rm -f $(OBJS)
	make -C ./srcs/Libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./srcs/Libft/ fclean

re: fclean all
