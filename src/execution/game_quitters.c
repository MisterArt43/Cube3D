/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_quitters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:31:59 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/26 22:28:59 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	free_and_exit(t_game *game, int exit_status)
{
	if (game)
		free_my_game(game);
	exit(exit_status);
}

int	ft_stop_mlx(t_game *game)
{
	free_and_exit(game, EXIT_SUCCESS);
	return (1);
}

void	free_my_game(t_game *game)
{
	txt_stop_all(game);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->game_tab)
		free_map(game->game_tab, game->game_tab_height - 1);
	stop_mlx(game);
	if (game->raycast)
		free(game->raycast);
	free(game);
}
