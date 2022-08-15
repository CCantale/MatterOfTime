# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 15:39:12 by ccantale          #+#    #+#              #
#    Updated: 2022/02/23 18:16:22 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GAME	=	MatterOfTime

CC	=	gcc
FLAGS	=	-Wall -Wextra -Werror

FILES	=	main.c \
		quit.c \
		error.c \
		loop.c \
		get_xpm.c \
		move.c \
		levels.c \
		animation.c \
		ft_open_door.c \

LIBFT	=	libft/libft.a
MINI	=	minilinuX/libmlx.a

OBJ	=	$(FILES:.c=.o)


all: $(LIBFT) $(MINI) $(GAME)

$(MINI): minilinuX/
	make -C minilinuX

$(LIBFT): libft/
	make -C libft
	make clean -C libft

$(GAME): $(OBJ)
	$(CC) $(OBJ) audio.o -Llibft -lft -LminilinuX -lmlx -L/usr/lib -IminilinuX -lSDL2main -lSDL2 -lXext -lX11 -lm -lz -o $(GAME)

%.o: %.c
	$(CC) -c audio.c -o audio.o
	$(CC) $(FLAGS) -I/usr/include -IminilinuX -O3 -c $(FILES)

clean: 
	rm $(OBJ)
	rm audio.o

fclean:
	rm $(GAME)

re: fclean 
	make

go:
	make
	./$(GAME)

send:
	rm -r ../$(GAME)/*.c ../$(GAME)/mot.h ../$(GAME)/sprites
	cp -r sprites *.c mot.h ../$(GAME)

.PHONY: all clean fclean re send

