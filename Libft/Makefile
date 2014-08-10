# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 19:50:41 by hvillain          #+#    #+#              #
#    Updated: 2014/08/10 17:40:25 by hvillain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

RM	=	/bin/rm

HEADDIR =	../../includes

SRC	=	./ft_putchar.c \
		./ft_memset.c \
		./ft_bzero.c \
		./ft_memcpy.c \
		./ft_memccpy.c \
		./ft_memmove.c \
		./ft_memchr.c \
		./ft_memcmp.c \
		./ft_strlen.c \
		./ft_strdup.c \
		./ft_strcpy.c \
		./ft_strncpy.c \
		./ft_strcat.c \
		./ft_strncat.c \
		./ft_strlcat.c \
		./ft_strchr.c \
		./ft_strrchr.c \
		./ft_strstr.c \
		./ft_strnstr.c \
		./ft_strstr.c \
		./ft_strcmp.c \
		./ft_strncmp.c \
		./ft_atoi.c \
		./ft_isalpha.c \
		./ft_isdigit.c \
		./ft_isalnum.c \
		./ft_isascii.c \
		./ft_isprint.c \
		./ft_toupper.c \
		./ft_tolower.c \
		./ft_putstr.c \
		./ft_strmap.c \
		./ft_strdel.c \
		./ft_memalloc.c \
		./ft_memdel.c \
		./ft_strsub.c \
		./ft_strclr.c \
		./ft_strjoin.c \
		./ft_strequ.c \
		./ft_strnequ.c \
		./ft_strnew.c \
		./ft_strmapi.c \
		./ft_striter.c \
		./ft_striteri.c \
		./ft_putendl.c \
		./get_next_line.c \
		./ft_strtrim.c \
		./ft_putnbr.c \
		./ft_ptrlen.c \
		./ft_strsplit.c \
		./free_tab.c \
		./ft_lstdel.c \
		./ft_lstdelone.c \
		./ft_lstiter.c \
		./ft_lstnew.c \
		./ft_realloc.c \
		./ft_putbit.c \
		./ft_bitwrite.c

OBJ	=	$(SRC:.c=.o)

FLAGS	=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

%.o: %.c
		gcc $(FLAGS) -c $< -o $@ -I $(HEADDIR)

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re:	fclean all
