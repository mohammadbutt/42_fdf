/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 22:57:05 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/11 23:12:11 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Applies the function f to each character of the string passed
** as argument by giving its index as first argument to create a “fresh” new
** string (with malloc(3)) resulting from the suc- cessive applications of f.
** Param #1 - The string to map.
** Param #2 - The function to applt to each character of and its index.
** RETURN VALUE - "Fresh" string created from the successive application of f.
** Libc functions - malloc
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		memory[i] = f(i, s[i]);
		i++;
	}
	memory[i] = '\0';
	return (memory);
}
