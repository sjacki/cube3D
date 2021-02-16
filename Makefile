# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 20:21:38 by sjacki            #+#    #+#              #
#    Updated: 2021/02/15 19:11:37 by sjacki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 		cube3d
FLAG			=		-Wall -Wextra -Werror -g

SRC				=		base/ft_cube3d.c  \
						base/ft_ray_casting.c \
						\
						parser/ft_parser.c \
						parser/ft_parser_texture.c \
						parser/ft_parser_map.c \
						parser/ft_parser_map_1.c \
						\
						3d/ft_draw_map.c \
						3d/ft_contr_pl.c \
						3d/ft_hook.c

MAKE_LIBFT		=		cd libft && make

LIBFT			= 		libft/libft.a


OBJ:= $(SRC:c=o)
		
%.o: %.c
	gcc $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE_LIBFT)
	gcc $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
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