/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:20:08 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/25 20:28:47 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <graphics.h>

void drawline(int x0, int y0, int x0, int y1)
{
	int dx;
	int dy;
	int p;
	int x;
	int y;

	dx = x1 - x0;
	dy = y1 - y0;

	x = x0;
	y = y0;

	p = 2 *dy-dx;

	while(x < x1)
	{
		if(p >= 0)
		{
			putpixel(x, y, 7);
			y = y + 1;
			p = p+2*dy-2*dx;
		}
		else
		{
			putpixel(x, y, 7);
			p = p+2*dy;
		}
		x = x+1;
	}
}

int main(void)
{
	int gdriver = DETECT, gmode, error, x0, y0, x1, y1;
	initgraph(&gdriver, &gmode, " NOT This is mlx 42 NOT");

	printf("Enter coordinates of first point: ");
	scanf("%d%d", &x0, &y0);

	printf("Enter coordinates of second point:");
	scanf("%d%d", &x1, &y1);
	drawline(x0, y0, x1, y1);

	retrun(0);
}
