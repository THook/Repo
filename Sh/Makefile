# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 19:50:41 by hvillain          #+#    #+#              #
#    Updated: 2014/01/30 14:04:03 by hvillain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= shell

SRC	=	./Libsh/ft_putchar.c \
		./Libsh/ft_strlen.c \
		./Libsh/ft_strjoin.c \
		./Libsh/ft_strcpy.c \
		./Libsh/ft_strdup.c \
		./Libsh/ft_strncpy.c \
		./Libsh/ft_strcmp.c \
		./Libsh/ft_strncmp.c \
		./Libsh/ft_putstr.c \
		./Libsh/get_next_line.c \
		./Libsh/ft_strtrim.c \
		./Libsh/ft_strsplit.c \
		./Libsh/ft_memalloc.c \
		./Libsh/ft_memset.c \
		./Libsh/ft_strsub.c \
		./Libsh/ft_strrchr.c \
		./Libsh/ft_strdub.c \
		./Libsh/ft_atoi.c \
		./Libsh/ft_isprint.c \
		./Libsh/ft_isdigit.c \
		./Libsh/ft_signal.c \
		./Libsh/ft_ptrlen.c \
		./Libsh/ft_putstr_fd.c \
		./Libsh/ft_itoa.c \
		./src/main.c \
		./src/2main.c \
		./src/env.c \
		./src/cd.c \
		./src/cd2.c \
		./src/builds.c \
		./src/envtab.c \
		./src/make_path.c \
		./src/piper.c \
		./src/execute.c \
		./src/card.c \
		./src/card1.c \
		./src/card2.c \
		./src/cardashian.c \

OBJ	=	$(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	cc $(FLAGS) -o $@ -c $< -I ./Libsh/include

$(NAME): $(OBJ)
	cc $(FLAGS) -o $(NAME) $^ 

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re:	fclean all
