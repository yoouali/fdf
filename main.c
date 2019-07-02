/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:51:26 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/02 04:47:39 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count_line(char *av)
{
	int		fd;
	char	*line;
	int		l;

	l = 0;
	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		l++;
	}
	close(fd);
	return (l);
}

void	print_int_tab(char	**tb, int **tab)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (tb[i])
	{
		j = 0;
		len = count_line(tb[i]);
		while (j < len)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}


int		main(int ac, char **av)
{
	int		fd;
	int		l;
	t_fdf	*map;
	if (ac != 2)
	{
		ft_putendl("usage : ./fdf file_name");
		return (0);
	}
	l = ft_count_line(av[1]);
	fd = open(av[1], O_RDONLY);
	map = ft_read_fdf(fd, l);
	if (!map)
	{
		ft_putendl("ther is a line error");
		exit(0);
	}
	ft_putstr2(map->tb);
	ft_putendl("$");
	print_int_tab(map->tb, map->pos);
	ft_putendl("$");
	print_int_tab(map->tb, map->col);
	return (0);
}
