# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tadey <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/14 00:46:10 by tadey             #+#    #+#              #
#    Updated: 2018/02/14 00:52:19 by tadey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
FLAGS = -Wall -Wextra -Werror
MLX = -I minilibx_macos_sierra -L minilibx_macos_sierra -lmlx
FRMWRK = -framework OpenGL -framework AppKit
LIBFT = -L libft/ -lft
SRC = *.c

all: $(NAME)

$(NAME): $(SRC)
	gcc -g $(FLAGS) $(MLX) $(LIBFT) $(FRMWRK) $(SRC) -o $(NAME)
	
clean:
	/bin/rm -f $(NAME)

re: clean all