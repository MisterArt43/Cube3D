/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:38:34 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/12 00:55:25 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*t_texture_info	*textures_initializer(t_game *game)
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
	//texture->xpm_path = "./sprites/stone.xpm";
	texture->texture_id = texture_id;
	//texture->texture = mlx_xpm_file_to_image(game->mlx, texture->xpm_path,
			//&texture->width_img, &texture->height_img);
	if (!texture->texture)
		return (ERROR);
	texture->texture_addr = mlx_get_data_addr(texture->texture,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	if (!texture->texture_addr)
		return (ERROR);
	//if (DEBUG == 1)
		//ft_printf("\n texture %s successfully loaded",
			//ft_strrchr(texture->xpm_path, '/'));
	return (0);
}*/

int	get_text_pixel(t_texture texture, int x, int y)
{
	int	color;

	if (x < 0 || x >= texture.width_img
		|| y < 0 || y >= texture.height_img)
		return (0);
	color = (*(int *)texture.texture_addr + (y * texture.line_length)
			+ (x * texture.bits_per_pixel));
	return (color);
}

void	set_texture_coordonates(t_ray *ray, int base_draw,
	int wall_height)
{
	ray->texture.texture_y = base_draw * (double)((double)(ray->texture.height_img)
		/ (double)wall_height);
	if (ray->texture.texture_id % 2 == 0)
		ray->texture.texture_x = ((ray->x / 64.0f) - (int)(ray->x / 64.0f))
			* ray->texture.width_img;
	else
		ray->texture.texture_x = ((ray->y / 64.0f) - (int)(ray->y / 64.0f))
			* ray->texture.width_img;
	if (ray->texture.texture_id == 3 || ray->texture.texture_id == 4)
		ray->texture.texture_x = ray->texture.width_img
			- ray->texture.texture_x;
}
