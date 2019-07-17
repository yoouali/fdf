/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 05:22:37 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/17 05:30:11 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../../gnl/get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdio.h>

/*
** the struct t_pixel has the data to evry point in the map
** x and y : Coordinates point
** z : point height
** col ; point color
*/

typedef	struct		s_pixel
{
	int		x;
	int		y;
	int		z;
	int		col;
}					t_pixel;

typedef	struct		s_bres
{
	int		dx;
	int		dy;
	int		xi;
	int		yi;
	int		p;
}					t_bres;
/*
typedef	struct		s_pint;
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		col1;
	int		col2;
	void	*ptr;
	void	*win;
}					t_pint;
*/
void				bresenham_fdf(int x0, int y0, int x1, int y1, void *ptr, void *win, int col);
void				free_t_pixel(t_pixel ***pix);
int					count_dim(char *str);
int					check_fdf(char *str);
void				free_tab(char **tab);
void				free_t_pixel(t_pixel ***pix);
t_pixel				*get_info(char *str, int y,int x);
void				*get_data_fdf_leak(t_pixel **pix, char **tab);
t_pixel				**get_data_fdf(char *line, int y, int dim);
void				*stock_fdf_leak(t_pixel ***fdf, int i, char *line);
t_pixel				***stock_fdf(char *str, int lines);

# endif
