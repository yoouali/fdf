/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:45:40 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/02 03:48:06 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef	struct			s_fdf
{
	int		**pos;
	int		**col;
	char	**tb;
}						t_fdf;

t_fdf	*ft_read_fdf(int fd, int l);
t_fdf	*stock_fdf(char **tab, int l);
int		color_atoi(char *str);
int		count_line(char *str);

#endif
