# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbratche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/03 19:51:53 by sbratche          #+#    #+#              #
#    Updated: 2018/02/03 19:51:55 by sbratche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

GCC		=	gcc -Wall -Wextra -Werror

SRC		= ./src/ft_fdf.c ./src/ft_key_hooks.c ./src/ft_projections.c \
		./src/ft_rendering.c ./src/ft_init.c

OBJ		= fdf.o ft_key_hooks.o ft_projections.o ft_rendering.o \
		init.o

INC		=	./inc/fdf.h

all: 
	make re -C ./libft
	$(GCC) $(SRC) -I $(INC) -I /usr/local/include ./libft/libft.a -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
