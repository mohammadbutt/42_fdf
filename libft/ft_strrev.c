/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 22:15:17 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/21 19:17:17 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Takes a string and reverses it.
** RETURN VALUE - Reverse string ending with a null terminator
*/

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		len;
	char	*string2;

	i = 0;
	len = ft_strlen(s);
	string2 = (char *)malloc(sizeof(char) * (len + 1));
	while (len--)
		string2[i++] = s[len];
	string2[i] = '\0';
	return (string2);
}
/*
** int main (void)
**{
**	char string1[] = "ABCD EFGH ijkl";
**	printf("%s", ft_strrev(string1));
**}
*/
