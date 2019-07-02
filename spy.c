/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spy.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 02:42:14 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/02 03:56:05 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_index(char a)
{
	char	*b;
	int		i;

	i = 0;
	b = "0123456789ABCDEF";
	if (a >= 'a' && a <= 'f')
		b = "0123456789abcdef";
	while (b[i] && b[i] != a)
		i++;
	return (i);
}

int		atoi_fdf(char *st)
{
	int		i;
	int		re;
	int		len;

	len = ft_strlen(st) - 1;
	i = 0;
	re = 0;
	while (st[i])
	{
		re += get_index(st[i]) * pow(16, len);
		len--;
		i++;
	}
	return (re);
}

int		color_atoi(char *str)
{
	int		i;
	int		j;
	char	*st;

	i = 1;
	if (str[i] != '0' || str[i + 1] != 'x')
		return (0);
	i = i + 2;
	if (!str[i])
		return (0);
	j = i;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' &&\
				str[i] <= 'F') || (str[i] >='a' && str[i] <= 'f'))
		i++;
	st = ft_strsub(str, j , i - j);
	return (atoi_fdf(st));
}
