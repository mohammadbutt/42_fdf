/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:33:21 by mbutt             #+#    #+#             */
/*   Updated: 2019/02/18 19:43:10 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memccpy() function copies bytes from string src to string dst.  If the
** character c (as converted to an unsigned char) occurs in the string src, the
** copy stops and a pointer to the byte after the copy of c in the string dst
** is returned.  Otherwise, n bytes are copied, and a NULL pointer is returned.
** The source and destination strings should not overlap, as the behavior is
** undefined.
*/
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*destination;
	const char		*source;

	destination = dst;
	source = src;
	while (n)
	{
		if ((*destination++ = *source++) == (char)c)
		{
			return (destination);
		}
		n--;
	}
	return (NULL);
}
/*
**	int main(void)
**	{
**	char destination1[]= "1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15";
**	const char source1[] = "Taj Mahal is a historic monument in India.";
**	char destination2[]= "1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15";
**	const char source2[] = "Taj Mahal is a historic monument in India.";
**	unsigned char c = 'c';
**	int n = 24;
**	printf("\nSystem:");
**	printf("\nc= %c, n= %d, output= %s\n", c,
**	n, (memccpy(destination1, source1, c, n)));
**	printf("%s\n\n", destination1);
**	printf("Mine:");
**	printf("\nc= %c, n= %d, output= %s\n", c,
**	n, (ft_memccpy(destination2, source2, c, n)));
**	printf("%s\n\n", destination2);
**	return(0);
**	}
*/
