/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:00:45 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/14 15:46:06 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strchr() function locates the first occurrence of c (converted to a char)
** in the string pointed to by s. The terminating null character is considered
** to be part of the string; therefore if c is `\0', the functions locate the
** terminating `\0'.
** The strrchr() function is identical to strchr(), except it locates the last
** occurrence of c.
** RETURN VALUES: The functions strchr() and strrchr() return a pointer to the
** located character, or NULL if the character does not appear in the string.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}
/*
** int main (void)
** {
**	const char *string1 = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng";
**	int c1 = '\0';
**	const char *string2 = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng";
**	int c2 = '\0';
**	const char *string3 = "This is a test.";
**	int c3 = ' ';
**	printf("%s\n", strchr(string1, c1));
**	printf("%s\n", ft_strchr(string2, c2));
**	printf("%s", ft_strchr(string3, c3));
**	return(0);
**}
*/
