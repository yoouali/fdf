/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 07:56:49 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/11 08:27:51 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_pow(int base, int n)
{
	int		re;
	int		i;

	if (n < 1)
		return (1);
	i = 0;
	re = 1;
	while (i < n)
	{
		re = re * base;
		i++;
	}
	return (re);
}

static	int			get_index(char x, int base)
{
	char	*b;
	int		i;

	if (x >= 'A' && x <= 'Z')
		x += 32;
	i = 0;
	b = "0123456789abcdef";
	while (i < base && b[i] != x)
		i++;
	if (i == base)
		return (0);
	return (i);
}

int					ft_atoi_base(char *str, int base)
{
	int		re;
	int		i;
	int		j;

	if (base == 10)
		return (ft_atoi(str));
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	j = i;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')\
			|| (str[i] >= 'A' && str[i] <= 'F'))
		i++;
	re = 0;
	while (j < i)
	{
		re += get_index(str[j], base) * ft_pow(base, i - j - 1);
		j++;
	}
	return (re);
}
