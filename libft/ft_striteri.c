/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 11:42:09 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/26 18:53:24 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function f to each character of the string passed as argument,
** and passing its index as first argument. Each character is passed by address
** to f to be modified if necessary.
** Param #1 - The string to iterate.
** Param #2 - The function to apply to each character of s and its index.
** RETURN VALUE - NONE
** Libc function - NONE
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;

	i = 0;
	if (s && f)
		while (s[i])
		{
			f(i, (s + i));
			i++;
		}
}
/*
** Different ways to write the while loop.
** By using an index.
**	while(s[i])
**	{
**		f(i, &s[i]);
**		i++;
**	}
** By using a pointer.
** 	while(*s)
** 	{
**		f(i, s);
**		s++;
**		i++;
**	}
*/
/*
** Function with in a function - Formal parameter
*/
/*
** void z_striteri(unsigned int i, char *s)
** {
**	*s = i + 48;
** }
** int main (void)
** {
**	char string1[] = "Testing this thing now and see what it does.";
**	ft_striteri(string1, z_striteri);
**	printf("%s", string1);
**	return(0);
**	}
*/
