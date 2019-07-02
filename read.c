/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:00:53 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/02 03:43:11 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_fdf(char *line, int *re)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (!line[i])
			break ;
		j++;
		while (line[i] != ' ' && line[i] != '\t' && line[i])
			i++;
	}
	if (*re == 0)
		*re = j;
	if (j < *re)
		return (0);
	return (1);
}

t_fdf		*ft_read_fdf(int fd, int l)
{
	char	**map;
	char	*line;
	int		re;

	if (l == 0)
		return (NULL);
	if (!(map = (char **)malloc(sizeof(char *) * (l + 1))))
		return (NULL);
	re = 0;
	l = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!check_fdf(line, &re))
			return (NULL);
		map[l] = line;
		l++;
	}
	map[l] = NULL;
	return (stock_fdf(map, l));
}
