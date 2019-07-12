/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:27:24 by mbutt             #+#    #+#             */
/*   Updated: 2019/07/12 11:08:05 by mbutt            ###   ########.fr       */
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

int main(void)
{
	t_mlx *mlx;
	int x;
	int y;
	int a;

	x = 20;
	y = 15;
//	a = 100;
	mlx = malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1280, 720, "test screen");
	
	draw_square(&mlx, x, y, 50);
	draw_horizontal_line(&mlx, x, 10, 50);

	mlx_loop(mlx->mlx_ptr);
}
