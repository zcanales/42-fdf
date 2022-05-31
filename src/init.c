/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:55:50 by zcanales          #+#    #+#             */
/*   Updated: 2022/04/22 08:58:44 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <math.h>

static void	map_init(t_fdf *fdf)
{
	fdf->map.width = 0;
	fdf->map.height = 0;
	fdf->map.map_int2 = NULL;
	fdf->map.map_x_y = NULL;
	fdf->map.angle_x = M_PI / 6;
	fdf->map.angle_y = M_PI / 6;
	fdf->map.move_x = WIDTH / 2;
	fdf->map.move_y = HEIGHT / 2;
}

static void	window_init(t_fdf	*fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "2D - FDF!");
}

void	img_init(t_fdf	*fdf)
{
	fdf->img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img.addr = (int *)mlx_get_data_addr(fdf->img.img,
			&fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
}

void	fdf_init(t_fdf	*fdf)
{
	window_init(fdf);
	map_init(fdf);
}
