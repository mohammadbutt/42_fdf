/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:23:01 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/29 21:06:33 by mbutt            ###   ########.fr       */
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
typedef struct		s_fdf
{
	int				*struct_coordinates;
	struct s_fdf	*next;
}					t_fdf;

t_fdf	*create(int *struct_coordinates);
t_fdf	*append(t_fdf *head, int *struct_coordinates);
t_fdf	*int_data_to_struct(int **int_data, int height_of_map);
void	print_data_coord(t_fdf *struct_pointer, char **characters);

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
}				t_mlx;

/*
** fdf.c functions
*/
//void	ft_read(int fd, char *argv); Not being used currently
int		ft_valid(int fd, int height, char *argv);
char	**str_data(int fd, int height, char *argv);
int		*ft_rows_columns(char **characters); /*This function might be deleted later*/
int		**str_to_int(char **characters);

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
int 	solve_driver1(int fd, int height, char *argv);

/*
** fcc_drawline.c
*/
int		ft_abs(int num);
void	plot_low_line(int x0, int y0, int x1, int y1);
void	plot_high_line(int x0, int y0, int x1, int y1);
void	plot_any_line(int x0, int y0, int x1, int y1);

#endif
