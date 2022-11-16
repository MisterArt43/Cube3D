/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:16:40 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/27 17:10:34 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	render_next_frame(t_game *game)
{
	//game_grid_drawer(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
	return (0);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > game->window_width - 1 || y < 0
		|| y > game->window_height - 1)
		return ;
	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel));
	*(unsigned int *)dst = color;
}
