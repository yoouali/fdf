/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:41:22 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/22 22:17:45 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_puterror(int err)
{
	if (err == 0)
		ft_putendl("Usage: ./fdf [map_file]");
	if (err == 1)
		ft_putendl("Error: invalid file");
	if (err == 2)
		ft_putendl("Error: allocation failure");
	exit(1);
}

t_mlx	*mlx_new(char *arg)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		ft_puterror(2);
	if (get_dim(arg, &mlx->width, &mlx->heigth) == 0)
		ft_puterror(1);
	mlx->pan = mlx_init();
	mlx->win = mlx_new_window(mlx->pan, WIDTH, HEIGTH, TITLE);
	mlx->img = mlx_new_image(mlx->pan, WIDTH, HEIGTH);
	mlx->zoom = 1;
	mlx->cols = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size,\
			&mlx->endian);
	mlx->pixs = read_file(arg, mlx->width, mlx->heigth);
	mlx->angle_x = 0.0;
	mlx->angle_y = 0.0;
	get_scale(mlx);	//Outputs the scale according to window dimensions
	project_map(mlx);//Changes pixes coordinates
	translate(mlx); // Centers the shapes (pixes coordinates)
	if (!clone_pixels(mlx))
	{
		//TODO: destroy pixels
		ft_puterror(2);
	}
	iso(mlx);
	render(mlx);
	return (mlx);
}

int		clone_pixels(t_mlx *mlx)
{
	int		i;
	int		j;


	if (!(mlx->proj = (t_pixel **)malloc(sizeof(t_pixel*) * mlx->heigth)))
		return (0);
	i = 0;
	while (i < mlx->heigth)
	{
		if (!(mlx->proj[i] = (t_pixel*)malloc(sizeof(t_pixel) * mlx->width)))
			return (0);
		i++;
	}
	mlx->proj[i] = NULL;
	return (1);
}

void	reset_image(t_mlx *mlx)
{
	mlx_destroy_image(mlx->pan, mlx->img);
	mlx->img = mlx_new_image(mlx->pan, WIDTH, HEIGTH);
	mlx->cols  = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size, &mlx->endian);
}
void	move_shape(t_mlx *mlx, int sx, int sy, int sz)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx->heigth)
	{
		j = 0;
		while (j < mlx->width)
		{
			mlx->proj[i][j].x += sx;
			mlx->proj[i][j].y += sy;
			j++;
		}
		i++;
	}
}


void	z_up_down(t_mlx *mlx, int zs)
{
	int			i;
	int			j;
	int			op;

	op = (zs < 0 ? -1 : 1);
	i = 0;
	while (mlx->pixs[i])
	{
		j = 0;
		while (j < mlx->width)
		{
			if (mlx->pixs[i][j].z != 0)
			{
				if (mlx->pixs[i][j].z + zs == 0)
					mlx->pixs[i][j].z +=  zs + op;
				else
					mlx->pixs[i][j].z +=  zs;
			}
			j++;
		}
		i++;
	}
}

void	rotate_x(t_mlx *mlx)
{
	int		i;
	int		j;
	int		y;

	i = 0;
	while (i < mlx->heigth)
	{
		j = 0;
		while (j < mlx->width)
		{
			y = mlx->pixs[i][j].y;
			mlx->pixs[i][j].y = round(mlx->pixs[i][j].y * cos(mlx->angle_x) +\
					mlx->pixs[i][j].z * sin(mlx->angle_x));
			mlx->pixs[i][j].z = round(-y * sin(mlx->angle_x) +\
					mlx->pixs[i][j].z * cos(mlx->angle_x));
			j++;
		}
		i++;
	}
}

void	rotate_y(t_mlx	*mlx)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	while (i < mlx->heigth)
	{
		j = 0;
		while (j < mlx->width)
		{
			x = mlx->pixs[i][j].x;
			mlx->pixs[i][j].x = round(mlx->pixs[i][j].x * cos(mlx->angle_y) +\
					mlx->pixs[i][j].z * sin(mlx->angle_y));
			mlx->pixs[i][j].z = round(-x * sin(mlx->angle_y) +\
					mlx->pixs[i][j].z * cos(mlx->angle_y));
			j++;
		}
		i++;
	}
}

void	zoom(t_mlx *mlx, double z)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx->heigth)
	{
		j = 0;
		while (j < mlx->width)
		{
			mlx->pixs[i][j].x *= z;
			mlx->pixs[i][j].y *= z;
			mlx->pixs[i][j].z *= z;
			j++;
		}
		i++;
	}
}

int		key_event(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(1);
	if (key >= 123 && key <= 126)
	{
		reset_image(mlx);
		if (key == 123)
			move_shape(mlx, -10, 0, 0);
		if (key == 124)
			move_shape(mlx, 10, 0, 0);
		if (key == 125)
			move_shape(mlx, 0, 10, 0);
		if (key == 126)
			move_shape(mlx, 0, -10, 0);
		draw_map(mlx);
		mlx_put_image_to_window(mlx->pan, mlx->win, mlx->img, 0, 0);
	}
	if (key == 116 || key == 121)
	{
		reset_image(mlx);
		if (key == 116)
			z_up_down(mlx, 3);
		if (key == 121)
			z_up_down(mlx, -3);
		iso(mlx);
		render(mlx);
		draw_map(mlx);
		mlx_put_image_to_window(mlx->pan, mlx->win, mlx->img, 0, 0);
	}
	if (key >= 91 || key == 84 ||  key == 86 || key == 88)
	{
		reset_image(mlx);
		if (key == 	91 || key == 84)
		{
			if (key == 91)
				mlx->angle_x = 0.3;
			else
				mlx->angle_x = 0.3;
			rotate_x(mlx);
		}
		if (key == 86 || key == 88)
		{
			if (key == 86)
				mlx->angle_y = 0.3;
			else
				mlx->angle_y = 0.3;
			rotate_y(mlx);
		}
		get_scale(mlx);
		translate(mlx);
		iso(mlx);
		render(mlx);
		draw_map(mlx);
		mlx_put_image_to_window(mlx->pan, mlx->win, mlx->img, 0, 0);
	}
	if (key == 78|| key == 69)
	{
		reset_image(mlx);
		if (key == 78)
			zoom(mlx, 0.5);	
		else
			zoom(mlx, 2);
		iso(mlx);
		render(mlx);
		draw_map(mlx);
		mlx_put_image_to_window(mlx->pan, mlx->win, mlx->img, 0, 0);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac != 2)
		ft_puterror(0);
	mlx = mlx_new(av[1]);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->pan, mlx->win, mlx->img, 0, 0);
	mlx_key_hook(mlx->win, key_event, mlx);
	mlx_loop(mlx->pan);
	del_pixels(mlx->pixs, mlx->heigth);
	del_pixels(mlx->proj, mlx->heigth);
	return (0);
}
