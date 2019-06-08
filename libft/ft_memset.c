/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:53:57 by mbutt             #+#    #+#             */
/*   Updated: 2019/02/21 11:30:40 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The C library function void *memset(void *str, int c, size_t len) copies the
** character c (an unsigned char) to the first len characters of the string
** pointed to, by the argument str.
**
** Example:
** memset(str,'$',7)
**
** This is string.h library function
** $$$$$$$ string.h library function
*/
#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	char	*string;
	size_t	num;

	string = str;
	num = 0;
	while (num < len)
	{
		string[num] = c;
		num++;
	}
	return (str);
}

/*
** int main (void)
** {
**	char str[] = "Test";
** 	printf("%s",(ft_memset(str, '#', 2)));
** 	return(0);
** }
*/
