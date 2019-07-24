/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:54:13 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/24 19:38:32 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(char *s, int base)
{
	static char	*charset = "0123456789ABCDEF";
	static char	*charset1 = "0123456789abcdef";
	int			i;
	int			res;
	int			len;

	i = 0;
	if (s[i] == '0' && s[i + 1] == 'x')
		s += 2;
	while (ft_contains(charset, s[i]) || ft_contains(charset1, s[i]))
		i++;
	len = i;
	res = 0;
	i = 0;
	while (ft_contains(charset, s[i]) || ft_contains(charset1, s[i]))
	{
		s[i] = ft_toupper(s[i]);
		res += ft_indexof(charset, s[i]) * ft_pow(base, --len);
		i++;
	}
	return (res);
}
