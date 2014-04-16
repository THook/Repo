#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:13:41 by amaurer           #+#    #+#              #
#    Updated: 2013/12/11 12:46:37 by amaurer          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	ft_ls
SRC = 	main.c\
		ls_option.c\
		ls_dir_operation.c\
		ls_print.c\
		ls_free.c\
		ls_print_short.c\
		ls_print_long.c\
		ls_print_long2.c\
		ls_sort.c\
		ls_error.c\
		ls_util.c
OBJ =	$(SRC:.c=.o)
FLAG =	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): makelibft
	@echo "============ $(NAME) ============"
	gcc $(FLAG) -o $(NAME) -Ilibft/includes -Llibft/ -lft -Ilibft $(SRC)

clean:
	@echo "============ clean ============"
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

makelibft:
	@echo "============ libft ============"
	make -C libft

c: re
	./$(NAME)
