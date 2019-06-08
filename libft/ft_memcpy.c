/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:59:14 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/14 14:43:57 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memcpy() function copies n bytes from memory area src to memory area dst.
** If dst and src overlap, behavior is undefined. Applications in which dst and
** src might overlap should use memmove(3) instead.
**
** Return Values - The memcpy() function returns the original value of dst.
*/
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*destination;
	const char	*source;
	size_t		num;

	destination = dst;
	source = src;
	num = 0;
	while (n)
	{
		destination[num] = source[num];
		num++;
		n--;
	}
	return (dst);
}

/*
** int main(void)
** {
**	char destination[] = "abcd";
**	const char source[] = "12345";
**	int n = 3;
**	printf("%s", ft_memcpy(destination, source, n));
**	return(0);
**}
*/
