/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 00:01:45 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/22 00:10:51 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description- Output the integer n to the file descriptor fd.
** Param#1 - The integer to print.
** Param#2 - The file descriptor.
** Return Value - None.
** Libc functions - write.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == FT_INT_MIN)
			ft_putstr_fd(("-2147483648"), fd);
		else
		{
			ft_putchar_fd(('-'), fd);
			n = -1 * n;
		}
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd((n % 10 + '0'), fd);
	}
	else if (n >= 0 && n < 10)
		ft_putchar_fd((n + '0'), fd);
}
/*
**int main (void)
** {
**	int n0 = -98765, n1 = 2147483647, n2 = -2147483648, n3 = 214, n4 = -214;
**	int fd0 = 0, fd1 = 1, fd2 = 2, fd3 = 3, fd4 = 4;
**	ft_putnbr_fd(n0,fd0); printf("\n");
**	ft_putnbr_fd(n1, fd1); printf("\n");
**	ft_putnbr_fd(n2, fd2); printf("\n");
**	ft_putnbr_fd(n3, fd3); printf("\n");
**	ft_putnbr_fd(n4, fd4);
**	return(0);
**}
*/
