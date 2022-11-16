/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_drawers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:19:42 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/12 01:04:53 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	draw_floor_and_ceilling(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->window_height)
	{
		x = 0;
		while (x < game->window_width)
		{
			if (y < game->window_height / 2)
				my_mlx_pixel_put(game, x, y, rgb_to_hexa(game->floor_color));
			else
				my_mlx_pixel_put(game, x, y, rgb_to_hexa(game->ceilling_color));
			x ++;
		}
		y ++;
	}
}

void	draw_walls(t_game *game, t_raycast *raycast, t_ray *ray, int x)
{
	int	wall_height;
	int	texture_color;
	int	y;
	int	i;

	i = 0;
	ray->traveled_dst = ray->traveled_dst
		* cos(assure_360_deg_angle(game->player_angle - raycast->ray_angle));
	if (ray->traveled_dst < 1)
		ray->traveled_dst = 1;
	wall_height = game->window_height / 10
		* game->window_height / ray->traveled_dst;
	if (wall_height > game->window_height)
		wall_height = game->window_height;
	y = game->window_height / 2 - wall_height / 2;
	if (y < 0)
		i = -y;
	set_texture_coordonates(ray, i, wall_height);
	while (i < wall_height && y + i < game->window_height)
	{
		ray->texture.texture_y += ray->texture.height_img / wall_height;
		texture_color = get_text_pixel(ray->texture,
				ray->texture.texture_x, ray->texture.texture_y);
		my_mlx_pixel_put(game, x, y + i, texture_color);
		i++;
	}
}
