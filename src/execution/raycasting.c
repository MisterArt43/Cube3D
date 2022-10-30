/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:55:46 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/30 16:17:40 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	is_in_map_limits(t_game *game, int x, int y)
{
	if ((x >= 0 && y >= 0) && x < game->game_tab_width
		&& y < game->game_tab_height)
		return (1);
	return (0);
}

void	draw_line(t_game *game, int x0, int y0, int x1, int y1)
{
	int	x;
	int	y;

	for (float i = 0.0; i <= 1; i += 0.005)
	{
		x = x0 + (x1 - x0) * i;
		y = y0 + (y1 - y0) * i;
		my_mlx_pixel_put(game, x, y, 0x00FF0000);
	}
}

void	raycasting(t_game *game)
{
	int			i;
	t_raycast	*raycast;

	i = 0;
	raycast = game->raycast;
	raycast->ray_angle = game->player_angle;
	raycast->depth_of_field = 0;
	while (i < raycast->ray_count)
	{
		check_horizontal_ray_collision(raycast, game);
		check_vertical_ray_collision(raycast, game);
		if (raycast->traveled_horiz >= raycast->traveled_vert)
			draw_line(game, game->x, game->y,
				raycast->last_horiz_x, raycast->last_horiz_y);
		else
			draw_line(game, game->x, game->y,
				raycast->last_vert_x, raycast->last_vert_y);
		i ++;
	}
	return ;
}

void	check_horizontal_ray_collision(t_raycast *raycast, t_game *game)
{
	float	a_tan;

	a_tan = -1 / tan(raycast->ray_angle);
	if (raycast->ray_angle > PI) // facing up
	{
		raycast->ray_y = ((game->y >> 6) << 6) - 0.0001;
		raycast->ray_x = (game->y - raycast->ray_y) * a_tan + game->x;
		raycast->ray_y_offset = -game->game_cell_size;
		raycast->ray_x_offset = -raycast->ray_y_offset * a_tan;
	}
	else if (raycast->ray_angle < PI) // facing down
	{
		raycast->ray_y = ((game->y >> 6) << 6) + game->game_cell_size;
		raycast->ray_x = (game->y - raycast->ray_y) * a_tan + game->x;
		raycast->ray_y_offset = game->game_cell_size;
		raycast->ray_x_offset = -raycast->ray_y_offset * a_tan;
	}
	else if (raycast->ray_angle == 0 || raycast->ray_angle == PI)
	{
		raycast->ray_x = game->x;
		raycast->ray_y = game->y;
		raycast->depth_of_field = 8;
	}
	while (raycast->depth_of_field < 8)
	{
		raycast->map_x = (int)raycast->ray_x >> 6;
		raycast->map_y = (int)raycast->ray_y >> 6;
		if (is_in_map_limits(game, raycast->map_x, raycast->map_y)
			&& game->game_tab[raycast->map_y][raycast->map_x] == 1)
		{
			raycast->last_horiz_x = raycast->ray_x;
			raycast->last_horiz_y = raycast->ray_y;
			raycast->depth_of_field = 8;
			raycast->traveled_horiz = get_traveled_ray_distance(game, raycast);
		}
		else
		{
			raycast->ray_x += raycast->ray_x_offset;
			raycast->ray_y += raycast->ray_y_offset;
			raycast->depth_of_field ++;
		}
	}
}

void	check_vertical_ray_collision(t_raycast *raycast, t_game *game)
{
	float	a_tan;

	ft_printf("\n entered vertical check");
	a_tan = -tan(raycast->ray_angle);
	if (raycast->ray_angle > PI / 2 && raycast->ray_angle < 3 * PI / 2) // looking left
	{
		raycast->ray_x = ((game->x >> 6) << 6) - 0.0001;
		raycast->ray_y = (game->x - raycast->ray_x) * a_tan + game->y;
		raycast->ray_x_offset = -game->game_cell_size;
		raycast->ray_y_offset = -raycast->ray_x_offset * a_tan;
	}
	else if (raycast->ray_angle < PI / 2 || raycast->ray_angle > 3 * PI / 2) // looking right
	{
		raycast->ray_x = ((game->x >> 6) << 6) + game->game_cell_size;
		raycast->ray_y = (game->x - raycast->ray_x) * a_tan + game->y;
		raycast->ray_x_offset = game->game_cell_size;
		raycast->ray_y_offset = -raycast->ray_x_offset * a_tan;
	}
	else if (raycast->ray_angle == 0 || raycast->ray_angle == PI)
	{
		raycast->ray_x = game->x;
		raycast->ray_y = game->y;
		raycast->depth_of_field = 8;
	}
	while (raycast->depth_of_field < 8)
	{
		raycast->map_x = (int)raycast->ray_x >> 6;
		raycast->map_y = (int)raycast->ray_y >> 6;
		if (is_in_map_limits(game, raycast->map_x, raycast->map_y)
			&& game->game_tab[raycast->map_y][raycast->map_x] == 1)
		{
			raycast->last_vert_x = raycast->ray_x;
			raycast->last_vert_y = raycast->ray_y;
			raycast->traveled_vert = get_traveled_ray_distance(game, raycast);
			raycast->depth_of_field = 8;
		}
		else
		{
			raycast->ray_x += raycast->ray_x_offset;
			raycast->ray_y += raycast->ray_y_offset;
			raycast->depth_of_field ++;
		}
	}
}
