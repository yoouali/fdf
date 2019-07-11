/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 05:26:20 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/11 15:23:08 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			count_dim(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (!str[i])
			break ;
		j++;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
	}
	free(str);
	return (j);
}

t_check		*check_fdf(char *str)
{
	t_check		*ch;
	char		*line;
	int			fd;

	fd = open(str, O_RDONLY);
	if (!(ch = (t_check *)malloc(sizeof(t_check))))
		return (NULL);
	ch->line = 1;
	if ((get_next_line(fd, &line) < 1) || (ch->dim = count_dim(line)) < 1)
	{
		free(ch);
		return (NULL);
	}
	while (get_next_line(fd, &line) == 1)
	{
		if (count_dim(line) < ch->dim)
		{
			free(ch);
			free(line);
			return (NULL);
		}
		ch->line++;
	}
	return (ch);
}
