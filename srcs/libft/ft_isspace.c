/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:58:27 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/12 15:35:16 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The isspace() function tests for the white-space characters. For any locale,
** this includes the following standard characters:
** ``\t''   ``\n''    ``\v''    ``\f''    ``\r''    `` ''
** RETURN VALUES: The isspace() function returns zero if the character tests
** false and returns non-zero if the character tests true.
*/

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == ' ')
	{
		return (1);
	}
	else if (c == '\f')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/*
** int main (void)
**{
**	char string1 = 'A';
**	printf("%d\n", isspace(string1));
**	printf("%d", ft_isspace(string1));
**	return(0);
** }
*/
