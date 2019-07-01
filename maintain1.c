/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintain1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 20:52:23 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/30 17:57:21 by mbutt            ###   ########.fr       */
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

int solve_driver1(int fd, int height, char *argv)
{
	char **characters;
	int **int_data;
	int **int_data_2;
	t_fdf *pointer_2;	//To test print data stored in struct;

	height = ft_valid(fd, height, argv);
	characters = str_data(fd, height, argv);
	int_data = str_to_int(characters);
	int_data_2 = str_to_int_struct(characters);
//	pointer_2 = int_data_to_struct(int_data, height); Might delete this
	

// For testing	
//	printf("   rows:|%d|\n", ft_height(characters));
//	printf("columns:|%d|\n\n", ft_width(characters));	
//	pointer_2 = int_data_to_struct(int_data, height);
//	print_data_coord(pointer_2, characters);
	return(1);
}

