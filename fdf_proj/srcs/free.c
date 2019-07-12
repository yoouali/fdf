/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 03:51:47 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/12 10:12:53 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** freeing the struct 't_pixel***'
*/

void		free_t_pixel(t_pixel ***pix)
{
	int		i;
	int		j;

	i = 0;
	while (pix[i])
	{
		j = 0;
		while (pix[i][j])
		{
			free(pix[i][j]);
			j++;
		}
		free(pix[i]);
		i++;
	}
	free(pix);
}

/*
** freeing matrix of char
*/

void		free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] || i < len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
