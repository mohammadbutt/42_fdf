/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcc_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:01:00 by mbutt             #+#    #+#             */
/*   Updated: 2019/07/16 13:24:24 by mbutt            ###   ########.fr       */
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
		mlx->delta_error = mlx->delta_error + (2 * mlx->dx);
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
*/

void get_struct_values(t_mlx *mlx)
{
	mlx->x0 = 0;
	mlx->y0 = 0;
}

/*
** ft_render: Renders takes a map and renders it onto a screen.
*/


void ft_render(t_mlx *mlx)
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
	printf("width:|%d|\n", width);
	printf("height:|%d|\n", height);
	while(height)
	{
		while(width)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xff);
			x = x + 15;
			width--;
//			printf("width:|%d|\n", width);
		}
		width = mlx->map_width;
		x = mlx->x0;
		y = y + 15;
		height--;
	}
//	printf("%d\n", mlx->int_data[0][0]);
//	printf("map_width:|%d|\n", mlx->map_width);
//	printf("map_height:|%d|\n", mlx->map_height);
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
