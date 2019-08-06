/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:56:42 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/05 21:22:03 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
//	ft_print_data(mlx);
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
