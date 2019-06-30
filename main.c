/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:35:17 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/29 22:35:56 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	int fd;
	int height;
	
	fd = 0;
	height = 0;
	if(argc == 1)
		ft_usage("Usage: ./fdf resources/test_maps\n");
	fd = open(argv[1], O_RDONLY);
	if(fd  == -1)
	{
		ft_exit("Main Error 1:\nFile does not exist\n");
//		ft_exit_dir(argv[1]);
	}
	solve_driver1(fd, height, argv[1]);

	close(fd);
	return(0);
}



/*
int main(int argc, char **argv)
{
	int fd;
	int height;
	char **characters;
	t_fdf struct_pointer; //delete after testing
//	struct_pointer = struct_pointer.struct_coordinates; //delete after testing

	ft_zero(&height, &fd, &fd, &fd);
	if(argc == 1)
		ft_usage("Usage: ./fdf resources/test_maps\n");
	fd = open(argv[1], O_RDONLY);
	if(fd  == -1)
	{
		ft_exit("Main Error 1:\nFile does not exist\n");
//		ft_exit_dir(argv[1]);
	}
	height = ft_valid(fd, height, argv[1]);
	characters = str_data(fd, height, argv[1]);
	str_to_int(characters);

	printf("   rows:|%d|\n", ft_height(characters));
	printf("columns:|%d|\n", ft_width(characters));
	print_data_coord(&struct_pointer, characters);

//	printf("|%d|\n", t_fdf.struct_coordinates[0][2]);
//	printf("|%d|\n", t_fdf->struct_coordinates[1][2]);

	close(fd);
	return(0);
}
*/
