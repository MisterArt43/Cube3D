/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:55:46 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/10 13:38:47 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	raycasting(t_game *game)
{
	int			i;
	t_raycast	*raycast;

	i = 0;
	raycast = game->raycast;
	raycast->ray_angle = assure_360_deg_angle(game->player_angle + (DR * 25));
	while (i < game->window_width)
	{
		raycast->traveled_horiz = 10000000;
		raycast->traveled_vert = 10000000;
		raycast->depth_of_field = 0;
		check_horizontal_ray_collision(raycast, game);
		raycast->depth_of_field = 0;
		check_vertical_ray_collision(raycast, game);
		if (raycast->traveled_horiz <= raycast->traveled_vert)
		{
			raycast->min_traveled = raycast->traveled_horiz;
			//debug_draw_line(game, raycast->last_horiz_x, raycast->last_horiz_y, game->x, game->y, 0x1500FF); //blueray
			//my_mlx_pixel_put(game, raycast->last_horiz_x, raycast->last_horiz_y, 0x00FFFF);		
		}
		else
		{
			raycast->min_traveled = raycast->traveled_vert;
			//debug_draw_line(game, raycast->last_vert_x, raycast->last_vert_y, game->x, game->y, 0x9EFF00); //yellowray
			//my_mlx_pixel_put(game, raycast->last_vert_x, raycast->last_vert_y, 0x00FFFF);		
		}
		draw_walls(game, raycast, i);
		raycast->ray_angle = assure_360_deg_angle(raycast->ray_angle - (DR * 50) / game->window_width);
		i++;
	}
}
