/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:45:44 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/27 11:25:31 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pixel	**to_pixel_leak(char **split, t_pixel **pix, char *line)
{
	del_pixel(pix);
	del_split(split);
	free(line);
	return (pix);
}

void	del_pixel(t_pixel **pixel)
{
	int		i;

	i = 0;
	if (pixel)
	{
		while (pixel[i])
			free(pixel[i++]);
		free(pixel);
		pixel = NULL;
	}
}

void	del_split(char **split)
{
	int		i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	split = NULL;
}

void	destroy_all(t_mlx *mlx, int er)
{
	if (mlx)
	{
		if (er == 2)
		{
			mlx_destroy_image(mlx->pan, mlx->img);
			mlx_destroy_window(mlx->pan, mlx->win);
			del_pixel(mlx->pixs);
			del_pixel(mlx->proj);
		}
		free(mlx);
	}
}
