/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:26:51 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/27 15:53:02 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	event_handler(t_game *game)
{
	game_grid_drawer(game);
	move_my_player(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
	return ;
}

void	game_renderer(t_game *game)
{
	game_grid_drawer(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, hook_key_press_handler, game);
	mlx_hook(game->mlx_win, 17, 1L << 0, free_and_exit, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, hook_key_release_handler, game);
	mlx_loop_hook(game->mlx, event_handler, game);
	mlx_loop(game->mlx);
	return ;
}

void	execution_launcher(char *map)
{
	t_game	*game;

	game = game_initializer(map);
	if (!game || !map)
		free_and_exit(game, EXIT_FAILURE);
	game_renderer(game);
	free_and_exit(game, EXIT_SUCCESS);
}
