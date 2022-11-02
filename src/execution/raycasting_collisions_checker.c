/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_collisions_checker.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:08:31 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/02 23:39:45 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	check_horizontal_ray_collision(t_raycast *raycast, t_game *game)
{
	raycasting_angle_interpeter(0, game, raycast);
	while (raycast->depth_of_field < DOF_DELIM)
	{
		raycast->map_x = (int)raycast->ray_x >> 6;
		raycast->map_y = (int)raycast->ray_y >> 6;
		if (is_in_map_limits(game, raycast->map_x, raycast->map_y)
			&& game->game_tab[raycast->map_y][raycast->map_x] == 1)
		{
			raycast->last_horiz_x = raycast->ray_x;
			raycast->last_horiz_y = raycast->ray_y;
			raycast->depth_of_field = 8;
			raycast->traveled_horiz = get_traveled_ray_distance(game->x,
					game->y, raycast->ray_x, raycast->ray_y);
		}
		else
		{
			raycast->ray_x += raycast->ray_x_offset;
			raycast->ray_y += raycast->ray_y_offset;
			raycast->depth_of_field ++;
		}
	}
}

void	check_vertical_ray_collision(t_raycast *raycast, t_game *game)
{
	raycasting_angle_interpeter(1, game, raycast);
	while (raycast->depth_of_field < DOF_DELIM)
	{
		raycast->map_x = (int)raycast->ray_x >> 6;
		raycast->map_y = (int)raycast->ray_y >> 6;
		if (is_in_map_limits(game, raycast->map_x, raycast->map_y)
			&& game->game_tab[raycast->map_y][raycast->map_x] == 1)
		{
			raycast->last_vert_x = raycast->ray_x;
			raycast->last_vert_y = raycast->ray_y;
			raycast->traveled_vert = get_traveled_ray_distance(game->x,
					game->y, raycast->ray_x, raycast->ray_y);
			raycast->depth_of_field = 8;
		}
		else
		{
			raycast->ray_x += raycast->ray_x_offset;
			raycast->ray_y += raycast->ray_y_offset;
			raycast->depth_of_field ++;
		}
	}
}
