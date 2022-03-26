# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 12:57:41 by ccantale          #+#    #+#              #
#    Updated: 2022/02/23 17:39:59 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = libft
FILES = ft_split.c \
	ft_calloc.c \
	ft_strlcpy.c \
	c_printf.c \
	d_u_printf.c \
	ft_printf.c \
	i_printf.c \
	s_p_printf.c \
	x_X_printf.c \
	ft_strlen.c \
	ft_atoi.c


OBJ = $(FILES:.c=.o)

all: $(NAME).a

$(NAME).a: $(OBJ)
	ar rcs $(NAME).a $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean: $(NAME).a
	rm *.o

fclean: clean
	rm $(NAME).a

re: fclean
	make

.PHONY: all clean fclean re
