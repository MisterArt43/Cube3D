/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:21:20 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/10 17:57:23 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_game	*game_initializer(char *map_path)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->window_width = 1200; //base_v = 1800
	game->window_height = 800; //base_v = 1100
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
	game->game_tab_height = 19; // debug / modified by parsing
	game->game_tab_width = 29; // debug / modified by parsing
	if (game->game_tab_width >= game->game_tab_height)
		game->game_tab_max_encountred_cell = game->game_tab_width;
	else
		game->game_tab_max_encountred_cell = game->game_tab_height;
	game->game_tab = tmp_game_tab_feeder(map_path, game);
	//game->game_cell_size = game->window_height / game->game_tab_height;
	game->game_cell_size = 64;
	game->displacement_speed = 4;
	game->player_angle = 2 * M_PI; // debug, change wiyh N, E, O angle
	game->floor_color[0] = 214; // debug / modified by parsing
	game->floor_color[1] = 214;// debug / modified by parsing
	game->floor_color[2] = 214;// debug / modified by parsing
	game->ceilling_color[0] = 180;// debug / modified by parsing
	game->ceilling_color[1] = 183;// debug / modified by parsing
	game->ceilling_color[2] = 207;	// debug / modified by parsing
	game->player_delta_x = cos(game->player_angle) * 5;
	game->player_delta_y = sin(game->player_angle) * 5;
	game->raycast = raycast_initializer(game); //malloc à protéger
	game->all_textures = textures_initializer(game); // malloc à protéger
	return (game);
}

t_raycast	*raycast_initializer(t_game *game)
{
	t_raycast	*raycast;

	raycast = (t_raycast *)ft_calloc(1, sizeof(t_raycast));
	raycast->ray_count = 60;
	return (raycast);
}
