/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:52:32 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/22 22:10:40 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ft_read does the following:
** 1. If the file specified by user is a folder, returns an error message.
** 2. If the file exists, reads and stores the file in a temporary placeholder
** 3. Counts the number of words stored in temporary placeholder.
** 4. Stores from temporary placeholder to a sturct.
** 5. 
*/
/*
void ft_read(int fd, char *argv)
{
	t_data	*data;
	int		ft_return;
	int		wcount;
	int		temp_wcount;
	char	*temp_line;

	ft_zero(&temp_wcount, &wcount, &ft_return, &ft_return);
	ft_return = get_next_line(fd, &temp_line);
	if(ft_return == -1)
		ft_exit(argv);
	if(ft_return == 1)
	{
		wcount = ft_wordcount(temp_line, ' ');
		printf("|%d||%d|line:|%s|\n", ft_return, wcount, temp_line);
		free(temp_line);
	}
	while((ft_return = get_next_line(fd, &temp_line) == 1))
	{
		temp_wcount = ft_wordcount(temp_line, ' ');
		if(temp_wcount != wcount)
			ft_exit("Error: Invalid file. Exiting program.\n");
		printf("|%d||%d|line:|%s|\n", ft_return, wcount, temp_line);
		free(temp_line);
	}
	printf("%d\n", ft_return);
}
*/
/*
void ft_read(int fd, char *argv)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	if(!(data))
		ft_exit("Unable to allocate memory\n");
	printf("cp 1\n");
	ft_zero(&data->wcount, &data->temp_wcount, &data->ft_return, &data->ft_return);
	printf("cp 2\n");
	data->ft_return = get_next_line(fd, &data->temp_line);
	printf("cp 3\n");
	if(data->ft_return == -1)
		ft_exit(argv);
	printf("cp 4\n");
	if(data->ft_return == 1)
	{
		data->wcount = ft_wordcount(data->temp_line, ' ');
		data->lines = data->temp_line;
		printf("|%d||%d|line:|%s|\n", data->ft_return, data->wcount, data->temp_line);
		free(data->temp_line);
		data = data->next;
	}
	printf("cp 5\n");

	data->ft_return = get_next_line(fd, &data->temp_line);
	printf("|%d|line:|%s|\n", data->ft_return, data->temp_line);
	printf("cp 6\n");

	while((data->ft_return = get_next_line(fd, &(data->temp_line)) == 1))
	{
		printf("cp 7\n");
		data->temp_wcount = ft_wordcount(data->temp_line,  ' ');
		if(data->temp_wcount != data->wcount)
			ft_exit("Error: Invalid file. Exiting program.\n");
		data->lines = data->temp_line;
		free(data->temp_line);
		data = data->next;
		printf("cp 8\n");
	}
	data->lines = NULL;
}
*/
int ft_valid(int fd, int height, char *argv)
{
	int		ft_return;
	int		wcount;
	int		temp_wcount;
	char	*temp_line;

	ft_zero(&temp_wcount, &wcount, &ft_return, &height);
	ft_return = get_next_line(fd, &temp_line);
	if(ft_return == -1)
		ft_exit_dir(argv);
	if(ft_return == 1)
	{
		wcount = ft_wordcount(temp_line, ' ');
		free(temp_line);
		height++;
	}
	while((ft_return = get_next_line(fd, &temp_line) == 1))
	{
		temp_wcount = ft_wordcount(temp_line, ' ');
		if(temp_wcount != wcount)
			ft_exit("Error: Invalid file. Exiting program.\n");
		free(temp_line);
		height++;
	}
	close(fd);
	return(height);
}

char **str_data(int fd, int height, char *argv)
{
	int i;
	int width;
	char **data_points;
	char *line;

	ft_zero(&fd, &i, &width, &width);
	data_points = (char **)malloc(sizeof(char *) * (height+1));
	if(data_points == NULL)
		return(NULL);
	fd = open(argv, O_RDONLY);
	while(get_next_line(fd, &line) == 1)
	{
		(width == 0) && (width = ft_strlen(line));
		line[width] = '\0';
		data_points[i] = ft_strdup(line);
		ft_bzero(line, width);
		free(line);
		i++;
	}
	data_points[i] = NULL;
	return(data_points);
}

int **str_to_int(char **data_points, int i, int j)
{
	int wordcount;
	int height;
	int **int_data;
	char **temp_data;

	ft_zero(&wordcount, &height, &height, &height);
	wordcount = ft_wordcount(data_points[i], ' ');
	height = ft_height((void **) data_points);
	int_data = (int **)malloc(sizeof(int *) * (height));
	while(height)
	{
//		temp_data = ft_strsplit(data_points[i], ' ');
		while(wordcount)
		{
			int_data[i] = (int *)malloc(sizeof(int) * (wordcount));
			int_data[i] = ft_strsplit(data_points[i], ' ');
			int_data[i][j] = ft_atoi(ft_strdup(temp_data[i]));
			j++;
			wordcount--;
		}
		j = 0;
		i++;
		height--;
		free(temp_data);
	}
	printf("%d\n", wordcount);
	printf("%d\n", height);
	return(int_data);
}

int main(int argc, char **argv)
{
	int fd;
	int height;
	char **data_points;

	ft_zero(&height, &fd, &fd, &fd);
	if(argc == 1)
		ft_usage("Usage: ./fdf resources/test_maps\n");
	fd = open(argv[1], O_RDONLY);
	if(fd  == -1)
	{
		ft_exit("Main Error 1:\nFile does not exist\n");
//		ft_exit_dir(argv[1]);
	}
	height = ft_valid(fd, height, argv[1]);
	data_points = str_data(fd, height, argv[1]);
	str_to_int(data_points, 0, 0);
	close(fd);
	return(0);
}
