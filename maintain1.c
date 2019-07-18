/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintain1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:03:07 by mbutt             #+#    #+#             */
/*   Updated: 2019/07/17 20:52:37 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ft_usage is used if the user does not specfiy a file name.
*/
void ft_usage(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

/*
** ft_exit_dir is used if the chosen file path is a directory
*/
void ft_exit_dir(char *str)
{
	ft_putstr("Error\n");
	perror(str);
	exit(EXIT_FAILURE);
}

/*
** ft_exit is used if the specified file does not exist or the file is invalid
*/
void ft_exit(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

void ft_exit_success(char *str)
{
	ft_putstr(str);
	exit(EXIT_SUCCESS);
}

/*
** ft_zero initializes the values of multiple variables to 0.
*/

int ft_zero(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
	return(0);
}


/*
** ft_height counts the number of elements/height/rows there are in a 2D-array.
** It will only work with strings. It will not work with int because in an int
** coming across 0 means that it was the end of the int array unless the length
** was specified.
*/

int ft_height(char **characters)
{
	int i;

	i = 0;
	if(characters)
		while(characters[i])
			i++;
	return(i);
}


/*
** ft_width counts the number of columns/width of a 2D-char array.
*/
int ft_width(char **characters)
{
	int width;

	width = ft_wordcount(characters[0], ' ');
	return(width);
}


/*
** ft_2d_atoi takes a string and converts all of the numbers in string format
** into an int array:
** Has builtin garbage collector to free memory that was allocated using
** malloc(3).
*/

int *ft_2d_atoi(char *str)
{
	int i;
	int wordcount;
	int *int_data;
	char **words;

	i = 0;
	wordcount = ft_wordcount(str, ' ');
	int_data = (int *)malloc(sizeof(int) * (wordcount));
	if(int_data == NULL)
		ft_exit("matintain1.c ft_2d_atoi() error: Unable to malloc.\n");
	words = ft_strsplit(str, ' ');
	while(wordcount)
	{
		int_data[i] = ft_atoi(words[i]);
		free(words[i]);
		i++;
		wordcount--;
	}
	free(words);
	return(int_data);
}
/*
** Map does not offset when the map is zoomed in or out.
** Centeralize_with_zoom helps offset when zoom is applied to
** centeralize the map.
*/
void centeralize_with_zoom(t_mlx *mlx, int key)
{
/*
** Note: Leave th values at 9 and 5.5 for now. But need to find a formula	
** that computes the center better.
*/
	if(key == ZOOM_IN_Q)
	{
		mlx->x0 = mlx->x0 - 9;
		mlx->x1 = mlx->x1 - 9;
		mlx->y0 = mlx->y0 - 5.5;
		mlx->y1 = mlx->y1 - 5.5;
	}
	else if(key == ZOOM_OUT_A)
	{
		mlx->x0 = mlx->x0 + 9;
		mlx->x1 = mlx->x1 + 9;
		mlx->y0 = mlx->y0 + 5.5;
		mlx->y1 = mlx->y1 + 5.5;
	}
}
void zoom_program(t_mlx *mlx, int key)
{
	if(key == ZOOM_IN_Q)
	{
		mlx->x0 = mlx->x0 * 1.02;
		mlx->x1 = mlx->x1 * 1.02;
		mlx->y0 = mlx->y0 * 1.02;
		mlx->y1 = mlx->y1 * 1.02;
	}
	else if(key == ZOOM_OUT_A)
	{
		mlx->x0 = mlx->x0 / 1.02;
		mlx->x1 = mlx->x1 / 1.02;
		mlx->y0 = mlx->y0 / 1.02;
		mlx->y1 = mlx->y1 / 1.02;
	}
	centeralize_with_zoom(mlx, key);
	ft_render(mlx);
}

void shift_program(t_mlx *mlx, int key)
{
	if(key == UP_K)
	{
		mlx->y0 = mlx->y0 - 5;
		mlx->y1 = mlx->y1 - 5;
	}
	else if(key == DOWN_K)
	{
		mlx->y0 = mlx->y0 + 5;
		mlx->y1 = mlx->y1 + 5;
	}
	else if(key == RIGHT_K)
	{
		mlx->x0 = mlx->x0 + 5;
		mlx->x1 = mlx->x1 + 5;
	}
	else if(key == LEFT_K)
	{
		mlx->x0 = mlx->x0 - 5;
		mlx->x1 = mlx->x1 - 5;
	}
	ft_render(mlx);
}

int program_keys(int key, t_mlx *mlx)
{
	if(key == ESCAPE_ESC)
		exit(0); //When preogram works fine, replace it with ft_exit_success();
	else if(key == UP_K || key == DOWN_K || key == LEFT_K || key == RIGHT_K)
		shift_program(mlx, key);
	else if(key == ZOOM_IN_Q || key == ZOOM_OUT_A)
		zoom_program(mlx, key);

	return(0);
}

int solve_driver1(int fd, int height, char *argv)
{
	t_mlx *mlx;
	char **characters;
	int **int_data;

	mlx = malloc(sizeof(t_mlx));
	if(mlx == NULL)
		ft_exit("maintain1.c solve_driver1() error: Unable to malloc.\n");
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, P_WIDTH, P_HEIGHT, "ok");
	height = ft_valid(fd, height, argv);
	characters = str_data(fd, height, argv);
//	get_struct_values(mlx);
	mlx->int_data = str_to_int(characters);
	mlx->map_height = ft_height(characters); // Can we also do mlx->map_height = height;?
	mlx->map_width = ft_width(characters);
	get_struct_values(mlx);
	ft_render(mlx);
//	ft_print_data(mlx);
	mlx_hook(mlx->win_ptr, 2, 5, program_keys, mlx);
	mlx_loop(mlx->mlx_ptr);
	return(1);
}
