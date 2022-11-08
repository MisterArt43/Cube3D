/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_drawers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:19:42 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/09 00:49:39 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	draw_walls(t_game *game, t_raycast *raycast, int x)
{
	int	wall_height;
	int	y;
	int	i;

	raycast->min_traveled = raycast->min_traveled * cos(assure_360_deg_angle(game->player_angle - raycast->ray_angle));
	i = 0;
	wall_height = 128 * game->window_height / (int)raycast->min_traveled;
	if (wall_height > game->window_height)
		wall_height = game->window_height;
	y = game->window_height / 2 - wall_height / 2;
	//ft_printf ("\n y : %d, wall_h : %d", y, wall_height);
	if (y < 0)
		i = -y;
	while (i < wall_height && y + i < game->window_height)
	{
		my_mlx_pixel_put(game, x, y + i, 0xff0000);
		i++;
	}
	return ;
}
