/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcc_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:46:06 by mbutt             #+#    #+#             */
/*   Updated: 2019/07/15 19:44:06 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Freecodecamp and wikipedia*/
#include <stdio.h>
#include "fdf.h"

/*
** Function drawline_base will be deleted and will not be used in the project
** because it is a barebone prototype
*/
/*
void drawline_base(int x0, int y0, int x1, int y1)
{
	int dx;
	int dy;
	int delta_error;

	dx = x1 - x0;
	dy = y1 - y0;
	delta_error = (2 * dy) - dx;
	printf("FreeCodeCamp\np:|%d|\n", delta_error);
	while(x0 < x1)
	{
		printf("x:|%d|y:|%d|\n", x0, y0);
		if(delta_error >= 0)
		{
			y0++;
			delta_error = delta_error - (2 * dx); // (2 * dx) can be optimized
		}
		delta_error = delta_error + (2 * dy); // (2 * dy) can be optimized
		x0++;
	}
}
*/
/*
** Takes two int values and returns the minimum.
** This function will be used with PANEL_HEIGHT and PANEL_WIDTH
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
** ft_abs performs the same functions as abs function found in the math.h library.
** Converts a value into an absolute value, so the number passed in becomes a positive
** if it was previously negative.
** Return Value: Returns a positive number or 0.
*/

int ft_abs(int num)
{
	if(num < 0)
		num = -1 * num;
	return(num);
}

void plot_low_line( t_fdf *fdf, int x0, int y0, int x1, int y1)
{
//	t_fdf	*fdf;
	int 	dx;
	int 	dy;
	int 	delta_error;
	int 	yi;

	dx = x1 - x0;
	dy = y1 - y0;
	yi = 1;
	if(dy < 0)
	{
		yi = -1;   // Can we do y0--? so in below if statement we can do y0++;?
		dy = -1 * dy;
	}
	delta_error = (2 * dy) - dx;
	while(x0 < x1)
	{
		printf("plot_low_line1\n");
		printf("x:|%d|y:|%d|\n", x0, y0);
		mlx_pixel_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, x0, y0, 0x696969);
		printf("plot_low_line2\n");
		if(delta_error > 0)
		{
			y0 = y0 + yi; //If we change the above, can we change this to y0++;?
			delta_error = delta_error - (2 * dx); /* (2 * dx) can be optimized*/
		}
		delta_error = delta_error + (2 * dy); /*(2 * dy) can be optimized*/
		x0++;
	}
}

void plot_high_line(t_fdf *fdf, int x0, int y0, int x1, int y1)
{
	int dx;
	int dy;
	int delta_error;
	int xi;

	dx = x1 - x0;
	dy = y1 - y0;
	xi = 1;
	if(dx < 0)
	{
		xi = -1; // Can we do x0--? so in below if statement we can do x0++;?
		dx = -1 * dx;
	}
	delta_error = (2 * dx) - dy;
	while(y0 < y1)
	{
		printf("x:|%d|y:|%d|\n", x0, y0);
		mlx_pixel_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, x0, y0, 0x696969);
		if(delta_error > 0)
		{
			x0 = x0 + xi;  // If we change the above, can we change it to x0++;?
			delta_error = delta_error - (2 * dy); /* (2 * dy) can be optimized*/
		}
		delta_error = delta_error + (2 * dx); /*(2 * dx) can be optimized*/
		y0++;
	}
}

void plot_any_line(t_fdf *fdf, int x0, int y0, int x1, int y1)
{
	if(ft_abs(y1 - y0) < ft_abs(x1 - x0))
	{
		if(x0 > x1)
			plot_low_line(fdf, x1, y1, x0, y0);
		else
			plot_low_line(fdf, x0, y0, x1, y1);
	}
	else
	{
		if(y0 > y1)
			plot_high_line(fdf, x1, y1, x0, y0);
		else
			plot_high_line(fdf, x0, y0, x1, y1);
	}
}

void isometric_view(int *x, int *y, int z)
{
	int temp_x;
	int temp_y;

	temp_x = *x;
	temp_y = *y;

	*x = (temp_x + temp_y) * cos(ISOMETRIC);
	*y = (temp_x - temp_y) * sin(ISOMETRIC) - z;
}

void topdown_view(int *x, int *y, int z)
{
	int temp_x;
	int temp_y;

	temp_x = *x;
	temp_y = *y;

	*x = (temp_x + temp_y) * cos(TOPDOWN);
	*y = (temp_x - temp_y) * sin(TOPDOWN) - z;
}
/*
** Divides the panel height with map height, and panel width with map width
** to find the minimum value that the map will be normalized by
*/

int normalize_map(t_fdf *fdf)
{
	int min;

	min = find_min(P_HEIGHT / fdf->map_height, P_WIDTH / fdf->map_width);
	return(min);
}

/*
** Centeralizes map
*/

void 	centeralize_map(t_fdf *fdf, int x, int y)
{
	fdf->x0 = x - fdf->map_width / 2;
	fdf->y0 = y - fdf->map_height / 2;
}

/*
** Takes the int value and places it onto map to make the map appear 3 Dimensional
*/

void	place_z_on_horizontal(t_fdf *fdf, int x, int y, int normalize)
{
	printf("place z 1:\n");
	printf("x:|%d|\n", x);
	printf("y:|%d|\n", y);
	fdf->z0 = (fdf->int_data_2[y][x]) * normalize;
	printf("place z 2:\n");
	fdf->z1 = (fdf->int_data_2[y][x+1]) * normalize;
}
void 	place_z_on_vertical(t_fdf *fdf, int x, int y, int normalize)
{
	fdf->z0 = fdf->int_data_2[y][x] * normalize;
	printf("place z on vertical 1\n");
	printf("x:|%d| y:|%d| |%d|\n", x, y, normalize);
	fdf->z1 = fdf->int_data_2[y+1][x] * normalize;
	printf("place z on vertical 2\n");

}

void	horizontal_x1_y1(t_fdf *fdf)
{
	fdf->x1 = fdf->x0 + 1;
	fdf->y1 = fdf->y0;
}

void	vertical_x1_y1(t_fdf *fdf)
{
//	printf("vertical render 1\n");
	fdf->x1 = fdf->x0;
//	printf("vertical_render 2\n");
	fdf->y1 = fdf->y0 + 1;
}
/*
void	horizontal_shift(t_fdf *fdf, int normalize)
{

}
*/
void	horizontal_render(t_fdf *fdf, int x, int y)
{
	int normalize;
	normalize = normalize_map(fdf);
	centeralize_map(fdf, x, y);
	place_z_on_horizontal(fdf, x, y, normalize);
	horizontal_x1_y1(fdf);
	plot_any_line(fdf, fdf->x0, fdf->y0, fdf->x1, fdf->y1);
}

void	vertical_render(t_fdf *fdf, int x, int y)
{
	int normalize;
	
	normalize = normalize_map(fdf);
	centeralize_map(fdf, x, y);
	place_z_on_vertical(fdf, x, y, normalize);
	vertical_x1_y1(fdf);
	plot_any_line(fdf, fdf->x0, fdf->y0, fdf->x1, fdf->y1);
}

void	ft_render(t_fdf *fdf)
{
//	t_mlx 	mlx;
	int 	x;
	int 	y;

	x = 0;
	y = 0;

//	mlx_clear_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
	while(y < fdf->map_height)
	{
		while(x < fdf->map_width)
		{
			if(x+1 < fdf->map_width)
			{
				horizontal_render(fdf, x, y);
			}
			if(y+1 < fdf->map_height)
			{
				vertical_render(fdf, x, y);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
/*
int main(void)
{
	int x0, y0, x1, y1;
	printf("Enter coordinates of first point: ");
	scanf("%d%d", &x0, &y0);

	printf("Enter coordinates of second point: ");
	scanf("%d%d", &x1, &y1);
	drawline_base(x0, y0, x1, y1);

	printf("\nprinting from plot_any_line function\n");

	plot_any_line(x0, y0, x1, y1);
	return(0);
}
*/
