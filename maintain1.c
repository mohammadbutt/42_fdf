/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintain1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 20:52:23 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/21 15:16:52 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Error messages:
** ft_usage is only used if the user does not specfiy a file name.
** ft_exit is used if the specified file does not exist or is invalid.
*/

void ft_usage(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

void ft_exit(char *str)
{
	ft_putstr("Error\n");
	perror(str);
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
