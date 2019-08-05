/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:19:34 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/25 18:15:49 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  The strstr() function locates the first occurrence of the null-terminated
** string needle in the null-terminated string haystack.
** The strnstr() function locates the first occurrence of the null-terminated
** string needle in the string haystack, where not more than len characters are
** searched. Characters that appear after a `\0' character are not searched.
** RETURN VALUES: If needle is an empty string, haystack is returned; if needle
** occurs nowhere in haystack, NULL is returned; otherwise a pointer to the
** first character of the first occurrence of needle is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	haystack_len;
	size_t	needle_len;

	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	i = 0;
	if (len > haystack_len && (needle_len > haystack_len))
		return (NULL);
	else if (haystack_len < 1 && needle_len < 1)
		return ((char *)haystack);
	else
	{
		while (len >= needle_len)
		{
			if (ft_strncmp(haystack + i, needle, needle_len) == 0)
				return ((char *)haystack + i);
			i++;
			len--;
		}
	}
	return (NULL);
}
/*
** int main (void)
** {
**	char *string1 = "123456789";
**	char *string2 = "123";
**	size_t max = 9;
**	char buf[10];
**	bzero(buf, 10);
**	strcpy(buf, "un deux 9");
**	printf("   strnstr:|%s|\n", strnstr(string1, string2, max));
**	printf("ft_strnstr:|%s|\n", ft_strnstr(string1, string2, max));
**	printf("\n\n");
**	printf("   strnstr:|%s|\n", strnstr(buf, "deux", 10));
**	printf("ft_strnstr:|%s|\n\n", ft_strnstr(buf, "deux", 10));
**	printf("After buf[9] = '6' and buf[1] = 0\n");
**	printf("buff[9] = '6' writes onto the null terminator\n");
**	printf("buff[1] = 0 is equal to null on Ascii table\n\n");
**	buf[9] = '6';
**	buf[1] = 0;
**	printf("   strnstr:|%s|\n", strnstr(buf, "deux", 10));
**	printf("ft_strnstr:|%s|\n", ft_strnstr(buf, "deux", 10));
**	return(0);
** }
*/
