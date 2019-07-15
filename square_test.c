/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:27:24 by mbutt             #+#    #+#             */
/*   Updated: 2019/07/14 19:32:58 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
typedef struct 	s_mlx1
{
	void 		*mlx_ptr;
	void 		*win_ptr;
}				t_mlx1;
*/

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

int ft_abs(int num)
{
	if(num < 1)
		num = -1 * num;
	return(num);
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

void draw_square(t_mlx **mlx, int x, int y, int size)
{
	int size_x;
	int size_y;
	int temp_x;
	int temp_y;
	size_t hue;

	size_x = size + x;
	size_y = size + y;
	temp_x = x;
	temp_y = y;
	hue = (*mlx)->color;
	mlx_clear_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
	menu(mlx);
	while(x < size_x)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x++, y, hue);
	while(y++ < size_y)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x, y, ft_hue(y, hue));
	while(x > temp_x)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x--, y, hue);
	while(y-- > temp_y)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x, y, ft_hue(y, hue));
}

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

void draw_cube(t_mlx **mlx, int x, int y, int size)
{
	int size_x;
	int size_y;
	int temp_x;
	int temp_y;
	size_t hue;

	size_x = size + x;
	size_y = size + y;
	temp_x = x;
	temp_y = y;
	hue = (*mlx)->color;
	mlx_clear_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
	menu(mlx);
	draw_square(mlx, x + (size/2), y - (size/2), size);
	diagonal_line(mlx, x, y, size);
	while(x < size_x)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x++, y, hue);
	diagonal_line(mlx, x, y, size);
	while(y++ < size_y)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x, y, ft_hue(y, hue));
	diagonal_line(mlx, x, y, size);
	while(x > temp_x)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x--, y, hue);
	diagonal_line(mlx, x, y, size);
	while(y-- > temp_y)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x, y, ft_hue(y, hue));
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
//	draw_square(mlx, (*mlx)->x, (*mlx)->y, (*mlx)->size);
	draw_cube(mlx, (*mlx)->x, (*mlx)->y, (*mlx)->size);
}

void zoom_program(t_mlx **mlx, int key)
{
	int size;

	size = (*mlx)->size;
	if(key == ZOOM_IN_Q)
		size = size + 30;
	else if(key == ZOOM_OUT_A)
		size = size - 30;

	if(key == ZOOM_IN_Q)
	{
		(*mlx)->x = (*mlx)->x - 15;
		(*mlx)->y = (*mlx)->y - 15;
	}
	else if(key == ZOOM_OUT_A)
	{
		(*mlx)->x = (*mlx)->x + 15;
		(*mlx)->y = (*mlx)->y + 15;
	}
	(*mlx)->size = size;
//	draw_square(mlx, (*mlx)->x, (*mlx)->y, size);
	draw_cube(mlx, (*mlx)->x, (*mlx)->y, size);
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
	(*mlx)->size = 30;
	(*mlx)->color = 0x7FFFD4;
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
	draw_cube(&mlx, x, y, size);
	mlx_hook(mlx->win_ptr, 2, 5, program_keys, &mlx);
	mlx_loop(mlx->mlx_ptr); //Required to end the program
}

