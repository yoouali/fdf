/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:43:45 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/24 22:14:26 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double		percent(int p1, int p2, int p)
{
	double	placement;
	double	distance;

	placement = p - p1;
	distance = p2 - p1;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			get_light(int c1, int c2, double perc)
{
	return ((int)((1 - perc) * c1 + perc * c2));
}

int			get_color(t_param *param, t_pixel p1, t_pixel p2)
{
	int		red;
	int		green;
	int		blue;
	double	perc;

	if (p1.color == p2.color)
		return (p1.color);
	if (fabs(p2.x - p1.x) > fabs(p2.y - p1.y))
		perc = percent(p1.x, p2.x, param->x0);
	else
		perc = percent(p1.y, p2.y, param->y0);
	red = get_light((p1.color >> 16) & 0xFF, (p2.color >> 16) & 0xFF, perc);
	green = get_light((p1.color >> 8) & 0xFF, (p2.color >> 8) & 0xFF, perc);
	blue = get_light(p1.color & 0xFF, p2.color & 0xFF, perc);
	return ((red << 16) | (green << 8) | blue);
}

void		draw_usage(t_mlx *mlx)
{
	mlx_string_put(mlx->pan, mlx->win, 50, 20, 0x40ff00, \
			"%%%%%%%%    USAGE    %%%%%%%%%%%%%%%%%%%");
	mlx_string_put(mlx->pan, mlx->win, 50, 40, 0x40ff00, \
			"[ ESC ]     ---->    Exit");
	mlx_string_put(mlx->pan, mlx->win, 50, 60, 0x40ff00, \
			"[  I  ]     ---->    Iso projection");
	mlx_string_put(mlx->pan, mlx->win, 50, 80, 0x40ff00, \
			"[  P  ]     ---->    Parallel projection");
	mlx_string_put(mlx->pan, mlx->win, 50, 100, 0x40ff00,\
			"[  +  ]     ---->    Zoom in");
	mlx_string_put(mlx->pan, mlx->win, 50, 120, 0x40ff00,\
			"[  -  ]     ---->    Zoom out");
	mlx_string_put(mlx->pan, mlx->win, 50, 140, 0x40ff00,\
			"[ UP  ]     ---->    Move Up");
	mlx_string_put(mlx->pan, mlx->win, 50, 160, 0x40ff00,\
			"[DOWN ]     ---->    Move Down");
	mlx_string_put(mlx->pan, mlx->win, 50, 180, 0x40ff00,\
			"[LEFT ]     ---->    Move Left");
	mlx_string_put(mlx->pan, mlx->win, 50, 200, 0x40ff00,\
			"[RIGHT]     ---->    Move Right");
	mlx_string_put(mlx->pan, mlx->win, 50, 220, 0x40ff00,\
			"[  U  ]     ---->    Heigth up");
	mlx_string_put(mlx->pan, mlx->win, 50, 240, 0x40ff00,\
			"[  D  ]     ---->    Heigth down");
}

void		draw_zoom_offset_info(t_mlx *mlx)
{
	char	*info;
	char	*tmp;
	double	x;

	x = 1 / mlx->zoom;
	info = (mlx->zoom < 1 ? ft_itoa(x) : ft_itoa(mlx->zoom));
	tmp = (mlx->zoom < 1 ? ft_strjoin("Zoom   :   x1/", info) :\
			ft_strjoin("Zoom   :   x", info));
	mlx_string_put(mlx->pan, mlx->win, 50, 1100, 0x40ff00, tmp);
	free(info);
	free(tmp);
	info = ft_itoa(mlx->xm);
	tmp = (mlx->xm < 0 ? ft_strjoin("Xoffset:   ", info) :\
			ft_strjoin("Xoffset:   +", info));
	mlx_string_put(mlx->pan, mlx->win, 50, 1120, 0x40ff00, tmp);
	free(info);
	free(tmp);
	info = ft_itoa(mlx->ym);
	tmp = (mlx->ym < 0 ? ft_strjoin("Yoffset:   ", info) :\
			ft_strjoin("Yoffset:   +", info));
	mlx_string_put(mlx->pan, mlx->win, 50, 1140, 0x40ff00, tmp);
	free(info);
	free(tmp);
}
