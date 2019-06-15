/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:20:11 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/14 21:27:33 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static void random_color(void *param)
{
	int red;
	int green;
	int blue;

	red = (rand() % 127);
	green = (rand() % 127);
	blue = (rand() % 127);
}

int deal_keys(int key, void *param)
{
	if(key == 0)
		ft_putchar('A');
	if(key == 8)
		random_color(param);
	if(key == 53)
		exit(0);
	return(0);
}

/*
int draw_function(void *param)
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;

	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "This is mlx 42 - by Mo");
	img_ptr = mlx_new_image(mlx_ptr, 500, 500);
//	mlx_get_data_addr(img_ptr, 127, 200, 0);
//	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_string_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF, "(_______)");
	return(0);
}
*/

/*
int draw_function(void * param)
{
	void *mlx_ptr;
	void *win_ptr;
//	void *img_ptr;

//	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr, 400, 400, "Mlx42 function - by Mo");
	mlx_string_put(mlx_ptr, win_ptr, 200, 200, 0xFFFFFF, "(____)");
}
*/
/*
void draw_function(void *param)
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 400, 400, "MLX42-by Mo");
	mlx_string_put(mlx_ptr, win_ptr, 200, 200, 0xFFFFFF, "(_____)");
}
*/

int main(void)
{
	t_mlx *fdf;

	fdf = (t_mlx *)malloc(sizeof(t_mlx));

	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 400, 400, "MLX-42-by Mo");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 200, 200, 0xFFFFFF, "(______)");
	mlx_loop(fdf->mlx_ptr);
}

/*
int main(void)
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 400, 400, "This is mlx 42- by Mo");
//	mlx_hook(win_ptr, 2, 5, deal_keys, (void *)0);
//	mlx_loop_hook(mlx_ptr, draw_function, (void *)0);
	
	mlx_string_put(mlx_ptr, win_ptr, 200, 200, 0xFFFFFF, "(_____)"); // Use it
//	draw_function;
	mlx_loop(mlx_ptr);
}
*/
/*
int main(void)
{
	void *mlx_ptr;
	void *win_ptr;
	int i;
	int key;
	void *param;
	void *img_ptr;
	int range[] = {128, 139, 205, 238, 255, 25600, 26763, 34443, 35584, 35653};
	int change_color;

	change_color = 0;
	i = 0;
	mlx_ptr = mlx_init();
	img_ptr = mlx_new_image(mlx_ptr, 400, 400);
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "This is mlx 42- by Mo");
	while(i < 250)
		mlx_pixel_put(mlx_ptr, win_ptr, 250, i++, 0x696969);
	i = 0;
	while(i < 250)
		mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 270, i++);
//	mlx_string_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF, "    (_)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 250, range[0], "    (_)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 270, range[1], "   (___)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 290, range[2], "  (_____)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 310, range[3], " (_______)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 330, range[4], "(_________)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 350, range[5], "    | |  ");
	mlx_string_put(mlx_ptr, win_ptr, 250, 370, range[6], "    | |  ");
	mlx_string_put(mlx_ptr, win_ptr, 250, 390, range[7], "    | |  ");
	mlx_string_put(mlx_ptr, win_ptr, 250, 410, range[8], "    | |  ");
	mlx_string_put(mlx_ptr, win_ptr, 250, 430, range[9], "    |_|  ");
	i = 0;
//	mlx_string_put(mlx_ptr, win_ptr, 250, 430, 0xff0000, "    |_|  ");

//	mlx_key_hook(win_ptr, deal_key, (void *)0);
//	mlx_hook(win_ptr, 2, 5, deal_key, (void *)0); //Allows long key presses. Works
//	mlx_hook(win_ptr, 3, key_release, (int) x_mask, (void *)0);
	mlx_mouse_hook(win_ptr, deal_button, (void *)0);
	mlx_hook(win_ptr, 2, 5, deal_key, (void *)0);
//	mlx_hook(win_ptr, 2, 5, color_with_c, (void *)0);
//	mlx_string_put(mlx_ptr, win_ptr, 250, 430, range[deal_key], "    |_|  ");

	img_ptr = mlx_new_image(mlx_ptr, 150, 150); //Image manipulation
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 130, 130);

	mlx_loop(mlx_ptr); //Tells the system that we want to print something
}
*/
