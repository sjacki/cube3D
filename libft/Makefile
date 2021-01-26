# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 20:21:38 by sjacki            #+#    #+#              #
#    Updated: 2021/01/26 19:52:19 by sjacki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 		libft.a
FLAG			=		-Wall -Wextra -Werror

SRC			=	base/ft_memset.c base/ft_bzero.c base/ft_memcpy.c base/ft_memccpy.c base/ft_memmove.c \
				base/ft_memchr.c base/ft_memcmp.c base/ft_strlcpy.c base/ft_strrchr.c base/ft_strncmp.c \
				base/ft_atoi.c base/ft_isalpha.c base/ft_isdigit.c base/ft_isalnum.c base/ft_isascii.c \
				base/ft_strlen.c \
				base/ft_isprint.c base/ft_toupper.c base/ft_tolower.c base/ft_strchr.c base/ft_strdup.c \
				base/ft_calloc.c base/ft_substr.c base/ft_strjoin.c base/ft_strtrim.c base/ft_strlcat.c \
				base/ft_strnstr.c \
				base/ft_substr.c base/ft_strjoin.c base/ft_strtrim.c base/ft_split.c base/ft_itoa.c \
				base/ft_strmapi.c base/ft_putchar_fd.c base/ft_putstr_fd.c base/ft_putendl_fd.c \
				base/ft_putnbr_fd.c	\
				\
				\
				ft_printf/base/ft_printf.c 					ft_printf/parser/parser.c \
				\
				\
				ft_printf/libft/ft_atoi.c		 			ft_printf/libft/ft_isdigit.c 						ft_printf/libft/ft_putnbr_fd.c \
				ft_printf/libft/ft_putstr_fd.c 				ft_printf/libft/ft_strchr.c  						ft_printf/libft/ft_strlen.c \
				ft_printf/libft/ft_putchar_fd.c 			ft_printf/libft/ft_putnbr_hex.c 					ft_printf/libft/ft_putnbr_hex_p.c\
				\
				\
				ft_printf/processor/ft_processor.c			ft_printf/processor/ft_processor_utils_d_i.c		ft_printf/processor/ft_processor_d_i.c \
				ft_printf/processor/ft_processor_u.c		ft_printf/processor/ft_processor_utils_u.c 			ft_printf/processor/ft_processor_c.c \
				ft_printf/processor/ft_processor_s.c		ft_printf/processor/ft_processor_percent.c 			ft_printf/processor/ft_processor_x.c \
				ft_printf/processor/ft_processor_p.c \
				\
				\
				get_next_line/get_next_line.c				get_next_line/get_next_line_utils.c \

OBJ:= $(SRC:c=o)

%.o: %.c
	gcc $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
