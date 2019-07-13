/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 05:38:17 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/13 03:37:06 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	int		lines;
	t_pixel	***pix;

	if (ac != 2)
	{
		ft_putendl("usage: ./fdf file_name");
		return (0);
	}
	if (!(lines = check_fdf(av[1])))
	{
		ft_putendl("line error");
		exit(0);
	}
	pix = stock_fdf(av[1], lines);
	free_t_pixel(pix);
	return (0);
}
