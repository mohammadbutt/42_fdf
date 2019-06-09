/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 20:28:38 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/17 18:14:59 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Allocates (with malloc(3)) and returns a copy of the string
** given as argument without whitespaces at the beginning or at the end of the
** string. Will be considered as whitespaces the following characters ’ ’, ’\n’
** and ’\t’. If s has no whitespaces at the beginning or at the end, the
** function returns a copy of s. If the allocation fails the function returns
** NULL.
** Param#1 - The string to be trimed.
** Param#2 - "Fresh" trimmed string ot a copy of s.
** Libc functions - malloc.
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*string;
	int		i1;
	int		i2;
	int		b;

	i1 = 0;
	i2 = 0;
	if (!s)
		return (NULL);
	b = ft_strlen(s) - 1;
	while (s[i1] == ' ' || s[i1] == '\n' || s[i1] == '\t')
		i1++;
	while ((s[i1] != '\0') && (s[b] == ' ' || s[b] == '\n' || s[b] == '\t'))
		b--;
	string = (char *)malloc(sizeof(char) * (b - i1 + 1 + 1));
	if ((!string))
		return (NULL);
	while (i1 <= b)
	{
		string[i2] = s[i1];
		i1++;
		i2++;
	}
	string[i2] = '\0';
	return (string);
}
/*
** int main (void)
** {
**char *s1 = "   \t  \n\n   \nHello \t  Please\n Trim me !\n   \n \t\t  ";
**char *s2 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !";
**char *s3 = "Hello \t  Please\n Trim me !";
**char *s4 = "\t \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  \t\t  ";
**char *s5 = "\n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n \n\t\t\n  ";
**char *s6 = "  \t \t \n   \n\n\n\t";
**char *s7 = "\t\t \n\n ";
**printf("1. |%s|\n\n", ft_strtrim(s1));
**printf("2. |%s|\n\n", ft_strtrim(s2));
**printf("3. |%s|\n\n", ft_strtrim(s3));
**printf("4. |%s|\n\n", ft_strtrim(s4));
**printf("5. |%s|\n\n", ft_strtrim(s5));
**printf("6. |%s|\n\n", ft_strtrim(s6));
**printf("7. |%s|\n\n", ft_strtrim(s7));
** }
*/
