/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:38:34 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/10 18:11:51 by vducoulo         ###   ########.fr       */
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
	if (single_texture_loader(game, &all_textures->north_texture) == ERROR
		|| single_texture_loader(game, &all_textures->south_texture) == ERROR
		|| single_texture_loader(game, &all_textures->east_texture) == ERROR
		|| single_texture_loader(game, &all_textures->west_texture) == ERROR)
		return (ERROR);
	return (0);
}

int	single_texture_loader(t_game *game, t_texture *texture)
{
	texture->xpm_path = "./sprites/stone.xpm";
	texture->texture = mlx_xpm_file_to_image(game->mlx, texture->xpm_path,
			&texture->width_img, &texture->height_img);
	if (!texture->texture)
		return (ERROR);
	texture->texture_addr = mlx_get_data_addr(texture->texture,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	if (!texture->texture_addr)
		return (ERROR);
	ft_printf("\n texture %s successfully loaded", ft_strrchr(texture->xpm_path, '/'));
	return (0);
}

int	get_text_pixel(t_texture *texture, int x, int y)
{
	int	color;

	if (x < 0 || x >= texture->width_img
		|| y < 0 || y >= texture->height_img)
		return (0);
	color = (*(int *)texture->texture_addr + (y * texture->line_length)
			+ (x * texture->bits_per_pixel / 8));
	return (color);
}
