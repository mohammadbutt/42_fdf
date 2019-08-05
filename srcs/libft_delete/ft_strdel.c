/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:05:47 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/12 15:39:06 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Takes as a parameter the address of a string that need to be
** freed with free(3), then sets its pointer to NULL.
** Param#1 - The string’s address that needs to be freed and its pointer set
** to NULL.
** RETURN VALUE _ NONE
** Libc FUnction - Free
*/

#include "libft.h"

void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
}
/*
** How to use ft_memdel to write ft_strdel?
**	ft_memdel((void **)as);
*/
