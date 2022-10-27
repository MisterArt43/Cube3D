/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:10 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/27 16:29:27 by vducoulo         ###   ########.fr       */
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
		while (game->x < bx + game->displacement_speed)
			my_mlx_pixel_put(game, ++game->x, game->y, 0xd4d8fa);
	if (selectid == 'x' && !increment)
		while (game->x > bx - game->displacement_speed)
			my_mlx_pixel_put(game, --game->x, game->y, 0xd4d8fa);
	if (selectid == 'y' && increment)
		while (game->y < by + game->displacement_speed)
			my_mlx_pixel_put(game, game->x, ++game->y, 0xd4d8fa);
	if (selectid == 'y' && !increment)
		while (game->y > by - game->displacement_speed)
			my_mlx_pixel_put(game, game->x, --game->y, 0xd4d8fa);
}

void	print_player_position(t_game *game)
{
	my_mlx_pixel_put(game, game->x, game->y, 0xd4d8fa);
	my_mlx_pixel_put(game, game->x + 1, game->y, 0xd4d8fa);
	my_mlx_pixel_put(game, game->x, game->y + 1, 0xd4d8fa);
	my_mlx_pixel_put(game, game->x + 1, game->y + 1, 0xd4d8fa);
}

void	debug_print_cubname(t_game *game)
{
	while (game->y < 200)
	{
		my_mlx_pixel_put(game, game->x, ++game->y, 0x00FF0000);
		usleep(100000);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
	}
}
