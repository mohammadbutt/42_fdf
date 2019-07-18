/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcc_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:01:00 by mbutt             #+#    #+#             */
/*   Updated: 2019/07/17 20:23:00 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

/*
** ft_swap, swaps values of a and b
*/

int ft_swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return(0);
}

/*
** Note: Function might not be used. But creating it in case its needed.
** Takes two int values and returns the minimum.
** This function will be used with PANEL_HEIGHT and PANEL_WIDTH.
*/

int find_min(int x, int y)
{
	if(x < y)
		return(x);
	else
		return(y);
	return(0);
}

/*
** ft_abs performs the same function as abs(3) function found in stdlib.h
** Converts a value into an absolute value, so a negative values becomes
** positive.
** Return Value: Returns a postive value.
*/

int ft_abs(int num)
{
	if(num < 0)
		num = -1 * num;
	return(num);
}

void calculate_delta_xy(t_mlx *mlx)
{
	mlx->dx = mlx->x1 - mlx->x0;
	mlx->dy = mlx->y1 - mlx->y0;
}

void plot_low_line(t_mlx *mlx)
{
	calculate_delta_xy(mlx);
	mlx->yi = 1;
	if(mlx->dy < 0)
	{
		mlx->yi = -1;
		mlx->dy = -1 * mlx->dy;
	}
	mlx->delta_error = (2 * mlx->dy) - mlx->dx;
	while(mlx->x0 < mlx->x1)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x0, mlx->y0, mlx->color);
		if(mlx->delta_error > 0)
		{
			mlx->y0 = mlx->y0 + mlx->yi;
			mlx->delta_error = mlx->delta_error - (2 * mlx->dx);
		}
		mlx->delta_error = mlx->delta_error + (2 * mlx->dy);
		mlx->x0++;
	}
}

void plot_high_line(t_mlx *mlx)
{
	calculate_delta_xy(mlx);
	mlx->xi = 1;
	if(mlx->dx < 0)
	{
		mlx->xi = -1;
		mlx->dx = -1 * mlx->dx;
	}
	mlx->delta_error = (2 * mlx->dx) - mlx->dy;
	while(mlx->y0 < mlx->y1)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x0, mlx->y0, mlx->color);
		if(mlx->delta_error > 0)
		{
			mlx->x0 = mlx->x0 + mlx->xi;
			mlx->delta_error = mlx->delta_error - (2 * mlx->dy);
		}
		mlx->delta_error = mlx->delta_error + (2 * mlx->dx);
		mlx->y0++;
	}
}

void plot_any_line(t_mlx *mlx)
{
	if(ft_abs(mlx->y1 - mlx->y0) < ft_abs(mlx->x1 - mlx->x0))
	{
		if(mlx->x0 > mlx->x1)
		{
			ft_swap(&mlx->x0, &mlx->x1);
			ft_swap(&mlx->y0, &mlx->y1);
			plot_low_line(mlx);
		}
		else
			plot_low_line(mlx);
	}
	else
	{
		if(mlx->y0 > mlx->y1)
		{
			ft_swap(&mlx->x0, &mlx->x1);
			ft_swap(&mlx->y0, &mlx->y1);
			plot_high_line(mlx);
		}
		else
			plot_high_line(mlx);
	}
}

void ft_menu(t_mlx *mlx)
{
	char *str1;
	char *str2;
	char *str3;
	char *str4;
	char *str5;

	str1 = "Menu Controls";
	str2 = "Shift: Arrow Keys: < ^ v >";
	str3 = "Zoom in and out: Q A";
	str4 = "Reset map: E";
	str5 = "Random Colors: R";

	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0x00d4ff, str1);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 30, 0x00d4ff, str2);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 50, 0x00d4ff, str3);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 70, 0x00d4ff, str4);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 90, 0x00d4ff, str5);
}
/*
** get_struct_values: sets values of several variables for struct t_mlx;
** P_WIDTH is divided by 150 and P_HEIGHT is divided by 100 and multiplied
** by the width and height of the map to centeralize it by off setting.
*/

void get_struct_values(t_mlx *mlx)
{
//	mlx->x0 = (P_WIDTH / 2) - (P_WIDTH/150 * mlx->map_width);   //Works - Put it back on after
//	mlx->y0 = (P_HEIGHT / 2) - (P_HEIGHT/100 * mlx->map_height); //Works - Put it back on after
	mlx->x0 = 50;
	mlx->x1 = mlx->x0 + 15;
	mlx->y0 = 50;
	mlx->y1 = mlx->y0;
//	mlx->y0 = 50;
//	mlx->y1 = mlx->y0;
	
	mlx->color = 0xff;
//	mlx->color = 0xff;
//	mlx->x0 = 50;
//	mlx->y0 = 50;
//	mlx->x1 = 100;
}

/*
** ft_dots: prints dots on the screen for a map.
** A dot is placed wherever there is a value.
*/


void ft_dots(t_mlx *mlx)
{
	int x;
	int y;
	int height;
	int width;

	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	height = mlx->map_height;
	width = mlx->map_width;
	
	x = mlx->x0;
	y = mlx->y0;
	while(height)
	{
		while(width)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xff);
			x = x + 15;
			width--;
		}
		width = mlx->map_width;
		x = mlx->x0;
		y = y + 15;
		height--;
	}
}

/*
** struct_copy: Copies values of source struct to destination struct:
** destination values are temporary values;
*/

void struct_copy(t_mlx *source, t_mlx *dest)
{
	dest->map_height = source->map_height;
	dest->map_width = source->map_width;
	dest->x0 = source->x0;
	dest->y0 = source->y0;
	dest->x1 = source->x1;
	dest->y1 = source->y1;
}

/*
** For ft_render values of x0 and y0 get modified because the line algorithm
** increments x0 and y0.
*/

void ft_render(t_mlx *mlx)
{
	t_mlx temp;

	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	struct_copy(mlx, &temp);
	temp.x0 = mlx->x0;
	temp.x1 = mlx->x1;
	temp.y0 = mlx->y0;
	temp.y1 = mlx->y1;
	
	printf("x0:|%d|, x1:|%d|\n y0:|%d|, y1:|%d|\n\n", mlx->x0, mlx->x1, mlx->y0, mlx->y1);
	printf("temp.map_height:|%d|\n", temp.map_height);
	printf("temp.map_width:|%d|\n", temp.map_width);
//	printf("mlx->x0:|%d|\n", mlx->x0);
//	printf("mlx->y0:|%d|\n", mlx->y0);
//	printf("mlx->x1:|%d|\n", mlx->x1);
//	printf("mlx->y1:|%d|\n\n", mlx->y1);
	while(temp.map_height)
	{
		while(temp.map_width)
		{
//Horizontal first, then vertical
			printf("H: x0:|%d|, x1:|%d|\n   y0:|%d|, y1:|%d|\n\n", mlx->x0, mlx->x1, mlx->y0, mlx->y1);
			plot_any_line(mlx);
			mlx->x0 = mlx->x0 - 15;
			mlx->x1 = mlx->x1 - 15;
			mlx->y1 = mlx->y1 + 15; // Adding for test 0.1
			printf("V: x0:|%d|, x1:|%d|\n   y0:|%d|, y1:|%d|\n\n", mlx->x0, mlx->x1, mlx->y0, mlx->y1);
			plot_any_line(mlx);
			printf("   x0:|%d|, x1:|%d|\n   y0:|%d|, y1:|%d|\n\n", mlx->x0, mlx->x1, mlx->y0, mlx->y1);
			mlx->y1 = mlx->y1 - 15;
			mlx->y0 = mlx->y0 - 15;
			mlx->x0 = mlx->x0 + 15;
			mlx->x1 = mlx->x0 + 15;
			temp.map_width--;
//			ft_exit("Exiting\n");
		}
		temp.map_width = mlx->map_width;
		temp.map_height--;
		printf("x0: x0:|%d|, x1:|%d|\n   y0:|%d|, y1:|%d|\n\n", mlx->x0, mlx->x1, mlx->y0, mlx->y1);
		mlx->y0 = mlx->y0 + 15;
		mlx->y1 = mlx->y1 + 15;	
		printf("y0: x0:|%d|, x1:|%d|\n   y0:|%d|, y1:|%d|\n\n", mlx->x0, mlx->x1, mlx->y0, mlx->y1);

		if(temp.map_height == 0)
		{
			printf("mlx->x0, mlx->y0, mlx->x1, mlx->y1:\n");
			printf("x0:|%d|, x1:|%d|\n   y0:|%d|, y1:|%d|\n\n", mlx->x0, mlx->x1, mlx->y0, mlx->y1);
			printf("temp.x0, temp.y0, temp.x1, temp.y1:\n");
			printf("x0:|%d|, x1:|%d|\n   y0:|%d|, y1:|%d|\n\n", temp.x0, temp.x1, temp.y0, temp.y1);
			mlx->x0 = temp.x0;
			mlx->x1 = mlx->x1 - 15;
			plot_any_line(mlx);
			mlx->y0 = temp.y0;
			plot_any_line(mlx);
		}
		mlx->x0 = temp.x0;
		mlx->x1 = temp.x1;
	}

//	printf("x0:|%d|, x1:|%d|\n y0:|%d|, y1:|%d|\n\n", mlx->x0, mlx->x1, mlx->y0, mlx->y1);
//	plot_any_line(mlx);

	mlx->x0 = temp.x0;
	mlx->y0 = temp.y0;
	mlx->x1 = temp.x1;
	mlx->y1 = temp.y1;
	printf("temp.map_height:|%d|\n", temp.map_height);
	printf("temp.map_width:|%d|\n", temp.map_width);
//	printf("mlx->x0:|%d|\n", mlx->x0);
//	printf("mlx->y0:|%d|\n", mlx->y0);
//	printf("mlx->x1:|%d|\n", mlx->x1);
//	printf("mlx->y1:|%d|\n", mlx->y1);


//	mlx->x0 = mlx->x1;
//	mlx->y0 = mlx->y1;
//	mlx->x1 = mlx->x1 + 15;
}

/*
** ft_print_data prints the data that is stored in t_mlx struct. Formats data
** perfectly for 42.fdf, for all other maps space would have to be adjusted.
*/
void ft_print_data(t_mlx *mlx)
{
	int i;
	int j;
	int width;
	int height;

	i = 0;
	j = 0;
	width = mlx->map_width;
	height = mlx->map_height;
	while(height)
	{
		while(j < width)
		{
			ft_putnbr(mlx->int_data[i][j]);
			if(mlx->int_data[i][j+1] == 0 && j+1 != width)
				ft_putstr("  ");
			else if(mlx->int_data[i][j+1] == 10)
				ft_putstr(" ");
			j++;
		}
		ft_putstr("\n");
		j = 0;
		i++;
		height--;
	}
}
