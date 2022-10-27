/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_rotations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:34:30 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/27 16:31:15 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	player_rotate_right(t_game *game)
{
	game->player_angle += 0.1;
	if (game->player_angle > 2 * PI)
		game->player_angle -= 2 * PI;
	game->player_delta_x = cos(game->player_angle) * 5;
	game->player_delta_y = sin(game->player_angle) * 5;
	if (DEBUG == 1)
		printf("\nplayer_angle : %f", game->player_angle);
	return ;
}

void	player_rotate_left(t_game *game)
{
	game->player_angle -= 0.1;
	if (game->player_angle < 0)
		game->player_angle += 2 * PI;
	game->player_delta_x = cos(game->player_angle) * 5;
	game->player_delta_y = sin(game->player_angle) * 5;
	if (DEBUG == 1)
		printf("\nplayer_angle : %f", game->player_angle);
	return ;
}
