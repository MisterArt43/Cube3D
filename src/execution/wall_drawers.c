/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_drawers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:19:42 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/07 15:48:00 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	draw_walls(t_game *game, t_raycast *raycast, int x)
{
	int	wall_height;
	int	y;
	int	i;

	i = 0;
	wall_height = 128 * game->window_height / (int)raycast->min_traveled;
	if (wall_height > game->window_height)
		wall_height = game->window_height;
	ft_printf("\n wall height : %d", wall_height);
	y = game->window_height / 2 - wall_height / 2;
	if (y < 0)
		i = -y;
	while (i < wall_height && y + i < wall_height)
	{
		my_mlx_pixel_put(game, x, y + i, 0xff0000);
		i++;
	}
	return ;
}
