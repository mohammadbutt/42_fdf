/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 19:24:38 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/26 16:15:51 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Outputs the integer n to the standard output.
** Param # 1 - The integer to output.
** RETURN VALUES - None.
** Libc functions - write(2).
*/

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n > FT_INT_MAX || n < FT_INT_MIN)
		return ;
	if (n == FT_INT_MIN)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -1 * n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}
/*
** int main (void)
** {
** char buf[100];
** int n1 = -987006500, n2 = 2147483647, n3 = -2147483648, n4 = 214, n5 = -214;
** ft_putnbr(n1); printf("\n");
** ft_putnbr(n2); printf("\n");
** ft_putnbr(n3); printf("\n");
** ft_putnbr(n4); printf("\n");
** ft_putnbr(n5); printf("\n\n");
** printf("%d",(strcmp(buf, "01-11230010203-562147483647-2147483648") == 0));
** return(0);
** }
*/
