/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_control_events1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:47:00 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/05 19:50:39 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	random_color(t_mlx *mlx, int key)
{
	size_t random_seed;

	random_seed = mlx->y0;
	random_seed = rand();
	mlx->color = rand() % random_seed;
	ft_render(mlx);
}

void	zoom_program(t_mlx *mlx, int key)
{
	if (key == ZOOM_IN_Q)
		mlx->xy_zoom = mlx->xy_zoom + XY_ZOOM;
	if (key == ZOOM_OUT_A && mlx->xy_zoom > 0.04)
		mlx->xy_zoom = mlx->xy_zoom - XY_ZOOM;
	ft_render(mlx);
}

void	change_altitude(t_mlx *mlx, int key)
{
	if (key == ALTITUDE_INCREASE_W)
		mlx->z_zoom = mlx->z_zoom + Z_ZOOM;
	else if (key == ALTITUDE_DECREASE_S)
		mlx->z_zoom = mlx->z_zoom - Z_ZOOM;
	ft_render(mlx);
}

void	reset_program(t_mlx *mlx)
{
	get_struct_values(mlx);
	ft_render(mlx);
}

void	shift_program(t_mlx *mlx, int key)
{
	if (key == UP_K)
		mlx->y_shift = mlx->y_shift - 5;
	else if (key == DOWN_K)
		mlx->y_shift = mlx->y_shift + 5;
	else if (key == LEFT_K)
		mlx->x_shift = mlx->x_shift - 5;
	else if (key == RIGHT_K)
		mlx->x_shift = mlx->x_shift + 5;
	ft_render(mlx);
}
