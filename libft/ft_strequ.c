/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:42:20 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/12 15:08:49 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Lexicographical comparison between s1 and s2. If the 2 strings
** are identical the function returns 1, or 0 otherwise.
** Param#1 - The first string to be compared.
** Param#2 - The second string to be compared.
** RETURN VALUE - 1 or 0 according to if the 2 strings are identical or not.
** Libc functions - None.
*/

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (!(s1) || !(s2))
		return (0);
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	else if (ft_strcmp(s1, s2) != 0)
		return (0);
	return (0);
}
/*
**int main (void)
**{
**	char *string1 = "Test";
**	char *string2 = "Test";
**	char *string3 = "Tested";
**	char *string4 = "Teste";
**	printf("Strings compared:\n|%s|\n|%s|\n",string1,string2);
**	printf("ft_strequ:%d\n\n", ft_strequ(string1, string2));
**	printf("Strings compared:\n|%s|\n|%s|\n",string3, string4);
**	printf("ft_strequ:%d\n", ft_strequ(string3, string4));
**}
*/
