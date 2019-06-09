/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:03:23 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/21 09:52:03 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Allocates (with malloc(3)) and returns a “fresh” string ending
** with ’\0’, result of the concatenation of s1 and s2. If the allocation fails
** the function returns NULL.
** Param#1 - The prefix string.
** Param#2 - The suffix string.
** RETURN VALUE - "Fresh" string result of the concatenation of the 2 strings.
** Libc functions - malloc.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i1;
	int		i2;
	char	*new_string;
	int		s1_len;
	int		s2_len;

	i1 = 0;
	i2 = 0;
	if (!(s1) || !(s2))
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_string = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new_string)
		return (NULL);
	while (s1[i1])
	{
		new_string[i1] = s1[i1];
		i1++;
	}
	while (s2[i2])
		new_string[i1++] = s2[i2++];
	new_string[i1] = '\0';
	return (new_string);
}
/*
** int main (void)
** {
**	char *string1 = "-";
**	char *string2 = "negative test";
**	printf("%s", ft_strjoin(string1, string2));
**	printf("%s", ft_strjoin("-", string2));
**}
*/
