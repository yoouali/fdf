/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:17:47 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/22 22:08:59 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./gnl/get_next_line.h"
# include <fcntl.h>
# include "./minilibx_macos/mlx.h"
# include <math.h>
# define WIDTH	2000//1280
# define HEIGTH	1200//720
#define XOFF	500
#define YOFF	500
# define DEFAULT_SCALE	50
#define Z_ZOOM	10
# define TITLE	"FDF"

#include <stdio.h>

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_pixel;

typedef struct		s_mlx
{
	//Map width and heigth (read from file)
	//Defines how many pixels are there ? 
	int				width;
	int				heigth;
	//mlx components
	void			*pan;
	void			*win;
	void			*img;
	char			*cols;
	//Image parameters
	int				size;
	int				bpp;
	int				endian;
	//array of coordinates/altitudes
	t_pixel			**proj;
	t_pixel			**pixs;
	//Camera options
	int				zoom;
	int				scale;
	double			angle_x;
	double			angle_y;
}					t_mlx;

typedef struct		s_param
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				err2;
	int				col;
}					t_param;

t_pixel			**read_file(char *fpath, int width, int heigth);
int				get_dim(char *fpath, int *width, int *heigth);
t_pixel			**to_pixel(int fd, int width, int height);
void			del_str_array(char **pixels);
void			del_pixels(t_pixel **pixels, int size);
void			fill_pixels_row(t_pixel *pix, int r, int width, char **s);
void			disp(char **s);
void			dis_pixels(t_mlx *mlx);


int		clone_pixels(t_mlx *mlx);
t_mlx	*mlx_new(char *arg);
void	ft_puterror(int err);
void	draw_line(t_mlx *mlx, t_pixel p1, t_pixel p2);
void	draw_map(t_mlx *mlx);
double	percent(int p1, int p2, int p);
int		get_color(t_param *param, t_pixel p1, t_pixel p2);
int		get_light(int c1, int c2, double percentage);
void	get_scale(t_mlx *mlx);
void	render(t_mlx *mlx);
void	iso(t_mlx *mlx);
void	translate(t_mlx *mlx);
void	project_map(t_mlx *mlx);
void	center_shape(t_mlx *mlx, int xc, int yc);

#endif
