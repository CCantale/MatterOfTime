# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 15:39:12 by ccantale          #+#    #+#              #
#    Updated: 2022/03/19 20:13:53 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
FLAGS		= -Wall -Wextra -Werror

NAME		= so_long

FILES		= so_long.c \
			  quit.c \
			  error.c \
			  loop.c \
			  get_xpm.c \
			  move.c \
			  get_level.c

LIBFT		= libft/libft.a
MINI		= minilibX/libmlx.dylib

OBJ			= $(FILES:.c=.o)


all: $(LIBFT) $(MINI) $(NAME)

$(MINI): minilibX/
	make -C minilibX

$(LIBFT): libft/
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit $(LIBFT) -o so_long

%.o: %.c
	$(CC) $(FLAGS) -c $(FILES)

clean: 
	make clean -C libft
	rm $(OBJ)

fclean: clean
	make clean -C minilibX
	make fclean -C libft
	rm so_long

re: 
	rm so_long
	make

.PHONY: all clean fclean re

