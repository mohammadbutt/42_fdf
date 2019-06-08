/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:01:30 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/07 13:50:06 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Sets every character of the string to the value ’\0’.
*/

#include "libft.h"

void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}
/*
** int main (void)
** {
**	char string[0xF00] = "testing";
**	ft_strclr(string);
**	printf("%s", string);
**	return(0);
** }
*/
