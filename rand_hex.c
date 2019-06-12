/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:57:14 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/11 16:34:02 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*
int rand_hex(int x)
{
	x = rand() & 0xff;
	x |= (rand() & 0xff) << 8;
	x |= (rand() & 0xff) << 16;
	x |= (rand() & 0xff) << 24;
	return(x);
}

int main(void)
{
	printf("%d\n", rand_hex(1));
}
*/
int main(void)
{
	unsigned short x;

	x = arc4random() & 0xff;
	x |= (arc4random() & 0xff) << 8;
	x |= (arc4random() & 0xff) << 16;
	x |= (arc4random() & 0xff) << 24;
	printf("%d\n", x);
}

