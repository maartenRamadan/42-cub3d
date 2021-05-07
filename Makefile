# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: Marty <Marty@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/04/15 12:25:09 by Marty         #+#    #+#                  #
#    Updated: 2020/04/16 23:03:53 by Marty         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FILES = cub3d.c \
		map_check_3.c \
		map_check_2.c \
		map_check_1.c \
		save_bmp.c \
		sprites_1.c \
		sprites_2.c \
		sprites_3.c \
		pixel_puts.c \
		raycasting.c \
		move.c \
		hooks.c

FLAGS = -O3 -Wall -Wextra -Werror -I

MLX = libmlx.dylib

LIBFT = libft.a

PRINTF = libftprintf.a

NAME = cub3D

LIBS = -Lsrcs/minilibx/ -lmlx -framework OpenGL -framework AppKit

all: libft mlx printf $(NAME)

mlx:
	make -C srcs/minilibx/
	@cp srcs/minilibx/$(MLX) .

libft:
	make -C srcs/Libft/
	@cp srcs/Libft/$(LIBFT) .

printf:
	make -C srcs/ft_printf/
	@cp srcs/ft_printf/$(PRINTF) .

$(NAME):
	gcc $(FLAGS) $(MLX) $(LIBFT) $(PRINTF) $(FILES) $(LIBS) -o $(NAME)
	make fclean -C srcs/Libft/
	make fclean -C srcs/ft_printf/
	make clean -C srcs/minilibx/

clean:
	rm -f $(LIBFT)
	rm -f $(PRINTF)
	rm -rf screenshot.bmp

fclean: clean
	rm -f $(MLX)
	rm -f $(NAME)

re: fclean all
