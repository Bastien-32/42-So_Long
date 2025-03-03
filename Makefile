# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: student <student@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 15:02:33 by badal-la          #+#    #+#              #
#    Updated: 2025/03/03 16:41:02 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	cc
CFLAGS 	=	-g -Wall -Wextra -Werror -Wno-deprecated-non-prototype

LIBFT_PATH 	= libft/
LIBFT_FILE 	= $(LIBFT_PATH)libft.a
PRINTF_PATH = ft_printf/
PRINTF_FILE = $(PRINTF_PATH)libftprintf.a
GNL_PATH 	= get_next_line/
GNL_FILES 	= $(GNL_PATH)get_next_line_bonus.c $(GNL_PATH)get_next_line_utils_bonus.c
MLX_PATH 	= minilibx-linux/
MLX_FILE 	= $(MLX_PATH)libmlx.a

MLX_FLAGS 	= -L$(MLX_PATH) -lmlx -L/usr/X11R6/lib -lX11 -lXext

SRC 	=	$(wildcard src/*.c) $(GNL_FILES)
OBJ 	=	$(patsubst %.c,%.o,$(SRC))

RM 		=	rm -f

LIBS 	=	$(MLX_FILE) $(MLX_FLAGS) $(LIBFT_FILE) $(PRINTF_FILE)

$(NAME): $(OBJ)
	make -C $(MLX_PATH)
	make -C $(LIBFT_PATH)
	make -C $(PRINTF_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME) -I includes/

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I includes/ -I $(LIBFT_PATH) -I $(MLX_PATH) -I $(PRINTF_PATH) -I $(GNL_PATH)

all: $(NAME)

clean:
	make clean -C $(MLX_PATH)
	make clean -C $(LIBFT_PATH)
	make clean -C $(PRINTF_PATH)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re test