/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:25:09 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/26 12:09:30 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** bzero -- write zeroes to a byte string
** The bzero() function writes n zeroed bytes to the string s.  If n is zero,
** bzero() does nothing.
** bzero() returns no values.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*string;
	size_t	num;

	string = s;
	num = 0;
	while (num < n)
	{
		string[num] = 0;
		num++;
	}
}
/*
** int main (void)
** {
**	char s[] = "Test";
**	ft_bzero(s, 0);
**	return(0);
** }
*/
