/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:55:42 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/03 15:08:32 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_min(t_mlx *mlx)
{
	int height;
	int width;

	height = P_HEIGHT / mlx->map_height;
	width = P_WIDTH / mlx->map_width;

	if(height < width)
		return(height);
	else if(width <= height)
		return(width);
	return(0);
}

double degree_to_radian(double degrees)
{
	double radian;

	radian = degrees * (M_PI/180);
	return(radian);
}


void rotation_matrix(t_mlx *mlx, int *x, int *y, int z)
{
	int temp_x;
	int temp_y;
	double radian;

	temp_x = *x;
	temp_y = *y;
//	radian = degree_to_radian(mlx->degree_angle);
//	*x = (temp_x + temp_y) * cos(radian);
//	*y = -z + (temp_x - temp_y) * sin(radian);

	*x = (temp_x - temp_y) * cos(0.52);
	*y = -z + (temp_x + temp_y) * sin(0.52);


}


/*
void rotation_matrix(t_mlx *mlx, int *x, int *y, int z)
{
	t_mlx temp;

	double radian;

	radian = degree_to_radian(mlx->degree_angle);
//	temp.x = (x * cos(radian)) - (y * sin(radian));
//	temp.y = -z + (x * sin(radian)) + (y * cos(radian));

	temp.x = (*x + *y) * cos(radian);
	temp.y = -z + (*x - *y) * sin(radian);

	*x = temp.x;
	*y = temp.y;
}
*/
/*
// Somewhat works, does not seg fault, but need to modify value that is
// associated with each z0 and z1 so creating a new function above.
void	rotation_matrix(t_mlx *mlx, t_mlx *temp, double degree_angle)
{
	t_mlx temp2;
	double radian;

	radian = degree_to_radian(degree_angle);
//	temp2.x = (mlx->x1 * cos(radian)) - (mlx->y1 * sin(radian));
//	temp2.y = (mlx->x1 * sin(radian)) + (mlx->y1 * cos(radian));
	
	temp2.x = (mlx->x1 + mlx->y1) * cos(radian);
	temp2.y = ((mlx->x1 - mlx->y1) * sin(radian)); // Adding z value
	temp2.y = -mlx->z1 + (mlx->x1 - mlx->y1) * sin(radian);

	mlx->x1 = temp2.x;
	mlx->y1 = temp2.y;
}
*/
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

void	copy_mlx_x0y0x1y1_to_temp_x0y0x1y1(t_mlx *mlx, t_mlx *temp)
{
	temp->x0 = mlx->x0;
	temp->x1 = mlx->x1;
	temp->y0 = mlx->y0;
	temp->y1 = mlx->y1;
}

void	copy_temp_x0y0x1y1_to_mlx_x0y0x1y1(t_mlx *mlx, t_mlx *temp)
{
	mlx->x0 = temp->x0;
	mlx->x1 = temp->x1;
	mlx->y0 = temp->y0;
	mlx->y1 = temp->y1;
}

void rotate_vertical_line(t_mlx *mlx, t_mlx *temp)
{
	int min;
	double degree_angle;

//	degree_angle = 150;	
	degree_angle = 30;
	min = ft_min(mlx);
	if(mlx->y < temp->map_height)
	{
	mlx->z0 = mlx->int_data[mlx->y][mlx->x] * mlx->z_zoom * min; // Added z value
	mlx->z1 = mlx->int_data[mlx->y + 1][mlx->x] * mlx->z_zoom * min; // Added z value
	}
//	copy_mlx_x0y0x1y1_to_temp_x0y0x1y1(mlx, temp);
//	mlx->x1 = mlx->x0 + mlx->size;
//	mlx->y1 = mlx->y0 - mlx->size;
//	mlx->y1 = mlx->y0 + mlx->size;
//	mlx->x1 = mlx->x0 + mlx->size;
	mlx->x1 = mlx->x0;
	mlx->y1 = mlx->y0 + 1;

	mlx->x0 = mlx->x0 * mlx->xy_zoom * min;
	mlx->x1 = mlx->x1 * mlx->xy_zoom * min;
	mlx->y0 = mlx->y0 * mlx->xy_zoom * min;
	mlx->y1 = mlx->y1 * mlx->xy_zoom * min;
//	subtract_x0y0_from_x1y1(mlx, temp);
//	rotation_matrix(mlx, temp, degree_angle);
	printf("1. Before rotation: x0:|%d|, y0:|%d|\n", mlx->x0,  mlx->y0);
	rotation_matrix(mlx, &mlx->x0, &mlx->y0, mlx->z0);
	printf("1.  After rotation: x0:|%d|, y0:|%d|\n\n", mlx->x0, mlx->y0);

	printf("2. Before rotation: x1:|%d|, y1:|%d|\n", mlx->x1,  mlx->y1);
	rotation_matrix(mlx, &mlx->x1, &mlx->y1, mlx->z1);
	printf("2.  After rotation: x1:|%d|, y1:|%d|\n\n", mlx->x1, mlx->y1);
//	add_rotated_x1y1_to_x0y0(mlx);
	mlx->x0 = mlx->x0 + mlx->x_shift;
	mlx->x1 = mlx->x1 + mlx->x_shift;
	mlx->y0 = mlx->y0 + mlx->y_shift;
	mlx->y1 = mlx->y1 + mlx->y_shift;
//	if(mlx->x == 0)
//	{
//		find_min_x(mlx, temp);
//		find_max_y(mlx, temp);
//	}
}
void rotate_horizontal_line(t_mlx *mlx, t_mlx *temp)
{
	int min;
	double degree_angle;

	min = ft_min(mlx);
	degree_angle = 30;
	if(mlx->x < temp->map_width)
	{
	mlx->z0 = mlx->int_data[mlx->y][mlx->x] * mlx->z_zoom * min;   //Added z value 
	mlx->z1 = mlx->int_data[mlx->y][mlx->x + 1] * mlx->z_zoom * min; //Added z value
	}
//	copy_temp_x0y0x1y1_to_mlx_x0y0x1y1(mlx, temp);
//	mlx->x1 = mlx->x0 + mlx->size;
	mlx->x1 = mlx->x0 + 1;
	mlx->y1 = mlx->y0;


	mlx->x0 = mlx->x0 * mlx->xy_zoom * min;
	mlx->x1 = mlx->x1 * mlx->xy_zoom * min;
	mlx->y0 = mlx->y0 * mlx->xy_zoom * min;
	mlx->y1 = mlx->y1 * mlx->xy_zoom * min;
//	subtract_x0y0_from_x1y1(mlx, temp);
//	rotation_matrix(mlx, temp, degree_angle);
	
	printf("3. Before rotation: x0:|%d|, y0:|%d|\n", mlx->x0,  mlx->y0);
	rotation_matrix(mlx, &mlx->x0, &mlx->y0, mlx->z0);
	printf("3.  After rotation: x0:|%d|, y0:|%d|\n\n", mlx->x0, mlx->y0);

	printf("4. Before rotation: x1:|%d|, y1:|%d|\n", mlx->x1,  mlx->y1);
	rotation_matrix(mlx, &mlx->x1, &mlx->y1, mlx->z1);
	printf("4.  After rotation: x1:|%d|, y1:|%d|\n\n", mlx->x1, mlx->y1);

	mlx->x0 = mlx->x0 + mlx->x_shift;
	mlx->x1 = mlx->x1 + mlx->x_shift;
	mlx->y0 = mlx->y0 + mlx->y_shift;
	mlx->y1 = mlx->y1 + mlx->y_shift;
//	add_rotated_x1y1_to_x0y0(mlx);
}



/*
// Works and rotates map. Trying to add z value above.
void rotate_vertical_line(t_mlx *mlx, t_mlx *temp)
{
	double degree_angle;

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
