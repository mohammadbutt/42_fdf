/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:01:07 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/12 13:40:19 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Decription - Applies the function f to each character of the string given as
** argument to create a “fresh” new string (with malloc(3)) resulting from the
** successive applications of f.
** Param #1 - The string to map.
** Param #2 - The function to apply to each character of s.
** RETURN VALUE - "Fresh" string created from the successive applications of f.
** Libc function - malloc.
*/

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*memory;
	size_t	s_len;

	i = 0;
	if (!(s))
		return (NULL);
	s_len = ft_strlen(s);
	memory = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!(memory))
		return (NULL);
	while (s[i])
	{
		memory[i] = f(s[i]);
		i++;
	}
	memory[i] = '\0';
	return (memory);
}
