/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcc_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:01:00 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/05 18:26:11 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void	calculate_delta_xy(t_mlx *mlx)
{
	mlx->dx = mlx->x1 - mlx->x0;
	mlx->dy = mlx->y1 - mlx->y0;
}

void	plot_low_line(t_mlx *mlx)
{
	size_t hue;

	hue = mlx->color;
	calculate_delta_xy(mlx);
	mlx->yi = 1;
	if (mlx->dy < 0)
	{
		mlx->yi = -1;
		mlx->dy = -1 * mlx->dy;
	}
	mlx->delta_error = (2 * mlx->dy) - mlx->dx;
	while (mlx->x0 < mlx->x1)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x0, mlx->y0, mlx->color);
		if (mlx->delta_error > 0)
		{
			mlx->y0 = mlx->y0 + mlx->yi;
			mlx->delta_error = mlx->delta_error - (2 * mlx->dx);
		}
		mlx->delta_error = mlx->delta_error + (2 * mlx->dy);
		mlx->x0++;
	}
}

void	plot_high_line(t_mlx *mlx)
{
	size_t hue;

	hue = mlx->color;
	calculate_delta_xy(mlx);
	mlx->xi = 1;
	if (mlx->dx < 0)
	{
		mlx->xi = -1;
		mlx->dx = -1 * mlx->dx;
	}
	mlx->delta_error = (2 * mlx->dx) - mlx->dy;
	while (mlx->y0 < mlx->y1)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->x0, mlx->y0, mlx->color);
		if (mlx->delta_error > 0)
		{
			mlx->x0 = mlx->x0 + mlx->xi;
			mlx->delta_error = mlx->delta_error - (2 * mlx->dy);
		}
		mlx->delta_error = mlx->delta_error + (2 * mlx->dx);
		mlx->y0++;
	}
}

void	plot_any_line(t_mlx *mlx)
{
	if (ft_abs(mlx->y1 - mlx->y0) < ft_abs(mlx->x1 - mlx->x0))
	{
		if (mlx->x0 > mlx->x1)
		{
			ft_swap(&mlx->x0, &mlx->x1);
			ft_swap(&mlx->y0, &mlx->y1);
			plot_low_line(mlx);
		}
		else
			plot_low_line(mlx);
	}
	else
	{
		if (mlx->y0 > mlx->y1)
		{
			ft_swap(&mlx->x0, &mlx->x1);
			ft_swap(&mlx->y0, &mlx->y1);
			plot_high_line(mlx);
		}
		else
			plot_high_line(mlx);
	}
}

void	ft_menu1(t_mlx *mlx)
{
	char *str1;
	char *str2;
	char *str3;
	char *str4;

	str1 = "Menu Controls";
	str2 = "Shift: Arrow Keys: < ^ v >";
	str3 = "Rotate: I J K L";
	str4 = "Zoom: Q A";
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0xffffff, str1);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 40, 0xadadad, str2);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 60, 0xadadad, str3);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 80, 0xadadad, str4);
}

void	ft_menu2(t_mlx *mlx)
{
	char *str5;
	char *str6;
	char *str7;

	str5 = "Altitude: W S";
	str6 = "Reset map: E";
	str7 = "Random Colors: R";
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 100, 0xadadad, str5);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 120, 0xadadad, str6);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 140, 0xadadad, str7);
}

void	ft_menu(t_mlx *mlx)
{
	ft_menu1(mlx);
	ft_menu2(mlx);
}

void	ft_render_vertical(t_mlx *mlx, t_mlx *temp)
{
	mlx->x0 = mlx->x;
	mlx->y0 = mlx->y;
	rotate_vertical_line(mlx, temp);
	if (mlx->y < temp->map_height)
		plot_any_line(mlx);
}

void	ft_render_horizontal(t_mlx *mlx, t_mlx *temp)
{
	mlx->x0 = mlx->x;
	mlx->y0 = mlx->y;
	rotate_horizontal_line(mlx, temp);
	if (mlx->x < temp->map_width)
		plot_any_line(mlx);
}

/*
** ft_render_horizontal_vertical calls onto ft_render_horizontal and
** ft_render_vertical to render lines. Not including the second if statement
** would produce lines as shown below:
**  _ _ _ _ _ _ _
** |_|_|_|_|_|_|_
** |_|_|_|_|_|_|_
** | | | | | | |
**
** But that is fixed when the second if statement if(mlx->y < temp->map_height)
** is included, which places the vertical line as long as y is less than height
** the map. Below is how the map will render now:
**  _ _ _ _ _ _ _
** |_|_|_|_|_|_|_|
** |_|_|_|_|_|_|_|
** |_|_|_|_|_|_|_|
*/

void	ft_render_vertical_horizontal(t_mlx *mlx, t_mlx *temp)
{
	if (mlx->camera == 0 || mlx->camera == 1)
	{
		if (mlx->y < temp->map_height)
			ft_render_vertical(mlx, temp);
		ft_render_horizontal(mlx, temp);
	}
}

void	ft_render(t_mlx *mlx)
{
	t_mlx temp;
	t_mlx temp_reset;

	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_print_data(mlx);
	ft_menu(mlx);
	struct_copy(mlx, &temp);
	struct_copy(mlx, &temp_reset);
	copy_height_width(mlx, &temp);
	while (mlx->y <= temp.map_height)
	{
		while (mlx->x <= temp.map_width)
		{
			ft_render_vertical_horizontal(mlx, &temp);
			mlx->x++;
		}
		mlx->x = 0;
		mlx->y++;
	}
	struct_copy(&temp_reset, mlx);
	mlx->x = 0;
	mlx->y = 0;
}
