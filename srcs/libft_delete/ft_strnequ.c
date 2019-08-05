/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:12:01 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/12 15:34:56 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Lexicographical comparison between s1 and s2 up to n characters
** or until a ’\0’ is reached. If the 2 strings are identical, the function
** returns 1, or 0 otherwise.
** Param#1 - The first string to be compared.
** Param#2 - The second string to be compared.
** Param#3 - The maximum number of characters to be compared.
** RETURN VALUE - 1 or 0 according to if the 2 strings are identical or not.
** Libc functions - NONE.
*/

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!(s1) || !(s2))
		return (0);
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	else if (ft_strncmp(s1, s2, n) != 1)
		return (0);
	return (0);
}
/*
**int main (void)
**{
**	char *string1 = "Test";
**	char *string2 = "Test";
**	int   n1		  = 4;
**	char *string3 = "Tested";
**	char *string4 = "Teste";
**	int   n2       = 6;
**	printf("Strings compared:\n|%s|\n|%s|\n",string1,string2);
**	printf("ft_strequ:%d\n\n", ft_strnequ(string1, string2, n1));
**	printf("Strings compared:\n|%s|\n|%s|\n",string3, string4);
**	printf("ft_strequ:%d\n", ft_strnequ(string3, string4, n2));
**}
*/
