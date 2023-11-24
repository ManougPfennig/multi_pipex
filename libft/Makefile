# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 18:32:43 by mapfenni          #+#    #+#              #
#    Updated: 2023/11/23 14:02:22 by mapfenni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_calloc.c ft_isascii.c ft_itoa.c ft_memcpy.c ft_putchar_fd.c \
ft_putstr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c ft_atoi.c ft_isalnum.c \
ft_isdigit.c ft_memchr.c ft_memmove.c ft_putendl_fd.c ft_split.c ft_strlcat.c \
ft_strncmp.c ft_tolower.c ft_bzero.c ft_isalpha.c ft_isprint.c \
ft_memcmp.c ft_memset.c ft_putnbr_fd.c ft_strchr.c ft_strlcpy.c ft_strnstr.c \
ft_toupper.c ft_strmapi.c ft_striteri.c ft_substr.c ft_strjoin.c ft_strtrim.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
ft_printf.c ft_putchar.c ft_putnbr_base_len.c ft_putnbr_len.c \
ft_putstr_len.c

CFLAGS += -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all