/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:46:30 by mbutt             #+#    #+#             */
/*   Updated: 2019/02/28 16:24:23 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memchr() function locates the first occurrence of c (converted to an
** unsigned char) in string s.
** RETURN VALUES: The memchr() function returns a pointer to the byte located,
** or NULL if no such byte exists within n bytes.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t count)
{
	unsigned const char			*output;
	int							num;

	output = s;
	num = 0;
	while (count)
	{
		if (*output++ == (unsigned char)c)
		{
			num++;
			break ;
		}
		count--;
	}
	if (num >= 1)
	{
		return (unsigned char*)output - 1;
	}
	else if (num == 0)
	{
		return (NULL);
	}
	return (NULL);
}
/*
** int main (void)
** {
**	char string1[] = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0";
**	char *string2 = string1;
**	unsigned char  c = '\0';
**	size_t count = 100;
**	printf("System memchr: %s\n", memchr(string1, c, count));
**	printf("    My memchr: %s", ft_memchr(string2, c, count));
**	return(0);
** }
*/
