/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:55:46 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/16 16:23:15 by vducoulo         ###   ########.fr       */
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
		check_ray_collision(raycast, raycast->horizontal_ray, game, 0);
		check_ray_collision(raycast, raycast->vertical_ray, game, 1);
		if (raycast->horizontal_ray->traveled_dst
			<= raycast->vertical_ray->traveled_dst)
		{
			//raycast->winning_ray = raycast->horizontal_ray;
			debug_draw_line(game, raycast->last_horiz_x, raycast->last_horiz_y, game->x, game->y, 0x1500FF); //blueray	
		}
		else
		{
			//raycast->winning_ray = raycast->vertical_ray;
			debug_draw_line(game, raycast->last_vert_x, raycast->last_vert_y, game->x, game->y, 0x9EFF00); //yellowray		
		}
		//draw_walls(game, raycast, raycast->winning_ray, i);
		raycast->ray_angle = assure_360_deg_angle(raycast->ray_angle - (DR * 25)
				/ game->window_width / 2);
		i++;
	}
}
