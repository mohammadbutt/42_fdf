/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 23:37:48 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/21 23:50:35 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Outputs the string s to the file descriptor fd.
** Param#1 - The string to output.
** Param#2 - The file descriptor.
** Return Value - None.
** Libc functions - Write.
*/

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int i;

	i = 0;
	if (s)
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
}
/*
** int main (void)
** {
**	char *s0 = "abc", *s1 = "def", *s2 = "ghi", *s3 = "jkl", *s4 = "mno";
**	int fd0 = 0, fd1 = 1, fd2 = 2, fd3 = 3, fd4 = 4;
**	ft_putstr_fd(s0, fd0); printf("\n");
**	ft_putstr_fd(s1, fd1); printf("\n");
**	ft_putstr_fd(s2, fd2); printf("\n");
**	ft_putstr_fd(s3, fd3); printf("\n");
**	ft_putstr_fd(s4, fd4); printf("\n");
** }
*/
