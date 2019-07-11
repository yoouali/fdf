/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:43:55 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/11 15:23:52 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int			get_col(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	if (!str[i])
		return (0xFFFFFF);
	i++;
	if (str[i] != '0' || str[i + 1] != 'x' || !str[i + 2])
		return (0);
	i = i + 2;
	return (ft_atoi_base(str + i, 16));
}

t_pixel		*get_data_pixel(char *line, int dim)
{
	t_pixel	*cas;
	char	**tab;
	int		i;

	i = 0;
	if (!(cas = (t_pixel *)malloc(sizeof(t_pixel) * dim)))
		return (NULL);
	tab = ft_split_white_spaces(line);
	while (i < dim)
	{
		cas[i].z = ft_atoi(tab[i]);
		cas[i].col = get_col(tab[i]);
		i++;
	}
	free_tab(tab);
	return (cas);
}

t_pixel		**stock_fdf(t_check *ch, int fd)
{
	t_pixel		**fdf;
	char		*line;
	int			i;

	if (!(fdf = (t_pixel **)malloc(sizeof(t_pixel *) * (ch->line + 1))))
		return (NULL);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		fdf[i] = get_data_pixel(line, ch->dim);
		free(line);
		i++;
	}
	fdf[i] = NULL;
	return (fdf);
}
