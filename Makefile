# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbutt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/06 22:08:05 by mbutt             #+#    #+#              #
#    Updated: 2019/08/05 20:55:05 by mbutt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
CC		= gcc
CFLAG	= -Wall -Wextra -Werror
SRC 	= srcs/bresenham_line_algorithm.c \
		  srcs/error_messages.c \
		  srcs/main_and_solve_driver.c \
		  srcs/menu.c \
		  srcs/parse_and_store.c \
		  srcs/program_control_events1.c srcs/program_control_events2.c \
		  srcs/render_map.c \
		  srcs/rotate_matrix1.c srcs/rotate_matrix2.c srcs/rotate_matrix3.c \
		  srcs/utility_functions1.c srcs/utility_functions2.c
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
