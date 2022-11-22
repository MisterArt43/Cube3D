/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_grid_drawer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:40:19 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/17 22:05:24 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	print_player_position(t_game *game)
{
	int	corrected_x;
	int	corrected_y;

	corrected_x = game->x / 7.1 + 16;
	corrected_y = game->y / 7.1 + game->window_height
		- (game->game_tab_height * game->game_cell_size / 7) - 16;
	my_mlx_pixel_put(game, corrected_x, corrected_y, 0x04ff00);
}

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
			top_left.x = 16 + (x * (game->game_cell_size / 7));
			top_left.y = (game->window_height
					- game->game_tab_height * game->game_cell_size / 7 - 16)
				+ (y * (game->game_cell_size / 7));
			bottom_right.x = top_left.x + (game->game_cell_size / 7);
			bottom_right.y = top_left.y + (game->game_cell_size / 7);
			vd_cube_drawer(game, &top_left, &bottom_right, 0x00000000);
			if (game->game_tab[y][x] == 1)
				vd_cube_drawer(game, &top_left, &bottom_right, 0x003C47);
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
