/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:37:10 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/22 00:11:33 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_scale(t_mlx *mlx)
{
	int		scalex;
	int		scaley;

	scalex = 1;
	while (scalex * mlx->width < round(WIDTH * 0.6))
		scalex++;
	scaley = 1;
	while (scaley * mlx->heigth < round(HEIGTH * 0.6))
		scaley++;
	mlx->scale = (scalex < scaley ? scalex : scaley);
	mlx->scale -= 1;
	printf("scale: %d\n", mlx->scale);
}

void	translate(t_mlx *mlx)
{
	int		i;
	int		j;
	int		xc;
	int		yc;

	xc = mlx->pixs[0][mlx->width - 1].x / 2;
	yc = mlx->pixs[mlx->heigth - 1][0].y / 2;
	xc = WIDTH / 2 - xc;
	yc = HEIGTH / 2 - yc;
	//printf("xc: %d, yc: %d\n", xc, yc);
	i = -1;
	while (++i < mlx->heigth)
	{
		j = -1;
		while (++j < mlx->width)
		{
			mlx->pixs[i][j].x = mlx->pixs[i][j].x + xc;
			mlx->pixs[i][j].y = mlx->pixs[i][j].y + yc;
		}
	}
}

void	center_shape(t_mlx *mlx, int xc, int yc)
{
	int		errx;
	int		erry;

	errx = round(WIDTH / 2) - xc;
	erry = round(HEIGTH / 2) - yc;
	xc = 0;
	while (xc < mlx->heigth)
	{
		yc = 0;
		while (yc < mlx->width)
		{
			mlx->proj[xc][yc].x += errx;
			mlx->proj[xc][yc].y += erry;
			yc++;
		}
		xc++;
	}
}

void	render(t_mlx *mlx)
{
	int		i;
	int		j;	
	int		xmax;
	int		xmin;
	int		ymax;
	int		ymin;

	xmax = 0;
	xmin = WIDTH;// fucking weird
	ymax = 0;
	ymin = HEIGTH;
	i = -1;
	while (++i < mlx->heigth)
	{
		j = -1;
		while (++j < mlx->width)
		{
			xmax = (mlx->proj[i][j].x > xmax ? mlx->proj[i][j].x\
					: xmax);
			xmin = (mlx->proj[i][j].x < xmin ? mlx->proj[i][j].x\
					: xmin);
			ymax = (mlx->proj[i][j].y > ymax ? mlx->proj[i][j].y\
					: ymax);
			ymin = (mlx->proj[i][j].y < ymin ? mlx->proj[i][j].y\
					: ymin);
		}
	}
	center_shape(mlx, round((xmax + xmin) / 2), round((ymax + ymin) / 2));
}

void	iso(t_mlx *mlx, int i, int j)
{

	mlx->proj[i][j].x = (mlx->pixs[i][j].x - mlx->pixs[i][j].y)\
			* cos(0.523599);
	mlx->proj[i][j].y = -mlx->pixs[i][j].z +\
	(mlx->pixs[i][j].x + mlx->pixs[i][j].y) * sin(0.523599);
}

void	project_map(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i < mlx->heigth)
	{
		j = -1;
		while (++j < mlx->width)
		{
			mlx->pixs[i][j].x = mlx->pixs[i][j].x * mlx->scale;
			mlx->pixs[i][j].y = mlx->pixs[i][j].y * mlx->scale;
			mlx->pixs[i][j].z = mlx->pixs[i][j].z * 5;
		}
	}
}
