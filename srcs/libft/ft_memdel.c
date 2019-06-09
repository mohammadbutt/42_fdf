/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:05:19 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/10 15:11:16 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Takes as a parameter the address of a memory area that needs to be freed
** with free(3), then puts the pointer to NULL.
** The free() function deallocates the memory allocation pointed to by ptr.
** If ptr is a NULL pointer, no operation is performed.
** Param#1 - A pointer’s address that needs its memory freed and set to NULL.
** RETURN VALUE - NONE
** Libc Function - free
*/

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (ap)
	{
		(free(*ap));
		*ap = NULL;
	}
}
/*
**int main (void)
**{
**	char *string1;
**	char *string2;
**	string1 = (char *) malloc(7);
**	strcpy(string1, "TESTING");
**	printf("%p\n", string1);
**	printf("%s\n\n", string1);
**	ft_memdel((void **)&string1);
**	printf("%p\n", string1);
**	printf("%s\n\n", string1);
**	string2 = (char *) malloc(7);
**	strcpy(string2, "ABCD");
**	printf("%p\n", string2);
**	printf("%s\n", string2);
**	ft_memdel((void **)&string2);
**	add the below while loop to check for memory leaks.
**	After compiling, in a new window type leaks a.out.
**	while(1)
**	{
**	}
**	return(0);
**}
*/
