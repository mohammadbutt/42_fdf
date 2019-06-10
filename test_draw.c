/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:20:11 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/09 21:15:15 by mbutt            ###   ########.fr       */
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
	ft_putchar('X');
	return(0);
}



int main(void)
{
	void *mlx_ptr;
	void *win_ptr;
	int i;

	i = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "This is mlx 42- by Mo");
	while(i < 250)
		mlx_pixel_put(mlx_ptr, win_ptr, 250, i++, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	
	mlx_string_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF, "    (_)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 270, 0xFFFFFF, "   (___)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 290, 0xFFFFFF, "  (_____)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 310, 0xFFFFFF, " (_______)");
	mlx_string_put(mlx_ptr, win_ptr, 250, 330, 0xFFFFFF, "(_________)");
	



	mlx_loop(mlx_ptr); /*Tells the system that we want to print something*/
}

