/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:51:40 by zcanales          #+#    #+#             */
/*   Updated: 2022/04/22 08:54:10 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../Libft/libft.h"
# include "../mlx/mlx.h"
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_cord
{
	int	x;
	int	y;
}t_cord;

typedef struct s_breshen
{
	int	dx;
	int	dy;
	int	cte;
	int	next;
}t_breshen;

typedef struct s_data
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

typedef struct s_map
{
	int		width;
	int		height;
	char	*map_x_y;
	int		**map_int2;
	t_cord	begin;
	t_cord	end;
	int		z_min;
	int		z_max;
	int		z_range;
	int		color;
	double	angle_x;
	double	angle_y;
	double	zoom;
	int		move_x;
	int		move_y;
}t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_map	map;
	int		dif_x;
	int		dif_y;
}t_fdf;

void	fdf_init(t_fdf *fdf);
void	img_init(t_fdf *fdf);
void	fdf_event(t_fdf *fdf);
int		draw(t_fdf *fdf);
void	read_map(t_fdf *fdf, char *file);
void	bresenham_algo(t_fdf *fdf, t_cord *begin, t_cord *end);
char	*get_next_line(int fd);
void	z_range(t_fdf *fdf);
void	free_int(t_fdf *fdf, int limit);
void	free_split(char **str_split);
void	putstr_error(t_fdf *fdf, char *str, int limit);
#endif
