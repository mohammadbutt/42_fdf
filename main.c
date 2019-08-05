/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:35:17 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/05 10:48:25 by mbutt            ###   ########.fr       */
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
