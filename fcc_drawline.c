/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcc_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:46:06 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/26 22:03:47 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Freecodecamp and wikipedia*/
#include <stdio.h>
#include "fdf.h"

/*
** Function drawline_base will be deleted and will not be used in the project
** because it is a barebone prototype
*/

int ft_abs(int num)
{
	if(num < 0)
		num = -1 * num;
	return(num);
}

void drawline_base(int x0, int y0, int x1, int y1)
{
	int dx;
	int dy;
	int d;

	dx = x1 - x0;
	dy = y1 - y0;
	d = (2 * dy) - dx;
	printf("FreeCodeCamp\np:|%d|\n", d);
	while(x0 < x1)
	{
		printf("x:|%d|y:|%d|\n", x0, y0);
		if(d >= 0)
		{
			y0++;
			d = d - (2 * dx); /* (2 * dx) can be optimized*/
		}
		d = d + (2 * dy); /* (2 * dy) can be optimized*/
		x0++;
	}
}

void plot_low_line(int x0, int y0, int x1, int y1)
{
	int dx;
	int dy;
	int d;
	int yi;

	dx = x1 - x0;
	dy = y1 - y0;
	yi = 1;
	if(dy < 0)
	{
		yi = -1;   // Can we do y0--? so in below if statement we can do y0++;?
		dy = -dy;
	}
	d = (2 * dy) - dx;
	while(x0 < x1)
	{
		printf("x:|%d|y:|%d|\n", x0, y0);
		if(d > 0)
		{
			y0 = y0 + yi; //If we change the above, can we change this to y0++;?
			d = d - (2 * dx); /* (2 * dx) can be optimized*/
		}
		d = d + (2 * dy); /*(2 * dy) can be optimized*/
		x0++;
	}
}

void plot_high_line(int x0, int y0, int x1, int y1)
{
	int dx;
	int dy;
	int d;
	int xi;

	dx = x1 - x0;
	dy = y1 - y0;
	xi = 1;
	if(dx < 0)
	{
		xi = -1; // Can we do x0--? so in below if statement we can do x0++;?
		dx = -dx;
	}
	d = (2 * dx) - dy;
	while(y0 < y1)
	{
		printf("x:|%d|y:|%d|\n", x0, y0);
		if(d > 0)
		{
			x0 = x0 + xi;  // If we change the above, can we change it to x0++;?
			d = d - (2 * dy); /* (2 * dy) can be optimized*/
		}
		d = d + (2 * dx); /*(2 * dx) can be optimized*/
		y0++;
	}
}

void plot_any_line(int x0, int y0, int x1, int y1)
{
	if(ft_abs(y1 - y0) < ft_abs(x1 - x0))
	{
		if(x0 > x1)
			plot_low_line(x1, y1, x0, y0);
		else
			plot_low_line(x0, y0, x1, y1);
	}
	else
	{
		if(y0 > y1)
			plot_high_line(x1, y1, x0, y0);
		else
			plot_high_line(x0, y0, x1, y1);
	}
}

/*
int main(void)
{
	int x0, y0, x1, y1;
	printf("Enter coordinates of first point: ");
	scanf("%d%d", &x0, &y0);

	printf("Enter coordinates of second point: ");
	scanf("%d%d", &x1, &y1);
	drawline_base(x0, y0, x1, y1);

	printf("\nprinting from plot_any_line function\n");

	plot_any_line(x0, y0, x1, y1);
	return(0);
}
*/
