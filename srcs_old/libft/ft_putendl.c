/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:08:44 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/21 16:19:33 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Outputs the string s to the standard output followed by a ’\n’.
** Param#1 - The string to output.
** Return Value - None.
** Libc function - write.
*/

#include "libft.h"

void	ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}
/*
**int main (void)
**{
**	char *string1 = "Testing this";
**	ft_putstr(string1);
**	ft_putendl(string1);
**	ft_putstr(string1);
**}
*/
