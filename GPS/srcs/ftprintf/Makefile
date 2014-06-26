#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmange <gmange@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 09:19:56 by gmange            #+#    #+#              #
#    Updated: 2014/03/18 17:21:13 by hvillain         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC				=	gcc #llvm-gcc
FLAGS			=	-Wall -Wextra -Werror
MKF				=	Makefile
HEAD			=	libftprintf.h

PTH_SRC			=	.

LIB				=	$(PTH_SRC)/libftprintf.a
PTH_INC			=	$(PTH_SRC)/includes

SRC				=	$(addprefix $(PTH_SRC)/, ft_printf.c\
					ft_nputchar.c ft_nputstr.c \
					ft_nputnbr.c) \

OBJ				=	$(SRC:.c=.o)

ALL_FIL			=	$(SRC) $(OBJ) $(LIB) $(MKF) $(HEAD)
ALF_DOT			=	$(ALL_FIL:%=.\#%)
ALF_SHP			=	$(ALL_FIL:%=\#%\#)
ALF_TLD			=	$(ALL_FIL:%=%~)
ALF_TMP			=	$(ALF_DOT) $(ALF_SHP) $(ALF_TLD)
ALF_SYC			=	$(ALL_FIL:%=%.!sync) $(ALF_TMP:%=%.!sync)

all: $(LIB)

$(NAME):

$(LIB): $(OBJ)
	ar rc $@ $^
	ranlib $(LIB)

%.o: %.c
	$(GCC) $(FLAGS) -I $(PTH_INC)/ -o $@ -c $< -I ../../includes/

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(LIB)
	@/bin/rm -f $(ALF_DOT)
	@/bin/rm -f $(ALF_SHP)
	@/bin/rm -f $(ALF_TLD)
	@/bin/rm -f $(ALF_SYC)

re: fclean all

.PHONY: all clean fclean re
