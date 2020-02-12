# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 13:42:49 by lvan-bei          #+#    #+#              #
#    Updated: 2019/04/03 23:40:49 by lvan-bei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OK_COLOR=\x1b[32;01m
RM_COLOR=\x1b[31;01m
NAME	= fractol

SRC =	srcs/main.c\
		srcs/key.c\
		srcs/julia.c\
		srcs/mandelbrot.c\
		srcs/burningship.c\
		srcs/background.c\
		srcs/menu.c\
		srcs/tools.c\

OBJ		= $(SRC:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

MLX		= ./miniLibx_macos/
MLX_LIB	= $(MLX)mlx.a
MLX_INC	= -I ./miniLibX
MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_LNK	= -L ./libft -l ft

.SILENT:

all: $(FT_LIB) $(MLX_LIB) $(NAME)

$(FT_LIB):
	make -C $(FT)
	echo "$(OK_COLOR)libft [created]"
$(MLX_LIB):
	make -C $(MLX)
	echo "$(OK_COLOR)minilibx [created]"
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)
	echo "$(OK_COLOR)objetcts [created]"
	echo "$(OK_COLOR)./fractol [created]"
clean:
	make -C $(FT) clean
	echo "$(RM_COLOR)libft [deleted]"
	make -C $(MLX) clean
	echo "$(RM_COLOR)minilibx [deleted]"
	rm -rf $(OBJ)
	echo "$(RM_COLOR)objetcts [deleted]"

fclean: clean
	rm -rf $(NAME)
	echo "$(RM_COLOR)./fractol [deleted]"
	make -C $(FT) fclean
	echo "$(RM_COLOR)libft [deleted]"
re: fclean all
