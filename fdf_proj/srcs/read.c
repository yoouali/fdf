/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 07:30:06 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/27 11:20:28 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_dim(char *file, t_mlx *mlx)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	mlx->width = 0;
	mlx->heigth = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		mlx->width = (mlx->width == 0) ? (int)\
		ft_countwd(line, " \t") : mlx->width;
		if (mlx->width < 1 || (int)ft_countwd(line, " \t") < mlx->width)
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
		mlx->heigth += 1;
	}
	close(fd);
	return (ret < 0 ? 0 : mlx->heigth);
}

t_pixel	**read_file(char *file, int width, int heigth)
{
	int		fd;
	t_pixel	**pixels;

	fd = open(file, O_RDONLY);
	if (!(pixels = to_pixel(fd, width, heigth)))
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (pixels);
}

t_pixel	**to_pixel(int fd, int width, int heigth)
{
	t_pixel		**pixels;
	char		*line;
	char		**split;
	int			i;
	int			ret;

	if (!(pixels = (t_pixel **)malloc(sizeof(t_pixel *) * (heigth + 1))))
		return (NULL);
	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(split = ft_strsplitset(line, " \t")) ||\
				!(pixels[i] = fill_pixels_row(i, width, split)))
			return (to_pixel_leak(split, pixels, line));
		free(line);
		i++;
	}
	pixels[i] = NULL;
	if (ret == -1)
	{
		del_pixel(pixels);
		return (NULL);
	}
	return (pixels);
}

t_pixel	*fill_pixels_row(int row, int width, char **split)
{
	t_pixel	*pix;
	int		i;
	char	*pos;

	if (!(pix = (t_pixel *)malloc(sizeof(t_pixel) * width)))
		return (NULL);
	i = 0;
	while (split[i])
	{
		if ((pos = ft_strchr(split[i], ',')))
			pix[i].color = ft_atoi_base(pos + 1, 16);
		else
			pix[i].color = 0xFFFFFF;
		pix[i].x = i;
		pix[i].y = row;
		pix[i].z = ft_atoi(split[i]);
		i++;
	}
	return (pix);
}
