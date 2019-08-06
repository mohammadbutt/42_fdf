/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:12:11 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/05 19:30:47 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ft_usage is used if the user does not specfiy a file name.
*/

void	ft_usage(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

/*
** ft_exit_dir is used if the chosen file path is a directory
*/

void	ft_exit_dir(char *str)
{
	ft_putstr("Error\n");
	perror(str);
	exit(EXIT_FAILURE);
}

/*
** ft_exit is used if the specified file does not exist or the file is invalid
*/

void	ft_exit(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

/*
** ft_exit_success is prompted when the user has entered a valid file path and
** the program is terminated by pressing the Esc key.
*/

void	ft_exit_success(char *str)
{
	ft_putstr(str);
	exit(EXIT_SUCCESS);
}

void	invalid_file_message(int ft_return, char *argv)
{
	if (ft_return == 0)
		ft_exit("Invalid Error. Empty file...\n");
	if (ft_return == -1)
		ft_exit_dir(argv);
}
