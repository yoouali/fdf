/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:41:22 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/27 22:00:48 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_shape(t_mlx *mlx, int key)
{
	reset_image(mlx);
	if (key == 123)
		mlx->xm -= 10;
	if (key == 124)
		mlx->xm += 10;
	if (key == 125)
		mlx->ym += 10;
	if (key == 126)
		mlx->ym -= 10;
}

void	zoom_shape(t_mlx *mlx, int key)
{
	reset_image(mlx);
	if (key == 78)
		zoom(mlx, 0.5);
	else
		zoom(mlx, 2);
	get_proj(mlx);
}

int		key_event(int key, t_mlx *mlx)
{
	if (key == 53)
		exit_fdf(mlx);
	if (!(key >= 123 && key <= 126) && key != 35 && key != 34 && key != 2 &&\
			key != 32 && key != 78 && key != 69)
		return (1);
	if (key == 35 || key == 34)
		togle_proj(mlx, key);
	if (mlx->projn == 1 && (key == 32 || key == 2))
		z_up_down(mlx, key);
	if (key >= 123 && key <= 126)
		move_shape(mlx, key);
	if (key == 78 || key == 69)
		zoom_shape(mlx, key);
	render(mlx, mlx->xm, mlx->ym);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->pan, mlx->win, mlx->img, 0, 0);
	draw_usage(mlx);
	draw_zoom_offset_info(mlx);
	return (0);
}

void	reset_image(t_mlx *mlx)
{
	mlx_destroy_image(mlx->pan, mlx->img);
	mlx->img = mlx_new_image(mlx->pan, WIDTH, HEIGTH);
	mlx->cols = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size, &mlx->end);
}

void	zoom(t_mlx *mlx, double z)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx->heigth)
	{
		j = 0;
		while (j < mlx->width)
		{
			mlx->pixs[i][j].x *= z;
			mlx->pixs[i][j].y *= z;
			mlx->pixs[i][j].z *= z;
			j++;
		}
		i++;
	}
	mlx->zoom *= z;
}
