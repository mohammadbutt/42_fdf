/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:21:42 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/26 17:52:28 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The atoi() function converts the initial portion of the string pointed to by
** str to int representation.
** It is equivalent to: (int)strtol(str, (char **)NULL, 10);
** While the atoi() function uses the current locale.
*/

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while (ft_isspace(*str) == 1)
		str++;
	while (*str == '-' || *str == '+')
	{
		if ((*str == '+') && (*(str + 1) == '+' || *(str + 1) == '-'))
			break ;
		else if ((*str == '-') && (*(str + 1) == '-' || *(str + 1) == '+'))
			break ;
		else if ((*str == '-') && (ft_isdigit(*(str + 1)) == 1))
			sign = sign - 2;
		str++;
	}
	while (ft_isdigit(*str) == 1)
	{
		if (*str >= '0' && *str <= '9')
			nb = 10 * nb + *str - '0';
		str++;
	}
	return (sign * nb);
}
/*
** int main(void)
** {
**	char *string1_1 = "\t\v\f\r\n \f-06050";
**	char *string1_2 = "\t\v\f\r\n \f- \f\t\n\r    06050";
**	char *string1_3 = "-1234THERE IS A NYANCAT UNDER YOUR BED123";
**	char *string2_1 = "\t\v\f\r\n \f-06050";
**	char *string2_2 = "\t\v\f\r\n \f- \f\t\n\r    06050";
**	char *string2_3 = "-1234THERE IS A NYANCAT UNDER YOUR BED123";
**	char *string1_4 = "\e06050";
**	char *string2_4 = "\e06050";
**	printf("\natoi:		ft_atoi:\n");
**	printf("%d		%d\n", atoi(string1_1), ft_atoi(string2_1));
**	printf("%d		%d\n", atoi(string1_2), ft_atoi(string2_2));
**	printf("%d		%d\n", atoi(string1_3), ft_atoi(string2_3));
**	printf("%d		%d\n", atoi(string1_4), ft_atoi(string2_4));
**	printf("%d		%d\n", atoi("+  2798"), ft_atoi("+  2798"));
**	printf("%d		%d\n", atoi("\n 42 24"), ft_atoi("\n 42 24"));
**	printf("%d		%d\n", atoi("1-2"), ft_atoi("1-2"));
**	printf("%d		%d\n", atoi("   +442"), ft_atoi("   +442"));
**	printf("%d		%d\n", atoi("++876"), ft_atoi("++876"));
**	printf("%d		%d\n", atoi("-+1"), ft_atoi("-+1"));
**	printf("%d		%d\n", atoi("2+2"), ft_atoi("2+2"));
**	printf("%d		%d\n", atoi("4,5"), ft_atoi("4,5"));
**	return(0);
** }
*/
