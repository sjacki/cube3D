# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 20:21:38 by sjacki            #+#    #+#              #
#    Updated: 2021/05/04 18:53:52 by alexandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 		cube3d
FLAG			=		 -g -Werror -Wextra -Wall

SRC				=		base/ft_cube3d.c  \
						base/ft_ray_casting.c \
						base/ft_hook.c \
						base/ft_algoritm.c \
						\
						parser/ft_parser.c \
						parser/ft_parser_texture.c \
						parser/ft_parser_map.c \
						parser/ft_parser_map_1.c \
						\

MAKE_LIBFT		=		cd libft && make

LIBFT			= 		libft/libft.a


OBJ:= $(SRC:c=o)
		
%.o: %.c
	gcc $(FLAG) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE_LIBFT)
	gcc $(OBJ) $(LIBFT) libmlx.a -framework OpenGL -framework AppKit -o $(NAME)
clean:
	$(MAKE_LIBFT) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE_LIBFT) fclean
	rm -f $(NAME)

re: fclean all

run: all
	clear
	./$(NAME) map/map.cub | cat -e