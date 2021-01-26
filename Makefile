# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 20:21:38 by sjacki            #+#    #+#              #
#    Updated: 2021/01/26 19:49:32 by sjacki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 		cube3d
FLAG			=		-Wall -Wextra -Werror

SRC				=		base/main.c 

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

run: re
	make clean
	clear
	./$(NAME)