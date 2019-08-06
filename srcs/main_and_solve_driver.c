/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_and_solve_driver.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:56:59 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/05 20:00:27 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		solve_driver(int fd, int height, char *argv)
{
	t_mlx	*mlx;
	char	**characters;
	int		**int_data;

	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		ft_exit("maintain1.c solve_driver1() error: Unable to malloc.\n");
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, P_WIDTH, P_HEIGHT, "ok");
	height = ft_valid(fd, height, argv);
	characters = str_data(fd, height, argv);
	mlx->int_data = str_to_int(characters);
//	mlx->map_height = ft_height(characters); // Can we mlx->map_height = height?
	mlx->map_height = height;
	mlx->map_width = ft_width(characters);
	get_struct_values(mlx);
//	ft_print_data(mlx); 		/*To test if values are stored properly*/
	ft_render(mlx);
	mlx_hook(mlx->win_ptr, 2, 5, program_keys, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (1);
}


int	main(int argc, char **argv)
{
	int fd;
	int height;

	fd = 0;
	height = 0;
	if (argc == 1)
		ft_usage("Usage: ./fdf resources/test_maps\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_exit("Main Error 1:\nFile does not exist\n");
//		ft_exit_dir(argv[1]);
	}
	solve_driver(fd, height, argv[1]);
	close(fd);
	return (0);
}
