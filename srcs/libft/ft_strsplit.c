/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:46:49 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/25 12:31:57 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Allocates (with malloc(3)) and returns an array of “fresh”
** strings (all ending with ’\0’, including the array itself) obtained by
** spliting s using the character c as a delimiter. If the allocation fails the
** function returns NULL.
** Example: ft_strsplit("*hello*fellow***students*", ’*’)
** returns the array ["hello", "fellow", "students"].
** param#1 - The string to split.
** Param#2 - The delimiter character.
** RETURN VALUE - The array of "fresh" string's result of the split.
** malloc, free.
*/

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		len;
	char	**new_s;
	int		a;

	i = 0;
	a = 0;
	if (!s)
		return (NULL);
	if (!(new_s = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	while (i <= ft_endtrim(s, c))
	{
		len = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0' && (len++ >= 0))
			i++;
		if (!(new_s[a] = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		new_s[a] = ft_strsub(s, i - len, len);
		a++;
	}
	new_s[a] = NULL;
	return (new_s);
}
/*
** int main (void)
** {
**	char const string[] = "coucou******testing***this***";
**	char c		= '*';
**	int i		= 0;
**	char **output;
**	output = ft_strsplit(string, c);
**	while(output[i])
**	{
**		printf("%s\n", output[i]);
**		i++;
**	}
**	printf("\n%c",output[0][2]);
**	return(0);
**}
*/
