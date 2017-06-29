# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/28 15:51:08 by bbrandt           #+#    #+#              #
#    Updated: 2017/06/29 22:25:54 by bryanbrandt      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = src/ft_build.c \
	   src/ft_wire.c \
	   src/parser.c \
	   src/main.c \

FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -o $(NAME) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit
	libft/libft.a
	echo "Fdf done"

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
