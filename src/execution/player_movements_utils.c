/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:18:28 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/17 22:24:55 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	is_wall_coliding(t_game *game, float x, float y)
{
	if (!is_in_window_limits(game, x, y))
		return (1);
	if (game->game_tab[(int)y / game->game_cell_size][(int)x
		/ game->game_cell_size] == 1)
		return (1);
	return (0);
}
