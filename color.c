/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:43:45 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/19 22:27:48 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double 		percent(int p1, int p2, int p)
{
	double placement;
	double distance;

	placement = p - p1;
	distance = p2 - p1;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int c1, int c2, double percentage)
{
	return ((int)((1 - percentage) * c1 + percentage * c2));
}

int		get_color(t_param *param, t_pixel p1, t_pixel p2)
{
	int     red;
	int     green;
	int     blue;
	double  percentage;

	if (p1.color == p2.color)
		return (p1.color);
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
		percentage = percent(p1.x, p2.x, param->x0);
	else
		percentage = percent(p1.y, p2.y, param->y0);
	red = get_light((p1.color >> 16) & 0xFF, (p2.color >> 16) & 0xFF, percentage);
	green = get_light((p1.color >> 8) & 0xFF, (p2.color >> 8) & 0xFF, percentage);
	blue = get_light(p1.color & 0xFF, p2.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
