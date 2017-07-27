# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/28 15:51:08 by bbrandt           #+#    #+#              #
#    Updated: 2017/07/27 14:52:27 by bbrandt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = src/ft_build.c \
	  src/ft_wire.c \
	  src/parser.c \
	  src/main.c \

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a -lmlx -framework OpenGL -framework AppKit
	@echo "Fdf done"

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
