/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:42:47 by mbutt             #+#    #+#             */
/*   Updated: 2019/07/25 21:31:39 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

double degrees_to_radians(double degrees)
{
	double radians;

	radians = degrees * (M_PI/180);

	return(radians);
}

int main(void)
{
	double x;
	double y;
	double temp_x;
	double temp_y;
	double degrees;
	double radians;

	degrees = 30;
	radians = degrees_to_radians(degrees);

	x = 10;
	y = 0;

	temp_x = (x * cos(radians)) - (y * sin(radians));
	temp_y = (x * sin(radians)) + (y * cos(radians));
	
	x = temp_x;
	y = temp_y;

	printf("x:|%f|, y:|%f|\n", x, y);
}
