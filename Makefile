# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beergin <beergin@student.42.tr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 17:39:52 by beergin           #+#    #+#              #
#    Updated: 2025/04/13 23:13:20 by beergin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MINIDIR = ./extras/minilibx-linux
SRCS = srcs/main.c srcs/utils.c srcs/utils2.c srcs/utils3.c srcs/utils4.c extras/get_next_line/get_next_line.c extras/get_next_line/get_next_line_utils.c srcs/start_game.c

MINILIBNAME = ./extras/minilibx-linux/libmlx.a

PRINTF_DIR = ./extras/ft_printf
PRINTF_NAME = ./extras/ft_printf/libftprintf.a

OBJ = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
		make -C ${PRINTF_DIR}
		make -C ${MINIDIR}
		ar rcs ${NAME} ${OBJ}
		${CC} ${CFLAGS} -o so_long ${SRCS} ${PRINTF_NAME} ${MINILIBNAME} ${NAME} -lX11 -lXext -lm
		
clean:
		make clean -C ${PRINTF_DIR}
		make clean -C ${MINIDIR}
		${RM} ${OBJ}

fclean: clean
		make fclean -C ${PRINTF_DIR}
		${RM} ${NAME} so_long

re: fclean all

.PHONY: all clean fclean re