/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:09:24 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/12 15:34:03 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strcmp() and strncmp() functions lexicographically compare the
** null-terminated strings s1 and s2.
** The strncmp() function compares not more than n characters. Because strncmp()
** is designed for comparing strings rather than binary data, characters that
** appear after a `\0' character are not compared.
** RETURN VALUES: The strcmp() and strncmp() functions return an integer greater
** than, equal to, or less than 0, according as the string s1 is greater than,
** equal to, or less than the string s2.  The comparison is done using unsigned
** characters, so that `\200' is greater than `\0'.
*/

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	while (n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned const char)s1[i] - (unsigned const char)s2[i]);
		n--;
		i++;
	}
	return (0);
}
/*
** Method 2 by using pointers.
** int ft_strncmp(const char *s1, const char *s2)
** {
**	while (n && (*s1 != '\0' || *s2 != '\0'))
**	{
**		if ((*s1 != *s2))
**			return (*(unsigned const char *)s1 - *(unsigned const char *)s2);
**		n--;
**		s1++;
**		s2++;
**	}
**	return (0);
**
** }
*/
/*
** int main (void)
** {
**	char *string1 = "Ttesting this test, but is it a good test";
**	char *string2 = "test";
**	size_t n 	  = 4;
**	printf("%d", strncmp(string1, string2, n));
**	printf("\n%d", ft_strncmp(string1, string2, n));
**	return(0);
** }
*/
