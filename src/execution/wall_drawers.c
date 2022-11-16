/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_drawers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:19:42 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/15 20:32:05 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	remove_fisheye_effect(t_game *game, t_raycast *raycast, t_ray *ray)
{
	ray->traveled_dst = ray->traveled_dst
		* cos(assure_360_deg_angle(game->player_angle - raycast->ray_angle));
	if (ray->traveled_dst < 1)
		ray->traveled_dst = 1;
}

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
	remove_fisheye_effect(game, raycast, ray);
	wall_height = 128 * game->window_height / ray->traveled_dst;
	set_texture_x_coordonates(game, ray);
	ray->texture->ratio = (double)(ray->texture->height_img)
		/ (double)wall_height;
	// if (wall_height > game->window_height)
	// 	wall_height = game->window_height;
	y = game->window_height / 2 - wall_height / 2;
	if (y < 0)
		i = -y;
	ray->texture->texture_y = i * ray->texture->ratio;
	while (i < wall_height && y + i < game->window_height)
	{
		ray->texture->texture_y += ray->texture->ratio;
		my_mlx_pixel_put(game, x, y + i,
			get_text_pixel(ray->texture,
				ray->texture->texture_x, ray->texture->texture_y));
		i++;
	}
}
