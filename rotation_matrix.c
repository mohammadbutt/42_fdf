/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:55:42 by mbutt             #+#    #+#             */
/*   Updated: 2019/07/27 23:36:44 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double degree_to_radian(double degrees)
{
	double radian;

	radian = degrees * (M_PI/180);
	return(radian);
}

void rotation_matrix(t_mlx *mlx, int *x, int *y, double degree_angle)
{
	t_mlx temp;
	double radian;

	radian = degree_to_radian(degree_angle);
	temp.x = (*x * cos(radian)) - (*y * sin(radian));
	temp.y = (*x * sin(radian)) + (*y * cos(radian));

	*x = temp.x;
	*y = temp.y;
}

void subtract_x0y0_from_x1y1(t_mlx *mlx)
{
	mlx->x1 = mlx->x1 - mlx->x0;
	mlx->y1 = mlx->y1 - mlx->y0;
}

void add_rotated_x1y1_to_x0y0(t_mlx *mlx)
{
	mlx->x1 = mlx->x1 + mlx->x0;
	mlx->y1 = mlx->y1 + mlx->y0;
}

void copy_mlx_xy_to_temp_xy(t_mlx *mlx, t_mlx *temp)
{
	temp->x0 = mlx->x0;
	temp->x1 = mlx->x1;
	temp->y0 = mlx->y0;
	temp->y1 = mlx->y1;
}

void copy_temp_xy_to_mlx_xy(t_mlx *mlx, t_mlx *temp)
{
	mlx->x0 = temp->x0;
	mlx->x1 = temp->x1;
	mlx->y0 = temp->y0;
	mlx->y1 = temp->y1;
}

void rotate_horizontal_line(t_mlx *mlx, t_mlx *temp)
{
//	t_mlx temp;
	double degree_angle;

//	degree_angle = -30;
	degree_angle = 30;
	copy_mlx_xy_to_temp_xy(mlx, temp);
	
	mlx->x1 = mlx->x1 + mlx->size;	
	subtract_x0y0_from_x1y1(mlx);
	rotation_matrix(mlx, &mlx->x1, &mlx->y1, degree_angle);
	add_rotated_x1y1_to_x0y0(mlx);
}

void rotate_vertical_line(t_mlx *mlx, t_mlx *temp)
{
//	t_mlx temp;
	double degree_angle;

//	degree_angle = 30;
	degree_angle = 150;
	copy_mlx_xy_to_temp_xy(mlx, temp);
	
	mlx->x1 = mlx->x1 + mlx->size;
	subtract_x0y0_from_x1y1(mlx);
	rotation_matrix(mlx, &mlx->x1, &mlx->y1, degree_angle);
	add_rotated_x1y1_to_x0y0(mlx);
}
/*
void	find_min_x(t_mlx *mlx, t_mlx *temp)
{
	if(temp->x0 < temp->x1)
	{
		mlx->x0 = temp->x0;
		mlx->x1 = temp->x0;
	}
	else if(temp->x1 < temp->x0)
	{
		mlx->x0 = temp->x1;
		mlx->x1 = temp->x1;
	}
}
*/
/*
void find_max_y(t_mlx *mlx, t_mlx *temp)
{
	if(temp->y0 > temp->y1)
	{
		mlx->y0 = temp->y0;
		mlx->y1 = temp->y0;
	}
	else if(temp->y1 > temp->y0)
	{
		mlx->y0 = temp->y1;
		mlx->y1 = temp->y1;
	}
}
*/

void find_max_y(t_mlx *mlx)
{
	if(mlx->y0 > mlx->y1)
		mlx->y = mlx->y0;
	else if(mlx->y1 > mlx->y0)
		mlx->y = mlx->y1;
}

void find_min_x(t_mlx *mlx)
{
	if(mlx->x0 < mlx->x1)
		mlx->x = mlx->x0;
	else if(mlx->x1 < mlx->x0)
		mlx->x = mlx->x1;
}




