/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_grid_drawer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:40:19 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/26 18:58:51 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	game_grid_drawer(t_game *game)
{
	t_vector2d	top_left;
	t_vector2d	bottom_right;
	int			y;
	int			x;

	y = 0;
	while (y < game->game_tab_height)
	{
		x = 0;
		while (x < game->game_tab_width)
		{
			if (game->game_tab[y][x] == 1)
			{
				top_left.x = x * game->game_cell_size;
				top_left.y = y * game->game_cell_size;
				bottom_right.x = top_left.x + game->game_cell_size;
				bottom_right.y = top_left.y + game->game_cell_size;
				vd_cube_drawer(game, &top_left, &bottom_right, 0x00FF0000);
			}
			x ++;
		}
		y ++;
	}
}

void	vd_cube_drawer(t_game *game, t_vector2d *top_left,
	t_vector2d *bottom_right, int color)
{
	int	x;
	int	y;

	y = top_left->y;
	while (y < bottom_right->y)
	{
		x = top_left->x;
		while (x < bottom_right->x)
		{
			my_mlx_pixel_put(game, x, y, color);
			x ++;
		}
		y ++;
	}
}
