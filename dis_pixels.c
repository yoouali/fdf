/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:15:33 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/20 11:41:15 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dis_pixels(t_mlx *mlx)
{
	int		i =  0;
	int		j;

	while (i < mlx->heigth)
	{
		j = 0;
		while (j < mlx->width)
		{
			printf("(%d, %d)\n", mlx->proj[i][j].x, mlx->proj[i][j].y);
			j++;
		}
		i++;
	}
}
