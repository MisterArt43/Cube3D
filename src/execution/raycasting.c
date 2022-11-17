/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:55:46 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/17 21:57:48 by vducoulo         ###   ########.fr       */
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
		check_ray_collision(raycast, &raycast->vertical_ray, game, 1);
		check_ray_collision(raycast, &raycast->horizontal_ray, game, 0);
		if (raycast->horizontal_ray.traveled_dst
			<= raycast->vertical_ray.traveled_dst)
		{
			draw_walls(game, raycast, &raycast->horizontal_ray, i);
		}
		else
		{
			draw_walls(game, raycast, &raycast->vertical_ray, i);
		}
		raycast->ray_angle = assure_360_deg_angle(raycast->ray_angle - (DR * 50)
				/ game->window_width);
		i++;
	}
}
