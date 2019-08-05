/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintain1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:03:07 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/05 12:04:30 by mbutt            ###   ########.fr       */
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

//	width = ft_wordcount(characters[0], ' ');
	width = ft_wordcount(characters[0]);

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
//	wordcount = ft_wordcount(str, ' ');
//	wordcount = ft_wordcount(str);
	wordcount = 0;
//	int_data = (int *)malloc(sizeof(int) * (wordcount));
//	int_data = malloc(sizeof(int) * (wordcount));
//	printf("ft_2d_atoi: wordcount:|%d|\n", wordcount);
//	if(int_data == NULL)
//		ft_exit("matintain1.c ft_2d_atoi() error: Unable to malloc.\n");
	words = ft_strsplit(str, ' ');
	while(words[wordcount])
		wordcount++;
	int_data = malloc(sizeof(int) * (wordcount));
	if(int_data == NULL)
		ft_exit("matintain1.c ft_2d_atoi() error: Unable to malloc.\n");
	while(wordcount)
	{
		if(ft_isdigit(words[i][0]) == 1)
			int_data[i] = ft_atoi(words[i]);
		else if(words[i][0] == '-' && ft_isdigit(words[i][1]) == 1)
			int_data[i] = ft_atoi(words[i]);
		else
			ft_exit("Invalid File.\n");
		free(words[i]);
		i++;
		wordcount--;
	}
	free(words);
	return(int_data);
}

int ft_hue(int y, int color)
{
	int final_color;
	final_color = color + ft_abs(y / 2);

	return(final_color);
}
void random_color(t_mlx *mlx, int key)
{
	size_t random_seed;

	random_seed = mlx->y0;
	random_seed = rand();
	mlx->color = rand() % random_seed;
	ft_render(mlx);
}

void zoom_program(t_mlx *mlx, int key)
{
	if(key == ZOOM_IN_Q)
		mlx->xy_zoom = mlx->xy_zoom + XY_ZOOM;
	if(key == ZOOM_OUT_A && mlx->xy_zoom > 0.04)
		mlx->xy_zoom = mlx->xy_zoom - XY_ZOOM;
	ft_render(mlx);
}

void change_altitude(t_mlx *mlx, int key)
{
	if(key == ALTITUDE_INCREASE_W)
		mlx->z_zoom = mlx->z_zoom + Z_ZOOM;
	else if(key == ALTITUDE_DECREASE_S)
		mlx->z_zoom = mlx->z_zoom - Z_ZOOM;
	ft_render(mlx);
}	

void reset_program(t_mlx *mlx)
{
	get_struct_values(mlx);
	ft_render(mlx);
}

void shift_program(t_mlx *mlx, int key)
{
	if(key == UP_K)
		mlx->y_shift = mlx->y_shift - 5;
	else if(key == DOWN_K)
		mlx->y_shift = mlx->y_shift + 5;
	else if(key == LEFT_K)
		mlx->x_shift = mlx->x_shift - 5;
	else if(key == RIGHT_K)
		mlx->x_shift = mlx->x_shift + 5;
	ft_render(mlx);
}

void change_camera(t_mlx *mlx)
{
	if(mlx->camera == 0)
		mlx->camera = 1;
	else if(mlx->camera == 1)
		mlx->camera = 0;
	ft_render(mlx);
}

void rotate_axis(t_mlx *mlx, int key)
{
	if(key == ROTATE_UP_I)
		mlx->x_axis = mlx->x_axis + 0.02;
	else if(key == ROTATE_DOWN_K)
		mlx->x_axis = mlx->x_axis - 0.02;
	else if(key == ROTATE_LEFT_J)
		mlx->y_axis = mlx->y_axis + 0.02;
	else if(key == ROTATE_RIGHT_L)
		mlx->y_axis = mlx->y_axis - 0.02;

	else if(key == ROTATE_SIDE_U)
		mlx->z_axis = mlx->z_axis + 0.02;
	else if(key == ROTATE_SIDE_O)
		mlx->z_axis = mlx->z_axis - 0.02;
	ft_render(mlx);
}

int program_keys(int key, t_mlx *mlx)
{
	if(key == ESCAPE_ESC)
		ft_exit_success("\33[1;32mProgram shut down successfully.\n\33[m");
	else if(key == UP_K || key == DOWN_K || key == LEFT_K || key == RIGHT_K)
		shift_program(mlx, key);
	else if(key == ZOOM_IN_Q || key == ZOOM_OUT_A)
		zoom_program(mlx, key);
	else if(key == RANDOM_COLOR_R)
		random_color(mlx, key);
	else if(key == RESET_PROGRAM_E)
		reset_program(mlx);
	else if(key == CHANGE_CAMERA_C)
		change_camera(mlx);
	else if(key == ALTITUDE_INCREASE_W || key == ALTITUDE_DECREASE_S)
		change_altitude(mlx, key);
	else if(key == ROTATE_UP_I || key == ROTATE_DOWN_K)
		rotate_axis(mlx, key);
	else if(key == ROTATE_LEFT_J || key == ROTATE_RIGHT_L)
		rotate_axis(mlx, key);
	else if(key == ROTATE_SIDE_U || key == ROTATE_SIDE_O)
		rotate_axis(mlx, key);
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
	mlx->int_data = str_to_int(characters);
	mlx->map_height = ft_height(characters); // Can we also do mlx->map_height = height;?
	mlx->map_width = ft_width(characters);
	get_struct_values(mlx);
//	ft_print_data(mlx); 		/*To test if values are stored properly*/
	ft_render(mlx);
	mlx_hook(mlx->win_ptr, 2, 5, program_keys, mlx);
	mlx_loop(mlx->mlx_ptr);
	return(1);
}
