/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 05:26:20 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/12 04:10:46 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** count the number of words
** the words is separated by spaces or tabs
** freeing 'str' before return
*/

int			count_dim(char *str)
{
	int		i;
	int		dim;

	i = 0;
	dim = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (!str[i])
			break ;
		dim++;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
	}
	free(str);
	return (dim);
}

/*
** count the number of lines
** checking the lines dim are not less than the first line dim
*/

int			check_fdf(char *str)
{
	char		*line;
	int			fd;
	int			dim;
	int			lines;

	fd = open(str, O_RDONLY);
	lines = 1;
	if ((get_next_line(fd, &line) < 1) || (dim = count_dim(line)) < 1)
	{
		close(fd);
		return (0);
	}
	while (get_next_line(fd, &line) == 1)
	{
		if (count_dim(line) < dim)
		{
			close(fd);
			return (0);
		}
		lines++;
	}
	close(fd);
	return (lines);
}
