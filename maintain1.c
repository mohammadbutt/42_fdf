/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintain1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 20:52:23 by mbutt             #+#    #+#             */
/*   Updated: 2019/07/11 16:29:05 by mbutt            ###   ########.fr       */
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

int press_button(int key_code, t_fdf *fdf)
{
	if(key_code == ESCAPE_ESC)
		exit(0);
	return(0);
}

int solve_driver1(int fd, int height, char *argv)
{
	t_fdf *fdf; // Can also test print data stored in struct
	char **characters;
	int **int_data;
	int **int_data_2;

	fdf = malloc(sizeof(t_fdf));
	if(fdf == NULL)
		ft_exit("maintain1.c solve_driver1() error: Unable to malloc.\n");
	fdf->mlx.mlx_ptr = mlx_init();
	fdf->mlx.win_ptr = mlx_new_window(fdf->mlx.mlx_ptr, P_HEIGHT, P_WIDTH, "ok");
												printf("maintain1.c: cp1\n");
	height = ft_valid(fd, height, argv);
												printf("maintain1.c: cp2\n");
	characters = str_data(fd, height, argv);
												printf("maintain1.c: cp3\n");
	int_data = str_to_int(characters);
												printf("maintain1.c: cp4\n");
	fdf->int_data_2 = str_to_int_struct(characters);
												printf("maintain1.c: cp5\n");
	fdf->map_height = ft_height(characters);
												printf("maintain1.c: cp6\n");
	fdf->map_width = ft_width(characters);
												printf("maintain1.c: cp7\n");
	ft_render(fdf);
												printf("maintain1.c: cp8\n");
//	fdf = int_data_to_struct(int_data, height); Might delete this
	
//	mlx_hook(fdf->mlx.mlx_ptr, 2, 3, press_button, fdf); /*Create press_button function*/
	mlx_loop(fdf->mlx.mlx_ptr);
// For testing	
//	printf("   rows:|%d|\n", ft_height(characters));
//	printf("columns:|%d|\n\n", ft_width(characters));	
//	fdf = int_data_to_struct(int_data, height);
//	print_data_coord(fdf, characters);
	return(1);
}

