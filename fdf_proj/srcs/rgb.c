/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:12:51 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/16 19:26:46 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** the function dec_to_hexa convert the value decimal to hexadecimal and stock it in char 
*/

char	*dec_to_hexa(int n)
{
	 int	re;
	 char	hexa[2];
	 int	i;

	 if (n == 0)
		 return (ft_strdup("00"));
	 i = 0;
	 while (n > 0)
	 {
		 re = n % 16;
		 if (re < 10)
			 hexa[i++] = 48 + re;
		 else
			 hexa[i++] = 55 + re;
		 n = n / 16;
	 }
	 hexa[i] = '\0';
	 return (ft_strdup(hexa));
}

/*
** giv the function dec_to_hexa all the 3 int 
** then join all the result r>b>b
** gev the string col to atoi_base
*/

int	rgb_to_col(int r, int g, int b)
{
	char	*col;
	char	*ptr;
	char	*tmp;
	int		re;

	ptr = dec_to_hexa(r);
	tmp = dec_to_hexa(g);
	col = ft_strjoin(ptr,tmp);
	free(ptr);
	free(tmp);
	tmp = col;
	ptr = dec_to_hexa(b);
	col = ft_strjoin(col, ptr);
	free(tmp);
	free(ptr);
	re = ft_atoi_base(col, 16);
	free(col);
	return (re);
}

int main(int ac, char **av)
{
	printf("%d\n", rgb_to_col(0,0,255));
	return (0);
}
