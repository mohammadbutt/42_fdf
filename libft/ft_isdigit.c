/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:18:48 by mbutt             #+#    #+#             */
/*   Updated: 2019/02/25 21:26:12 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The isdigit() function tests for a decimal digit character.
** RETURN VALUES: The isdigit() and isnumber() functions return zero if the
** character tests false and return non-zero if the character tests true.
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
**	char c = '#';
**	printf("%d", isdigit(c));
**	printf("\n%d", ft_isdigit(c));
**	return(0);
** }
*/
