/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:01:27 by zcanales          #+#    #+#             */
/*   Updated: 2022/04/22 09:42:02 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	draw_x_cte(t_fdf *fdf, t_cord *begin, t_cord *end)
{
	t_breshen	b;

	b.dx = end->x - begin->x;
	b.dy = end->y - begin->y;
	b.next = 1;
	if (b.dx < 0)
	{
		b.next = -1;
		b.dx *= -1;
	}
	b.cte = (2 * b.dx) - b.dy;
	while (begin->y < end->y)
	{
		fdf->img.addr[begin->y * WIDTH + begin->x] = 0xFF00FF;
		if (b.cte > 0)
		{
			begin->x += b.next;
			b.cte = b.cte + (2 * b.dx) - (2 * b.dy);
		}
		else
			b.cte = b.cte + 2 * b.dx;
		begin->y++;
	}
}

static void	draw_y_cte(t_fdf *fdf, t_cord *begin, t_cord *end)
{
	t_breshen	b;

	b.dx = end->x - begin->x;
	b.dy = end->y - begin->y;
	b.next = 1;
	if (b.dy < 0)
	{
		b.next = -1;
		b.dy *= -1;
	}
	b.cte = (2 * b.dy) - b.dx;
	while (begin->x < end->x)
	{
		fdf->img.addr[begin->y * WIDTH + begin->x] = 0xFF00FF;
		if (b.cte > 0)
		{
			begin->y += b.next;
			b.cte = b.cte + (2 * b.dy) - (2 * b.dx);
		}
		else
			b.cte = b.cte + 2 * b.dy;
		begin->x++;
	}
}

void	bresenham_algo(t_fdf *fdf, t_cord *begin, t_cord *end)
{
	if (abs(end->y - begin->y) < abs(end->x - begin->x))
	{
		if (begin->x > end->x)
			draw_y_cte(fdf, end, begin);
		else
			draw_y_cte(fdf, begin, end);
	}
	else
	{
		if (begin->y > end->y)
			draw_x_cte(fdf, end, begin);
		else
			draw_x_cte(fdf, begin, end);
	}
}
