/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_rotations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:34:30 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/15 20:29:15 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	player_rotate_right(t_game *game)
{
	game->player_angle += 0.1;
	game->player_angle = assure_360_deg_angle(game->player_angle);
	game->player_delta_x = cos(game->player_angle) * 5;
	game->player_delta_y = sin(game->player_angle) * 5;
}

void	player_rotate_left(t_game *game)
{
	game->player_angle -= 0.1;
	game->player_angle = assure_360_deg_angle(game->player_angle);
	game->player_delta_x = cos(game->player_angle) * 5;
	game->player_delta_y = sin(game->player_angle) * 5;
}
