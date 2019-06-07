# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbutt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/06 22:08:05 by mbutt             #+#    #+#              #
#    Updated: 2019/06/06 22:52:04 by mbutt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -c
C_FILES = *.c
O_FILES = *.o

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(C_FILES) #Creates .o files
	ar rc $(NAME) $(O_FILES) #takes each .o file and creates a static library

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re

build:
	@echo "Building..."
