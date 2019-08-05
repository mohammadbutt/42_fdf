/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:07:43 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/05 13:14:54 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Counts words broken on the delimiter
*/

#include "libft.h"

int	ft_wordcount(char const *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (count);
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

/*
** int main (void)
** {
**	char string[] 	= " testing   this  string  ";
**	char delimiter 			= ' ';
**	printf("String:|%s|\n", string);
**	printf("Delimiter:|%c|\n", delimiter);
**	printf("Word Count:|%d|\n", ft_wordcount((char *)string, delimiter));
**	return(0);
**}
*/
