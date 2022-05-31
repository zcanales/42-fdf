/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_range.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:12:04 by zcanales          #+#    #+#             */
/*   Updated: 2021/11/11 12:52:33 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	z_range(t_fdf *fdf)
{
	int	h;
	int	w;

	h = -1;
	fdf->map.z_min = fdf->map.map_int2[0][0];
	fdf->map.z_max = fdf->map.map_int2[0][0];
	while (++h < fdf->map.height)
	{
		w = -1;
		while (++w < fdf->map.width)
		{
			if (fdf->map.map_int2[h][w] > fdf->map.z_max)
				fdf->map.z_max = fdf->map.map_int2[h][w];
			if (fdf->map.map_int2[h][w] < fdf->map.z_min)
				fdf->map.z_min = fdf->map.map_int2[h][w];
		}
	}
	fdf->map.z_range = abs(fdf->map.z_max - fdf->map.z_min);
}
