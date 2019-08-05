/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:56:36 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/25 12:35:17 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Seperates words at the delimiter and prints the last word in
** in the string without the delimiter.
** Libc function: ft_strsub
*/

#include "libft.h"

char		*ft_words(char const *s, char c)
{
	int		i;
	int		b;
	size_t	len;
	char	*new_string;

	i = 0;
	b = ft_endtrim(s, c);
	while (i < b - 1)
	{
		len = 0;
		while (s[i] == c && s[i] != '\0')
		{
			i++;
		}
		while (s[i] != c && s[i] != '\0')
		{
			len++;
			i++;
		}
		new_string = (char *)malloc(sizeof(char) * (len + 1));
		new_string = ft_strsub(s, i - len, len);
		printf("%s\n", new_string);
	}
	new_string[i] = '\0';
	return (new_string);
}
/*
** int main (void)
** {
**	char *string = "***Testing***this***thing***now*******";
**	char c = '*';
**	char *string1 = ft_words(string,c);
**	printf("%s", string1);
**	return(0);
** }
*/
