/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 07:11:34 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/24 19:54:19 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pixel		**clone_pixs(t_mlx *mlx)
{
	int		i;

	i = 0;
	if (!(mlx->proj = (t_pixel**)malloc(sizeof(t_pixel*) * (mlx->heigth + 1))))
		return (NULL);
	while (i < mlx->heigth)
	{
		if (!(mlx->proj[i] = (t_pixel*)malloc(sizeof(t_pixel) * mlx->width)))
			return (clone_pixs_leak(mlx, i));
		i++;
	}
	mlx->proj[i] = NULL;
	return (mlx->proj);
}

void		center_shape(t_mlx *mlx, t_render r, int xm, int ym)
{
	xm = WIDTH / 2 - (r.xmax + r.xmin) / 2 + xm;
	ym = HEIGTH / 2 - (r.ymax + r.ymin) / 2 + ym;
	r.i = 0;
	while (r.i < mlx->heigth)
	{
		r.j = 0;
		while (r.j < mlx->width)
		{
			mlx->proj[r.i][r.j].x += xm;
			mlx->proj[r.i][r.j].y += ym;
			r.j++;
		}
		r.i++;
	}
}

void		up_scale(t_mlx *mlx, int scale)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx->heigth)
	{
		j = 0;
		while (j < mlx->width)
		{
			mlx->pixs[i][j].x *= scale;
			mlx->pixs[i][j].y *= scale;
			mlx->pixs[i][j].z *= 4;
			j++;
		}
		i++;
	}
}

void		get_scale(t_mlx *mlx)
{
	int		scalex;
	int		scaley;
	int		scale;

	scalex = 1;
	while (scalex * mlx->width < round(WIDTH * 0.5))
		scalex++;
	scaley = 1;
	while (scaley * mlx->heigth < round(HEIGTH * 0.5))
		scaley++;
	scale = (scalex < scaley ? scalex : scaley);
	up_scale(mlx, scale);
}
