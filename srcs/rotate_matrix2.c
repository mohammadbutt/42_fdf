/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matrix2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:38:02 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/06 14:35:49 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** rotate_x_axis, rotate_y_axis, and rotate_z_axis are derived using the
** standard rotation matrix equation:
** new_x = x cosθ - y sinθ
** new_y = x sinθ + y cosθ.
** x and y are changed based on what which axis is being used as radian or
** thetha.
*/

void	rotate_x_axis(t_mlx *mlx, int *y, int *z, double x_axis)
{
	int temp_y;
	int temp_z;

	temp_y = (*y * cos(x_axis)) - (*z * sin(x_axis));
	temp_z = (*y * sin(x_axis)) + (*z * cos(x_axis));
	*y = temp_y;
	*z = temp_z;
}

void	rotate_y_axis(t_mlx *mlx, int *x, int *z, double y_axis)
{
	int temp_x;
	int temp_z;

	temp_x = (*x * cos(y_axis)) - (*z * sin(y_axis));
	temp_z = (*x * sin(y_axis)) + (*z * cos(y_axis));
	*x = temp_x;
	*z = temp_z;
}

/*
** rotation at z axis is similar to rotating at y axis, but leaving it for now.
*/

void	rotate_z_axis(t_mlx *mlx, int *x, int *y, double z_axis)
{
	int temp_x;
	int temp_y;

	temp_x = (*x * cos(z_axis)) - (*y * sin(z_axis));
	temp_y = (*x * sin(z_axis)) + (*y * cos(z_axis));
	*x = temp_x;
	*y = temp_y;
}

void	rotate_xyz_axis(t_mlx *mlx)
{
	rotate_x_axis(mlx, &mlx->y0, &mlx->z0, mlx->x_axis);
	rotate_x_axis(mlx, &mlx->y1, &mlx->z1, mlx->x_axis);
	rotate_y_axis(mlx, &mlx->x0, &mlx->y0, mlx->y_axis);
	rotate_y_axis(mlx, &mlx->x1, &mlx->y1, mlx->y_axis);
	rotate_z_axis(mlx, &mlx->x0, &mlx->y0, mlx->z_axis);
	rotate_z_axis(mlx, &mlx->x1, &mlx->y1, mlx->z_axis);
}
