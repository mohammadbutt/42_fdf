/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_control_events2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:50:46 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/06 11:45:53 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_camera(t_mlx *mlx)
{
	if (mlx->camera == 0)
		mlx->camera = 1;
	else if (mlx->camera == 1)
		mlx->camera = 0;
	ft_render(mlx);
}

void	rotate_axis(t_mlx *mlx, int key)
{
	if (key == ROTATE_UP_I)
		mlx->x_axis = mlx->x_axis + 0.02;
	else if (key == ROTATE_DOWN_K)
		mlx->x_axis = mlx->x_axis - 0.02;
	else if (key == ROTATE_LEFT_J)
		mlx->y_axis = mlx->y_axis + 0.02;
	else if (key == ROTATE_RIGHT_L)
		mlx->y_axis = mlx->y_axis - 0.02;
	else if (key == ROTATE_SIDE_U)
		mlx->z_axis = mlx->z_axis + 0.02;
	else if (key == ROTATE_SIDE_O)
		mlx->z_axis = mlx->z_axis - 0.02;
	ft_render(mlx);
}

int		program_keys(int key, t_mlx *mlx)
{
	if (key == ESCAPE_ESC)
		ft_exit_success(GREEN"Program shut down successfully.\n");
	else if (key == UP_K || key == DOWN_K || key == LEFT_K || key == RIGHT_K)
		shift_program(mlx, key);
	else if (key == ZOOM_IN_Q || key == ZOOM_OUT_A)
		zoom_program(mlx, key);
	else if (key == RANDOM_COLOR_R)
		random_color(mlx, key);
	else if (key == RESET_PROGRAM_E)
		reset_program(mlx);
	else if (key == CHANGE_CAMERA_C)
		change_camera(mlx);
	else if (key == ALTITUDE_INCREASE_W || key == ALTITUDE_DECREASE_S)
		change_altitude(mlx, key);
	else if (key == ROTATE_UP_I || key == ROTATE_DOWN_K)
		rotate_axis(mlx, key);
	else if (key == ROTATE_LEFT_J || key == ROTATE_RIGHT_L)
		rotate_axis(mlx, key);
	else if (key == ROTATE_SIDE_U || key == ROTATE_SIDE_O)
		rotate_axis(mlx, key);
	return (0);
}
