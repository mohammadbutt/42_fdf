/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintain1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 20:52:23 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/20 20:54:09 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Prints error message and exits the program.
*/

void ft_exit(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}
