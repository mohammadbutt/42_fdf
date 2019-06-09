/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:54:28 by mbutt             #+#    #+#             */
/*   Updated: 2019/02/25 22:12:54 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memcmp() function compares byte string s1 against byte string s2. Both
** strings are assumed to be n bytes long.
** RETURN VALUES: The memcmp() function returns zero if the two strings are
** identical, otherwise returns the difference between the first two differing
** bytes (treated as unsigned char values, so that `\200' is greater than `\0',
** for example). Zero-length strings are always identical.  This behavior is
** not required by C and portable code should only depend on the sign of the
** returned value.
*/

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*string1;
	unsigned const char	*string2;

	string1 = s1;
	string2 = s2;
	while (n > 0)
	{
		if (*string1 != *string2)
		{
			return (*string1 - *string2);
		}
		string1++;
		string2++;
		n--;
	}
	return (0);
}
/*
** int main (void)
** {
**	const char *string1 = "\xff\xaa\xde\x12\xff";
**	const char *string2 = "\xff\xaa\xde\x12\xffOSAAAAA";
**	size_t n	   = 6;
**
**	printf("\nstring1:%s\nstring2:%s\n      n:%zu", string1, string2, n);
**	printf("\n\n   memcmp: %d", memcmp(string1, string2, n));
**	printf("\nft_memcmp: %d\n\n", ft_memcmp(string1, string2, n));
**	return(0);
**
** }
*/
