/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 12:52:49 by mbutt             #+#    #+#             */
/*   Updated: 2019/02/23 21:26:57 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strdup() function allocates sufficient memory for a copy of the string
** s1, does the copy, and returns a pointer to it. The pointer may subsequently
** be used as an argument to the function free(3).
** If insufficient memory is available, NULL is returned and errno is set to
** ENOMEM.
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*string2;
	int			i;

	i = 0;
	string2 = (char*)malloc(1 + ft_strlen(s1));
	if (!string2)
	{
		return (NULL);
	}
	while (s1[i])
	{
		string2[i] = s1[i];
		i++;
	}
	string2[i] = '\0';
	return (string2);
}
/*
** int main (void)
** {
**	const char *string1 = "Test";
**	char *string3;
**	char *string4;
**	string3 = strdup(string1);
**	string4 = ft_strdup(string1);
**	printf("   strdup: %s\n", string3);
**	printf("ft_strdup: %s\n", string4);
**
**	return(0);
**}
*/
