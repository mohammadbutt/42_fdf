/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:57:37 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/05 18:13:26 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

/*
** ft_swap, swaps values of a and b
*/

int		ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return (0);
}

/*
** ft_abs performs the same function as abs(3) function found in stdlib.h
** Converts a value into an absolute value, so a negative values becomes
** positive.
** Return Value: Returns a postive value.
*/

int		ft_abs(int num)
{
	if (num < 0)
		num = -1 * num;
	return (num);
}

/*
** Struct_copy copies values of source x0, y0 and x1, y1 struct to destination
** struct.
*/

void	struct_copy(t_mlx *source, t_mlx *dest)
{
	dest->x0 = source->x0;
	dest->y0 = source->y0;
	dest->x1 = source->x1;
	dest->y1 = source->y1;
}

/*
** get struct_values initializes values of several variables for the struct
*/

void	get_struct_values(t_mlx *mlx)
{
	mlx->size = 15;
	mlx->x = 0;
	mlx->y = 0;
	mlx->x0 = 0;
	mlx->y0 = 0;
	mlx->x1 = mlx->x0;
	mlx->y1 = mlx->y0;
	mlx->camera = 0;
	mlx->x_shift = 0;
	mlx->y_shift = 0;
	mlx->camera = 0;
	mlx->degree_angle = 30;
	mlx->xy_zoom = 0.5;
	mlx->z_zoom = 0.03;
	mlx->x_axis = 0;
	mlx->y_axis = 0;
	mlx->z_axis = 0;
	mlx->color = 0xff000;
}

/*
** Copies values of height and width from struct and saves them in a temp struct
** and decrements height and width by 1.
*/
void copy_height_width(t_mlx *mlx, t_mlx *temp)
{
	temp->map_height = mlx->map_height;
	temp->map_width = mlx->map_width;
	temp->map_height--;
	temp->map_width--;
}
