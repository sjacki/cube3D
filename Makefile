# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 20:21:38 by sjacki            #+#    #+#              #
#    Updated: 2021/01/28 20:03:58 by sjacki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 		cube3d
FLAG			=		-Wall -Wextra -Werror -g

SRC				=		base/ft_cube3d.c \
						\
						parser/ft_parser.c parser/ft_parser_texture.c

MAKE_LIBFT		=		cd libft && make

LIBFT			= 		libft/libft.a

OBJ:= $(SRC:c=o)
		
%.o: %.c
	gcc $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE_LIBFT)
	gcc $(OBJ) $(LIBFT) -o $(NAME)
clean:
	$(MAKE_LIBFT) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE_LIBFT) fclean
	rm -f $(NAME)

re: fclean all

run: all
	clear
	./$(NAME) map/map.cub