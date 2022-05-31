/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:17:20 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/31 11:05:44 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdlib.h>

void	free_split(char **str_split)
{
	int	i;

	i = 0;
	while (str_split[i])
		free(str_split[i++]);
	free(str_split);
}

void	free_int(t_fdf *fdf, int limit)
{
	int	height;

	height = -1;
	while (++height < limit)
		free(fdf->map.map_int2[height]);
	free(fdf->map.map_int2);
}

void	putstr_error(t_fdf *fdf, char *str, int limit)
{
	if (!ft_strncmp("ERROR: Cannot allocate malloc2\n", str, ft_strlen(str)))
		free_int(fdf, limit);
	ft_putstr_fd(str, 1);
	exit(2);
}
