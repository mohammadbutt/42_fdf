/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:13:16 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/24 11:07:26 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” memory area. The memory
** allocated is initialized to 0. If the alloca- tion fails the function
** returns NULL.
** The malloc() function allocates size bytes of memory and returns a pointer
** to the allocated memory.
** Param # 1 - The size of the memory that needs to be allocated.
** RETURN VALUE: The allocated memory area.
** Libc functions: malloc(3)
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*memory;
	size_t			i;

	i = 0;
	memory = (unsigned char *)malloc(sizeof(unsigned char) * (size));
	if ((!(memory)) || size > MAX_SIZE_T)
		return (NULL);
	else
	{
		while (i <= size)
			memory[i++] = 0;
	}
	return (memory);
}
/*
** int main (void)
** {
**	char *string1;
**	char *string2;
**	string1 = (char*) malloc(7+1);
**	string2 = (char *) ft_memalloc(7+1);
**	strcpy(string1, "iuiuiu");
**	strcpy(string2, "iiuiuiu");
**	printf("%s", string2);
**	printf("\n");
**	printf("%s\n", string1);
**	free(string1);
**	free(string2);
**	while(1)
**	{
**	}
**	return(0);
** }
*/
