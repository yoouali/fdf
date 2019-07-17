/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 03:42:06 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/17 05:29:32 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		draw_y(t_bres *bres, int x0, int y0, int y1, void *ptr, void *win, int col)
{
	bres->p = 2 * bres->dx - bres->dy;
	mlx_pixel_put(ptr, win, x0, y0, col);
	while (y0 != y1)
	{
		if (bres->p > 0)
		{
			x0 = x0 + bres->xi;
			bres->p = bres->p + 2 * bres->dy- 2 * bres->dy;
		}
		else
			bres->p = bres->p + 2 * bres->dx;
		y0 = y0 + bres->yi;
		col = col - 500;	
		mlx_pixel_put(ptr, win, x0, y0, col);
	}
}

void		draw_x(t_bres *bres, int x0, int y0, int x1, void *ptr, void *win, int col)
{
	bres->p = 2 * bres->dy - bres->dx;
	mlx_pixel_put(ptr, win, x0, y0, col);
	while (x0 !=  x1)
	{
		if (bres->p > 0)
		{
			y0 = y0 + bres->yi;
			bres->p = bres->p + 2 * bres->dy - 2 * bres->dx;
		}
		else
			bres->p = bres->p + 2 * bres->dy;
		x0 = x0 + bres->xi;
		col = col - 500;	
		mlx_pixel_put(ptr, win, x0, y0, col);
	}
}

void		bresenham_fdf(int x0, int y0, int x1, int y1, void *ptr, void *win, int col)
{
	t_bres	*bres;

	bres = (t_bres *)malloc(sizeof(t_bres));
	bres->dx = abs(x1 - x0);
	bres->dy = abs(y1 - y0);
	bres->xi = 1;
	bres->yi = 1;
	if (x1 < x0)
		bres->xi = -1;
	if (y1 < y0)
		bres->yi = -1;
	if (bres->dx >= bres->dy)
		draw_x(bres, x0, y0, x1, ptr, win, col);
	else
		draw_y(bres, x0, y0, y1, ptr, win, col);
}

int main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	void *ptr = mlx_init();
	void *win = mlx_new_window(ptr, 500, 500, "fdf");
	int x0, x1, y0, y1;
	x0 = atoi(av[1]);
	y0 = atoi(av[2]);
	x1 = atoi(av[3]);
	y1 = atoi(av[4]);
	bresenham_fdf(x0, y0, x1, y1, ptr, win, 0xffffff);
	mlx_loop(ptr);
	return (0);
}
