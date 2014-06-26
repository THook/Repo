# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/12 09:11:04 by hvillain          #+#    #+#              #
#    Updated: 2014/03/17 19:40:45 by hvillain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	lem-in

SRCS =	./srcs/lemmin/get.c \
		./srcs/lemmin/glob.c \
		./srcs/lemmin/parser.c \
		./srcs/lemmin/pipe.c \
		./srcs/lemmin/tools.c \
		./srcs/lemmin/resolve.c \
		./srcs/lemmin/error_messages.c \
		./srcs/lemmin/lets_lem.c

LIBFT =	./srcs/Libft/libft.a

PRINTF = ./srcs/ftprintf/libftprintf.a

OBJS =	$(SRCS:.c=.o)

FLAGS =	-Wall -Wextra -Werror -g3

all: $(LIBFT) $(PRINTF) $(NAME)

%.o: %.c
	cc $(FLAGS) -o $@ -c $< -I ./includes

$(NAME): $(LIBFT) $(OBJS)
	cc $(FLAGS) -o $(NAME) $^ -I ./includes/

t: $(NAME)
	./$< <test.lem

$(LIBFT):
	make -C ./srcs/Libft/ all

$(PRINTF):
	make -C ./srcs/ftprintf/ all

clean:
	/bin/rm -f $(OBJS)
	make -C ./srcs/Libft/ clean
	make -C ./srcs/ftprintf/ clean
fclean: clean
	/bin/rm -f $(NAME)
	make -C ./srcs/Libft/ fclean
	make -C ./srcs/ftprintf/ fclean

re: fclean all
