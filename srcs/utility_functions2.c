/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:16:47 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/06 11:48:14 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ft_zero initializes the values of multiple variables to 0.
*/

int		ft_zero(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
	return (0);
}

/*
** ft_height counts the number of elements/height/rows there are in a 2D-array.
** It will only work with strings. It will not work with int because in an int
** coming across 0 means that it was the end of the int array unless the length
** was specified.
*/

int		ft_height(char **characters)
{
	int i;

	i = 0;
	if (characters)
		while (characters[i])
			i++;
	return (i);
}

/*
** ft_width counts the number of columns/width of a 2D-char array.
*/

int		ft_width(char **characters)
{
	int width;

	width = ft_wordcount(characters[0], ' ');
	return (width);
}

/*
** ft_print_data prints the data that is stored in t_mlx struct inside int_data.
*/

void	ft_print_data(t_mlx *mlx)
{
	int i;
	int j;
	int width;
	int height;

	i = 0;
	j = 0;
	width = mlx->map_width;
	height = mlx->map_height;
	while (height)
	{
		while (j < width)
		{
			ft_putnbr(mlx->int_data[i][j]);
			ft_putstr(" ");
			j++;
		}
		ft_putstr("\n");
		j = 0;
		i++;
		height--;
	}
}
