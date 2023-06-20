# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 11:19:49 by kgebski           #+#    #+#              #
#    Updated: 2023/06/03 16:57:05 by kgebski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3d
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -O3
LIBFT       = ./inc/libft/libft.a
LIBFT_DIR   = ./inc/libft/
HDRS_DIR    = ./inc/
SRC_DIR     = ./src

MLX_DIR     = ./inc/minilibx_opengl
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -framework OpenGL -framework AppKit -lz

SRCS	= src/_main.c 
HDRS	= -I$(LIBFT_DIR)/inc -I$(MLX_DIR) -I$(HDRS_DIR)
LIBS	= -L$(LIBFT_DIR) -L$(MLX_DIR) $(MLX_FLAGS)
OBJS	= $(SRCS:.c=.o)


all: mlx libft ${NAME}

${NAME}: $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX_LIB)

libft: 
	make -C ${LIBFT_DIR}

.c.o:
	gcc ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HDRS_DIR} -I ${LIBFT_DIR}
	
mlx:
	make -C $(MLX_DIR)

clean:
	rm -f ${OBJS}
	make -C $(MLX_DIR) clean
	make -C ${LIBFT_DIR} clean

fclean: clean
	rm -f ${NAME}
	make -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY: all clean fclean re libft