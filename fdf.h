/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:23:01 by mbutt             #+#    #+#             */
/*   Updated: 2019/08/04 14:00:33 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//#include "../resources/minilibx_macos/mlx.h"
//#include "./minilibx/mlx.h"
#include "./resources/minilibx_macos/mlx.h"
#include "libft/libft.h"
#include <math.h>
#include <unistd.h>

/*
** Put structs here
*/
/*
typedef struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
}	t_mlx;

typedef struct s_image
{
	char *get_data;
	int bpp;
	int size_line;
	int endian;
}	t_image;
*/
/*
typedef struct	s_data
{
	int				**coordinates;
	int				ft_return;

	int				wcount;
	int				temp_wcount;
	char			*temp_line;
	char 			*lines;
	char 			*words;
	struct s_data 	*next;
}					t_data;
*/

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

# define ISOMETRIC 0.52
# define TOPDOWN 1.57

//# define XY_ZOOM 0.01
//# define Z_ZOOM 0.01

#define XY_ZOOM 0.005
#define Z_ZOOM 0.005

/*
** Structs ---------------------------------------------------------------------
*/


typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;
	int			size;
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
	double		angle_y;
	double		angle_z;
	double		degree_angle;
	double 		x_axis;
	double 		y_axis;
	double		z_axis;
	double		map_min;
//	int			size;
//	void		*img_ptr; Not using it currently
}				t_mlx;

typedef struct		s_fdf
{
	t_mlx			mlx;
	int				x0;
	int				y0;
	int				z0;
	int				x1;
	int				y1;
	int				z1;
	int				x_move;
	int				y_move;
	int				**int_data_2;
	int				*struct_coordinates;
	int				map_width; /*map_columns*/
	int				map_height; /*map_rows*/
	struct s_fdf	*next;
}					t_fdf;

/*
** linked_list.c ---------------------------------------------------------------
*/

t_fdf	*create(int *struct_coordinates);
t_fdf	*append(t_fdf *head, int *struct_coordinates);
t_fdf	*int_data_to_struct(int **int_data, int height);
int		**str_to_int_struct(char **characters);
void	print_data_coord(t_fdf *struct_pointer, char **characters);

/*
** fdf.c 
*/
//void	ft_read(int fd, char *argv); Not being used currently
int		ft_valid(int fd, int height, char *argv);
char	**str_data(int fd, int height, char *argv);
int		*ft_rows_columns(char **characters); /*This function might be deleted later*/
int		**str_to_int(char **characters);
//int		**str_to_int_struct(char **characters); function is commented.

/*
** maintain1.c functions
*/
void 	ft_usage(char *str);
void 	ft_exit_dir(char *str);
void	ft_exit(char *str);
void	ft_exit_success(char *str);
int		ft_zero(int *a, int *b, int *c, int *d);
int		ft_height(char **characters);
int		ft_width(char **characters);
int		*ft_2d_atoi(char *str);
int 	ft_hue(int y, int color);
void	random_color(t_mlx *mlx, int key);
void	centeralize_with_zoom(t_mlx *mlx, int key);
void	zoom_program(t_mlx *mlx, int key);
void	reset_program(t_mlx *mlx);
void	shift_program(t_mlx *mlx, int key);
//int		program_keys(int key, t_mlx **mlx);
void	iso_projection(t_mlx *mlx);
void	change_camera(t_mlx *mlx);
void	rotate_axis(t_mlx *mlx, int key);
int		program_keys(int key, t_mlx *mlx);
int 	solve_driver1(int fd, int height, char *argv);

/*
** fcc_drawline.c
*/
int		find_min(int x, int y);
int		ft_abs(int num);
void	calculate_delta_xy(t_mlx *mlx);
void	plot_low_line(t_mlx *mlx);
void	plot_high_line(t_mlx *mlx);
void	plot_any_line(t_mlx *mlx);
//void	plot_low_line(t_mlx **mlx);
//void	plot_high_line(t_mlx **mlx);
//void	plot_any_line(t_mlx **mlx);
//void	plot_low_line(t_fdf *fdf, int x0, int y0, int x1, int y1);
//void	plot_high_line(t_fdf * fdf, int x0, int y0, int x1, int y1);
//void	plot_any_line(t_fdf *fdf, int x0, int y0, int x1, int y1);
void	get_struct_values(t_mlx *mlx);
void	isometric_view(int *x, int *y, int z);
void	topdown_view(int *x, int *y, int z);
int		normalize_map(t_fdf *fdf);
void	centeralize_map(t_fdf *fdf, int x, int y);
void	place_z_on_horizontal(t_fdf *fdf, int x, int y, int normalize);
void	place_z_on_vertical(t_fdf *fdf, int x, int y, int normalize);
void	horizontal_x1_y1(t_fdf *fdf);
void	vertical_x1_y1(t_fdf *fdf);
void	horizontal_shift(t_fdf *fdf);
void	horizontal_render(t_fdf *fdf, int x, int y);
void	vertical_render(t_fdf *fdf, int x, int y);
void	ft_dots(t_mlx *mlx);
void	struct_copy(t_mlx *source, t_mlx *dest);
void	get_z_value(t_mlx *mlx, t_mlx *temp);
void	ft_render_vertical(t_mlx *mlx, t_mlx *temp);
void	ft_render_horizontal(t_mlx *mlx, t_mlx *temp);
void	ft_render_vertical_horizontal(t_mlx *mlx, t_mlx *temp);
void	ft_render_edges(t_mlx *mlx, t_mlx *temp);
//void	reset_xy_values(t_mlx *mlx, t_mlx *temp);
void	reset_x0x1(t_mlx *mlx, t_mlx *temp_reset);
void	reset_y0y1(t_mlx *mlx, t_mlx *temp_reset);
void	reset_x0x1_y0y1(t_mlx *mlx, t_mlx *temp_reset);
void	ft_render(t_mlx *mlx);
void	ft_print_data(t_mlx *mlx);

/*
** rotation_matrix.c
*/

int		ft_min(t_mlx *mlx);
double 	degree_to_radian(double degrees);
//void 	rotation_matrix(t_mlx *mlx, int *x, int *y, double degree_angle);
//void	rotation_matrix(t_mlx *mlx, t_mlx *temp, double degree_angle);
void	rotation_matrix(t_mlx *mlx, int *x, int *y, int z);
void	subtract_x0y0_from_x1y1(t_mlx *mlx, t_mlx *temp);
void	add_rotated_x1y1_to_x0y0(t_mlx *mlx);
void	copy_mlx_x0y0x1y1_to_temp_x0y0x1y1(t_mlx *mlx, t_mlx *temp);
void	copy_temp_x0y0x1y1_to_mlx_x0y0x1y1(t_mlx *mlx, t_mlx *temp);
void	rotate_horizontal_line(t_mlx *mlx, t_mlx *temp);
void	rotate_vertical_line(t_mlx *mlx, t_mlx *temp);
void	find_min_x(t_mlx *mlx, t_mlx *temp);
void	find_max_y(t_mlx *mlx, t_mlx *temp);
void	copy_temp_xy_to_mlx_x0y0x1y1(t_mlx *mlx, t_mlx *temp);
void 	rotate_x_axis(t_mlx *mlx, int *y, int *z, double x_axis);
void	rotate_y_axis(t_mlx *mlx, int *x, int *z, double y_axis);
void	rotate_z_axis(t_mlx *mlx, int *x, int *y, double z_axis);

#endif
