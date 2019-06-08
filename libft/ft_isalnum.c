/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:28:09 by mbutt             #+#    #+#             */
/*   Updated: 2019/02/25 21:37:51 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The isalnum() function tests for any character for which isalpha(3) or
** isdigit(3) is true.  The value of the argument must be representable as an
** unsigned char or the value of EOF.
** RETURN VALUES: The isalnum() function returns zero if the character tests
** false and returns non-zero if the character tests true.
*/

#include "libft.h"

int		ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
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
**	char c = '&';
**	printf("%d", isalnum(c));
**	printf("\n%d", ft_isalnum(c));
**	return(0);
** }
*/
