/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 21:26:23 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/04 20:45:09 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strcat() and strncat() functions append a copy of the null-terminated
** string s2 to the end of the null-terminated string s1, then add a terminating
** `\0'.  The string s1 must have sufficient space to hold the result.
** The strncat() function appends not more than n characters from s2, and then
** adds a terminating `\0'.
** The source and destination strings should not overlap, as the behavior is
** undefined.
** RETURN VALUES: The strcat() and strncat() functions return the pointer s1.
*/

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (s1[i])
	{
		i++;
	}
	while (n)
	{
		if (s2[num] != '\0')
		{
			s1[i] = s2[num];
			i++;
			num++;
		}
		n--;
	}
	s1[i] = '\0';
	return (s1);
}
/*
** int main (void)
** {
**	const char source1[] = "These";
**	char dst1[7] = "abc";
**	size_t n 		= 0;
**	printf("	 strncat:|%s|", strncat(dst1, source1, n));
**	printf("\nft_strncat:|%s|", ft_strncat(dst1, source1, n));
**	return(0);
** }
*/
