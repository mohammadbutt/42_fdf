/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:39:44 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/21 13:58:31 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Takes an integer and gives the length of that integer.
** Works both with negative and positive integers.
** For negative integers, counts the negative sign in length.
*/

#include "libft.h"

int		ft_numlen(int n)
{
	int	len;
	int	place_holder;
	int copy_of_n;

	len = 0;
	place_holder = 11;
	copy_of_n = n;
	if (n == 0)
		return (1);
	while (len <= place_holder)
	{
		if ((n > 0 || n < 0) && (n % 10 < 10))
			len++;
		else if (n == 0)
			break ;
		n = n / 10;
	}
	if (copy_of_n >= 0)
		return (len);
	else
		return (++len);
}
/*
** int main (void)
** {
**	int num1 = 2147483647;
**	int num2 = -2147483648;
**	int num3 = 12345;
**	int num4 = -12345;
**	int num5 = -0;
**	printf("%d\n%d\n%d", ft_numlen(num1), ft_numlen(num2), ft_numlen(num3));
**	printf("\n%d\n%d", ft_numlen(num4),ft_numlen(num5));
**	return(0);
**}
*/
