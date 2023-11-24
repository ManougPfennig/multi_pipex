# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 13:49:45 by mapfenni          #+#    #+#              #
#    Updated: 2023/11/24 15:09:35 by mapfenni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = ./main.c ./src/parsing.c ./src/error.c ./src/pipex.c \
./src/pipex_utils.c ./src/second_pipex.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	make -C ./libft
	gcc ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS} ${BONUS}
	make clean -C ./libft

fclean: clean
	rm -f ${NAME}
	make clean -C ./libft

re: fclean all
	make fclean -C ./libft