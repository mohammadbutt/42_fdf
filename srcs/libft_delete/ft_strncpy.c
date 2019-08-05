/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:48:12 by mbutt             #+#    #+#             */
/*   Updated: 2019/02/24 17:27:19 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The stpncpy() and strncpy() functions copy at most len characters from src
** into dst. If src is less than len characters long, the remainder of dst is
** filled with `\0' characters.  Otherwise, dst is not terminated.
** RETURN VALUES: The strcpy() and strncpy() functions return dst.
*/

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;

	i = 0;
	while (len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	while (len)
	{
		dst[i] = 0;
		i++;
		len--;
	}
	return (dst);
}
/*
** int main (void)
** {
**	char  *source1 = "stars";
**	char 	dest1[50];
**	char 	dest2[50];
**	size_t 		n1     	= 50;
**	printf("   strncpy: %s", strncpy(dest1, source1, n1));
**	printf("\nft_strncpy: %s", ft_strncpy(dest2, source1, n1));
**	return(0);
** }
*/
