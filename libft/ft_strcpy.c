/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 20:42:44 by mbutt             #+#    #+#             */
/*   Updated: 2019/02/23 21:32:27 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The stpcpy() and strcpy() functions copy the string src to dst (including the
** terminating `\0' character.)
** RETURN VALUES: The strcpy() and strncpy() functions return dst.
*/

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
** int main (void)
** {
**	const char source1[] = "This is Source 1";
**	char 		dest1[] = "This is destination1";
**	const char source2[] = "This is Source 2";
**	char		dest2[] = "This is destination2";
**	printf("strcpy: %s\n", strcpy(dest1, source1));
**	printf("ft_strcpy: %s\n", ft_strcpy(dest2, source2));
**	return(0);
** }
*/
