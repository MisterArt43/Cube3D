/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:10 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/26 16:01:02 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	ft_print_five(char selectid, int increment, t_game *game)
{
	int	bx;
	int	by;

	bx = game->x;
	by = game->y;
	if (selectid == 'x' && increment)
		while (game->x < bx + 5)
			my_mlx_pixel_put(game, ++game->x, game->y, 0x00FF0000);
	if (selectid == 'x' && !increment)
		while (game->x > bx - 5)
			my_mlx_pixel_put(game, --game->x, game->y, 0x00FF0000);
	if (selectid == 'y' && increment)
		while (game->y < by + 5)
			my_mlx_pixel_put(game, game->x, ++game->y, 0x00FF0000);
	if (selectid == 'y' && !increment)
		while (game->y > by - 5)
			my_mlx_pixel_put(game, game->x, --game->y, 0x00FF0000);
}
