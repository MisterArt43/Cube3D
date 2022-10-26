/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:18:43 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/26 22:20:44 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	hook_key_press_handler(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 53)
		free_and_exit(game, EXIT_SUCCESS);
	if (keycode == 13)
		game->movement_tab[0] = 1;
	if (keycode == 1)
		game->movement_tab[1] = 1;
	if (keycode == 0)
		game->movement_tab[2] = 1;
	if (keycode == 2)
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
	if (keycode == 13)
		game->movement_tab[0] = 0;
	if (keycode == 1)
		game->movement_tab[1] = 0;
	if (keycode == 0)
		game->movement_tab[2] = 0;
	if (keycode == 2)
		game->movement_tab[3] = 0;
	if (keycode == 124)
		game->movement_tab[4] = 0;
	if (keycode == 123)
		game->movement_tab[5] = 0;
	return (0);
}
