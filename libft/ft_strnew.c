/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 22:31:44 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/10 15:05:34 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Allocates (with malloc(3)) and returns a “fresh” string ending
** with ’\0’. Each character of the string is initialized at ’\0’. If the
** allocation fails the function returns NULL.)
** Param #1 - The size of the string to be allocated.
** RETURN VALUES - The string allocataed and initialized to 0.
** Libc Functions - mallo(3).
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*memory;

	i = 0;
	memory = (char *)malloc(sizeof(char) * (size + 1));
	if (!(memory))
		return (NULL);
	else
	{
		while (i <= size)
			memory[i++] = 0;
	}
	return (memory);
}
