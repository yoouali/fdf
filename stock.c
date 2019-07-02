/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 02:18:24 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/02 04:31:19 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			count_line(char *str)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (!str[i])
			break ;
		len++;
		while (str[i] != ' ' && str[i] != '\t' && str[i])
			i++;
	}
	return (len);
}

int			*get_pos(char *str, int len)
{
	int		*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tab = (int *)malloc(sizeof(int) * len)))
		return (NULL);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (!str[i])
			break ;
		tab[j] = ft_atoi(str + i);
		j++;
		while (str[i] != ' ' && str[i] != '\t' && str[i])
			i++;
	}
	return (tab);
}

int			*get_col(char *str, int len)
{
	int		*tab;
	int		i;
	int		j;

	if (!(tab = (int *)malloc(sizeof(int) *  len)))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (!str[i])
			break ;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != ',')
			i++;
		if (str[i] == ',')
			tab[j] = color_atoi(str + i);
		else
			tab[j] = 0;
		j++;
		while (str[i] != ' ' && str[i] != '\t' && str[i])
			i++;
	}
	return (tab);
}

t_fdf		*stock_fdf(char **tab, int l)
{
	t_fdf		*map;
	int			i;
	int			len;

	i = 0;
	if (!(map = (t_fdf *)malloc(sizeof(t_fdf))))
		return (NULL);
	if (!(map->pos = (int **)malloc(sizeof(int *) * (l + 1))))
		return (NULL);
	if (!(map->col = (int **)malloc(sizeof(int *) * (l + 1))))
		return (NULL);
	while (tab[i])
	{
		len = count_line(tab[i]);
		map->pos[i] = get_pos(tab[i], len);
		map->col[i] = get_col(tab[i], len);
		i++;
	}
	map->pos[i] = NULL;
	map->col[i] = NULL;
	map->tb = tab;
	return (map);
}
