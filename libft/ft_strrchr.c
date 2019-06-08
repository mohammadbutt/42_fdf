/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:11:58 by mbutt             #+#    #+#             */
/*   Updated: 2019/02/28 20:43:27 by mbutt            ###   ########.fr       */
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

char	*ft_strrchr(const char *s, int c)
{
	int num;
	int i;

	num = 0;
	i = 0;
	c = (unsigned char)c;
	if (c == '\0')
	{
		return (ft_strchr(s, c));
	}
	while (s[i])
	{
		(s[i] == c) && num++;
		i++;
	}
	i = 0;
	while (s[i] && num)
	{
		(s[i] == c) && num--;
		i++;
	}
	return (ft_strchr(s + i - 1, c));
}
/*
** int main (void)
** {
**	const char *string1 = "Testing this thing";
**	int c1 = 't';
**	const char *string2 = "Testing this this ";
**	int c2 = 't';
**	printf("%s\n", strrchr(string1, c1));
**	printf("%s", ft_strrchr(string2, c2));
**	return(0);
** }
*/
