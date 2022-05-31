/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:52:22 by zcanales          #+#    #+#             */
/*   Updated: 2021/11/10 16:34:39 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	int				neg;
	int				i;
	unsigned int	sum;

	sum = 0;
	i = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		sum = (sum * 10) + (str[i++] - '0');
	if ((sum > 2147483647 && neg == 1) || (sum > 2147483648 && neg == -1))
	{
		ft_putstr_fd("Error: Invalid MAP (max/min int)", 1);
		exit(2);
	}
	return (sum * neg);
}
