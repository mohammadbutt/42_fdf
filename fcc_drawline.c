/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcc_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:01:00 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/04 17:49:28 by mbutt            ###   ########.fr       */
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
	size_t hue;

	hue = mlx->color;
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
//		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x0, mlx->y0, mlx->color);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x0, mlx->y0, ft_hue(mlx->y0, hue));
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
	size_t hue;

	hue = mlx->color;
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
//		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x0, mlx->y0, mlx->color);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x0, mlx->y0, ft_hue(mlx->y0, hue));
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
	char *str6;
	char *str7;

	str1 = "Menu Controls";
	str2 = "Shift: Arrow Keys: < ^ v >";
	str3 = "Rotate: I J K L";
	str4 = "Zoom: Q A";
	str5 = "Altitude: W S";
	str6 = "Reset map: E";
	str7 = "Random Colors: R";

	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0xffffff, str1);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 40, 0xadadad, str2);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 60, 0xadadad, str3);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 80, 0xadadad, str4);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 100, 0xadadad, str5);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 120, 0xadadad, str6);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 140, 0xadadad, str7);

}
/*
** get_struct_values: sets values of several variables for struct t_mlx;
** P_WIDTH is divided by 150 and P_HEIGHT is divided by 100 and multiplied
** by the width and height of the map to centeralize it by off setting.
*/
/*
void get_struct_values(t_mlx *mlx)
{
//	mlx->x0 = (P_WIDTH / 2) - (P_WIDTH/150 * mlx->map_width);   //Works - Put it back on after
//	mlx->y0 = (P_HEIGHT / 2) - (P_HEIGHT/100 * mlx->map_height); //Works - Put it back on after
	mlx->size = 15;
	mlx->x0 = 50;
	mlx->x1 = mlx->x0 + mlx->size;
	mlx->y0 = 50;
	mlx->y1 = mlx->y0;
	
	mlx->color = 0xff;
}
*/
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
			x = x + mlx->size;
			width--;
		}
		width = mlx->map_width;
		x = mlx->x0;
		y = y + mlx->size;
		height--;
	}
}

/*
** struct_copy: Copies values of source struct to destination struct:
** destination values are temporary values;
*/
/*
void struct_copy(t_mlx *source, t_mlx *dest)
{
	dest->map_height = source->map_height;
	dest->map_width = source->map_width;
	dest->x0 = source->x0;
	dest->y0 = source->y0;
	dest->x1 = source->x1;
	dest->y1 = source->y1;
}
*/
/*
** ft_render_horizontal and ft_render_vertical create a flat map.
** There is a lot of addition and subtraction, so I will try my best to
** explain a few points.
** plot_any_line(mlx) simply draws a straight horizontal line from x0 to x1,
** going left to right ⇨ . In doing so, x0 becomes x1.
** size is subtracted from x0 and x1, so when the vertical straight line is
** drawn, it would start at the tail, instead of the head.
** size is added to y1, so a vertical line can be drawn in the downwards
** direction ⇩ .
*/

// Both functions work, just
// Method 1


/*
void get_z_value(t_mlx *mlx, t_mlx *temp)
{
	if((mlx->x +1) < temp->map_width)
	{
		mlx->z0 = mlx->int_data[mlx->y][mlx->x];
		mlx->z1 = mlx->int_data[mlx->y][mlx->x + 1];
	}
	mlx->x0 = mlx->z0;
	mlx->x1 = mlx->z1;
}
*/
/*
// Works - making slight changes
void ft_render_horizontal(t_mlx *mlx, t_mlx *temp)
{
	mlx->x1 = mlx->x0 + mlx->size;
//	get_z_value(mlx, temp);
	plot_any_line(mlx);
	mlx->x0 = mlx->x0 - mlx->size;
	mlx->x1 = mlx->x1 - mlx->size;
	mlx->y1 = mlx->y1 + mlx->size;
//	ft_exit()
}
*/
/*
// Deprecated.
// Works and creates borderlines. Making changes to implement angles
void ft_render_horizontal(t_mlx *mlx, t_mlx *temp)
{
	mlx->x1 = mlx->x0 + mlx->size;
	if(mlx->x < temp->map_width)
		plot_any_line(mlx);
	if(mlx->y != temp->map_height)
	{
		mlx->x0 = mlx->x0 - mlx->size;
		mlx->x1 = mlx->x1 - mlx->size;
		mlx->y1 = mlx->y1 + mlx->size;
	}
}
*/

// Working on z values
void ft_render_vertical(t_mlx *mlx, t_mlx *temp)
{
//	mlx->x0 = mlx->x + (temp->map_width * 2);
//	mlx->y0 = mlx->y + (temp->map_height * 0.000001);	
//	mlx->x0 = mlx->x + (P_WIDTH / 3);
//	mlx->y0 = mlx->y + (P_HEIGHT / 3);
	mlx->x0 = mlx->x;
	mlx->y0 = mlx->y;

//	mlx->x0 = mlx->x0 + 30;
//	mlx->y0 = mlx->y0 + 4;	
//	mlx->x0 = mlx->x + 640;
//	mlx->y0 = mlx->y + 360;

//	printf("x0:|%d|, y0:|%d|\n", mlx->x0, mlx->y0);
//	printf("x1:|%d|, y1:|%d|\n\n", mlx->x1, mlx->y1);
	rotate_vertical_line(mlx, temp);
	if(mlx->y < temp->map_height)
		plot_any_line(mlx);
}

void ft_render_horizontal(t_mlx *mlx, t_mlx *temp)
{
//	mlx->x0 = mlx->x + (temp->map_width * 2);
//	mlx->y0 = mlx->y + (temp->map_height * 0.000001);
//	mlx->x0 = mlx->x + (P_WIDTH / 3);
//	mlx->y0 = mlx->y + (P_HEIGHT / 3);
	mlx->x0 = mlx->x;
	mlx->y0 = mlx->y;

//	mlx->x0 = mlx->x0 + 30;
//	mlx->y0 = mlx->y0 + 4;

//	mlx->x0 = mlx->x + 640;
//	mlx->y0 = mlx->y + 360;

	rotate_horizontal_line(mlx, temp);
	if(mlx->x < temp->map_width)
		plot_any_line(mlx);
}

/*
//Camera change works - Need to work on Z Values
void ft_render_vertical(t_mlx *mlx, t_mlx *temp)
{
	if(mlx->camera == 1)
		mlx->y1 = mlx->y1 + mlx->size;

	if(mlx->camera == 0)
		rotate_vertical_line(mlx, temp);
	if(mlx->y < temp->map_height)
		plot_any_line(mlx);
	if(mlx->camera == 1)
		mlx->y0 = mlx->y0 - mlx->size;
		mlx->y1 = mlx->y1 - mlx->size;
}

void ft_render_horizontal(t_mlx *mlx, t_mlx *temp)
{
	 if(mlx->camera == 1)
 		mlx->x1 = mlx->x1 + mlx->size;
	if(mlx->camera == 0)
		rotate_horizontal_line(mlx, temp);
	if(mlx->x < temp->map_width)
		plot_any_line(mlx);
}
*/

/*
// Works - Adding rotation to this.
void ft_render_vertical(t_mlx *mlx, t_mlx *temp)
{
	mlx->y1 = mlx->y1 + mlx->size;
	plot_any_line(mlx);
	mlx->y0 = mlx->y0 - mlx->size;
	mlx->y1 = mlx->y1 - mlx->size;
}

void ft_render_horizontal(t_mlx *mlx, t_mlx *temp)
{
	mlx->x1 = mlx->x1 + mlx->size;

	if(mlx->x < temp->map_width)
		plot_any_line(mlx);
}
*/
/*
// Deprecated 2
// Works, but changing order. ft_render_vertical will be done first and then
// ft_render_horizontal will be done, so ft_render_horizontal can bring us back to the
// default starting point for the next cube.
void ft_render_horizontal(t_mlx *mlx, t_mlx *temp)
{
	mlx->x1 = mlx->x0 + mlx->size;

//	rotate_horizontal_line(mlx, temp);
	if(mlx->x < temp->map_width)
		plot_any_line(mlx);
//	if(mlx->y != temp->map_height)
//	{
//		copy_temp_xy_to_mlx_xy(mlx, temp);
//		mlx->y1 = mlx->y1 + mlx->size;
//	}
//	if(mlx->y != temp->map_height)

	if(mlx->y < temp->map_height)
	{
		mlx->x0 = mlx->x0 - mlx->size;
		mlx->x1 = mlx->x1 - mlx->size;
		mlx->y1 = mlx->y1 + mlx->size;
	}
}

void ft_render_vertical(t_mlx *mlx, t_mlx *temp)
{
//	get_z_value(mlx, temp);
	if(mlx->x == temp->map_width) 			//Added for border edges.
		mlx->x0 = mlx->x0 + mlx->size;		//Added for border edges.
//	rotate_vertical_line(mlx, temp); 
	plot_any_line(mlx);
//	copy_temp_xy_to_mlx_xy(mlx, temp);
	mlx->x0 = mlx->x0 + mlx->size;
	mlx->x1 = mlx->x1 + mlx->size;
	mlx->y1 = mlx->y1 - mlx->size;
	mlx->y0 = mlx->y0 - mlx->size;
//	mlx->x0 = mlx->x0 + mlx->size;
//	mlx->x1 = mlx->x0 + mlx->size;
//	get_z_value(mlx, temp);
}
*/
/*
** for ft_render_vertical, x0 = x1, but y1 is greater than y0, which allows us
** to draw vertical line in the downwards direction ⇩ .
** In the next 2 lines, size is subtracted from the y1 and y0, to bring y1 and
** y0 back to the tail, also y1 and y0 are equal to each other.
** size is added to x0 and x1, but x1 is greater x0 allowing us to create a
** striaght horizontal line next time.
*/
/*
// Deprecated
// Works and creates borderlines. Making changes to implement angles.
void ft_render_vertical(t_mlx *mlx, t_mlx *temp)
{
//	get_z_value(mlx, temp);
	if(mlx->x == temp->map_width) 			//Added for border edges.
		mlx->x0 = mlx->x0 + mlx->size;		//Added for border edges.
	plot_any_line(mlx);
	mlx->y1 = mlx->y1 - mlx->size;
	mlx->y0 = mlx->y0 - mlx->size;
	mlx->x0 = mlx->x0 + mlx->size;
	mlx->x1 = mlx->x0 + mlx->size;
//	get_z_value(mlx, temp);
}
*/

/*
** ft_render_horizontal_vertical just calls onto ft_render_horizontal and
** ft_render_vertical to render lines. Below is how the lines would appear:
**  _ _ _ _ _ _ _
** |_|_|_|_|_|_|_
** |_|_|_|_|_|_|_
** | | | | | | |
** 
** The map is rendered fine, except, there are no enclosed lines rendered at the
** end and the bottom, ft_render_edges takes care of that.
*/

//void ft_render_horizontal_vertical(t_mlx *mlx, t_mlx *temp)
void	ft_render_vertical_horizontal(t_mlx *mlx, t_mlx *temp)
{
	if(mlx->camera == 0 || mlx->camera == 1)
	{
		if(mlx->y < temp->map_height)	
			ft_render_vertical(mlx, temp);
		ft_render_horizontal(mlx, temp);
	}
}

/*
** ft_render_edges creates the bottom borderline for the map,a horizontal line
** from left to right and then the right borderline, a vertical line from top to
** bottom. Below is how the rendered map would look like now:
**  _ _ _ _ _ _ _
** |_|_|_|_|_|_|_|
** |_|_|_|_|_|_|_|
** |_|_|_|_|_|_|_|
*/


void ft_render_edges(t_mlx *mlx, t_mlx *temp)
{
	mlx->x0 = temp->x0;
	mlx->x1 = mlx->x1 - mlx->size;
	plot_any_line(mlx);
	mlx->y0 = temp->y0;
	plot_any_line(mlx);
}


/*
// Method 2
void ft_render_horizontal(t_mlx *mlx)
{
	plot_any_line(mlx);
}

void ft_render_vertical(t_mlx *mlx)
{
	mlx->y1 = mlx->y1 + mlx->size;
	plot_any_line(mlx);
	mlx->y0 = mlx->y0 - mlx->size;
	mlx->y1 = mlx->y0;
	mlx->x1 = mlx->x1 + mlx->size;
}

void ft_render_horizontal_vertical(t_mlx *mlx)
{
	ft_render_horizontal(mlx);
	ft_render_vertical(mlx);
}

void ft_render_edges(t_mlx *mlx, t_mlx *temp)
{
	mlx->x0 = temp->x0;
	mlx->x1 = mlx->x1 - mlx->size;
	plot_any_line(mlx);
	mlx->x0 = temp->x0;
	mlx->x1 = temp->x0;
	mlx->y0 = temp->y0;
	plot_any_line(mlx);
}
*/
/*
** struct_copy: Copies values of source struct to destination struct:
** destination values are temporary values;
*/

void struct_copy(t_mlx *source, t_mlx *dest)
{
	dest->map_height = source->map_height;
	dest->map_width = source->map_width;
	dest->map_height--;
	dest->map_width--;
	dest->x0 = source->x0;
	dest->y0 = source->y0;
	dest->x1 = source->x1;
	dest->y1 = source->y1;
}

void get_struct_values(t_mlx *mlx)
{
	t_mlx temp;
	size_t hue;
	mlx->size = 15;
	mlx->x = 0;
	mlx->y = 0;
//	mlx->x0 = 0;
//	mlx->y0 = 0;
	mlx->camera = 0;
	mlx->x_shift = 0;
	mlx->y_shift = 0;
	mlx->x0 = (P_WIDTH / 2); //- (P_WIDTH/160 * mlx->map_width);   //Works - Put it back on after
	mlx->y0 = (P_HEIGHT / 2);// - (P_HEIGHT/95 * mlx->map_height); //Works - Put it back on after
	mlx->x1 = mlx->x0;
	mlx->y1 = mlx->y0;
	mlx->camera = 0;
	mlx->angle_y = 0.5;
	mlx->angle_z = 0.25;
	mlx->degree_angle = 30;
	mlx->xy_zoom = 0.5;
	mlx->z_zoom = 0.03;
	mlx->x_axis = 0;
	mlx->y_axis = 0;
	mlx->z_axis = 0;
//	t_mlx temp;	
//	mlx->size = 15;
//	mlx->x0 = mlx->size;
//	mlx->x1 = mlx->size;
//	mlx->y0 = mlx->size;
//	mlx->y1 = mlx->size;

	mlx->color = 0xff000;
//	hue = 0xff;
//	mlx->color = ft_hue(mlx->y0, hue);
}

/*
** For ft_render values of x0 and y0 get modified because the line algorithm
** increments x0 and y0.
*/
/*
void ft_render(t_mlx *mlx)
{
	t_mlx temp;
	
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
//	ft_menu(mlx);
	struct_copy(mlx, &temp);
	while(temp.map_height)
	{
		while(temp.map_width)
		{
			ft_render_horizontal_vertical(mlx);
			temp.map_width--;
		}
		temp.map_width = mlx->map_width;
		temp.map_height--;
		mlx->y0 = mlx->y0 + mlx->size;
		mlx->y1 = mlx->y1 + mlx->size;
		if(temp.map_height == 0)
			ft_render_edges(mlx, &temp);
		mlx->x0 = temp.x0;
		mlx->x1 = temp.x1;
	}
	mlx->x0 = temp.x0;
	mlx->y0 = temp.y0;
	mlx->x1 = temp.x1;
	mlx->y1 = temp.y1;
}
*/

/*
** Once x0 and x1
*/

void reset_x0x1(t_mlx *mlx, t_mlx *temp_reset)
{
	mlx->x0 = temp_reset->x0;
	mlx->x1 = temp_reset->x1;
	mlx->x = 0;
}

/*
** reset_y0y1 is used in ft_render to reset values for y0, and y1. Because
** y0 and y1 get changed in the while loop. It is important to reset y0 and y1
** back to it's original values if we want to integrate keyboard into the
** program allowing us to shift the program in any direction and change zoom.
*/

void reset_y0y1(t_mlx *mlx, t_mlx *temp_reset)
{
	mlx->y0 = temp_reset->y0;
	mlx->y1 = temp_reset->y1;
	mlx->y = 0;
}

void reset_x0x1_y0y1(t_mlx *mlx, t_mlx *temp_reset)
{
	reset_x0x1(mlx, temp_reset);
	reset_y0y1(mlx, temp_reset);
}
//Working on it - Need to make z value work
void ft_render(t_mlx *mlx)
{
	t_mlx temp;
	t_mlx temp_reset;
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_menu(mlx);
	struct_copy(mlx, &temp);
	copy_mlx_x0y0x1y1_to_temp_x0y0x1y1(mlx, &temp_reset);
	while(mlx->y <= temp.map_height)
	{
		while(mlx->x <= temp.map_width)
		{
			ft_render_vertical_horizontal(mlx, &temp);
			mlx->x++;
		}
		mlx->x = 0;
		mlx->y++;
	}
	reset_x0x1_y0y1(mlx, &temp_reset);
}


/*
//Rotation works - Need to make z value work
void ft_render(t_mlx *mlx)
{
	t_mlx temp;
	t_mlx temp_reset;
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_menu(mlx);
	struct_copy(mlx, &temp);
	copy_mlx_x0y0x1y1_to_temp_x0y0x1y1(mlx, &temp_reset);
	while(mlx->y <= temp.map_height)
	{
		while(mlx->x <= temp.map_width)
		{
			ft_render_vertical_horizontal(mlx, &temp);
			ft_putnbr(mlx->int_data[mlx->y][mlx->x]);
			ft_putstr(" ");
			mlx->x++;
		}
		ft_putstr("\n");
		if(mlx->camera == 0)
			copy_temp_xy_to_mlx_x0y0x1y1(mlx, &temp);
		else if(mlx->camera == 1)
		{
			mlx->y0 = mlx->y0 + mlx->size;
			mlx->y1 = mlx->y1 + mlx->size;
			reset_x0x1(mlx, &temp);
		}
		mlx->x = 0;
		mlx->y++;
	}
	reset_x0x1_y0y1(mlx, &temp_reset);
}
*/

/*
// flat map Works - Adding rotation
void ft_render(t_mlx *mlx)
{
	t_mlx temp;

	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	struct_copy(mlx, &temp);

	while(mlx->y <= temp.map_height)
	{
		while(mlx->x <= temp.map_width)
		{
			if(mlx->y < temp.map_height)
				ft_render_horizontal_vertical(mlx, &temp);
			else if(mlx->y == temp.map_height)
				ft_render_horizontal(mlx, &temp);
			mlx->x++;
		}
		mlx->x = 0;
		mlx->y++;
		mlx->y0 = mlx->y0 + mlx->size;
		mlx->y1 = mlx->y1 + mlx->size;
		reset_x0x1(mlx, &temp);
	}
	reset_y0y1(mlx, &temp);
}
*/

/*
// Deprecated
// Works, trying to fix borderline edges.
void ft_render(t_mlx *mlx)
{
	t_mlx temp;

	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	struct_copy(mlx, &temp);
	while(mlx->y < temp.map_height)
	{
		while(mlx->x < temp.map_width)
		{
			ft_render_horizontal_vertical(mlx, &temp);
			mlx->x++;
		}
		mlx->x = 0;
		mlx->y++;
		mlx->y0 = mlx->y0 + mlx->size;
		mlx->y1 = mlx->y1 + mlx->size;
		if(mlx->y == temp.map_height)
			ft_render_edges(mlx, &temp);
		reset_x0x1(mlx, &temp);
	}
	reset_y0y1(mlx, &temp);
//	mlx->y = 0;
}
*/


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

