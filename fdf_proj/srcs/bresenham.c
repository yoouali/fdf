/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 03:42:06 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/18 20:04:37 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		draw_y(t_bres bres, t_pint pint)
{
	bres.p = 2 * bres.dx - bres.dy;
	mlx_pixel_put(pint.ptr, pint.win, pint.x0, pint.y0, pint.col1);
	while (pint.y0 != pint.y1)
	{
		if (bres.p > 0)
		{
			pint.x0 = pint.x0 + bres.xi;
			bres.p = bres.p + 2 * bres.dx - 2 * bres.dy;
		}
		else
			bres.p = bres.p + 2 * bres.dx;
		pint.y0 = pint.y0 + bres.yi;
		mlx_pixel_put(pint.ptr, pint.win, pint.x0, pint.y0, pint.col1);
	}
}

void		draw_x(t_bres bres, t_pint pint)
{
	bres.p = 2 * bres.dy - bres.dx;
	mlx_pixel_put(pint.ptr, pint.win, pint.x0, pint.y0, pint.col1);
	while (pint.x0 != pint.x1)
	{
		if (bres.p > 0)
		{
			pint.y0 = pint.y0 + bres.yi;
			bres.p = bres.p + 2 * bres.dy - 2 * bres.dx;
		}
		else
			bres.p = bres.p + 2 * bres.dy;
		pint.x0 = pint.x0 + bres.xi;
		mlx_pixel_put(pint.ptr, pint.win, pint.x0, pint.y0, pint.col1);
	}
}

void		bresenham_fdf(t_pint pint)
{
	t_bres	bres;

	bres.dx = abs(pint.x1 - pint.x0);
	bres.dy = abs(pint.y1 - pint.y0);
	bres.xi = 1;
	bres.yi = 1;
	if (pint.x1 < pint.x0)
		bres.xi = -1;
	if (pint.y1 < pint.y0)
		bres.yi = -1;
	if (bres.dx >= bres.dy)
		draw_x(bres, pint);
	else
		draw_y(bres, pint);
}
