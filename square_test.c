/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:27:24 by mbutt             #+#    #+#             */
/*   Updated: 2019/07/11 22:06:52 by mbutt            ###   ########.fr       */
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
	int temp_size;

//	x = x + size;
//	y = y + size;

	temp_size = y;
	size = size + x;
	while(x < size)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x++, y, 0xff0000);
	while(y < size)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x, y++, 0xff0000);
	while(x > temp_size)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x--, y, 0xff0000);
	while(y > temp_size)
		mlx_pixel_put((*mlx)->mlx_ptr, (*mlx)->win_ptr, x, y--, 0xff0000);
}

void draw_one_line(t_mlx **mlx, int x, int y, int size)
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
	int z;
//	void *mlx_ptr;
//	void *win_ptr;

	x = 100;
	y = 100;
	z = 100;
	mlx = malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1280, 720, "test screen");
	
	draw_square(&mlx, x, y, 200);
	draw_one_line(&mlx, x, y, 200);	
	while(z < 200)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, z++, 45, 0xffffff);
//	mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xff0000);
/*
	while(x < 200)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x++, 50, 0xff0000);
	while(y < 200)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y++, 0xff0000);
	while(x > 50)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x--, y, 0xff0000);
	while(y > 50)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y--, 0xff0000);
*/

	mlx_loop(mlx->mlx_ptr);
}
