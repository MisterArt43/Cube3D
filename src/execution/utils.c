/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:10:33 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/10 13:57:22 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

unsigned long	rgb_to_hexa(int color[3])
{
	return (((color[0] & 0xff) << 16) + ((color[1] & 0xff) << 8)
		+ (color[2] & 0xff));
}

int	ft_atoi_cub_edition(const char *str)
{
	int		sign;
	size_t	i;
	size_t	r;

	sign = 1;
	i = 0;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (r * sign);
}
