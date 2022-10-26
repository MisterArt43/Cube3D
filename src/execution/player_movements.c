/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:30:31 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/26 22:35:17 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	move_my_player(t_game *game)
{
	if (game->movement_tab[0])
		player_move_forward();
	if (game->movement_tab[1])
		player_move_backward();
	if (game->movement_tab[2])
		player_turn_left();
	if (game->movement_tab[3])
		player_turn_right();
	if (game->movement_tab[4])
		player_rotate_right();
	if (game->movement_tab[5])
		player_rotate_left();
}

void	player_move_forward(void)
{
	return ;
}

void	player_move_backward(void)
{
	return ;
}

void	player_turn_right(void)
{
	return ;
}

void	player_turn_left(void)
{
	return ;
}
