/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:32:27 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/31 11:06:00 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static void	get_map_width(t_fdf	*fdf, char	*str_gnl)
{
	int		width;
	char	**str_split;

	width = 0;
	str_split = ft_split(str_gnl, ' ');
	while (str_split[width])
	{
		if (str_split[width][0] == '\n')
			break ;
		width++;
	}
	free_split(str_split);
	if (!fdf->map.height)
		fdf->map.width = width;
	else if (fdf->map.width != width)
		putstr_error(fdf, "ERROR: Invalid MAP (wrong width)\n", 0);
}

static int	check_number(char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == ',')
			break ;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	convert_number(t_fdf *fdf)
{
	char	**str_split;
	int		i;
	int		c;
	int		j;

	c = -1;
	j = -1;
	fdf->map.map_int2 = (int **)malloc(sizeof(int *) * fdf->map.height);
	if (!fdf->map.map_int2)
		putstr_error(fdf, "ERROR: Cannot allocate malloc\n", 0);
	str_split = ft_split(fdf->map.map_x_y, ' ');
	while (++j < fdf->map.height)
	{
		fdf->map.map_int2[j] = (int *)malloc(sizeof(int) * fdf->map.width);
		if (!fdf->map.map_int2[j])
			putstr_error(fdf, "ERROR: Cannot allocate malloc2\n", --j);
		i = -1;
		while (++i < fdf->map.width)
		{
			if (!check_number(str_split[++c]))
				putstr_error(fdf, "ERROR: Invalid MAP (wrong parameters)\n", 0);
			fdf->map.map_int2[j][i] = ft_atoi(str_split[c]);
		}
	}
	free_split(str_split);
}

static char	*save_map(t_fdf	*fdf, char	*gnl)
{
	char	*new_map;
	int		i;

	i = -1;
	while (gnl[++i])
	{
		if (gnl[i] == '\n')
			gnl[i] = ' ';
	}
	if (!fdf->map.map_x_y)
		new_map = ft_strdup(gnl);
	else
	{
		new_map = ft_strjoin(fdf->map.map_x_y, gnl);
		free(fdf->map.map_x_y);
	}
	free(gnl);
	return (new_map);
}

void	read_map(t_fdf *fdf, char *str)
{
	int		fd;
	char	*gnl;

	if (ft_strlen(str) < 4 && ft_strncmp(&str[ft_strlen(str) - 4], ".fdf", 4))
		putstr_error(fdf, "ERROR : Cannot open the map\n", 2);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		putstr_error(fdf, "ERROR : Cannot open the map\n", 2);
	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		get_map_width(fdf, gnl);
		fdf->map.map_x_y = save_map(fdf, gnl);
		fdf->map.height++;
	}
	close(fd);
	if (fdf->map.height == 1 && fdf->map.width == 1)
		exit(1);
	convert_number(fdf);
	free(fdf->map.map_x_y);
}
