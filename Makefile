# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 20:21:38 by sjacki            #+#    #+#              #
#    Updated: 2021/05/12 02:04:13 by alexandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

C_FILES			=		base/ft_cube3d.c  \
						base/ft_ray_casting.c \
						base/ft_hook.c \
						base/ft_select_texture.c \
						base/ft_drw_spr.c \
						base/ft_move_ch.c \
						base/ft_move_ch_1.c \
						base/ft_draw_minimap.c \
						base/ft_render_1.c \
						base/ft_render_2.c \
						base/ft_other_fun.c \
						base/ft_other_fun_1.c \
						base/ft_other_fun_2.c \
						base/ft_mk_screenshot.c \
						\
						parser/ft_parser.c \
						parser/ft_parser_texture.c \
						parser/ft_parser_map.c \
						parser/ft_parser_map_1.c \
						parser/ft_other_pars.c \
						parser/ft_parser_other.c \
						\

O_FILES = $(C_FILES:.c=.o)

HEADER = header/cube3d.h

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(O_FILES)
	make -C ./libft
	make -C ./static_mlx
	make -C ./dy_mlx
	mv ./dy_mlx/libmlx.dylib ./
	gcc -g -Wall -Wextra -Werror $(O_FILES) ./libft/libft.a ./static_mlx/libmlx.a libmlx.dylib -framework OpenGL -framework Appkit -o $(NAME)

%.o: %.c $(HEADER)
	gcc -c $<

clean:
	rm -f $(O_FILES)
	make clean -C ./libft
	make clean -C ./static_mlx
	make clean -C ./dy_mlx

fclean: clean
	rm -f $(NAME)
	rm libmlx.dylib
	make fclean -C ./libft

bonus: re

re: fclean all