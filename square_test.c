/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:27:24 by mbutt             #+#    #+#             */
/*   Updated: 2019/07/26 12:08:55 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square_test.h"
/*
typedef struct 	s_mlx1
{
	void 		*mlx_ptr;
	void 		*win_ptr;
}				t_mlx1;
*/

int ft_swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return(0);
}

int ft_abs(int num)
{
	if(num < 0)
		num = -1 * num;
	return(num);
}

void calculate_dx_dy(t_mlx **mlx)
{
	(*mlx)->dx = (*mlx)->x1 - (*mlx)->x0;
	(*mlx)->dy = (*mlx)->y1 - (*mlx)->y0;
}

void plot_low_line(t_mlx **mlx)
{
//	calculate_dx_dy(mlx);
	(*mlx)->dx = (*mlx)->x1 - (*mlx)->x0;
	(*mlx)->dy = (*mlx)->y1 - (*mlx)->y0;
	(*mlx)->yi = 1;
	if((*mlx)->dy < 0)
	{
		(*mlx)->yi = -1;
		(*mlx)->dy = -1 * (*mlx)->dy;
	}
	(*mlx)->delta_error = (2 * (*mlx)->dy) - (*mlx)->dx;
	while((*mlx)->x0 < (*mlx)->x1)
	{
//		printf("x0:|%d|, x1:|%d|, y0:|%d|, y1:|%d|\n", (*mlx)->x0, (*mlx)->x1, (*mlx)->y0, (*mlx)->y1);
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, (*mlx)->x0,
				(*mlx)->y0, (*mlx)->color);
		if((*mlx)->delta_error > 0)
		{
			(*mlx)->y0 = (*mlx)->y0 + (*mlx)->yi;
			(*mlx)->delta_error = (*mlx)->delta_error - (2 * (*mlx)->dx);
		}
		(*mlx)->delta_error = (*mlx)->delta_error + (2 * (*mlx)->dy);
		(*mlx)->x0++;
	}
}

void plot_high_line(t_mlx **mlx)
{
	(*mlx)->dx = (*mlx)->x1 - (*mlx)->x0;
	(*mlx)->dy = (*mlx)->y1 - (*mlx)->y0;
	(*mlx)->xi = 1;
	if((*mlx)->dx < 0)
	{
		(*mlx)->xi = -1;
		(*mlx)->dx = -1 * (*mlx)->dx;
	}
	(*mlx)->delta_error = (2 * (*mlx)->dx) - (*mlx)->dy;
	while((*mlx)->y0 < (*mlx)->y1)
	{
//		printf("x0:|%d|, x1:|%d|, y0:|%d|, y1:|%d|\n", (*mlx)->x0, (*mlx)->x1, (*mlx)->y0, (*mlx)->y1);
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, (*mlx)->x0,
				(*mlx)->y0, (*mlx)->color);
		if((*mlx)->delta_error > 0)
		{
			(*mlx)->x0 = (*mlx)->x0 + (*mlx)->xi;
			(*mlx)->delta_error = (*mlx)->delta_error - (2 * (*mlx)->dy);
		}
		(*mlx)->delta_error = (*mlx)->delta_error + (2 * (*mlx)->dx);
		(*mlx)->y0++;
	}
}

void plot_any_line(t_mlx **mlx)
{
	if(ft_abs((*mlx)->y1 - (*mlx)->y0) < ft_abs((*mlx)->x1 - (*mlx)->x0))
	{
		if((*mlx)->x0 > (*mlx)->x1)
		{
			ft_swap(&(*mlx)->x0, &(*mlx)->x1);
			ft_swap(&(*mlx)->y0, &(*mlx)->y1);
			plot_low_line(mlx);
		}
		else
			plot_low_line(mlx);
	}
	else
	{
		if((*mlx)->y0 > (*mlx)->y1)
		{
			ft_swap(&(*mlx)->x0, &(*mlx)->x1);
			ft_swap(&(*mlx)->y0, &(*mlx)->y1);
			plot_high_line(mlx);
		}
		else
			plot_high_line(mlx);
	}
}

void menu(t_mlx **mlx)
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

	mlx_string_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, 10, 10, 0x00d4ff, str1);
	mlx_string_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, 10, 30, 0x00d4ff, str2);
	mlx_string_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, 10, 50, 0x00d4ff, str3);
	mlx_string_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, 10, 70, 0x00d4ff, str4);
	mlx_string_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, 10, 90, 0x00d4ff, str5);
}

/*
** ft_hue generates different colors based on the height of the square.
** y and color are multiplied by 95 and 9, but they can be multiplied by some
** other values to get different range of colors.
*/

int ft_hue(int y, int color)
{
	int num1;
	int num2;
	int final_color;

	color = 5 * color;
	final_color =color + y;
	return(ft_abs(final_color));
}
/*
void draw_square(t_mlx **mlx, int x, int y, int size)
{
	int x1;
	int y1;
	int temp_x;
	int temp_y;
	size_t hue;

	x1 = size + x;
	y1 = size + y;
	temp_x = x;
	temp_y = y;
	hue = (*mlx)->color;
	mlx_clear_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
	menu(mlx);
	while(x < x1)	
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x++, y, hue);
	while(y++ < y1)	
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x, y, ft_hue(y, hue));
	while(x > temp_x)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x--, y, hue);
	while(y-- > temp_y)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x, y, ft_hue(y, hue));
}
*/
/*
void draw_square(t_mlx **mlx, int x, int y, int size)
{
	size_t hue;

	(*mlx)->x0 = x;
	(*mlx)->y0 = y;
	(*mlx)->x1 = size + x;
	(*mlx)->y1 = y;
	hue = (*mlx)->color;
	mlx_clear_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
	menu(mlx);

	plot_any_line(mlx);
	(*mlx)->y1 = y + size;

	plot_any_line(mlx);
	(*mlx)->x0 = (*mlx)->x1 - size;

	plot_any_line(mlx);
	(*mlx)->x1 = (*mlx)->x1 - size;
	(*mlx)->x0 = (*mlx)->x0 - size;
	(*mlx)->y1 = (*mlx)->y1 - size;
	plot_any_line(mlx);
}
*/
void draw_square(t_mlx **mlx, int x, int y, int size)
{
	size_t hue;

	(*mlx)->x0 = x;
	(*mlx)->y0 = y;
	(*mlx)->x1 = size + x;
	(*mlx)->y1 = y;
	hue = (*mlx)->color;
	mlx_clear_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
	menu(mlx);
	
//Added the angle below:
//	(*mlx)->y0 = (*mlx)->y0 * 0.5;
//Added the angle above

	plot_any_line(mlx);
	(*mlx)->y1 = y + size;

//Added the angle below:
//	(*mlx)->x0 = (*mlx)->x0 * 0.25;
//Added the angle above

	plot_any_line(mlx);
	(*mlx)->x0 = (*mlx)->x1 - size;

//Added the angle below:
//	(*mlx)->y1 = (*mlx)->y1 * 0.5;
//Added the angle above

	plot_any_line(mlx);
	(*mlx)->x1 = (*mlx)->x1 - size;
	(*mlx)->x0 = (*mlx)->x0 - size;
	(*mlx)->y1 = (*mlx)->y1 - size;

//Added the angle below:
//	(*mlx)->x1 = (*mlx)->x1 * 0.25;
//Added the angle above
	plot_any_line(mlx);
}

/*
void diagonal_line(t_mlx **mlx, int x0, int y0, int size)
{
	int  x1;
	int  y1;
	size_t hue;
	
	size = size / 2;
	x1 = x0 + size;
	y1 = y0 + size;
	hue = (*mlx)->color;

	while(x0 <= x1 && y0 <= y1)
	{
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x0++, y0, ft_hue(y0, hue));
		y0--;
	}
}
*/

void diagonal_line(t_mlx **mlx, int x0, int y0, int size)
{
	size_t hue;

	size = size / 2;
	(*mlx)->x0 = x0;
	(*mlx)->y0 = y0;
	(*mlx)->x1 = x0 + size;
	(*mlx)->y1 = y0 + size;
	hue = (*mlx)->color;

	plot_any_line(mlx);
}

void draw_cube(t_mlx **mlx, int x, int y, int size)
{
	int size_x;
	int size_y;
	size_t hue;

	size_x = size + x;
	size_y = size + y;
//	temp_x = x;
//	temp_y = y;
	hue = (*mlx)->color;
	mlx_clear_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
	menu(mlx);
	draw_square(mlx, x + (size/2), y + (size/2), size); //uncomment this after
	diagonal_line(mlx, x, y, size);
	draw_square(mlx, x, y, size);
	diagonal_line(mlx, x + size, y, size);
	diagonal_line(mlx, x, y + size, size);
	diagonal_line(mlx, x + size, y + size, size);
//	while(x < size_x)
//		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x++, y, hue);
//	diagonal_line(mlx, x, y, size);
//	while(y++ < size_y)
//		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x, y, ft_hue(y, hue));
//	diagonal_line(mlx, x, y, size);
//	while(x > temp_x)
//		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x--, y, hue);
//	diagonal_line(mlx, x, y, size);
//	while(y-- > temp_y)
//		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x, y, ft_hue(y, hue));
}


void draw_horizontal_line(t_mlx **mlx, int x, int y, int size)
{
	size = size + x;
	while(x < size)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x++, y, 0xffff00);
}

void shift_program(t_mlx **mlx, int key)
{
	if(key == UP_K)
		(*mlx)->y = (*mlx)->y - 5;
	else if(key == DOWN_K)
		(*mlx)->y = (*mlx)->y + 5;
	else if(key == RIGHT_K)
		(*mlx)->x = (*mlx)->x + 5;
	else if(key == LEFT_K)
		(*mlx)->x = (*mlx)->x - 5;
//	top_horizontal(mlx);
//	right_vertical(mlx);
//	bottom_horizontal(mlx);
//	left_vertical(mlx);
//	draw_square(mlx, (*mlx)->x, (*mlx)->y, (*mlx)->size);
//	draw_cube(mlx, (*mlx)->x, (*mlx)->y, (*mlx)->size);
	ft_diamond(mlx);
}

void zoom_program(t_mlx **mlx, int key)
{
	int size;

	size = (*mlx)->size;
	if(key == ZOOM_IN_Q)
//		size = size + 30;
		size = size + 1;
	else if(key == ZOOM_OUT_A)
//		size = size - 30;
		size = size - 1;
// Centeralizes map

	if(key == ZOOM_IN_Q)
	{
		(*mlx)->x = (*mlx)->x - 0.5;
		(*mlx)->y = (*mlx)->y - 0.5;
	}
	else if(key == ZOOM_OUT_A)
	{
		(*mlx)->x = (*mlx)->x + 0.5;
		(*mlx)->y = (*mlx)->y + 0.5;
	}

	(*mlx)->size = size;
//	draw_square(mlx, (*mlx)->x, (*mlx)->y, size);
	ft_diamond(mlx);
//	draw_cube(mlx, (*mlx)->x, (*mlx)->y, size);
}
void random_color(t_mlx **mlx)
{
	size_t random_seed;

//	random_seed = 0xff;
	random_seed = (*mlx)->y;
	random_seed = rand();

	(*mlx)->color = rand() % random_seed;
//	draw_square(mlx, (*mlx)->x, (*mlx)->y, (*mlx)->size);
	draw_cube(mlx, (*mlx)->x, (*mlx)->y, (*mlx)->size);
}

void get_struct_values(t_mlx **mlx)
{
	(*mlx)->x = P_WIDTH / 2;
	(*mlx)->y = P_HEIGHT / 2;
	(*mlx)->size = 100;
	(*mlx)->color = 0x7FFFD4;
	(*mlx)->angle_y = 0.5;
	(*mlx)->angle_z = 0.25;
	(*mlx)->ro_x = 0;
	(*mlx)->ro_y = 0;
//	(*mlx)->color = 0x00ffff;
}

void reset_program(t_mlx **mlx, int key)
{
	(*mlx)->x = P_WIDTH / 2;
	(*mlx)->y = P_HEIGHT / 2;
	(*mlx)->size = 30;
	(*mlx)->color = 0x7FFFD4;
//	draw_square(mlx, (*mlx)->x, (*mlx)->y, (*mlx)->size);
	draw_cube(mlx, (*mlx)->x, (*mlx)->y, (*mlx)->size);
}

int program_keys(int key, t_mlx **mlx)
{
	if(key == ESCAPE_ESC)
		exit(0);
	else if(key == UP_K || key == DOWN_K || key == LEFT_K || key == RIGHT_K)
		shift_program(mlx, key);
	else if(key == ZOOM_IN_Q || key == ZOOM_OUT_A)
		zoom_program(mlx, key);
	else if(key == RESET_PROGRAM_E)
		reset_program(mlx, RESET_PROGRAM_E);
	else if(key == RANDOM_COLOR_R)
		random_color(mlx);
	return(0);

}

/*
void horizontal_down(t_mlx **mlx)
{
	(*mlx)->x0 = (*mlx)->x;
	(*mlx)->y0 = (*mlx)->y;

	(*mlx)->x1 = (*mlx)->x0 + 100;
	(*mlx)->y1 = (*mlx)->y0;
//	(*mlx)->y1 = (*mlx)->y1 + (*mlx)->y1 * 0.5;
	plot_any_line(mlx);
}



void right_top_diagonal(t_mlx **mlx)
{
	(*mlx)->x0 = (*mlx)->x;
	(*mlx)->y0 = (*mlx)->y;
	
	(*mlx)->y1 = (*mlx)->y0;
	(*mlx)->x1 = (*mlx)->x0 + 100;
	(*mlx)->y1 = (*mlx)->y0;
//	(*mlx)->y1 = (*mlx)->y1 + (*mlx)->y1 * 0.28;
	plot_any_line(mlx);
}

void right_bottom_diagonal(t_mlx **mlx)
{	
	(*mlx)->y1 = (*mlx)->y1 + 100;
//	(*mlx)->x1 = (*mlx)->x1 - (*mlx)->x1 * 0.156;
	plot_any_line(mlx);	
}

void left_top_diagonal(t_mlx **mlx)
{

 	(*mlx)->x0 = (*mlx)->x;
 	(*mlx)->y0 = (*mlx)->y;
	
	(*mlx)->x1 = (*mlx)->x0 - 100;
	(*mlx)->y1 = (*mlx)->y0;
//	(*mlx)->y1 = (*mlx)->y1 + (*mlx)->y1 * 0.28;
	plot_any_line(mlx);
}

void left_bottom_diagonal(t_mlx **mlx)
{
	(*mlx)->y1 = (*mlx)->y1 + 100;
//	(*mlx)->x1 = (*mlx)->x1 + (*mlx)->x1 * 0.156;
	plot_any_line(mlx);
}
*/

/*
void after_rotation(t_mlx **mlx)
{
	t_mlx temp;

	radian = 0.785;
	temp.x1 = ((*mlx)->x1 * cos(radian)) - ((*mlx)->y1 * sin(radian));
	temp.y1 = ((*mlx)->x1 * sin(radian)) + ((*mlx)->y1 * cos(radian));

	(*mlx)->x1 = temp.x1;
	(*mlx)->y1 = temp.y1;
}
*/
/*
void calculate_rotation_matrix_xy(t_mlx **mlx)
{
	(*mlx)->ro_x = (*mlx)->x1 - (*mlx)->x0;
	(*mlx)->ro_y = (*mlx)->y1 - (*mlx)->y0;
}
double degrees_to_radian(double degrees)
{
	double radian;

	radian = degrees * (M_PI/180);
	return(radian);
}

void apply_rotation(t_mlx **mlx, double degrees)
{
	t_mlx temp;
	double radian;
	
	radian = degrees_to_radian(degrees);
	printf("radians:|%f|\n", radian);
	calculate_rotation_matrix_xy(mlx);	
	temp.x1 = ((*mlx)->ro_x * cos(radian)) - ((*mlx)->ro_y * sin(radian));
	temp.y1 = ((*mlx)->ro_x * sin(radian)) + ((*mlx)->ro_y * cos(radian));
	
//	(*mlx)->x1 = (*mlx)->x1 + temp.x1;
//	(*mlx)->y1 = (*mlx)->y1 + temp.y1;
	(*mlx)->x0 = (*mlx)->x0 + temp.x1;
	(*mlx)->y0 = (*mlx)->y0 + temp.y1;
}
*/
/*
void after_rotation(t_mlx **mlx, double degrees)
{
	t_mlx temp;
	double radian;

//	temp.x0 = (*mlx)->x0;
//	temp.x1 = (*mlx)->x1;
//	temp.y0 = (*mlx)->y0;
//	temp.y1 = (*mlx)->y1;
//	temp.x = (*mlx)->x;
//	temp.y = (*mlx)->y;
	

	temp.x = (*mlx)->x1 - (*mlx)->x0;
	temp.y = (*mlx)->y1 - (*mlx)->y0;

}
*/
/*
void right_top_diagonal(t_mlx **mlx)
{
	(*mlx)->x0 = (*mlx)->x;
	(*mlx)->y0 = (*mlx)->y;

	(*mlx)->y1 = (*mlx)->y0;
	(*mlx)->x1 = (*mlx)->x0 + 50;

	(*mlx)->y1 = (*mlx)->y1 + (*mlx)->y1 * 0.28;
	plot_any_line(mlx);
}
*/
/*
void right_top_diagonal(t_mlx **mlx)
{
	(*mlx)->size = 100;
	double degrees_angle;
	
	degrees_angle = 45;
	(*mlx)->x0 = (*mlx)->x;
	(*mlx)->y0 = (*mlx)->y;

	(*mlx)->y1 = (*mlx)->y0;
	(*mlx)->x1 = (*mlx)->x0 + (*mlx)->size;

	apply_rotation(mlx, degrees_angle);
	plot_any_line(mlx);
}
*/
/*
void right_bottom_diagonal(t_mlx **mlx)
{	
	(*mlx)->x0 = (*mlx)->x;

	(*mlx)->y0 = (*mlx)->y0 + 50;
	plot_any_line(mlx);	
}
*/
/*
void adjust_length(t_mlx **mlx)
{
	t_mlx temp;

	temp.x1 = (*mlx)->x1;
	temp.x1 = (*mlx)->x1 + (*mlx)->size;
	
}

void right_bottom_diagonal(t_mlx **mlx)
{

}

void left_top_diagonal(t_mlx **mlx)
{

 	(*mlx)->x0 = (*mlx)->x;
 	(*mlx)->y0 = (*mlx)->y;
	
	(*mlx)->y1 = (*mlx)->y0;
	(*mlx)->x1 = (*mlx)->x0 - 50;
	(*mlx)->y1 = (*mlx)->y1 + (*mlx)->y1 * 0.28;
	plot_any_line(mlx);
}
*/
/*
void left_bottom_diagonal(t_mlx **mlx)
{
	printf("1:\n");
	printf("x0:|%d|, x1:|%d|, y0:|%d|, y1:|%d|\n", (*mlx)->x0, (*mlx)->x1, (*mlx)->y0, (*mlx)->y1);

	(*mlx)->x0 = (*mlx)->x;
	(*mlx)->y0 = (*mlx)->y0 + 50;
//	if((*mlx)->x0 == (*mlx)->x1)
//		(*mlx)->x0 = (*mlx)->x0 + 50;
//	(*mlx)->x1 = (*mlx)->x;
//	(*mlx)->y1 = (*mlx)->y1 + 50;
//	if()
	printf("2:\n");
	printf("x0:|%d|, x1:|%d|, y0:|%d|, y1:|%d|\n\n", (*mlx)->x0, (*mlx)->x1, (*mlx)->y0, (*mlx)->y1);

	plot_any_line(mlx);
}
*/
/*
void right_top_diagonal(t_mlx **mlx)
{
	(*mlx)->x0 = (*mlx)->x;
	(*mlx)->y0 = (*mlx)->y;

	
}
*/
/*
void vertical_left(t_mlx **mlx)
{
	t_mlx temp;
	(*mlx)->y1 = (*mlx)->y0;
	(*mlx)->y1 = (*mlx)->y1 + 100;
	printf("(*mlx)->y0:|%d|\n", (*mlx)->y0);
	printf("(*mlx)->y1:|%d|\n", (*mlx)->y1);
	printf("(*mlx)->x0:|%d|\n", (*mlx)->x0);
	printf("(*mlx)->x1:|%d|\n\n", (*mlx)->x1);
	(*mlx)->x1 = (*mlx)->x0;
//	(*mlx)->x1 = (*mlx)->x1 - (*mlx)->x1 * 0.5;// Alternate
//	(*mlx)->x1 = (*mlx)->x1 * 0.25;
	(*mlx)->x1 = (*mlx)->x1 - (*mlx)->x1 * 0.25;
	printf("(*mlx)->x0:|%d|\n", (*mlx)->x0);
	printf("(*mlx)->x1:|%d|\n\n", (*mlx)->x1);
	temp.x1 = (*mlx)->x1;
	temp.y1 = (*mlx)->y1;
	plot_any_line(mlx);

	(*mlx)->x0 = temp.x1;
	(*mlx)->x1 = temp.x1;
	(*mlx)->y1 = temp.y1;
	(*mlx)->y0 = temp.y1;

	printf("vertical_left (*mlx)->x0:|%d|\n", (*mlx)->x0);
	printf("vertical_left (*mlx)->x1:|%d|\n", (*mlx)->x1);
	printf("vertical_left (*mlx)->y0:|%d|\n", (*mlx)->y0);
	printf("vertical_left (*mlx)->y1:|%d|\n", (*mlx)->y1);
}
*/
/*
void horizontal_up(t_mlx **mlx)
{
//	(*mlx)->x0 = (*mlx)->x;
//	(*mlx)->y0 = (*mlx)->y;

	(*mlx)->x1 = (*mlx)->x1 - 100;
//	(*mlx)->y1 = (*mlx)->y1 - (*mlx)->y1 * 0.25;
	(*mlx)->y1 = (*mlx)->y0;
//	(*mlx)->y1 = (*mlx)->y1 - (*mlx)->y1 * 0.5;


//	ft_swap(&(*mlx)->x1, &(*mlx)->x0);
//	(*mlx)->y1 = (*mlx)->y1 * 0.5;
	plot_any_line(mlx);
}
*/
/*
void vertical_right(t_mlx **mlx)
{
	(*mlx)->x0 = (*mlx)->x;
	(*mlx)->y0 = (*mlx)->y;

	(*mlx)->y1 = (*mlx)->y0 + 100;
	(*mlx)->x1 = (*mlx)->x0;
//	(*mlx)->x1 = (*mlx)->x1 - (*mlx)->x1 * 0.25;
//	(*mlx)->x1 = (*mlx)->x1 * 0.25;
	plot_any_line(mlx);
}
*/
/*
void ft_diamond(t_mlx **mlx)
{
	mlx_clear_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
	menu(mlx);
	right_top_diagonal(mlx);
	right_bottom_diagonal(mlx);
	left_top_diagonal(mlx);
	left_bottom_diagonal(mlx);
}
*/
/*
void draw_straight_line(t_mlx ** mlx)
{
	(*mlx)->x0 = 50;
	(*mlx)->x1 = 100;
	(*mlx)->y0 = 50;
	(*mlx)->y1 = 50;

	plot_any_line(mlx);
}
*/

double degree_to_radian(double degrees)
{
	double radian;

	radian = degrees * (M_PI/180);
	return(radian);
}

void rotation_matrix(t_mlx **mlx, int *x, int *y, double degree_angle)
{
	t_mlx temp;
	double radian;

	radian = degree_to_radian(degree_angle);
	temp.x = (*x * cos(radian)) - (*y * sin(radian));
	temp.y = (*x * sin(radian)) + (*y * cos(radian));

	*x = temp.x;
	*y = temp.y;

}

void apply_rotation(t_mlx **mlx, double degree_angle)
{
	rotation_matrix(mlx, &(*mlx)->x0, &(*mlx)->y0, degree_angle);
	rotation_matrix(mlx, &(*mlx)->x1, &(*mlx)->y1, degree_angle);
}

void find_max_xy(t_mlx **mlx, t_mlx *temp)
{
	if(temp->x0 > temp->x1)
	{
		(*mlx)->x0 = temp->x0;
		(*mlx)->x1 = temp->x0;
	}
	else
	{
		(*mlx)->x0 = temp->x1;
		(*mlx)->x1 = temp->x1;
	}
	if(temp->y0 > temp->y1)
	{
		(*mlx)->y0 = temp->y0;
		(*mlx)->y1 = temp->y0;
	}
	else
	{
		(*mlx)->y0 = temp->y1;
		(*mlx)->y1 = temp->y1;
	}
}

void find_min_xy(t_mlx **mlx, t_mlx *temp)
{
	if(temp->x0 < temp->x1)
	{
		(*mlx)->x0 = temp->x0;
		(*mlx)->x1 = temp->x0;
	}
	else
	{
		(*mlx)->x0 = temp->x1;
		(*mlx)->x1 = temp->x1;
	}
	if(temp->y0 < temp->y1)
	{
		(*mlx)->y0 = temp->y0;
		(*mlx)->y1 = temp->y0;
	}
	else
	{
		(*mlx)->y0 = temp->y1;
		(*mlx)->y1 = temp->y1;
	}
}
void find_min_x(t_mlx **mlx, t_mlx *temp)
{
	if(temp->x0 < temp->x1)
	{
		(*mlx)->x0 = temp->x0;
		(*mlx)->x1 = temp->x0;
	}
	else if(temp->x1 < temp->x0)
	{
		(*mlx)->x0 = temp->x1;
		(*mlx)->x1 = temp->x1;
	}
}

void find_max_y(t_mlx **mlx, t_mlx *temp)
{
	if(temp->y0 > temp->y1)
	{
		(*mlx)->y0 = temp->y0;
		(*mlx)->y1 = temp->y0;
	}
	else if(temp->y1 > temp->y0)
	{
		(*mlx)->y0 = temp->y1;
		(*mlx)->y1 = temp->y1;
	}
}

void mlx_xy_to_temp_xy(t_mlx **mlx, t_mlx *temp)
{
	temp->x0 = (*mlx)->x0;
	temp->x1 = (*mlx)->x1;
	temp->y0 = (*mlx)->y0;
	temp->y1 = (*mlx)->y1;
}

/*
void top_horizontal(t_mlx **mlx)
{
	t_mlx temp;
	
	mlx_clear_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);

	(*mlx)->x0 = (*mlx)->x;
	(*mlx)->x1 = (*mlx)->x;
	(*mlx)->y0 = (*mlx)->y;
	(*mlx)->y1 = (*mlx)->y;

	(*mlx)->x1 = (*mlx)->x1 + (*mlx)->size;
	
//	temp.x0 = (*mlx)->x0;
//	temp.x1 = (*mlx)->x1;
//	temp.y0 = (*mlx)->y0;
//	temp.y1 = (*mlx)->y1;
	
	mlx_xy_to_temp_xy(mlx, &temp);

	apply_rotation(mlx);
	plot_any_line(mlx);

	find_max_xy(mlx, &temp);
}

void right_vertical(t_mlx **mlx)
{
	t_mlx temp;
	mlx_clear_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
	(*mlx)->y1 = (*mlx)->y1 + (*mlx)->size;
	
//	temp.x0 = (*mlx)->x0;
//	temp.x1 = (*mlx)->x1;
//	temp.y0 = (*mlx)->y0;
//	temp.y1 = (*mlx)->y1;
	
	mlx_xy_to_temp_xy(mlx, &temp);

	apply_rotation(mlx);
	plot_any_line(mlx);
	find_max_xy(mlx, &temp);
}

void bottom_horizontal(t_mlx **mlx)
{
	t_mlx temp;
	mlx_clear_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
	(*mlx)->x1 = (*mlx)->x1 - (*mlx)->size;

	mlx_xy_to_temp_xy(mlx, &temp);
	apply_rotation(mlx);
	plot_any_line(mlx);
	find_max_xy(mlx, &temp);
}

void left_vertical(t_mlx **mlx)
{
	t_mlx temp;
	mlx_clear_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
	(*mlx)->x0 = (*mlx)->x0 - (*mlx)->size;
	(*mlx)->x1 = (*mlx)->x1 - (*mlx)->size;
	(*mlx)->y1 = (*mlx)->y1 - (*mlx)->size;
	
	mlx_xy_to_temp_xy(mlx, &temp);
	apply_rotation(mlx);
	plot_any_line(mlx);
	find_max_xy(mlx, &temp);


}
*/

void subtract_x0y0_from_x1y1(t_mlx **mlx)
{
	(*mlx)->x1 = (*mlx)->x1 - (*mlx)->x0;
	(*mlx)->y1 = (*mlx)->y1 - (*mlx)->y0;
}

void 	add_rotated_x1y1_to_x0y0(t_mlx **mlx)
{
	(*mlx)->x1 = (*mlx)->x1 + (*mlx)->x0;
	(*mlx)->y1 = (*mlx)->y1 + (*mlx)->y0;
}
/*
// Works
void top_horizontal(t_mlx **mlx)
{
	t_mlx temp;
	double degree_angle;

	degree_angle = 30;

	(*mlx)->x0 = (*mlx)->x;
	(*mlx)->x1 = (*mlx)->x;
	(*mlx)->y0 = (*mlx)->y;
	(*mlx)->y1 = (*mlx)->y;

	(*mlx)->x1 = (*mlx)->x1 + (*mlx)->size;
	mlx_xy_to_temp_xy(mlx, &temp);
	subtract_x0y0_from_x1y1(mlx);

	rotation_matrix(mlx, &(*mlx)->x1, &(*mlx)->y1, degree_angle);
	add_rotated_x1y1_to_x0y0(mlx);
	plot_any_line(mlx);
}


void right_vertical(t_mlx **mlx)
{
	t_mlx temp;
	double degree_angle;

	degree_angle = -30;

	(*mlx)->x1 = (*mlx)->x1 + (*mlx)->size;
	subtract_x0y0_from_x1y1(mlx);

	rotation_matrix(mlx, &(*mlx)->x1, &(*mlx)->y1, degree_angle);

	add_rotated_x1y1_to_x0y0(mlx);
	plot_any_line(mlx);
}

void bottom_horizontal(t_mlx **mlx)
{
	t_mlx temp;
	double degree_angle;

	degree_angle = -150;
	(*mlx)->x1 = (*mlx)->x1 + (*mlx)->size;
	subtract_x0y0_from_x1y1(mlx);

	rotation_matrix(mlx, &(*mlx)->x1, &(*mlx)->y1, degree_angle);
	add_rotated_x1y1_to_x0y0(mlx);

	mlx_xy_to_temp_xy(mlx, &temp);
	plot_any_line(mlx);
	find_min_xy(mlx, &temp);
}

void left_vertical(t_mlx **mlx)
{
	(*mlx)->x1 = (*mlx)->x;
	(*mlx)->y1 = (*mlx)->y;

	plot_any_line(mlx);
}
*/


void copy_mlx_xy_to_temp_xy(t_mlx **mlx, t_mlx *temp)
{
	temp->x0 = (*mlx)->x0;
	temp->x1 = (*mlx)->x1;
	temp->y0 = (*mlx)->y0;
	temp->y1 = (*mlx)->y1;
}

void copy_temp_xy_to_mlx_xy(t_mlx **mlx, t_mlx *temp)
{
	(*mlx)->x0 = temp->x0;
	(*mlx)->x1 = temp->x1;
	(*mlx)->y0 = temp->y0;
	(*mlx)->y1 = temp->y1;
}


void top_horizontal(t_mlx **mlx)
{
//	t_mlx temp;
	double degree_angle;

	degree_angle = 30;

	(*mlx)->x0 = (*mlx)->x;
	(*mlx)->x1 = (*mlx)->x;
	(*mlx)->y0 = (*mlx)->y;
	(*mlx)->y1 = (*mlx)->y;

	(*mlx)->x1 = (*mlx)->x1 + (*mlx)->size;
//	mlx_xy_to_temp_xy(mlx, &temp);
	subtract_x0y0_from_x1y1(mlx);

	rotation_matrix(mlx, &(*mlx)->x1, &(*mlx)->y1, degree_angle);
	add_rotated_x1y1_to_x0y0(mlx);
	plot_any_line(mlx);
}

void left_vertical(t_mlx **mlx)
{
	t_mlx temp;
	double degree_angle;

	degree_angle = 150; // angle of -210 also works
//degree_angle = -210;  // we can do x1 + size
//	degree_angle = -60; // we can do y1 + size

	(*mlx)->x0 = (*mlx)->x;
	(*mlx)->x1 = (*mlx)->x;
	(*mlx)->y0 = (*mlx)->y;
	(*mlx)->y1 = (*mlx)->y;

	(*mlx)->x1 = (*mlx)->x1 + (*mlx)->size;
//	(*mlx)->y1 = (*mlx)->y1 + (*mlx)->size;
	subtract_x0y0_from_x1y1(mlx);
	rotation_matrix(mlx, &(*mlx)->x1, &(*mlx)->y1, degree_angle);
	add_rotated_x1y1_to_x0y0(mlx);
	copy_mlx_xy_to_temp_xy(mlx, &temp);
	plot_any_line(mlx);
	find_min_x(mlx, &temp);
	find_max_y(mlx, &temp);
}

void bottom_horizontal(t_mlx **mlx)
{
	double degree_angle;
	
	degree_angle = 30;

	(*mlx)->x1 = (*mlx)->x1 + (*mlx)->size;
	subtract_x0y0_from_x1y1(mlx);
	rotation_matrix(mlx, &(*mlx)->x1, &(*mlx)->y1, degree_angle);
	add_rotated_x1y1_to_x0y0(mlx);
	plot_any_line(mlx);
}

void right_vertical(t_mlx **mlx)
{
	double degree_angle;
	
	degree_angle = -30;
	(*mlx)->x1 = (*mlx)->x1 + (*mlx)->size;
	subtract_x0y0_from_x1y1(mlx);
	rotation_matrix(mlx, &(*mlx)->x1, &(*mlx)->y1, degree_angle);
	add_rotated_x1y1_to_x0y0(mlx);
	plot_any_line(mlx);
}

void ft_diamond(t_mlx **mlx)
{
	mlx_clear_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
	(*mlx)->color = 0xff0000; //Red Color
	top_horizontal(mlx);

	(*mlx)->color = 0x00ff00; //Green Color
	left_vertical(mlx);

//	(*mlx)->color = 0x0000ff; //Blue Color
//	bottom_horizontal(mlx);

//	(*mlx)->color = 0xffff00; //Yellow Color
//	right_vertical(mlx);
}

int main(void)
{
	t_mlx *mlx;
	int x;
	int y;
	int size;
	
	int x2 = 655;
	int y2 = 345;
	int size2 = 30;

	int x3;
	int y3;
	int size3;

	mlx = malloc(sizeof(t_mlx)); //Builds the connection between computer and display.

	get_struct_values(&mlx);
	x = mlx->x;
	y = mlx->y;
	size = mlx->size;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1280, 720, "test screen");
//	draw_square(&mlx, x, y, size);
//	draw_cube(&mlx, x, y, size);
//	printf("1. horizontal_down");
//	horizontal_down(&mlx);
//	printf("2. vertical left\n");
//	vertical_left(&mlx);
//	printf("3. horizontal up\n");
//	horizontal_up(&mlx);
//	printf("4. vertical_right\n");
//	vertical_right(&mlx);

//	printf("1. right_top_diagonal\n");
//	right_top_diagonal(&mlx);
//	printf("2. right_bottom_diagonal\n");
//	right_bottom_diagonal(&mlx);
//	printf("3. left_top_diagonal\n");
//	left_top_diagonal(&mlx);
//	printf("4. left_bottom_diagonal\n");
//	left_bottom_diagonal(&mlx);

	ft_diamond(&mlx);
//	mlx->x = mlx->x +  85; //+ &mlx->size;
//	mlx->y = mlx->y +  49; //+ &mlx->size;	
	mlx->x = mlx->x + (mlx->size *  0.87);
	mlx->y = mlx->y + (mlx->size *  0.49) ;
	ft_diamond(&mlx);

	mlx->x = mlx->x + (mlx->size *  0.87);
	mlx->y = mlx->y + (mlx->size *  0.49) ;
	ft_diamond(&mlx);
//	mlx->x = mlx->x + 85;
//	mlx->y = mlx->y + 50;
/*	
	ft_diamond(&mlx);
	mlx->x = mlx->x - (85 + 85 + 85);
	mlx->y = mlx->y - (50);
	ft_diamond(&mlx);
	mlx->x = mlx->x + 85;
	mlx->y = mlx->y + 50;
	ft_diamond(&mlx);
	mlx->x = mlx->x + 85;
	mlx->y = mlx->y + 50;
	ft_diamond(&mlx);
*/
/*	
	printf("top_horizontal:\n");
	top_horizontal(&mlx);
	printf("right_vertical:\n");
	right_vertical(&mlx);
	printf("bottom_horizontal:\n");
	bottom_horizontal(&mlx);
	printf("left_vertical:\n");
	left_vertical(&mlx);
*/
/*	
	printf("top_horizontal:\n");
	top_horizontal(&mlx);
	printf("left_vertical:\n");
	left_vertical(&mlx);
	printf("bottom_horizontal:\n");
	bottom_horizontal(&mlx);
	printf("right_vertical:\n");
	right_vertical(&mlx);
*/
	mlx_hook(mlx->win_ptr, 2, 5, program_keys, &mlx);
	mlx_loop(mlx->mlx_ptr); //Required to end the program


}

