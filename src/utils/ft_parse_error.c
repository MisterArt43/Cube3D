/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:17:22 by abucia            #+#    #+#             */
/*   Updated: 2022/11/18 15:46:31 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	free_map(int **map, int n)
{
	while (n != -1)
	{
		free(map[n]);
		n--;
	}
	free(map);
	return (1);
}

int	txt_stop_all(t_game *game)
{
	if (game->all_textures->east_texture->texture)
		mlx_destroy_image(game->mlx, game->all_textures->east_texture->texture);
	if (game->all_textures->west_texture->texture)
		mlx_destroy_image(game->mlx, game->all_textures->west_texture->texture);
	if (game->all_textures->north_texture->texture)
		mlx_destroy_image(game->mlx,
			game->all_textures->north_texture->texture);
	if (game->all_textures->south_texture->texture)
		mlx_destroy_image(game->mlx,
			game->all_textures->south_texture->texture);
	if (game->all_textures->east_texture)
		free(game->all_textures->east_texture);
	if (game->all_textures->north_texture)
		free(game->all_textures->north_texture);
	if (game->all_textures->south_texture)
		free(game->all_textures->south_texture);
	if (game->all_textures->west_texture)
		free(game->all_textures->west_texture);
	if (game->all_textures)
		free(game->all_textures);
	return (1);
}
