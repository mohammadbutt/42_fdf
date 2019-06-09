/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:07:43 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/18 14:46:12 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Counts words broken on the delimiter
*/

#include "libft.h"

int		ft_wordcount(char const *s, char c)
{
	int	i;
	int	b;
	int	num;
	int	s_len;

	i = 0;
	num = 0;
	s_len = ft_strlen(s);
	b = ft_strlen(s) - 1;
	while (s[i] == c)
		i++;
	while (s[i] != '\0' && s[b] == c)
		b--;
	if (s_len == 0 || s[i] == '\0')
		return (num);
	num++;
	while (i++ < b)
		((s[i] == c) && (s[i + 1] != c)) && num++;
	return (num);
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
