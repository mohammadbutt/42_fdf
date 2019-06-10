/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:20:11 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/10 16:18:04 by mbutt            ###   ########.fr       */
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

//	(key == 1) && (ft_putchar('S'));
//	(key == 2) && (ft_putchar('D'));
//	(key == 3) && (ft_putchar('F'));
//	(key == 4) && (ft_putchar('H'));
//	(key == 5) && (ft_putchar('G'));
//	(key == 6) && (ft_putchar('Z'));
//	(key == 7) && (ft_putchar('X'));
//	(key == 8) && (ft_putchar('C'));
//	(key == 9) && (ft_putchar('V'));
//

	return(0);
}

/*
int keyboard_integration(void *mlx_ptr, void *win_ptr, int key, void *param)
{
	int i;

	i = 330;
	ft_putchar('K');
	mlx_string_put(mlx_ptr, win_ptr, 250, i = i + 20, 0xFFFFFF, "(_________)");
	return(0);
}
*/
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

	i = 0;
//	key = 3;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "This is mlx 42- by Mo");
	while(i < 250)
		mlx_pixel_put(mlx_ptr, win_ptr, 250, i++, 0x696969);
	mlx_string_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF, "    (_)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 270, 0xFFFFFF, "   (___)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 290, 0xFFFFFF, "  (_____)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 310, 0xFFFFFF, " (_______)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 330, 0xFFFFFF, "(_________)");
	i = 330;

	mlx_key_hook(win_ptr, deal_key, (void *)0);
//	mlx_key_hook(win_ptr, keyboard_integration, (void*)0);
	mlx_mouse_hook(win_ptr, deal_button, (void *)0);

	mlx_loop(mlx_ptr); /*Tells the system that we want to print something*/
}

