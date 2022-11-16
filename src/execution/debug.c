/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:10 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/02 20:34:10 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	set_mlx_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->window_height)
	{
		x = 0;
		while (x < game->window_width)
		{
			my_mlx_pixel_put(game, x, y, 0x333333);
			x ++;
		}
		y ++;
	}
}

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

void	debug_draw_line(t_game *game, int x0, int y0, int x1, int y1, int color)
{
	int	x;
	int	y;

	for (float i = 0.0; i <= 1; i += 0.005)
	{
		x = x0 + (x1 - x0) * i;
		y = y0 + (y1 - y0) * i;
		my_mlx_pixel_put(game, x, y, color);
	}
}
