/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:55:46 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/27 17:31:46 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	raycasting(t_game *game)
{
	int			i;
	t_raycast	raycast;

	i = 0;
	raycast = game->raycast;
	raycast.ray_angle = game->player_angle;
	raycast.depth_of_field = 0;
	while (i < game->raycast.ray_count)
	{
		check_horizontal_ray_collision(raycast, game);
	}
	return ;
}

void	check_horizontal_ray_collision(t_raycast raycast, t_game *game)
{
	float	a_tan;

	a_tan = -1 / tan(raycast.ray_angle);
	if (raycast.ray_angle > PI)
	{
		raycast.ray_y = ((game->y >> 6) << 6) - 0.0001;
		raycast.ray_x = (game->x - game->y) * a_tan + game->x;
		raycast.ray_y_offset = -64;
		raycast.ray_y_offset = -raycast.ray_y_offset * a_tan;
	}
	else if (raycast.ray_angle < PI)
	{
		raycast.ray_y = ((game->y >> 6) << 6) + 64;
		raycast.ray_x = (game->x - game->y) * a_tan + game->x;
		raycast.ray_y_offset = 64;
		raycast.ray_y_offset = -raycast.ray_y_offset * a_tan;
	}
	else if (raycast.ray_angle == 0 || raycast.ray_angle == PI)
	{
		raycast.ray_x = game->x;
		raycast.ray_y = game->y;
		raycast.depth_of_field = 8;
	}
	while (raycast.depth_of_field < 8)
	{
		
	}
}
