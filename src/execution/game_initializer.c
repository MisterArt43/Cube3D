/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:21:20 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/26 16:07:26 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_game	*game_initializer(void)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->window_width = 1800;
	game->window_height = 1100;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->window_width,
			game->window_height,
			"Cub3D");
	game->img = mlx_new_image(game->mlx, game->window_width,
			game->window_height);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	game->x = 100; // debug 
	game->y = 100; // debug
	return (game);
}
