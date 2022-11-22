/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:30:31 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/19 19:51:40 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	player_move_forward(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->x + game->player_delta_x * 2;
	new_y = game->y + game->player_delta_y * 2;
	if (BONUS != 1 || !is_wall_coliding(game, new_x, new_y))
	{
		game->x += game->player_delta_x * 2;
		game->y += game->player_delta_y * 2;
	}
	return ;
}

void	player_move_backward(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->x - game->player_delta_x * 2;
	new_y = game->y - game->player_delta_y * 2;
	if (BONUS != 1 || !is_wall_coliding(game, new_x, new_y))
	{
		game->x -= game->player_delta_x * 2;
		game->y -= game->player_delta_y * 2;
	}
	return ;
}

void	player_turn_left(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->x + cos(game->player_angle + M_PI / 2) * 5;
	new_y = game->y + sin(game->player_angle + M_PI / 2) * 5;
	if (BONUS != 1 || !is_wall_coliding(game, new_x, new_y))
	{
		game->x += cos(game->player_angle + M_PI / 2) * 5;
		game->y += sin(game->player_angle + M_PI / 2) * 5;
	}
	return ;
}

void	player_turn_right(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->x + cos(game->player_angle - M_PI / 2) * 5;
	new_y = game->y + sin(game->player_angle - M_PI / 2) * 5;
	if (BONUS != 1 || !is_wall_coliding(game, new_x, new_y))
	{
		game->x += cos(game->player_angle - M_PI / 2) * 5;
		game->y += sin(game->player_angle - M_PI / 2) * 5;
	}
	return ;
}

void	move_my_player(t_game *game)
{
	if (game->movement_tab[0])
		player_move_forward(game);
	if (game->movement_tab[1])
		player_move_backward(game);
	if (game->movement_tab[2])
		player_turn_left(game);
	if (game->movement_tab[3])
		player_turn_right(game);
	if (game->movement_tab[4])
		player_rotate_right(game);
	if (game->movement_tab[5])
		player_rotate_left(game);
	print_player_position(game);
}
