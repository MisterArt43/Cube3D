/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:21:20 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/19 21:41:37 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	texture_id_attributor(t_texture_info *alltextures)
{
	alltextures->north_texture->texture_id = 2;
	alltextures->south_texture->texture_id = 4;
	alltextures->east_texture->texture_id = 3;
	alltextures->west_texture->texture_id = 1;
}

void	init_game_window(t_game *game)
{
	game->window_width = 2048;
	game->window_height = 1024;
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
}

void	null_game_struct(t_game *game)
{
	game->all_textures = NULL;
	game->img = NULL;
	game->mlx_win = NULL;
	game->game_tab = NULL;
	game->raycast = NULL;
}

void	game_initializer(char *map_path, t_game *game)
{
	game->movement_tab[0] = 0;
	game->movement_tab[1] = 0;
	game->movement_tab[2] = 0;
	game->movement_tab[3] = 0;
	game->movement_tab[4] = 0;
	game->movement_tab[5] = 0;
	null_game_struct(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game->all_textures = textures_initializer();
	if (!game->all_textures)
		free_and_exit(game, EXIT_FAILURE);
	start_parse(map_path, game);
	texture_id_attributor(game->all_textures);
	init_game_window(game);
	game->game_cell_size = 64;
	game->displacement_speed = 4;
	game->player_delta_x = cos(game->player_angle) * 5;
	game->player_delta_y = sin(game->player_angle) * 5;
	game->raycast = (t_raycast *)ft_calloc(1, sizeof(t_raycast));
	if (!game->raycast)
		return ;
}
