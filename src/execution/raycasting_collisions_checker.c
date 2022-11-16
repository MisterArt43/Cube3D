/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_collisions_checker.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:08:31 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/11 12:44:51 by vducoulo         ###   ########.fr       */
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

// void	check_vertical_ray_collision(t_raycast *raycast, t_ray *ray,
// 	t_game *game)
// {
// 	raycasting_angle_interpeter(1, game, ray, raycast->ray_angle);
// 	while (ray->depth_of_field < game->game_tab_max_encountred_cell)
// 	{
// 		raycast->map_x = (int)raycast->ray_x >> 6;
// 		raycast->map_y = (int)raycast->ray_y >> 6;
// 		if (is_in_map_limits(game, raycast->map_x, raycast->map_y)
// 			&& game->game_tab[raycast->map_y][raycast->map_x] == 1)
// 		{
// 			//my_mlx_pixel_put(game, raycast->ray_x, raycast->ray_y, 0x00FFFF);
// 			raycast->last_vert_x = raycast->ray_x;
// 			raycast->last_vert_y = raycast->ray_y;
// 			raycast->depth_of_field = game->game_tab_max_encountred_cell;
// 			raycast->traveled_vert = get_traveled_ray_distance(game->x,
// 					game->y, raycast->ray_x, raycast->ray_y);
// 		}
// 		else
// 		{
// 			raycast->ray_x += raycast->ray_x_offset;
// 			raycast->ray_y += raycast->ray_y_offset;
// 			raycast->depth_of_field ++;
// 		}
// 	}
// }
