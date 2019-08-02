/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:55:42 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/01 19:59:14 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double degree_to_radian(double degrees)
{
	double radian;

	radian = degrees * (M_PI/180);
	return(radian);
}
void	rotation_matrix(t_mlx *mlx, t_mlx *temp, double degree_angle)
{
	t_mlx temp2;
	double radian;

	radian = degree_to_radian(degree_angle);
//	temp2.x = (mlx->x1 * cos(radian)) - (mlx->y1 * sin(radian));
//	temp2.y = (mlx->x1 * sin(radian)) + (mlx->y1 * cos(radian));
	
	temp2.x = (mlx->x1 + mlx->y1) * cos(radian);
//	temp2.y = ((mlx->x1 - mlx->y1) * sin(radian)); // Adding z value
	temp2.y = -mlx->z1 + (mlx->x1 - mlx->y1) * sin(radian);

	mlx->x1 = temp2.x;
	mlx->y1 = temp2.y;
}

/*
// Works and changed variables Need to implement z values.
//void rotation_matrix(t_mlx *mlx, int *x, int *y, double degree_angle)
void	rotation_matrix(t_mlx *mlx, t_mlx *temp, double degree_angle)
{
	t_mlx temp2;
	double radian;

	radian = degree_to_radian(degree_angle);
	temp2.x = (mlx->x1 * cos(radian)) - (mlx->y1 * sin(radian));
	temp2.y = (mlx->x1 * sin(radian)) + (mlx->y1 * cos(radian));

	mlx->x1 = temp2.x;
	mlx->y1 = temp2.y;
}
*/
/*
// Works, but changing variables
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
*/
void subtract_x0y0_from_x1y1(t_mlx *mlx, t_mlx *temp)
{
//	mlx->y1 = mlx->int_data[temp->y][temp->x+1];
//	mlx->y0 = mlx->int_data[temp->y][temp->x];
	mlx->x1 = mlx->x1 - mlx->x0;
	mlx->y1 = mlx->y1 - mlx->y0;
//	mlx->z1 = mlx->z1 - mlx->z0;
}

/*
// Works, trying to add z values
void subtract_x0y0_from_x1y1(t_mlx *mlx, t_mlx *temp)
{
	mlx->x1 = mlx->x1 - mlx->x0;
	mlx->y1 = mlx->y1 - mlx->y0;
}
*/

void add_rotated_x1y1_to_x0y0(t_mlx *mlx)
{
	mlx->x1 = mlx->x1 + mlx->x0;
	mlx->y1 = mlx->y1 + mlx->y0;
}

//void copy_mlx_xy_to_temp_xy(t_mlx *mlx, t_mlx *temp)
void	copy_mlx_x0y0x1y1_to_temp_x0y0x1y1(t_mlx *mlx, t_mlx *temp)
{
	temp->x0 = mlx->x0;
	temp->x1 = mlx->x1;
	temp->y0 = mlx->y0;
	temp->y1 = mlx->y1;
//	temp->z0 = mlx->z0;
//	temp->z1 = mlx->z1;
//	temp->y0 = temp->z0;
//	temp->y1 = temp->z1;
}

//void copy_temp_xy_to_mlx_xy(t_mlx *mlx, t_mlx *temp)
void	copy_temp_x0y0x1y1_to_mlx_x0y0x1y1(t_mlx *mlx, t_mlx *temp)
{
	mlx->x0 = temp->x0;
	mlx->x1 = temp->x1;
	mlx->y0 = temp->y0;
	mlx->y1 = temp->y1;
//	mlx->z0 = temp->z0;
//	mlx->z1 = temp->z1;
//	mlx->y0 = mlx->z0;
//	mlx->y1 = mlx->z1;
}
void rotate_vertical_line(t_mlx *mlx, t_mlx *temp)
{
	double degree_angle;

//	degree_angle = 30;

	degree_angle = 150;	
	if(mlx->y < temp->map_height)
	{
	mlx->z0 = mlx->int_data[mlx->y][mlx->x]; // Added z value
	mlx->z1 = mlx->int_data[mlx->y + 1][mlx->x]; // Added z value
	}
	copy_mlx_x0y0x1y1_to_temp_x0y0x1y1(mlx, temp);
	mlx->x1 = mlx->x1 + mlx->size;
	subtract_x0y0_from_x1y1(mlx, temp);
	rotation_matrix(mlx, temp, degree_angle);
	add_rotated_x1y1_to_x0y0(mlx);


	if(mlx->x == 0)
	{
		find_min_x(mlx, temp);
		find_max_y(mlx, temp);
	}
}

void rotate_horizontal_line(t_mlx *mlx, t_mlx *temp)
{
	double degree_angle;

//	degree_angle = -30;
	degree_angle = 30;

	if(mlx->x < temp->map_width)
	{
	mlx->z0 = mlx->int_data[mlx->y][mlx->x];   //Added z value 
	mlx->z1 = mlx->int_data[mlx->y][mlx->x + 1]; //Added z value
	}
	copy_temp_x0y0x1y1_to_mlx_x0y0x1y1(mlx, temp);
	mlx->x1 = mlx->x1 + mlx->size;
	subtract_x0y0_from_x1y1(mlx, temp);
	rotation_matrix(mlx, temp, degree_angle);
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

/*
** copy_temp_xy_to_mlx_x0y0x1y1 is used with find_min_x and find_max_y
*/

void copy_temp_xy_to_mlx_x0y0x1y1(t_mlx *mlx, t_mlx *temp)
{
	mlx->x0 = temp->x;
	mlx->x1 = temp->x;
	mlx->y0 = temp->y;
	mlx->y1 = temp->y;
}


void find_min_x(t_mlx *mlx, t_mlx *temp)
{
	temp->x = 0;
	if(mlx->x0 < mlx->x1)
		temp->x = mlx->x0;
	else if(mlx->x1 <= mlx->x0)
		temp->x = mlx->x1;
}

void find_max_y(t_mlx *mlx, t_mlx *temp)
{
	temp->y = 0;
	if(mlx->y0 > mlx->y1)
		temp->y = mlx->y0;
	else if(mlx->y1 >= mlx->y0)
		temp->y = mlx->y1;
}
