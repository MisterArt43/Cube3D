/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:18:43 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/27 15:54:50 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	hook_key_press_handler(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 53)
		free_and_exit(game, EXIT_SUCCESS);
	if (keycode == 65362)
		game->movement_tab[0] = 1;
	if (keycode == 65364)
		game->movement_tab[1] = 1;
	if (keycode == 65361)
		game->movement_tab[2] = 1;
	if (keycode == 65363)
		game->movement_tab[3] = 1;
	if (keycode == 124)
		game->movement_tab[4] = 1;
	if (keycode == 123)
		game->movement_tab[5] = 1;
	return (0);
}

int	hook_key_release_handler(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 53)
		free_and_exit(game, EXIT_SUCCESS);
	if (keycode == 65362)
		game->movement_tab[0] = 0;
	if (keycode == 65364)
		game->movement_tab[1] = 0;
	if (keycode == 65361)
		game->movement_tab[2] = 0;
	if (keycode == 65363)
		game->movement_tab[3] = 0;
	if (keycode == 124)
		game->movement_tab[4] = 0;
	if (keycode == 123)
		game->movement_tab[5] = 0;
	return (0);
}
