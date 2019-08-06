/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:08:38 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/19 15:23:02 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strlen() function computes the length of the string s.
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	num;

	num = 0;
	while (s[num])
	{
		num++;
	}
	return (num);
}
/*
** int main(void)
** {
**	char string[] = "Testing";
**	printf("%zu", ft_strlen(string));
**	return(0);
** }
*/
