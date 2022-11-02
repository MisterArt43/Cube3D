/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_player_angle_adapters.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:42:50 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/02 21:14:22 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	raycasting_horizontal_looking_up(t_game *game, t_raycast *raycast,
		float a_tan)
{
	raycast->ray_y = ((game->y >> 6) << 6) - 0.0001;
	raycast->ray_x = (game->y - raycast->ray_y) * a_tan + game->x;
	raycast->ray_y_offset = -game->game_cell_size;
	raycast->ray_x_offset = -raycast->ray_y_offset * a_tan;
	return ;
}

void	raycasting_horizontal_looking_down(t_game *game, t_raycast *raycast,
		float a_tan)
{
	raycast->ray_y = ((game->y >> 6) << 6) + game->game_cell_size;
	raycast->ray_x = (game->y - raycast->ray_y) * a_tan + game->x;
	raycast->ray_y_offset = game->game_cell_size;
	raycast->ray_x_offset = -raycast->ray_y_offset * a_tan;
	return ;
}

void	raycasting_looking_straight(t_game *game, t_raycast *raycast)
{
	raycast->ray_x = game->x;
	raycast->ray_y = game->y;
	raycast->depth_of_field = DOF_DELIM;
	return ;
}

void	raycasting_vertical_looking_right(t_game *game, t_raycast *raycast,
		float a_tan)
{
	raycast->ray_x = ((game->x >> 6) << 6) + game->game_cell_size;
	raycast->ray_y = (game->x - raycast->ray_x) * a_tan + game->y;
	raycast->ray_x_offset = game->game_cell_size;
	raycast->ray_y_offset = -raycast->ray_x_offset * a_tan;
	return ;
}

void	raycasting_vertical_looking_left(t_game *game, t_raycast *raycast,
		float a_tan)
{
	raycast->ray_x = ((game->x >> 6) << 6) - 0.0001;
	raycast->ray_y = (game->x - raycast->ray_x) * a_tan + game->y;
	raycast->ray_x_offset = -game->game_cell_size;
	raycast->ray_y_offset = -raycast->ray_x_offset * a_tan;
	return ;
}
