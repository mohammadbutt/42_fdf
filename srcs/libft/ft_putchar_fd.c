/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 22:37:55 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/21 23:31:23 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Outputs the char c to the file descriptor fd.
** Param#1 - The character to output.
** Param#2 - The file descriptor.
** RETURN VALUE - NONE.
** Libc functions - write.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
** int main (void)
** {
**	char c = 'C', d = 'D', e = 'E', f = 'F', g = 'G', h = 'H';
**	int fd_c = 0, fd_d = 1, fd_e = 2, fd_f = 3, fd_g = 4, fd_h = 5;
**	ft_putchar_fd(c, fd_c); printf("\n");
**	ft_putchar_fd(d, fd_d); printf("\n");
**	ft_putchar_fd(e, fd_e); printf("\n");
**	ft_putchar_fd(f, fd_f); printf("\n");
**	ft_putchar_fd(g, fd_g); printf("\n");
**	ft_putchar_fd(h, fd_h); printf("\n");
**	return(0);
** }
*/
