/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:30:31 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/16 17:42:43 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	player_move_forward(t_game *game)
{
	game->x += game->player_delta_x;
	game->y += game->player_delta_y;
	my_mlx_pixel_put(game, game->x, game->y, 0xd4d8fa);
	return ;
}

void	player_move_backward(t_game *game)
{
	game->x -= game->player_delta_x;
	game->y -= game->player_delta_y;
	my_mlx_pixel_put(game, game->x, game->y, 0xd4d8fa);
	return ;
}

void	player_turn_right(t_game *game)
{
	game->x -= game->player_delta_x * 5;
	return ;
}

void	player_turn_left(t_game *game)
{
	game->y -= game->player_delta_y * 5;
	//ft_print_five('x', 0, game);
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
