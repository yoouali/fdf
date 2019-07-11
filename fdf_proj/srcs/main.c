/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 05:38:17 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/11 15:20:41 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	t_check	*ch;
	t_pixel	**fdf;

	if (ac != 2)
	{
		ft_putendl("usage: ./fdf file_name");
		return (0);
	}
	ch = check_fdf(av[1]);
	fd = open(av[1], O_RDONLY);
	if (!ch)
	{
		ft_putendl("ther is a line error");
		exit(0);
	}
	fdf = stock_fdf(ch, fd);
	int		i = 0;
	int j;
	printf("lo\n");
	while (i < ch->line)
	{
		j = 0;
		while (j < ch->dim)
		{
			printf (" %d : %d |", fdf[i][j].z, fdf[i][j].col);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
