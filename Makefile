# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 15:39:12 by ccantale          #+#    #+#              #
#    Updated: 2022/03/21 15:53:56 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	gcc
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
	$(CC) $(FLAGS) $(OBJ) -lmlx -lSDL2main -lSDL2 -framework OpenGL -framework AppKit $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) -c audio.c
	$(CC) $(FLAGS) -c $(FILES)

clean: 
	make clean -C minilibX
	make fclean -C libft
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: 
	rm $(NAME)
	make

.PHONY: all clean fclean re

