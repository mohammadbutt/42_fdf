/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:04:36 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/20 18:33:36 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description -Allocates (with malloc(3)) and returns a “fresh” substring from
** the string given as argument. The substring begins at indexstart and is of
** size len. If start and len aren’t refering to a valid substring, the
** behavior is undefined. If the allocation fails, the function returns NULL.
** Param#1 - The string from which create the substring.
** Param#2 - The start index of the substring.
** Param#3 - The size of the substring.
** RETURN VALUE - The substring.
** Libc functions - malloc.
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*memory;

	i = 0;
	memory = (char *)malloc(sizeof(char) * (len + 1));
	if (!(memory) || !(s))
		return (NULL);
	while (s[start] && len--)
		memory[i++] = s[start++];
	memory[i] = '\0';
	return (memory);
}
/*
** int main(void)
** {
**	char *string1 = "***DEFGHIJ***KLMN***OPQR***STUVWXYZ";
**	int	 	start = 20;
**	size_t	len	  = 4;
**	char *test;
**	test = ft_strsub(string1, start, len);
**	printf("|%s|\n", test);
**	while(1)
**	{
**	}
**	return(0);
**}
*/
