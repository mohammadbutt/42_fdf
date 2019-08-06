/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:44:57 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/05 21:11:51 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ft_valid checks if the file path is a directory or if the file is invalid
** because all of the lines dont have the same number of elements or words.
*/

int		ft_valid(int fd, int height, char *argv)
{
	int		ft_return;
	int		wcount;
	int		temp_wcount;
	char	*temp_line;

	ft_zero(&temp_wcount, &wcount, &ft_return, &height);
	ft_return = get_next_line(fd, &temp_line);
	invalid_file_message(ft_return, argv);
	if (ft_return == 1)
	{
		wcount = ft_wordcount(temp_line, ' ');
		free(temp_line);
		height++;
	}
	while ((ft_return = get_next_line(fd, &temp_line) == 1))
	{
		temp_wcount = ft_wordcount(temp_line, ' ');
		if (temp_wcount != wcount)
			ft_exit("Error: Invalid file. Exiting program.\n");
		free(temp_line);
		height++;
	}
	close(fd);
	return (height);
}

/*
** str_data takes the file discriptor, height, and file name to store
** data points in a 2-Dimensional char array.
*/

char	**str_data(int fd, int height, char *argv)
{
	int		i;
	int		width;
	char	**characters;
	char	*line;

	ft_zero(&fd, &i, &width, &width);
	characters = (char **)malloc(sizeof(char *) * (height + 1));
	if (characters == NULL)
		return (NULL);
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		width = ft_strlen(line);
		line[width] = '\0';
		characters[i] = ft_strdup(line);
		free(line);
		i++;
	}
	characters[i] = NULL;
	return (characters);
}

/*
** ft_2d_atoi takes a string and converts all of the numbers from string format
** into an int array:
** Has builtin garbage collector to free memory that was allocated using
** malloc(3).
*/

int		*ft_2d_atoi(char *str)
{
	int		i;
	int		wordcount;
	int		*int_data;
	char	**words;

	i = 0;
	wordcount = ft_wordcount(str, ' ');
	words = ft_strsplit(str, ' ');
	int_data = malloc(sizeof(int) * (wordcount));
	if (int_data == NULL)
		ft_exit("matintain1.c ft_2d_atoi() error: Unable to malloc.\n");
	while (wordcount)
	{
		if (ft_isdigit(words[i][0]) == 1)
			int_data[i] = ft_atoi(words[i]);
		else if (words[i][0] == '-' && ft_isdigit(words[i][1]) == 1)
			int_data[i] = ft_atoi(words[i]);
		else
			ft_exit("Invalid File.\n");
		free(words[i]);
		i++;
		wordcount--;
	}
	free(words);
	return (int_data);
}

/*
** **str_to_int takes in 2D array of string that were stored using str_data,
** and converts them into 2D int array.
**
** 2D string array that's taken in is stored as such:
** "0  1  3  0"
** "0 10 -5  0"
**
** This will look like this:
** characters[0] = "7  1  3  0"
** characters[1] = "4 10 -5  0"
** When any of the elements in this string are accessed they are perceived
** as characters, not numbers. chararcters [1][0] will be '4', characters[1][1]
** will be ' ', a space, and characters[1][2] will be '1';
**
** After the string is converted to a 2d int array, it will be stored as such:
** {7, 1, 3, 0}
** {4, 10, -5, 0}
** Now when any of the elements in this int array are accessed they are
** perceived as numbers. int_data[1][0] will be 4. int_data[1][1] will be 10,
** and int_data[1][2] will be -5.
*/

int		**str_to_int(char **characters)
{
	int i;
	int height;
	int **int_data;

	i = 0;
	height = ft_height(characters);
	int_data = malloc(sizeof(int *) * (height));
	if (int_data == NULL)
		ft_exit("fdf.c str_to_int error: Unable to allocate memory.\n");
	while (height)
	{
		int_data[i] = ft_2d_atoi(characters[i]);
		i++;
		height--;
	}
	return (int_data);
}
