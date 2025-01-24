# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 17:44:14 by fmartusc          #+#    #+#              #
#    Updated: 2025/01/12 17:44:14 by fmartusc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = utils.c checkargc.c stackinit.c pushswap.c  list.c OP_revrotate.c \
		OP_rotate.c OP_swappop.c algo_rythm1.c algo_rythm2.c algo_rythm3.c \
		desperatehw.c only1ac.c onlyac2.c

OUT = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -g -c  $< -o ${<:.c=.o}

$(NAME): $(OUT)
		cc  -o $(NAME)  $(OUT)

all:	$(NAME)

clean:
		rm -f $(OUT)

fclean: clean
		rm -f $(NAME)

re:	fclean all
