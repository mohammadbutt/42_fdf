/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:42:08 by mbutt             #+#    #+#             */
/*   Updated: 2019/02/25 21:51:57 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The isascii() function tests for an ASCII character, which is any character
** between 0 and octal 0177 inclusive.
*/

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
/*
** int main (void)
** {
**	char c = 129;
**	printf("%d", isascii(c));
**	printf("\n%d", ft_isascii(c));
**	return (0);
** }
*/
