# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 15:39:12 by ccantale          #+#    #+#              #
#    Updated: 2022/08/15 02:59:55 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

NAME	=	MatterOfTime

FILES	=	main.c \
			quit.c \
			error.c \
			loop.c \
			get_xpm.c \
			move.c \
			levels.c \
			animation.c \
			ft_open_door.c

LIBFT	=	libft/libft.a
MINI	=	minilibX/libmlx.dylib

OBJ	=	$(FILES:.c=.o)


all: $(LIBFT) $(MINI) $(NAME)

$(MINI): minilibX/
	make -C minilibX

$(LIBFT): libft/
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $(FILES)

clean: 
	rm $(OBJ)

fclean: clean
	make clean -C minilibX
	make fclean -C libft
	rm $(NAME)

re: 
	rm $(NAME)
	make

.PHONY: all clean fclean re

