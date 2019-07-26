/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:31:38 by mbutt             #+#    #+#             */
/*   Updated: 2019/07/25 15:56:56 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SQUARE_TEST_H
# define SQUARE_TEST_H

#include "./resources/minilibx_macos/mlx.h"
#include "libft/libft.h"
#include <math.h>
#include <unistd.h>

/*
** Macros ----------------------------------------------------------------------
*/

/*
** Key-Bindings: Below are the key codes to navigate the program
*/

# define UP_K 126
# define DOWN_K 125
# define LEFT_K 123
# define RIGHT_K 124

# define ZOOM_IN_Q 12
# define ZOOM_OUT_A 0

# define SPIKE_INCREASE_W 13
# define SPIKE_DECREASE_S 1

# define RANDOM_COLOR_R 15
# define RESET_PROGRAM_E 14
# define CHANGE_CAMERA_C 8
# define ESCAPE_ESC 53


# define P_WIDTH 1280
# define P_HEIGHT 720

# define ISOMETRIC 0.52
# define TOPDOWN 1.57

# define XY_ZOOM 0.25
# define Z_ZOOM 0.25

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	double		ro_x;
	double		ro_y;
	double		x;
	double		y;
//	int			size;
	double		size;
	size_t		color;
	int			x0;
	int			y0;
	int			z0;
	int			x1;
	int			y1;
	int			z1;
	int			dx;
	int			dy;
	int			delta_error;
	int			xi;
	int			yi;
	int			**int_data;
	int			map_width;
	int			map_height;
	int			camera;
	double		angle_y;
	double		angle_z;
//	int			size;
//	void		*img_ptr; Not using it currently
}				t_mlx;

int ft_swap(int *a, int *b);
int ft_abs(int num);
void calculate_dx_dy(t_mlx **mlx);
void plot_low_line(t_mlx **mlx);
void plot_high_line(t_mlx **mlx);
void plot_any_line(t_mlx **mlx);
void menu(t_mlx **mlx);
int ft_hue(int y, int color);
void draw_square(t_mlx **mlx, int x, int y, int size);
void diagonal_line(t_mlx **mlx, int x0, int y0, int size);
void draw_cube(t_mlx **mlx, int x, int y, int size);
void draw_horizontal_line(t_mlx **mlx, int x, int y, int size);
void shift_program(t_mlx **mlx, int key);
void zoom_program(t_mlx **mlx, int key);
void random_color(t_mlx **mlx);
void get_struct_values(t_mlx **mlx);
void top_horizontal(t_mlx **mlx);
void right_vertical(t_mlx **mlx);
void bottom_horizontal(t_mlx **mlx);
void left_vertical(t_mlx **mlx);
void right_top_diagonal(t_mlx **mlx);
void right_bottom_diagonal(t_mlx **mlx);
void left_top_diagonal(t_mlx **mlx);
void left_bottom_diagonal(t_mlx **mlx);
void ft_diamond(t_mlx **mlx);
void reset_program(t_mlx **mlx, int key);
int program_keys(int key, t_mlx **mlx);

#endif
