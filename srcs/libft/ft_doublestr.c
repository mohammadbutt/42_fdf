/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublestr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 23:27:48 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/19 15:59:11 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Creates an array of a string with double pointer.
*/

#include "libft.h"

char	**ft_doublestr(char const *s)
{
	while (*s)
	{
		write(1, s++, 1);
	}
	return (0);
}
/*
**int main (void)
** {
**	char *string1[] = {"Testing", "this", "thing", "to", "see"};
**	char array[4] = ft_doublestr(string1[4]);
**	printf("%s", array[0]);
**	ft_doublestr(string1[2]);
**	return(0);
**}
*/
