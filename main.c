/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:52:32 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/20 23:01:21 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
void ft_exit(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}
*/

void ft_read(int fd, char *argv)
{
	int ft_return;
//	int word_count;
	char *one_line;

	if((ft_return = get_next_line(fd, &one_line) != 1))
	{
//		ft_exit("ft_read error 2");
		ft_exit(argv);
	}
	while((ft_return= get_next_line(fd, &one_line) == 1))
	{
		printf("|%d|line:|%s|\n", ft_return, one_line);
		free(one_line);
	}
	printf("%d\n", ft_return);
}

int main(int argc, char **argv)
{
	int fd;
//	int ft_return;
//	char *one_line;

	if(argc == 1)
		ft_usage("Usage: ./fdf resources/test_maps\n");
	fd = open(argv[1], O_RDONLY);
	if(fd  == -1)
	{
		ft_exit("Main error 1");
//		ft_exit(argv[1]);
	}
	ft_read(fd, argv[1]);
	close(fd);
	return(0);
}
