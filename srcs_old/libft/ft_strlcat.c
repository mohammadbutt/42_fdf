/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:23:01 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/30 14:38:11 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strlcpy() and strlcat() functions copy and concatenate strings with the
** same input parameters and output result as snprintf(3). They are designed to
** be safer, more consistent, and less error prone replacements for the easily
** misused functions strncpy(3) and strncat(3).
** strlcpy() and strlcat() take the full size of the destination buffer and
** guarantee NUL-termination if there is room.
** Note that room for the NUL should be included in dstsize.
** strlcat() appends string src to the end of dst.  It will append at most
** dstsize - strlen(dst) - 1 characters. It will then NUL-terminate, unless
** dstsize is 0 or the original dst string was longer than dstsize (in practice
** this should not happen as it means that either dstsize is incorrect or that
** dst is not a proper string).
** If the src and dst strings overlap, the behavior is undefined.
** RETURN VALUES: Like snprintf(3), the strlcpy() and strlcat() functions return
** the total length of the string they tried to create. For strlcpy() that means
** the length of src. For strlcat() that means the initial length of dst plus
** the length of src.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		counter;
	int		d_i;
	int		s_i;
	int		len;

	d_i = 0;
	s_i = 0;
	len = dstsize - ft_strlen(dst);
	counter = ft_strlen(src);
	while (dstsize)
	{
		(dstsize <= ft_strlen(dst)) && counter++;
		dstsize--;
	}
	while (dst[d_i])
		d_i++;
	while (len-- > 1)
		dst[d_i++] = src[s_i++];
	dst[d_i] = '\0';
	return (counter);
}
/*
**int main (void)
**{
**	const char source1[] = "DEFGHI";
**	char dst1[0XF00] = "AB";
**	size_t  dstsize1 = 10;
**	const char source2[] = "DEFGHI";
**	char dst2[0XF00] = "AB";
**	size_t  dstsize2 = 10;
**	printf("Before strlcat:\n");
**	printf("              dstsize1:|%zu|\n", dstsize1);
**	printf("               source1:|%s|\n", source1);
**	printf("                  dst1:|%s|\n", dst1);
**	printf(" After strlcat:\n");
**	printf("               strlcat:|%lu|\n", strlcat(dst1, source1,
**	dstsize1));
**	printf("                  dst1:|%s|\n",dst1);
**	printf("Before ft_strlcat:\n");
**	printf("              dstsize2:|%zu|\n", dstsize2);
**	printf("               source2:|%s|\n", source2);
**	printf("                  dst2:|%s|\n", dst2);
**	printf(" After ft_strlcat:\n");
**	printf("               ft_strlcat:|%lu|\n", ft_strlcat(dst2, source2,
**	dstsize2));
**	printf("                  dst2:|%s|\n",dst2);
**	return(0);
**}
*/
