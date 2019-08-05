/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:34:55 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/04 21:01:30 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ft_valid checks if the file path is a directory or if the file is invalid 
** because all of the lines dont have the same number of elements or words.
*/
int ft_valid(int fd, int height, char *argv)
{
	int		ft_return;
	int		wcount;
	int		temp_wcount;
	char	*temp_line;

	ft_zero(&temp_wcount, &wcount, &ft_return, &height);
	ft_return = get_next_line(fd, &temp_line);
	if(ft_return == 0)
		ft_exit("Invalid Error. Empty file.\n");
	if(ft_return == -1)
		ft_exit_dir(argv);
	if(ft_return == 1)
	{
		wcount = ft_wordcount(temp_line);
		free(temp_line);
		height++;
	}
	while((ft_return = get_next_line(fd, &temp_line) == 1))
	{
		temp_wcount = ft_wordcount(temp_line);
		if(temp_wcount != wcount)
			ft_exit("Error: Invalid file. Exiting program.\n");
		free(temp_line);
		height++;
	}
	close(fd);
	return(height);
}
/*
** str_data takes the file discriptor, height, and file name to store
** data points in a 2-Dimensional char array.
*/
char **str_data(int fd, int height, char *argv)
{
	int i;
	int width;
	char **characters;
	char *line;

	ft_zero(&fd, &i, &width, &width);
	characters = (char **)malloc(sizeof(char *) * (height + 1));
	if(characters == NULL)
		return(NULL);
	fd = open(argv, O_RDONLY);
	while(get_next_line(fd, &line) == 1)
	{
		width = ft_strlen(line);
		line[width] = '\0';
		characters[i] = ft_strdup(line);
		free(line);
		i++;
	}
	characters[i] = NULL;
	return(characters);
}
/*
** str_to_int takes datapoints that were stored in a 2d char array, converts
** then into integers and stores them in a 2-Dimensional int array.
*/
int		**str_to_int(char **characters)
{
	int i;
	int height;
	int **int_data;
	i = 0;
	height = ft_height(characters);
	int_data = malloc(sizeof(int *) * (height));
	if(int_data == NULL)
		ft_exit("fdf.c str_to_int error: Unable to allocate memory.\n");
	while(height)
	{
		int_data[i] = ft_2d_atoi(characters[i]);
		i++;
		height--;
	}
	return(int_data);
}

/*
** Below is to test str_to_int()
*/
/*
	i = 0;
	int j = 0;
	int wordcount = ft_wordcount(characters[i], ' ');
	int temp_wordcount = wordcount;
	height = ft_height(characters);
	while(height)
	{
		while(wordcount)
		{
			printf("%d ", int_data[i][j++]);
			wordcount--;
		}
		printf("\n");
		i++;
		j = 0;
		height--;
		wordcount = temp_wordcount;
	}
*/
