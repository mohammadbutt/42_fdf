# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbutt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/06 22:08:05 by mbutt             #+#    #+#              #
#    Updated: 2019/06/07 18:36:07 by mbutt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -c
C_FILES = *.c
O_FILES = $(C_FILES:.c=.o)

MLX_LINK = -L ./minilibx/ -lmlx
FRAMEWORK = -framework OpenGL -framework Appkit
FT_LINK = -L ./libf -lft

$(NAME):
	make -C libft/
	$(CC) $(CFLAGS) $(MLX_LINK) $(FRAMEWORK) $(FT_LINK) $(C_FILES) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(O_FILES)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
.PHONY: all clean fclean re
