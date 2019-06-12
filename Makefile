# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbutt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/06 22:08:05 by mbutt             #+#    #+#              #
#    Updated: 2019/06/11 18:44:31 by mbutt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
CC = gcc
CFLAG	= -Wall -Wextra -Werror -g
#SRC		= srcs/test_draw.c
SRC = test_draw.c
OBJ 	= $(SRC:.c=.o)

#MLXLINK = -L resources/minilibx 				#uncomment it for linux
#MINILIBX = -I resources/minilibx 				#uncomment it for linux
MLXLINK = -L resources/minilibx_macos 			#comment it for linux
MINILIBX = -I resources/minilibx_macos 			#comment it for linux
#LIBFT = srcs/libft/libft.a
LIBFT = libft/libft.a
OPENGL = -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(OBJ)
	#make -C resources/minilibx/				#uncomment it for linux
	make -C resources/minilibx_macos/			#comment it for linux
	make -C libft/
	#make -C srcs/libft/
	$(CC) $(CFLAG) $(MLXLINK) $(MINILIBX) $(LIBFT) $(OPENGL) $^ -o $(NAME)

clean:
	#make clean -C resources/minilibx/	#uncomment it for linux
	make clean -C resources/minilibx_macos/		#comment it for linux
	make clean -C libft/
	/bin/rm -f *.o
	#make clean -C srcs/libft/
	#/bin/rm -f srcs/*.o

fclean: clean
	#make fclean -C srcs/libft/
	make fclean -C libft/
	/bin/rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
