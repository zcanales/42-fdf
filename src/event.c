/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:53:17 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/31 11:05:58 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	mouse_press_exit(int keycode, t_fdf *fdf)
{
	(void)keycode;
	(void)fdf;
	return (0);
}

static int	key_press_exit(int keycode, t_fdf *fdf)
{
	(void)fdf;
	if (keycode == 53)
		exit(0);
	return (0);
}

void	fdf_event(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 1, key_press_exit, &fdf);
	mlx_hook(fdf->win, 17, 1L << 5, mouse_press_exit, &fdf);
}
