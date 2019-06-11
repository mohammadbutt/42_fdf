/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:20:11 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/11 15:44:37 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
int main(void)
{
	ft_putstr("This is a test\n");
}
*/

int deal_key(int key, void *param)
{
	void *mlx_ptr;

	mlx_ptr = mlx_init();
	if(key == 0)
		ft_putchar('A');
	if(key == 1)
		ft_putchar('S');
	if(key == 2)
		ft_putchar('D');
	if(key == 3)
		ft_putchar('F');
	if(key == 53)
		exit(0);
	if(key == 8)
		mlx_get_color_value(mlx_ptr, 0x696969);
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

int key_press(int key, void *param)
{
	void *mlx_ptr;
	mlx_ptr = mlx_init();
	if(key == 0)
		ft_putchar('A');
	return(0);
}
int key_release(int key, void *param)
{
	void *mlx_ptr;
	mlx_ptr = mlx_init();
	if(key == 0)
		ft_putchar('A');
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

	i = 0;
	mlx_ptr = mlx_init();
	img_ptr = mlx_new_image(mlx_ptr, 400, 400);
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "This is mlx 42- by Mo");
	while(i < 250)
		mlx_pixel_put(mlx_ptr, win_ptr, 250, i++, 0x696969);
	i = 0;
	while(i < 250)
		mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 270, i++);
	mlx_string_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF, "    (_)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 270, 0xFFFFFF, "   (___)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 290, 0xFFFFFF, "  (_____)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 310, 0xFFFFFF, " (_______)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 330, 0xffffff, "(_________)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 350, 0xffffff, "    | |  ");
	mlx_string_put(mlx_ptr, win_ptr, 250, 370, 0xffffff, "    | |  ");
	mlx_string_put(mlx_ptr, win_ptr, 250, 390, 0xffffff, "    | |  ");
	mlx_string_put(mlx_ptr, win_ptr, 250, 410, 0xffffff, "    | |  ");
	mlx_string_put(mlx_ptr, win_ptr, 250, 430, 0xffffff, "    |_|  ");
	i = 330;
	mlx_string_put(mlx_ptr, win_ptr, 250, 430, 0xff0000, "    |_|  ");

//	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_hook(win_ptr, 2, 5, deal_key, (void *)0);
//	mlx_hook(win_ptr, 3, key_release, (int) x_mask, (void *)0);
	mlx_mouse_hook(win_ptr, deal_button, (void *)0);
	img_ptr = mlx_new_image(mlx_ptr, 150, 150); /*Image manipulation*/
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 130, 130);

	mlx_loop(mlx_ptr); /*Tells the system that we want to print something*/
}

