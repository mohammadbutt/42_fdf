/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 20:12:08 by mbutt             #+#    #+#             */
/*   Updated: 2019/02/24 21:10:23 by mbutt            ###   ########.fr       */
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

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (s1[i])
	{
		i++;
	}
	while (s2[num])
	{
		s1[i] = s2[num];
		num++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
/*
** int main (void)
** {
**	const char 	string2[] = "Testing";
**	char 		string1[20] = "This is a ";
**
**	printf("strcat: %s", strcat(string1, string2));
**	printf("\nft_strcat: %s", ft_strcat(string1, string2));
**	return(0);
** }
*/
