/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:08:01 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/12 15:10:45 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strcmp() and strncmp() functions lexicographically compare the
** null-terminated strings s1 and s2.
** RETURN VALUES: The strcmp() and strncmp() functions return an integer greater
** than, equal to, or less than 0, according as the string s1 is greater than,
** equal to, or less than the string s2.  The comparison is done using unsigned
** characters, so that `\200' is greater than `\0'.
*/

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned const char)s1[i] - (unsigned const char)s2[i]);
		i++;
	}
	return (0);
}
/*
** Method 2 by using pointers
** int ft_strcmp(const char *s1, const char *s2)
** {
**	 while (*s1 || *s2)
**	{
**		if (*s1 != *s2)
**		{
**			return (*(unsigned const char *)s1 - *(unsigned const char *)s2);
**		}
**		s1++;
**		s2++;
**	}
**	return (0);
** }
*/
/*
** int main (void)
** {
**	char *string1 = "Test";
**	char *string2 = "ABCD";
**	printf("%d", strcmp(string1, string2));
**	printf("\n%d", ft_strcmp(string1, string2));
**	return(0);
** }
*/
