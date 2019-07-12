/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:27:24 by mbutt             #+#    #+#             */
/*   Updated: 2019/07/12 15:04:41 by mbutt            ###   ########.fr       */
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
	char str1[100];
	char str2[100];
	char str3[100];
	char str4[100];
	char str5[100];

	ft_strcpy(str1, "Menu Controls");
	ft_strcpy(str2, "Shift: Arrow Keys: < ^ v >");
	ft_strcpy(str3, "Zoom in and out: Q A");
	ft_strcpy(str4, "Reset map: E");
	ft_strcpy(str5, "Random Colors: R");
	printf("%s\n", str2);
	mlx_string_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, 10, 10, 0x00d4ff, str1);
	mlx_string_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, 10, 30, 0x00d4ff, str2);
	mlx_string_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, 10, 50, 0x00d4ff, str3);
	mlx_string_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, 10, 70, 0x00d4ff, str4);
	mlx_string_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, 10, 90, 0x00d4ff, str5);

}
void draw_square(t_mlx **mlx, int x, int y, int size)
{
	int size_x;
	int size_y;
	int temp_x;
	int temp_y;

	size_x = size + x;
	size_y = size + y;
	temp_x = x;
	temp_y = y;
	mlx_clear_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
	menu(mlx);
	while(x < size_x)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x++, y, 0xff0000);
	while(y < size_y)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x, y++, 0xff0000);
	while(x > temp_x)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x--, y, 0xff0000);
	while(y > temp_y)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x, y--, 0xff0000);

}

void draw_horizontal_line(t_mlx **mlx, int x, int y, int size)
{
	size = size + x;
	while(x < size)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x++, y, 0xffff00);
}
/*
void zoom_program(t_mlx **mlx, int key)
{
	if(key == ZOOM_INT_Q)
		
}
*/

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
	draw_square(mlx, (*mlx)->x, (*mlx)->y, (*mlx)->size);
}

void zoom_program(t_mlx **mlx, int key)
{
	int x;
	int y;
	int size;

	x = (*mlx)->x;
	y = (*mlx)->y;
	size = (*mlx)->size;

	if(key == ZOOM_IN_Q)
		size = size / 0.95;
	else if(key == ZOOM_OUT_A)
		size = size * 0.95;

	(*mlx)->x = x;
	(*mlx)->y = y;
	(*mlx)->size = size;
	draw_square(mlx, x, y, size);
}

void get_struct_values(t_mlx **mlx)
{
	(*mlx)->x = 30;
	(*mlx)->y = 30;
	(*mlx)->size = 30;
}

void reset_program(t_mlx **mlx, int key)
{
	(*mlx)->x = 30;
	(*mlx)->y = 30;
	(*mlx)->size = 30;
	draw_square(mlx, (*mlx)->x, (*mlx)->y, (*mlx)->size);
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
	return(0);

}

int main(void)
{
	t_mlx *mlx;
	int x;
	int y;
	int size;

	mlx = malloc(sizeof(t_mlx)); /*Builds the connection between computer and display.*/

	get_struct_values(&mlx);
	x = mlx->x;
	y = mlx->y;
	size = mlx->size;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1280, 720, "test screen");
	
	draw_square(&mlx, x, y, size);
	draw_horizontal_line(&mlx, x, 10, size);
	mlx_hook(mlx->win_ptr, 2, 5, program_keys, &mlx);

	mlx_loop(mlx->mlx_ptr); /*Required to end the program*/
}
