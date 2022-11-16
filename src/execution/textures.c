/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:38:34 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/16 16:44:09 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_texture_info	*textures_initializer(t_game *game)
{
	t_texture_info	*all_textures;

	all_textures = ft_calloc(1, sizeof(t_texture_info));
	if (all_textures_loader(game, all_textures) == ERROR)
		return (NULL);
	else
		return (all_textures);
}

int	all_textures_loader(t_game	*game, t_texture_info *all_textures)
{
	all_textures->north_texture = ft_calloc(1, sizeof(t_texture));
	all_textures->east_texture = ft_calloc(1, sizeof(t_texture));
	all_textures->south_texture = ft_calloc(1, sizeof(t_texture));
	all_textures->west_texture = ft_calloc(1, sizeof(t_texture));
	if (single_texture_loader(game, all_textures->north_texture, 2) == ERROR
		|| single_texture_loader(game, all_textures->south_texture, 4) == ERROR
		|| single_texture_loader(game, all_textures->east_texture, 3) == ERROR
		|| single_texture_loader(game, all_textures->west_texture, 1) == ERROR)
		return (ERROR);
	return (0);
}

int	single_texture_loader(t_game *game, t_texture *texture, int texture_id)
{
	texture->texture_id = texture_id;
	return (0);
}

int	get_text_pixel(t_texture *texture, int x, int y)
{
	int	color;

	if (!texture)
		return (0);
	if (x < 0 || x >= texture->width_img || y < 0 || y >= texture->height_img)
		return (0);
	color = (*(int *)(texture->texture_addr + (x * texture->bits_per_pixel)
				+ (y * texture->line_length)));
	return (color);
}

void	set_texture_x_coordonates(t_game *game, t_ray *ray)
{
	if (ray->texture->texture_id % 2 == 0)
		ray->texture->texture_x = ((ray->x / 64.0f) - (int)(ray->x / 64.0f))
			* ray->texture->width_img;
	else
		ray->texture->texture_x = ((ray->y / 64.0f) - (int)(ray->y / 64.0f))
			* ray->texture->width_img;
	if (ray->texture->texture_id == 3 || ray->texture->texture_id == 4)
		ray->texture->texture_x = ray->texture->width_img
			- ray->texture->texture_x;
}
