/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matrix1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:37:38 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/06 08:37:47 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_normalize(t_mlx *mlx)
{
	int height;
	int width;

	height = P_HEIGHT / mlx->map_height;
	width = P_WIDTH / mlx->map_width;
	if (height < width)
		return (height);
	else if (width <= height)
		return (width);
	return (0);
}

double	degree_to_radian(double degrees)
{
	double radian;

	radian = degrees * (M_PI / 180);
	return (radian);
}

void	rotation_matrix(t_mlx *mlx, int *x, int *y, int z)
{
	int		temp_x;
	int		temp_y;
	double	radian;

	temp_x = *x;
	temp_y = *y;
	if (mlx->camera == 0)
		mlx->degree_angle = 30;
	else if (mlx->camera == 1)
		mlx->degree_angle = 15;
	radian = degree_to_radian(mlx->degree_angle);
	*x = (temp_x - temp_y) * cos(radian);
	*y = -z + (temp_x + temp_y) * sin(radian);
}

void	adjust_zoom(t_mlx *mlx, int normalize)
{
	mlx->x0 = mlx->x0 * mlx->xy_zoom * normalize;
	mlx->x1 = mlx->x1 * mlx->xy_zoom * normalize;
	mlx->y0 = mlx->y0 * mlx->xy_zoom * normalize;
	mlx->y1 = mlx->y1 * mlx->xy_zoom * normalize;
}
