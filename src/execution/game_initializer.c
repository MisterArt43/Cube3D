/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:21:20 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/16 14:12:37 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_game	*game_initializer(char *map_path)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->window_width = 1200;
	game->window_height = 800;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free(game), exit(EXIT_FAILURE), NULL);
	start_parse(map_path, game);
	game->mlx_win = mlx_new_window(game->mlx, game->window_width,
			game->window_height,
			"Cub3D");
	game->img = mlx_new_image(game->mlx, game->window_width,
			game->window_height);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	game->bits_per_pixel /= 8;
	if (game->game_tab_width >= game->game_tab_height)
		game->game_tab_max_encountred_cell = game->game_tab_width;
	else
		game->game_tab_max_encountred_cell = game->game_tab_height;
	game->game_cell_size = 64;
	game->displacement_speed = 4;
	game->player_delta_x = cos(game->player_angle) * 5;
	game->player_delta_y = sin(game->player_angle) * 5;
	game->raycast = (t_raycast *)ft_calloc(1, sizeof(t_raycast));
	if (!game->raycast)
		return (NULL);
	//game->all_textures = textures_initializer(game); // malloc à protéger
	return (game);
}

t_raycast	*raycast_initializer(t_game *game)
{
	t_raycast	*raycast;

	raycast = (t_raycast *)ft_calloc(1, sizeof(t_raycast));
	return (raycast);
}
