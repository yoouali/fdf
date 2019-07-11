/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 05:22:37 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/11 15:24:27 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../../gnl/get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

/*
** t_check struct for the function check_fdf 
** check->line : the number of lines in  the file
** check->dim  : the number of words in the first line
*/

typedef	struct		s_check
{
	int		line;
	int		dim;
}					t_check;


typedef	struct		s_pixel
{
	int		z;
	int		col;
}					t_pixel;


t_check				*check_fdf(char *str);
t_pixel				**stock_fdf(t_check *ch, int fd);

# endif
