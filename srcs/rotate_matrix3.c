/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matrix3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:38:19 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/06 08:24:34 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_projection_view(t_mlx *mlx)
{
	rotation_matrix(mlx, &mlx->x0, &mlx->y0, mlx->z0);
	rotation_matrix(mlx, &mlx->x1, &mlx->y1, mlx->z1);
}

void	shift_and_centeralize_map(t_mlx *mlx)
{
	mlx->x0 = mlx->x0 + mlx->x_shift + (P_WIDTH / 2.5);
	mlx->x1 = mlx->x1 + mlx->x_shift + (P_WIDTH / 2.5);
	mlx->y0 = mlx->y0 + mlx->y_shift + (P_HEIGHT / 4);
	mlx->y1 = mlx->y1 + mlx->y_shift + (P_HEIGHT / 4);
}

void	implement_transformations(t_mlx *mlx, int normalize)
{
	adjust_zoom(mlx, normalize);
	rotate_xyz_axis(mlx);
	change_projection_view(mlx);
	shift_and_centeralize_map(mlx);
}

void	rotate_vertical_line(t_mlx *mlx, t_mlx *temp)
{
	int normalize;

	normalize = ft_normalize(mlx);
	if (mlx->y < temp->map_height)
	{
		mlx->z0 = mlx->int_data[mlx->y][mlx->x] * mlx->z_zoom * normalize;
		mlx->z1 = mlx->int_data[mlx->y + 1][mlx->x] * mlx->z_zoom * normalize;
	}
	mlx->x1 = mlx->x0;
	mlx->y1 = mlx->y0 + 1;
	implement_transformations(mlx, normalize);
}

void	rotate_horizontal_line(t_mlx *mlx, t_mlx *temp)
{
	int normalize;

	normalize = ft_normalize(mlx);
	if (mlx->x < temp->map_width)
	{
		mlx->z0 = mlx->int_data[mlx->y][mlx->x] * mlx->z_zoom * normalize;
		mlx->z1 = mlx->int_data[mlx->y][mlx->x + 1] * mlx->z_zoom * normalize;
	}
	mlx->x1 = mlx->x0 + 1;
	mlx->y1 = mlx->y0;
	implement_transformations(mlx, normalize);
}
