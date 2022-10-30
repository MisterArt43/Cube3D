/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:02:24 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/30 16:06:46 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

double	get_traveled_ray_distance(t_game *game, t_raycast *raycast)
{
	return (cos(raycast->ray_angle) * (raycast->ray_x - game->x)
		- sin(raycast->ray_angle) * (raycast->ray_y - game->y));
}
