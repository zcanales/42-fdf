/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:19:42 by zcanales          #+#    #+#             */
/*   Updated: 2022/04/22 09:42:03 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdlib.h>
#include <math.h>

static void	draw_cord_y(t_fdf *fdf, int x, int y)
{
	fdf->map.begin.x = ((x - y) * fdf->dif_x * cos(fdf->map.angle_x))
		+ fdf->map.move_x;
	fdf->map.end.x = ((x - (y + 1)) * fdf->dif_x * (cos((fdf->map.angle_x))))
		+ fdf->map.move_x;
	fdf->map.begin.y = ((x + y)) * sin(fdf->map.angle_y) * fdf->dif_y
		- fdf->map.map_int2[y][x] * fdf->map.zoom + fdf->map.move_y;
	fdf->map.end.y = ((x + y + 1) * sin(fdf->map.angle_y) * fdf->dif_y)
		- fdf->map.map_int2[y + 1][x] * fdf->map.zoom + fdf->map.move_y;
	bresenham_algo(fdf, &fdf->map.begin, &fdf->map.end);
}

static void	draw_cord_x(t_fdf *fdf, int x, int y)
{
	fdf->map.begin.x = (((x - y) * fdf->dif_x * cos(fdf->map.angle_x)))
		+ fdf->map.move_x;
	fdf->map.end.x = ((x + 1 - y) * fdf->dif_x * cos((fdf->map.angle_x)))
		+ fdf->map.move_x;
	fdf->map.begin.y = ((x + y) * sin(fdf->map.angle_y) * fdf->dif_y)
		- fdf->map.map_int2[y][x] * fdf->map.zoom + fdf->map.move_y;
	fdf->map.end.y = (((x + 1) + y) * sin(fdf->map.angle_y) * fdf->dif_y)
		- fdf->map.map_int2[y][x + 1] * fdf->map.zoom + fdf->map.move_y;
	bresenham_algo(fdf, &fdf->map.begin, &fdf->map.end);
}

static void	draw_rectangles(t_fdf *fdf)
{
	t_cord	cord;

	cord.y = -1;
	while (++cord.y < fdf->map.height)
	{
		cord.x = -1;
		while (++cord.x < fdf->map.width)
		{
			if (cord.x < (fdf->map.width - 1))
				draw_cord_x(fdf, cord.x, cord.y);
			if (cord.y < (fdf->map.height - 1))
				draw_cord_y(fdf, cord.x, cord.y);
		}
	}
}

static void	check_values(t_fdf *fdf)
{
	if (fdf->map.z_range * fdf->dif_y > HEIGHT)
	{
		fdf->map.zoom = 1;
		fdf->dif_x = 1;
		fdf->dif_y = 1;
	}
	if (fdf->map.z_range > HEIGHT)
		fdf->map.zoom = (HEIGHT / (double)fdf->map.z_range) * 0.1;
	if (fdf->map.zoom == 0)
		fdf->map.zoom = 1;
	if (fdf->dif_x == 0)
		fdf->dif_x = 1;
	if (fdf->dif_y == 0)
		fdf->dif_y = 1;
}

int	draw(t_fdf *fdf)
{
	int	z1;
	int	z2;

	img_init(fdf);
	fdf->dif_x = WIDTH / fdf->map.width / 4;
	fdf->dif_y = HEIGHT / fdf->map.height / 4;
	z_range(fdf);
	z1 = HEIGHT / fdf->map.height / 6;
	z2 = WIDTH / fdf->map.width / 6;
	if (z1 < z2)
		fdf->map.zoom = z1;
	else
		fdf->map.zoom = z2;
	check_values(fdf);
	draw_rectangles(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
	return (0);
}
