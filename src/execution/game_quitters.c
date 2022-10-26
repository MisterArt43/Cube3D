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

//add free matrix
void	free_my_game(t_game *game)
{
	free(game);
}
