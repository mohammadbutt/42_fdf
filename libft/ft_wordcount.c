/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:07:43 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/05 13:01:14 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Counts words broken on the delimiter
*/

#include "libft.h"

int ft_wordcount(char const *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if(str == NULL)
		return(count);
	while(str[i])
	{
//		if(ft_space(str[i]) == 0 && (ft_space(str[i+1]) == 1 || str[i+1] == '\0'))
		if(str[i] != c && (str[i+1] == c || str[i+1] == '\0'))	
			count++;
		i++;
	}
	return(count);
}


/*
int ft_space(char c)
{
	if(c == ' ' || c == '\t' || c == '\n')
		return(1);
	return(0);
}

int ft_wordcount(char const *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if(str == NULL)
		return(count);
	while(str[i])
	{
		if(ft_space(str[i]) == 0 && (ft_space(str[i+1]) == 1 || str[i+1] == '\0'))
			count++;
		i++;
	}
	return(count);
}
*/
/*
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
*/
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
