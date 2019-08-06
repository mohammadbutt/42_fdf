/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:23:01 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/06 08:23:08 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//#include "../resources/minilibx_macos/mlx.h"
//#include "./minilibx/mlx.h"
#include "../resources/minilibx_macos/mlx.h"
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

# define ALTITUDE_INCREASE_W 13
# define ALTITUDE_DECREASE_S 1

# define RANDOM_COLOR_R 15
# define RESET_PROGRAM_E 14
# define CHANGE_CAMERA_C 8
# define ESCAPE_ESC 53

# define ROTATE_UP_I 34 
# define ROTATE_LEFT_J 38
# define ROTATE_DOWN_K 40
# define ROTATE_RIGHT_L 37
# define ROTATE_SIDE_U 32
# define ROTATE_SIDE_O 31

/*
** To get isometric and top_down values in below macros, we convert the angle
** to a radian by performing the following calculation:
** isometric radian = 30 * (π/180) --> isometric radian = 0.52;
** top_down radian  = 90 * (𝜋/180) --> top_down radian  = 1.57; 
*/

# define P_WIDTH 1280
# define P_HEIGHT 720
# define XY_ZOOM 0.005
# define Z_ZOOM 0.005

/*
** Structs ---------------------------------------------------------------------
*/


typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;
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
	int			x_shift;
	int			y_shift;
	double 		xy_zoom;
	double		z_zoom;
	double		degree_angle;
	double 		x_axis;
	double 		y_axis;
	double		z_axis;
	double		map_min;
}				t_mlx;

/*
**	bresenham_line_algorithm.c
*/

void	calculate_delta_xy(t_mlx *mlx);
void	plot_low_line(t_mlx *mlx);
void	plot_high_line(t_mlx *mlx);
void	plot_any_line(t_mlx *mlx);

/*
** error_messages.c
*/

void	ft_usage(char *str);
void	ft_exit_dir(char *str);
void	ft_exit(char *str);
void	ft_exit_success(char *str);
void	invalid_file_message(int ft_return, char *argv);

/*
** main_and_solve_driver.c
*/

int		solve_driver1(int fd, int height, char *argv);
int		main(int argc, char **argv);

/*
** menu.c
*/

void	ft_menu1(t_mlx *mlx);
void	ft_menu2(t_mlx *mlx);
void	ft_menu(t_mlx *mlx);


/*
** parse_and_store.c
*/

int		ft_valid(int fd, int height, char *argv);
char	**str_data(int fd, int height, char *argv);
int		*ft_2d_atoi(char *str);
int		**str_to_int(char **characters);

/*
** program_control_events1.c
*/

void	random_color(t_mlx *mlx, int key);
void	zoom_program(t_mlx *mlx, int key);
void	change_altitude(t_mlx *mlx, int key);
void	reset_program(t_mlx *mlx);
void	shift_program(t_mlx *mlx, int key);

/*
** program_control_events2.c
*/

void	change_camera(t_mlx *mlx);
void	rotate_axis(t_mlx *mlx, int key);
int		program_keys(int key, t_mlx *mlx);

/*
** render_map.c
*/

void	ft_render_vertical(t_mlx *mlx, t_mlx *temp);
void	ft_render_horizontal(t_mlx *mlx, t_mlx *temp);
void	ft_render_vertical_horizontal(t_mlx *mlx, t_mlx *temp);
void	ft_render(t_mlx *mlx);

/*
** rotate_matrix1.c
*/

int		ft_normalize(t_mlx *mlx);
double	degree_to_radian(double degrees);
void	rotation_matrix(t_mlx *mlx, int *x, int *y, int z);
void	adjust_zoom(t_mlx *mlx, int normalize);

/*
** rotate_matrix2.c
*/

void	rotate_x_axis(t_mlx *mlx, int *y, int *z, double x_axis);
void	rotate_y_axis(t_mlx *mlx, int *x, int *z, double y_axis);
void	rotate_z_axis(t_mlx *mlx, int *x, int *y, double z_axis);
void	rotate_xyz_axis(t_mlx *mlx);

/*
** rotate_matrix3.c
*/

void	change_projection_view(t_mlx *mlx);
void	shift_and_centeralize_map(t_mlx *mlx);
void	implement_transformations(t_mlx *mlx, int normalize);
void	rotate_vertical_line(t_mlx *mlx, t_mlx *temp);
void	rotate_horizontal_line(t_mlx *mlx, t_mlx *temp);

/*
** utility_functions1.c
*/

int		ft_swap(int *a, int *b);
int		ft_abs(int num);
void	struct_copy(t_mlx *source, t_mlx *dest);
void	get_struct_values(t_mlx *mlx);
void	copy_height_width(t_mlx *mlx, t_mlx *temp);


/*
** utility_functions2.c
*/

int		ft_zero(int *a, int *b, int *c, int *d);
int		ft_height(char **characters);
int		ft_width(char **characters);
void	ft_print_data(t_mlx *mlx);


#endif
