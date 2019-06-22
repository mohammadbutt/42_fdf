/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:52:32 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/21 21:47:21 by mbutt            ###   ########.fr       */
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
int ft_valid(int fd, char *argv)
{
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
		free(temp_line);
	}
	while((ft_return = get_next_line(fd, &temp_line) == 1))
	{
		temp_wcount = ft_wordcount(temp_line, ' ');
		if(temp_wcount != wcount)
			ft_exit("Error: Invalid file. Exiting program.\n");
		free(temp_line);
	}
	return()
}

int main(int argc, char **argv)
{
	int fd;

	if(argc == 1)
		ft_usage("Usage: ./fdf resources/test_maps\n");
	fd = open(argv[1], O_RDONLY);
	if(fd  == -1)
	{
		ft_exit("Main error 1: File does not exist");
//		ft_exit(argv[1]);
	}
	ft_read(fd, argv[1]);
	close(fd);
	return(0);
}
