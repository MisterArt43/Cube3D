/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:55:46 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/02 21:49:30 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	raycasting(t_game *game)
{
	int			i;
	t_raycast	*raycast;

	i = 0;
	raycast = game->raycast;
	raycast->ray_angle = game->player_angle - DR * 30;
	if (raycast->ray_angle < 0)
		raycast->ray_angle += 2 * M_PI;
	if (raycast->ray_angle > 2 * M_PI)
		raycast->ray_angle -= 2 * M_PI;
	//raycast->ray_angle = game->player_angle;
	while (i < raycast->ray_count)
	{
		raycast->traveled_horiz = 10000000;
		raycast->traveled_vert = 10000000;
		raycast->depth_of_field = 0;
		check_horizontal_ray_collision(raycast, game);
		raycast->depth_of_field = 0;
		check_vertical_ray_collision(raycast, game);
		if (raycast->traveled_horiz <= raycast->traveled_vert)
			debug_draw_line(game, raycast->last_horiz_x, raycast->last_horiz_y, game->x, game->y, 0x00FF0000);
		else
			debug_draw_line(game, raycast->last_vert_x, raycast->last_vert_y, game->x, game->y, 0x00FF0000);
		raycast->ray_angle += DR;
		i++;
	}
	return ;
}
