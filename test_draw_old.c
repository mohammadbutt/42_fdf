/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:20:11 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/13 20:52:18 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
int main(void)
{
	ft_putstr("This is a test\n");
}
*/
int color_with_c(int key, void *param)
{
	static int i;

	i = 5;
	if(key == 8)
		return(i);
	return(0);
}

int deal_key(int key, void *param)
{
	if(key == 0)
		ft_putchar('A');
	if(key == 1)
		ft_putchar('S');
	if(key == 2)
		ft_putchar('D');
	if(key == 3)
		ft_putchar('F');
	if(key == 8)
	{
		color_with_c(key, param);
		return(8);
	}
	if(key == 53)
		exit(0);
//	if(key == 8)
//		mlx_get_color_value(mlx_ptr, 0x696969);
	return(0);
}


int deal_button(int key, void *param)
{
	if(key == 1)
		ft_putchar('1');
	if(key == 2)
		ft_putchar('2');
	if(key == 4)
		ft_putchar('4');
	if(key == 5)
		ft_putchar('5');
	return(0);
}

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
//	mlx_hook(win_ptr, 2, 5, deal_key, (void *)0); /*Allows long key presses. Works*/
//	mlx_hook(win_ptr, 3, key_release, (int) x_mask, (void *)0);
	mlx_mouse_hook(win_ptr, deal_button, (void *)0);
	mlx_hook(win_ptr, 2, 5, deal_key, (void *)0);
//	mlx_hook(win_ptr, 2, 5, color_with_c, (void *)0);
//	mlx_string_put(mlx_ptr, win_ptr, 250, 430, range[deal_key], "    |_|  ");

	img_ptr = mlx_new_image(mlx_ptr, 150, 150); /*Image manipulation*/
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 130, 130);

	mlx_loop(mlx_ptr); /*Tells the system that we want to print something*/
}

