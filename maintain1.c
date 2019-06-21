/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintain1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 20:52:23 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/20 21:32:29 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Prints error message and exits the program.
*/

void ft_usage(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

void ft_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

