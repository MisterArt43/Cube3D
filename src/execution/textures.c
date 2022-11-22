/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:38:34 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/18 15:42:11 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_texture_info	*textures_initializer(void)
{
	t_texture_info	*all_textures;
	int				ret;

	ret = 0;
	all_textures = ft_calloc(1, sizeof(t_texture_info));
	if (!all_textures)
		return (NULL);
	ret = all_textures_loader(all_textures);
	if (ret != 5)
	{
		if (ret <= 1)
			free(all_textures->north_texture);
		if (ret <= 2)
			free(all_textures->east_texture);
		if (ret <= 3)
			free(all_textures->south_texture);
		if (ret <= 4)
			free(all_textures->west_texture);
		free(all_textures);
		return (NULL);
	}
	return (all_textures);
}

int	all_textures_loader(t_texture_info *all_textures)
{
	all_textures->north_texture = ft_calloc(1, sizeof(t_texture));
	if (!all_textures->north_texture)
		return (1);
	all_textures->east_texture = ft_calloc(1, sizeof(t_texture));
	if (!all_textures->east_texture)
		return (2);
	all_textures->south_texture = ft_calloc(1, sizeof(t_texture));
	if (!all_textures->south_texture)
		return (3);
	all_textures->west_texture = ft_calloc(1, sizeof(t_texture));
	if (!all_textures->west_texture)
		return (4);
	return (5);
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

void	set_texture_x_coordonates(t_ray *ray)
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
