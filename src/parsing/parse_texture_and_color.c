/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_and_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:21:41 by abucia            #+#    #+#             */
/*   Updated: 2022/11/19 20:04:57 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_texture	init_texture(t_game *game, char *path)
{
	t_texture	new;

	ft_strlen(path);
	new.texture = mlx_xpm_file_to_image(game->mlx, path, \
	&new.width_img, &new.height_img);
	if (!new.texture)
		if (txt_stop_all(game))
			return (free(path), \
			ft_ermap("Error occurred while loading texture", \
			game->fd_str, game), new);
	new.texture_addr = mlx_get_data_addr(new.texture, &new.bits_per_pixel, \
	&new.line_length, &new.endian);
	new.bits_per_pixel /= 8;
	free(path);
	return (new);
}

void	load_texture(t_game *game, t_texture *texture, int *i)
{
	int	sub;

	if (texture->texture != NULL && txt_stop_all(game))
		ft_ermap("Too many texture parameter\n", game->fd_str, game);
	*i += 3;
	skip_to_next_word(game->fd_str, i);
	sub = *i;
	skip_to_eol_or_eof(game->fd_str, i);
	if (game->fd_str[*i] == '\n')
		*i -= 1;
	while ((game->fd_str[*i] == ' ' || \
	game->fd_str[*i] == '\t') && *i > sub)
		*i -= 1;
	*texture = init_texture(game, ft_substr(game->fd_str, sub, *i - sub + 1));
}

int	init_color(t_game *game, int *i, int (*color)[3], int nb)
{
	if ((*color)[nb] != -1 && txt_stop_all(game))
		ft_ermap("Too many color parameter\n", game->fd_str, game);
	(*color)[nb] = ft_atoi((game->fd_str + *i), i);
	if ((*color)[nb] < 0 || (*color)[nb] > 255)
	{
		txt_stop_all(game);
		ft_ermap("Invalid map value (must be between 0 - 255)\n", \
		game->fd_str, game);
	}
	return ((*color)[nb]);
}

void	pass_first_arg(int *i, int nb, t_game *game)
{
	if (nb == 0)
		*i += 2;
	skip_to_next_word(game->fd_str, i);
	if ((game->fd_str[*i] == '\n' || \
	!ft_isdigit(game->fd_str[*i])) && txt_stop_all(game))
		ft_ermap("invalide color format", game->fd_str, game);
}

void	load_color(t_game *game, int (*color)[3], int *i, int nb)
{
	pass_first_arg(i, nb, game);
	(*color)[nb] = init_color(game, i, color, nb);
	skip_to_next_word(game->fd_str, i);
	if (nb != 2)
		while (game->fd_str[*i] && game->fd_str[*i] != ',')
			if (game->fd_str[*i] != ' ' && game->fd_str[*i] != '\t' && (*i)++)
				if (txt_stop_all(game))
					ft_ermap("invalid color format", game->fd_str, game);
	if (game->fd_str[*i] == ',' && nb != 2)
		*i += 1;
	if (nb != 2)
		load_color(game, color, i, (nb + 1));
	else
	{
		while (game->fd_str[*i] && game->fd_str[*i] != '\n')
		{
			if (!ft_isdigit(game->fd_str[*i]) && game->fd_str[*i] != ' ' \
			&& txt_stop_all(game))
				ft_ermap("invalid color format", game->fd_str, game);
			*i += 1;
		}
	}
}
