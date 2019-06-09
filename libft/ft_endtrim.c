/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:52:34 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/25 12:31:49 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Takes a string with delimiter and removes delimiter from the
** end and gives the index of the last character in the string that is not a
** delimiter
*/

#include "libft.h"

int	ft_endtrim(char const *s, char c)
{
	int b;

	b = ft_strlen(s) - 1;
	while (s[b] == c)
		b--;
	return (b);
}
/*
** int main (void)
** {
**	char *string = "***123********";
**	char c = '*';
**	printf("%d", ft_endtrim(string, c));
** }
*/
