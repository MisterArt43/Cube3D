/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:26:51 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/26 15:56:22 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	test_mlx(t_game *game)
{
	mlx_hook(game->mlx_win, 2, 0, hook_key_press_handler, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);
	return ;
}

void	execution_launcher(char *map)
{
	t_game	*game;

	game = game_initializer();
	if (!game || !map)
		free_and_exit(game, EXIT_FAILURE);
	test_mlx(game);
	free_and_exit(game, EXIT_SUCCESS);
}
