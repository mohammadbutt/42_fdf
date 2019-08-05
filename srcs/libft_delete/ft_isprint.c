/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:53:34 by mbutt             #+#    #+#             */
/*   Updated: 2019/02/25 22:00:41 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The isprint() function tests for any printing character, including space
** (` ').
** RETURN VALUES: The isprint() function returns zero if the character tests
** false and returns non-zero if the character tests true.
*/

#include "libft.h"

int		ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
** {
**	char c = 126;
**	printf("%d", isprint(c));
**	printf("\n%d", ft_isprint(c));
**	return(0);
** }
*/
