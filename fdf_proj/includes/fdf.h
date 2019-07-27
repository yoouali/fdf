/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 07:07:31 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/27 22:01:45 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../../gnl/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# define WIDTH	2000
# define HEIGTH	1200
# define TITLE	"Fdf"


typedef	struct	s_pixel
{
	double		x;
	double		y;
	double		z;
	int		color;
}				t_pixel;

typedef	struct	s_mlx
{
	int		width;
	int		heigth;
	t_pixel	**pixs;
	t_pixel	**proj;
	void	*pan;
	void	*win;
	void	*img;
	char	*cols;
	int		size;
	int		bpp;
	int		end;
	int		projn;
	int		xm;
	int		ym;
	double	zoom;
}				t_mlx;

typedef	struct	s_param
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		col;
	int		err2;
}				t_param;

typedef	struct	s_render
{
	int		i;
	int		j;
	int		xmin;
	int		xmax;
	int		ymin;
	int		ymax;
}				t_render;

void			ft_puterror(int err, t_mlx *mlx);
int				get_dim(char *file, t_mlx *mlx);
t_pixel			*fill_pixels_row(int i, int width, char **split);
void			del_pixel(t_pixel **pixel);
void			del_split(char **split);
t_pixel			**to_pixel_leak(char **split, t_pixel **pix, char *line);
t_pixel			**to_pixel(int fd, int widt, int heigth);
t_pixel			**read_file(char *file, int width, int heigth);
t_pixel			**clone_pixs(t_mlx *mlx);
void			get_scale(t_mlx *mlx);
void			get_proj(t_mlx *mlx);
void			paral(t_mlx *mlx);
void			iso(t_mlx *mlx);
void			center_shape(t_mlx *mlx, t_render r, int xm, int ym);
void			render(t_mlx *mlx, int xm, int ym);
t_mlx			*mlx_new(char *file);
void			draw_map(t_mlx *mlx);
int				get_color(t_param *param, t_pixel p1, t_pixel p2);
int				key_event(int key, t_mlx *mlx);
int				key_event(int key, t_mlx *mlx);
void			reset_image(t_mlx *mlx);
void			exit_fdf(t_mlx *mlx);
void			zoom_shape(t_mlx *mlx, int key);
void			zoom(t_mlx *mlx, double z);
void			destroy_all(t_mlx *mlx, int err);
void			draw_usage(t_mlx *mlx);
void			draw_zoom_offset_info(t_mlx *mlx);
void			z_up_down(t_mlx *mlx, int key);
void			togle_proj(t_mlx *mlx, int key);

#endif
