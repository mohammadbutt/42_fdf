# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbutt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/06 22:08:05 by mbutt             #+#    #+#              #
#    Updated: 2019/08/05 19:01:17 by mbutt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
CC		= gcc
CFLAG	= -Wall -Wextra -Werror
#SRC	= srcs/test_draw.c Dont use it
SRC 	= srcs/bresenham_line_algorithm.c \
		  srcs/main.c srcs/maintain1.c srcs/fcc_drawline.c \
		  srcs/parse_and_store.c \
		  srcs/render_map.c \
		  srcs/rotation_matrix.c \
		  srcs/utility_functions1.c srcs/utility_functions2.c
#SRC		= fdf.c main.c maintain1.c fcc_drawline.c rotation_matrix.c #linked_list.c
#SRC		= square_test.c
OBJ		= $(SRC:.c=.o)

#MLXLINK = -L resources/minilibx 				#uncomment it for linux
#MINILIBX = -I resources/minilibx 				#uncomment it for linux
MLXLINK = -L resources/minilibx_macos 			#comment it for linux
MINILIBX = -I resources/minilibx_macos 			#comment it for linux
LIBFT = srcs/libft/libft.a
#LIBFT = libft/libft.a
OPENGL = -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(OBJ)
	#make -C resources/minilibx/				#uncomment it for linux
	make -C resources/minilibx_macos/			#comment it for linux
	#make -C libft/
	make -C srcs/libft/
	$(CC) $(CFLAG) $(MLXLINK) $(MINILIBX) $(LIBFT) $(OPENGL) $^ -o $(NAME)

clean:
	#make clean -C resources/minilibx/	#uncomment it for linux
	make clean -C resources/minilibx_macos/		#comment it for linux
	#make clean -C libft/
	#/bin/rm -f *.o
	make clean -C srcs/libft/
	/bin/rm -f srcs/*.o

fclean: clean
	make fclean -C srcs/libft/
	#make fclean -C libft/
	/bin/rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
