/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:15:00 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/31 11:05:58 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	if (argc == 2)
	{
		fdf_init(&fdf);
		read_map(&fdf, argv[1]);
		draw(&fdf);
		fdf_event(&fdf);
		mlx_loop(fdf.mlx);
	}
	else
		ft_putstr_fd("Correct usage: ./fdf [map]\n", 1);
	return (0);
}
