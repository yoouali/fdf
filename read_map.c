/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:33:07 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/21 21:12:45 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Check whether the file contains
**	a valid form of map.
**	every row of coordinates in the file
**	must fit into the size (greater or equal to)
**	of the first row which can't be an empty line.
*/

t_pixel	**read_file(char *fpath, int width, int heigth)
{
	int		fd;
	t_pixel	**pixels;

	fd = open(fpath, O_RDONLY);
	if (fd < 0)
		return (NULL);
	pixels = to_pixel(fd, width, heigth);
	close(fd);
	return (pixels);
}

/*
**	Gets the dimensions of the raw map
*/

int		get_dim(char *fpath, int *width, int *heigth)
{
	char	*line;
	int		fd;
	
	fd = open(fpath, O_RDONLY);
	*width = -1;
	*heigth = 0;
	while (get_next_line(fd, &line) == 1)
	{
		*width = (*width == -1) ? (int)ft_countwd(line, " \t") : *width;
		if ((int)ft_countwd(line, " \t") < *width)
		{
			ft_strdel(&line);
			close(fd);
			return (0);
		}
		ft_strdel(&line);
		(*heigth)++;
	}
	close(fd);
	return (1);
}

/*
**	Makes a matrix of pixels from a raw
**	map file, the function assumes a valid file.
*/

t_pixel	**to_pixel(int fd, int width, int heigth)
{
	t_pixel		**pixels;
	char		*line;
	char		**split;
	int			i;
	int			ret;

	if (!(pixels = (t_pixel**)malloc(sizeof(t_pixel*) * (heigth + 1))))
		return (NULL);
	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(pixels[i] = (t_pixel*)malloc(sizeof(t_pixel) * width))\
			|| !(split = ft_strsplitset(line, " \t")))
			return (NULL);
		free(line);
		fill_pixels_row(pixels[i], i, width, split);
		i++;
	}
	pixels[i] = NULL;
	if (ret == -1)
	{
		del_pixels(pixels, heigth);
		return (NULL);
	}
	pixels[i] = NULL;
	return (pixels);
}

/*
**	fills a given row in a matrix of pixels
**	each cell contains a pixel structure is filled
**	with data extracted from a string array representing
**	the altitude/color map
*/

void	fill_pixels_row(t_pixel *pix, int row, int width, char **str)
{
	int		i;
	char	*pos;

	i = 0;
	while (i < width)
	{
		if ((pos = ft_strchr(str[i], ',')))
			pix[i].color = ft_atoi_base(pos + 1, 16);
		else
			pix[i].color = 0xFFFFFF;
		pix[i].x = i;
		pix[i].y = row;
		pix[i].z = ft_atoi(str[i]);
		i++;
	}
	del_str_array(str);
}

void	del_pixels(t_pixel **pixels, int size)
{
	int		i;

	i = 0;
	while (i < size)
		free(pixels[i++]);
	free(pixels[i]);
	free(pixels);
}

void	del_str_array(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr[i]);
	free(arr);
}
