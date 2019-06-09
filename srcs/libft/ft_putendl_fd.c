/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 23:52:19 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/22 00:00:09 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Description- Output the string s to the file descriptor fd followed by a '\n'
**Param#1- The string to output.
**Param#2- The file descriptor.
**Return Value- None.
**Libc functions- write.
*/

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
** int main (void)
** {
**	char *s0 = "abc", *s1 = "def", *s2 = "ghi", *s3 = "jkl", *s4 = "mno";
**	int fd0 = 0, fd1 = 1, fd2 = 2, fd3 = 3, fd4 = 4;
**	ft_putendl_fd(s0, fd0);
**	ft_putendl_fd(s1, fd1);
**	ft_putendl_fd(s2, fd2);
**	ft_putendl_fd(s3, fd3);
**	ft_putendl_fd(s4, fd4);
** }
*/
