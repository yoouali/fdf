/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 07:33:07 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/24 19:54:08 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	render(t_mlx *mlx, int xm, int ym)
{
	t_render	r;

	r.xmin = WIDTH;
	r.xmax = 0;
	r.ymin = HEIGTH;
	r.ymax = 0;
	r.i = -1;
	while (++r.i < mlx->heigth)
	{
		r.j = -1;
		while (++r.j < mlx->width)
		{
			r.xmax = (mlx->proj[r.i][r.j].x > r.xmax ? mlx->proj[r.i][r.j].x\
					: r.xmax);
			r.xmin = (mlx->proj[r.i][r.j].x < r.xmin ? mlx->proj[r.i][r.j].x\
					: r.xmin);
			r.ymax = (mlx->proj[r.i][r.j].y > r.ymax ? mlx->proj[r.i][r.j].y\
					: r.ymax);
			r.ymin = (mlx->proj[r.i][r.j].y < r.ymin ? mlx->proj[r.i][r.j].y\
					: r.ymin);
		}
	}
	center_shape(mlx, r, xm, ym);
}

void	iso(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx->heigth)
	{
		j = 0;
		while (j < mlx->width)
		{
			mlx->proj[i][j].x = (mlx->pixs[i][j].x - mlx->pixs[i][j].y) *\
								cos(0.523599);
			mlx->proj[i][j].y = -mlx->pixs[i][j].z + (mlx->pixs[i][j].x +\
					mlx->pixs[i][j].y) * sin(0.523599);
			mlx->proj[i][j].z = mlx->pixs[i][j].z;
			mlx->proj[i][j].color = mlx->pixs[i][j].color;
			j++;
		}
		i++;
	}
}

void	paral(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx->heigth)
	{
		j = 0;
		while (j < mlx->width)
		{
			mlx->proj[i][j].x = mlx->pixs[i][j].x;
			mlx->proj[i][j].y = mlx->pixs[i][j].y;
			mlx->proj[i][j].z = mlx->pixs[i][j].z;
			mlx->proj[i][j].color = mlx->pixs[i][j].color;
			j++;
		}
		i++;
	}
}

void	get_proj(t_mlx *mlx)
{
	if (mlx->projn == 1)
		iso(mlx);
	else if (mlx->projn == 2)
		paral(mlx);
}
