# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 11:30:21 by rvarela-          #+#    #+#              #
#    Updated: 2024/04/12 16:05:43 by rvarela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Werror -Wextra -g
LIBFLAGS = ar -rcs
#MLXFLAGS = -lmlx -lXext -lX11 -lbsd
MKFLAG = --no-print-directory

SRC_DIR = src

INC_DIR = includes

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

#LIBMLX = ./mlx/libmlx.a
#MLX_DIR = ./mlx

SRC = main.c handle_errors.c read_map.c bresenham_line.c\
	draw_map.c





OBJ = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) #$(LIBMLX)
	cc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	cc $(CFLAGS) -c $< -I $(INC_DIR) -o $@

$(LIBFT):
	$(MAKE) $(MKFLAG) -C $(LIBFT_DIR)

#$(LIBMLX):
#	$(MAKE) $(MKFLAG) -sC $(MLX_DIR)

clean:
	rm -rf $(OBJ)
	$(MAKE) $(MKFLAG) clean -C $(LIBFT_DIR)
#	$(MAKE) $(MKFLAG) clean -C $(MLX_DIR)
	
fclean: clean
	rm -rf $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re