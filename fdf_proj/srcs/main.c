/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 07:15:43 by yoouali           #+#    #+#             */
/*   Updated: 2019/07/27 11:37:48 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	exit_fdf(t_mlx *mlx)
{
	del_pixel(mlx->pixs);
	del_pixel(mlx->proj);
	mlx_destroy_image(mlx->pan, mlx->img);
	mlx_destroy_window(mlx->pan, mlx->win);
	free(mlx);
	exit(1);
}

void	ft_puterror(int er, t_mlx *mlx)
{
	destroy_all(mlx, er);
	if (er == 0)
		ft_putendl("Usage: ./fdf file_name");
	if (er == 1)
		ft_putendl("Error: invalid file");
	if (er == 2)
		ft_putendl("Error: allocation failure");
	if (er == 3)
		ft_putendl("Error: No file found");
	exit(1);
}

t_mlx	*mlx_new(char *file)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		ft_puterror(2, mlx);
	if (get_dim(file, mlx) == 0)
		ft_puterror(1, mlx);
	mlx->pan = mlx_init();
	mlx->win = mlx_new_window(mlx->pan, WIDTH, HEIGTH, TITLE);
	mlx->img = mlx_new_image(mlx->pan, WIDTH, HEIGTH);
	mlx->cols = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size, &mlx->end);
	if (!(mlx->pixs = read_file(file, mlx->width, mlx->heigth)))
		ft_puterror(2, mlx);
	if (!(mlx->proj = clone_pixs(mlx)))
		ft_puterror(2, mlx);
	get_scale(mlx);
	mlx->projn = 2;
	get_proj(mlx);
	mlx->xm = 0;
	mlx->ym = 0;
	mlx->zoom = 1;
	render(mlx, mlx->xm, mlx->ym);
	return (mlx);
}

void	dis_pixels(t_mlx *mlx)
{
	int		i =  0;
	int		j;

	while (i < mlx->heigth)
	{
		j = 0;
		while (j < mlx->width)
		{
			printf("%f ", mlx->proj[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;
	int		fd;

	if (ac != 2)
		ft_puterror(0, NULL);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_puterror(3, NULL);
	close(fd);
	mlx = mlx_new(av[1]);
	dis_pixels(mlx);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->pan, mlx->win, mlx->img, 0, 0);
	draw_usage(mlx);
	draw_usage(mlx);
	draw_zoom_offset_info(mlx);
	mlx_key_hook(mlx->win, key_event, mlx);
	mlx_loop(mlx->pan);
	return (0);
}
