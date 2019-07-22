/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:15:31 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/11 11:18:29 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwd(char const *s, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s || !set)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (!ft_contains(set, s[i]))
		{
			j++;
			while (s[i] && !ft_contains(set, s[i]))
				i++;
		}
		else
			i++;
	}
	return (j);
}

