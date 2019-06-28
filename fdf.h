/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:23:01 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/27 19:53:18 by mbutt            ###   ########.fr       */
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
typedef struct	s_data
{
	int				ft_return;
	int				wcount;
	int				temp_wcount;
	char			*temp_line;
	char 			*lines;
	char 			*words;
	struct s_data 	*next;
}					t_data;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
}				t_mlx;

/*
** main.c functions
*/
//void	ft_read(int fd, char *argv); Not being used currently
int		ft_valid(int fd, int height, char *argv);
char	**str_data(int fd, int height, char *argv);
int		*ft_rows_columns(char **characters); /*This function might be deleted later*/
int 	**str_to_int(char **characters, int i);

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

/*
** fcc_drawline.c
*/
int		ft_abs(int num);
void	plot_low_line(int x0, int y0, int x1, int y1);
void	plot_high_line(int x0, int y0, int x1, int y1);
void	plot_any_line(int x0, int y0, int x1, int y1);

#endif
