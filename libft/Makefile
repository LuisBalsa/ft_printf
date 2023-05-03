# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 15:35:28 by luide-so          #+#    #+#              #
#    Updated: 2023/04/25 23:11:15 by luide-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ${filter-out ${SRC_BONUS}, ${wildcard ft_*.c}}
SRC_BONUS = ${wildcard ft_lst*.c}
OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}
HEADER = libft.h
INCLUDE = -I .
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS} ${HEADER}
	@ar rcs ${NAME} ${OBJS} ${HEADER}
	@echo "\n${NAME} created"

bonus: ${OBJS} ${OBJS_BONUS} ${HEADER}
	@ar rcs ${NAME} ${OBJS} ${OBJS_BONUS} ${HEADER}
	@echo "\n$@ created"

%.o:%.c
	@${CC} ${CFLAGS} ${INCLUDE} -c -o $@ $^
	@echo "\n$@ created"

clean:
	@${RM} ${OBJS} ${OBJS_BONUS}
	@echo "\nObjects deleted"

fclean: clean
	@${RM} ${NAME}
	@echo "\n${NAME} deleted"

re: fclean all

.PHONY: all clean fclean re