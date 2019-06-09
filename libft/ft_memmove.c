/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:54:18 by mbutt             #+#    #+#             */
/*   Updated: 2019/02/20 12:22:49 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memmove() function copies len bytes from string src to string dst.
** The two strings may overlap; the copy is always done in a non-destructive
** manner.
** RETURN VALUES: The memmove() function returns the original value of dst.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*destination;
	const char	*source;
	size_t		num;

	destination = dst;
	source = src;
	if (destination > source)
	{
		num = len;
		while (num > 0)
		{
			destination[num - 1] = source[num - 1];
			num--;
		}
	}
	else if (destination < source)
	{
		ft_memcpy(destination, source, len);
	}
	return (dst);
}
/*
** int main (void)
** {
**	char		destination1[] = "Stackoverflowxy";
**	char		*source1, *source2, *source3, *destination2, *destination3;
**	size_t		len = 10;
**
**	source1 = destination1;
**	source2 = destination1;
**	destination2 = destination1;
**	source3 = destination1;
**	destination3 = destination1;
**
**	printf("\nmemcpy:\n");
**	printf("%s\n",(memcpy(destination1+5, NULL, len)));
**	printf("%s\n", destination1);
**
**	printf("\nmemmove:\n");
**	printf("%s\n", (memmove(destination2+5, NULL, len)));
**	printf("%s\n", destination2);
**
**	printf("\nMy memove:\n");
**	printf("%s\n", (ft_memmove(destination3+5, NULL, len)));
**	printf("%s\n\n", destination3);
**	return(0);
** }
*/
