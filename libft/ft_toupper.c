/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:47:18 by mbutt             #+#    #+#             */
/*   Updated: 2019/02/25 20:53:30 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The toupper() function converts a lower-case letter to the corresponding
** upper-case letter. The argument must be representable as an unsigned char or
** the value of EOF.
** RETURN VALUES: If the argument is a lower-case letter, the toupper() function
** returns the corresponding upper-case letter if there is one; otherwise, the
** argument is returned unchanged.
*/

#include "libft.h"

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}
/*
** int main (void)
** {
**	char c = '1';
**	printf("%c", ft_toupper(c));
**	return(0);
** }
*/
