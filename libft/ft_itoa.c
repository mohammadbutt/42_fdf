/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 20:09:36 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/21 15:23:44 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Allocate (with malloc(3)) and returns a “fresh” string ending
** with ’\0’ representing the integer n given as argument. Negative numbers must
** be supported. If the allocation fails, the function returns NULL.
** Param#1 - The integer to be transformed into a string.
** RETURN VALUE - The string representing the integer passed as argument.
** Libc functions - malloc (3)
*/

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*string1;
	int		sign;

	i = 0;
	sign = 0;
	len = ft_numlen(n);
	if (!(string1 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == FT_INT_MIN)
		return (ft_strdup("-2147483648"));
	((n < 0) && --sign) && (n = -1 * n);
	while (i < (len + sign))
	{
		string1[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	string1[i] = '\0';
	if (sign == -1)
		return (ft_strjoin("-", ft_strrev(string1)));
	else
		return (ft_strrev(string1));
}
/*
**int main (void)
**{
**	int num1 = 2147483647;
**	int num2 = -2147483648;
**	int num3 = 34879;
**	int num4 = -987456;
**	char *i1 = ft_itoa(-623);
**	char *i2 = ft_itoa(156);
**	char *i3 = ft_itoa(-0);
**	char *i5 = ft_itoa((-2147483647 -1));
**	int num5 = -0;
**	printf("%s\n%c\n\n", ft_itoa(num1), ft_itoa(num1)[0]);
**	printf("%s\n%c\n\n", ft_itoa(num2), ft_itoa(num2)[0]);
**	printf("%s\n%c\n\n", ft_itoa(num3), ft_itoa(num3)[0]);
**	printf("%s\n%c\n\n", ft_itoa(num4), ft_itoa(num4)[0]);
**	printf("%d\n", ft_strcmp(i1, "-623"));
**	printf("%d\n", ft_strcmp(i2, "156"));
**	printf("%d\n", ft_strcmp(i3, "-0"));
**	printf("%s\n", i5);
**	printf("%s", ft_itoa(num5));
**}
*/
