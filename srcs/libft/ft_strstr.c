/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 20:56:57 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/04 12:56:47 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strstr() function locates the first occurrence of the null-terminated
** string needle in the null-terminated string haystack.
** RETURN VALUES: If needle is an empty string, haystack is returned; if needle
** occurs nowhere in haystack, NULL is returned; otherwise a pointer to the
** first character of the first occurrence of needle is returned.
*/

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	i = 0;
	if ((ft_strlen(haystack) < 1) && (ft_strlen(needle) < 1))
	{
		return ((char *)haystack);
	}
	else
	{
		while (haystack[i])
		{
			if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
			{
				return ((char *)haystack + i);
			}
			i++;
		}
	}
	return (NULL);
}
/*
** int main(void)
** {
**	const char *string1_1 = "";
**	const char *string1_2 = ""; // Takes string instead of character
**	const char *string2_1 = "";
**	const char *string2_2 = "";
**	printf("\nstring1_1:|%s|", string1_1);
**	printf("\nstring2_1:|%s|", string2_1);
**	printf("\nstring1_2:|%s|", string1_2);
**	printf("\nstring2_2:|%s|", string2_2);
**	printf("\n\n   strstr:|%s|", strstr(string1_1, string1_2));
**	printf("\nft_strstr:|%s|", ft_strstr(string2_1, string2_2));
**	return(0);
**}
*/
