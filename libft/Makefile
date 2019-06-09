# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbutt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 19:54:05 by mbutt             #+#    #+#              #
#    Updated: 2019/06/07 18:05:24 by mbutt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -c
C_FILES = ft_*.c \
		  get_next_line.c
O_FILES = *.o

all: $(NAME)

$(NAME):	
	$(CC) $(CFLAGS) $(C_FILES) #Creates .o file
	ar rc $(NAME) $(O_FILES) #takes each .o file and creates a static library libft.a \ 

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
