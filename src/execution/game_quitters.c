/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_quitters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:31:59 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/26 15:36:47 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	free_and_exit(t_game *game, int exit_status)
{
	if (game)
		free_my_game(game);
	exit(exit_status);
}

void	free_my_game(t_game *game)
{
	free(game);
}
