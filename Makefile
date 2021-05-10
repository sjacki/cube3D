# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 20:21:38 by sjacki            #+#    #+#              #
#    Updated: 2021/05/11 02:00:06 by alexandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 		cub3D
FLAG			=		 -g -Werror -Wextra -Wall

SRC				=		base/ft_cube3d.c  \
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
						\

MAKE_LIBFT		=		cd libft && make

MAKE_MLX		=		cd static_mlx && make

MAKE_MLX_DY		=		cd dy_mlx && make

LIBFT			= 		libft/libft.a

MLX				= 		static_mlx/libmlx.a

MLX_DY			= 		libmlx.dylib

MOVE_DY_MLX		=		cd dy_mlx && mv libmlx.dylib ../

REMOVE_DY_MLX	= 		rm -r libmlx.dylib

REMOVE_SCREEN	=		rm -r screenshot/screen.bmp

OBJ:= $(SRC:c=o)
		
%.o: %.c
	gcc $(FLAG) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE_MLX)
	$(MAKE_MLX_DY)
	$(MAKE_LIBFT)
	$(MOVE_DY_MLX)
	gcc $(OBJ) $(LIBFT) $(MLX) $(MLX_DY) -framework OpenGL -framework AppKit -o $(NAME)
clean:
	$(REMOVE_DY_MLX)
	$(MAKE_MLX) clean
	$(MAKE_MLX_DY) clean
	$(MAKE_LIBFT) clean
	rm -f $(OBJ)
	$(REMOVE_SCREEN)

fclean: clean
	$(MAKE_MLX) clean
	$(MAKE_MLX_DY) clean
	$(MAKE_LIBFT) fclean
	rm -f $(NAME)

re: fclean all

run: all
	clear
	./$(NAME) map/map.cub --save | cat -e