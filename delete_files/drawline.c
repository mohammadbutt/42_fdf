/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:20:08 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/26 20:30:16 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
//#include <graphics.h>


void drawline(int x0, int y0, int x1, int y1)
{
	int dx;
	int dy;
	int p;

	dx = x1 - x0;
	dy = y1 - y0;
	p = (2 * dy) - dx;
	printf("thecrazyprogrammer\np:|%d|\n", p);
	while(x0 < x1)
	{
		printf("x:|%d|y:|%d|\n", x0, y0);
		if(p >= 0)
		{
			y0++;
			p = p + (2 * dy) - (2 * dx);
		}
		else
			p = p + (2 * dy);
		x0++;
	}
}

/*
void drawline(double x0, double y0, double x1, double y1)
{
	double x;
	double y;
	double dx;
	double dy;
	double uvector;

	y = y0;
	x = x0;
	dy = y1 - y0;
	dx = x1 - x0;
	uvector = sqrt((pow(dy, 2)) + (pow(dx, 2)));
	dy = dy/uvector;
	dx = dx/uvector;
	while(uvector > 0)
	{
		printf("x:|%f|\n",x);
		printf("y:|%f|\n\n", y);
		y = dy + y;
		x = dx + x;
		uvector--;
	}
}
*/
int main(void)
{
	int x0, y0, x1, y1;
	printf("Enter coordinates of first point: ");
	scanf("%d%d", &x0, &y0);

	printf("Enter coordinates of second point:");
	scanf("%d%d", &x1, &y1);
	drawline(x0, y0, x1, y1);

	return(0);
}
