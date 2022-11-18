/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_collisions_checker.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:08:31 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/15 20:25:01 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	check_ray_collision(t_raycast *raycast, t_ray *ray,
	t_game *game, int vertical)
{
	ray->traveled_dst = 10000000;
	ray->depth_of_field = 0;
	raycasting_angle_interpeter(vertical, game, ray, raycast->ray_angle);
	while (ray->depth_of_field < game->game_tab_max_encountred_cell)
	{
		ray->map_x = (int)ray->x >> 6;
		ray->map_y = (int)ray->y >> 6;
		if (is_in_map_limits(game, ray->map_x, ray->map_y)
			&& game->game_tab[ray->map_y][ray->map_x] == 1)
		{
			ray->depth_of_field = game->game_tab_max_encountred_cell;
			ray->traveled_dst = get_traveled_ray_distance(game->x,
					game->y, ray->x, ray->y);
		}
		else
		{
			ray->x += ray->x_offset;
			ray->y += ray->y_offset;
			ray->depth_of_field ++;
		}
	}
}
