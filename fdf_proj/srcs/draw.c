/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 04:28:47 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/13 05:07:35 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>

void drawline(int x0,int y0, int x1, int y1, void *ptr, void *win)
{
}

int main()
{
	void *ptr = mlx_init();
	void *win = mlx_new_window(ptr, 500, 500, "fdf");
	int x0 = 50;
	int x1 = 20;
	int y0 = 10;
	int y1 = 50;
	drawline(x0, y0, x1,y1, ptr, win);
	mlx_loop(ptr);
}
