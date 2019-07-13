/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:43:55 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/13 03:36:55 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** using ./libft/ft_atoi to get the value of z
** if tmp|ft_strchr(str, ',') return 'NULL' the col is white
** if the form of tmp is not 0xcol_val the col is black
** else using ./libft/ft_atoi_base to get the value of col with decimal
*/

t_pixel		*get_info(char *str, int y, int x)
{
	t_pixel		*pix;
	int			i;
	char		*tmp;

	i = 0;
	if (!(pix = (t_pixel *)malloc(sizeof(t_pixel))))
		return (NULL);
	pix->x = x;
	pix->y = y;
	pix->z = ft_atoi(str);
	if (!(tmp = ft_strchr(str, ',')))
		pix->col = 0xffffff;
	else
	{
		if (tmp[i + 1] != '0' || tmp[i + 2] != 'x' || !tmp[i + 3])
			pix->col = 0;
		else
			pix->col = ft_atoi_base(tmp + i + 3, 16);
	}
	return (pix);
}

/*
** freeing the 'tab' or 'pix'
*/

void		*get_data_fdf_leak(t_pixel **pix, char **tab)
{
	if (tab)
		free_tab(tab);
	free(pix);
	return (NULL);
}

/*
** allocate to the scund pointer 'pix'
** split the line to get matrix of words
** then put the return of get_info in evry row of 'pix'
** if get_info return 'NULL' the 'tab' and 'pix' get freed and rerurn NULL
** freeing the 'tab' with ./fdf_proj/srcs/free<free_tab>
*/

t_pixel		**get_data_fdf(char *line, int y, int dim)
{
	int		i;
	char	**tab;
	t_pixel	**pix;

	pix = NULL;
	if (!(tab = ft_split_white_spaces(line)) ||\
			!(pix = (t_pixel **)malloc(sizeof(t_pixel *) * (dim + 1))))
		return (get_data_fdf_leak(pix, tab));
	i = -1;
	while (tab[++i])
	{
		if (!(pix[i] = get_info(tab[i], y, i)))
		{
			while (--i >= 0)
				free(pix[i]);
			free(pix);
			free_tab(tab);
			return (NULL);
		}
	}
	free_tab(tab);
	pix[i] = NULL;
	return (pix);
}

/*
** freeing the t_pixel struct and the line
*/

void		*stock_fdf_leak(t_pixel ***fdf, int i, char *line)
{
	int j;
	int k;

	j = 0;
	while (j < i)
	{
		k = 0;
		while (fdf[j][k])
			free(fdf[j][k++]);
		free(fdf[j++]);
	}
	free(fdf);
	free(line);
	return (NULL);
}

/*
** allocate to the first pointer 'fdf'
** and put the return of get_data_fdf in evry row in 'fdf'
** if get_data_fdf return 'NULL' call stock_fdf_leak
*/

t_pixel		***stock_fdf(char *str, int lines)
{
	int		fd;
	char	*line;
	t_pixel	***fdf;
	int		i;
	int		dim;

	i = 0;
	if (!(fdf = (t_pixel ***)malloc(sizeof(t_pixel**) * (lines + 1))))
		return (NULL);
	fd = open(str, O_RDONLY);
	dim = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (dim == 0)
			dim = count_dim(ft_strdup(line));
		if (!(fdf[i] = get_data_fdf(line, i, dim)))
			return (stock_fdf_leak(fdf, i, line));
		free(line);
		i++;
	}
	fdf[i] = NULL;
	close(fd);
	return (fdf);
}
