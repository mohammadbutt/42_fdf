/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:06:27 by mbutt             #+#    #+#             */
/*   Updated: 2019/02/25 21:15:42 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The isalpha() function tests for any character for which isupper(3) or
** islower(3) is true.  The value of the argument must be representable as an
** unsigned char or the value of EOF.
** RETURN VALUES: The isalpha() function returns zero if the character tests
** false and returns non-zero if the character tests true.
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
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
**	char c = '0';
**	printf("%d", isalpha(c));
**	printf("\n%d", ft_isalpha(c));
**	return(0);
**}
*/
