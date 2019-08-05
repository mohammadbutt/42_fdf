/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:50:03 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/26 18:29:29 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function f to each character of the string passed as argument.
** Each character is passed by address to f to be modified if necessary.
** Param # 1 - The string to iterate
** Param # 2 - The function to apply to each character of s.
** Return VALUE - None
** Libc functions - None.
*/

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	if (s && f)
		while (s[i])
		{
			f(s + i);
			i++;
		}
}
/*
**Different ways to write the while loop
** By using a pointer
**	while(*s)
**	{
**		f(&*s);
**		s++;
**		f(&*s++);// above two lines can be replaced by this one line.
**	}
** By using an index
**	while (s[i])
** 	{
**		f(&s[i]);
**		i++;
**		f(&s[i++]);// above two lines can be replaced by this one line.
**	}
** By using an index
**	while (s[i])
** 	{
**		f(s + i);
**		i++;
**		f(s+(i++));// above two lines can be replaced by this one line.
**	}
*/
/*
**void f_striter(char *s)
**	{
**		*s = 'F';
**	}
**int main (void)
**{
**	char string1[] = "THIS IS A TEST";
**	ft_striter(string1, f_striter);
**	printf("%s", string1);
**	return(0);
**}
*/
