/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:14:58 by abucia            #+#    #+#             */
/*   Updated: 2022/11/16 15:18:33 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	get_dimension(int *h, int *w, char *str)
{
	int	i;
	int	biggest;

	*h = 0;
	*w = 0;
	biggest = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (*w < biggest)
				*w = biggest;
			biggest = 0;
			*h += 1;
			i++;
		}
		biggest++;
		if (str[i])
			i++;
	}
}

int	*fill_tab(t_game *game, char *str, int n, int j)
{
	int			*line;
	t_dual_int	i;

	i.x = 0;
	i.y = n;
	line = malloc(sizeof(int) * game->game_tab_width);
	while (n != 0)
		if (str[i.x++] == '\n')
			n--;
	while (str[i.x] && str[i.x] != '\n')
	{
		if (str[i.x] != 48 && str[i.x] != 49 && str[i.x] != 78 && str[i.x] != \
		83 && str[i.x] != 69 && str[i.x] != 87 && str[i.x] != 32 && \
		txt_stop_all(game) && free_map(game->game_tab, i.y))
			return (ft_ermap("Invalid map char\n", game->fd_str, game), NULL);
		if (str[i.x] == ' ')
			line[j] = 2;
		else
			line[j] = str[i.x] - '0';
		j++;
		i.x++;
	}
	while (j != game->game_tab_width)
		line[j++] = 2;
	return (line);
}

void	check_all_before_gen_map(t_game *game)
{
	if (game->all_textures->east_texture->texture && \
	game->all_textures->west_texture->texture && \
	game->all_textures->north_texture->texture && \
	game->all_textures->south_texture->texture && \
	game->floor_color[0] != -1 && game->ceilling_color[0] != -1)
		return ;
	txt_stop_all(game);
	ft_ermap("at least one texture or color is missing", game->fd_str, game);
}

void	gen_tab(t_game *game, char *str)
{
	int	i;

	check_all_before_gen_map(game);
	i = 0;
	while (*(str - 1) != '\n')
		str--;
	get_dimension(&game->game_tab_height, &game->game_tab_width, str);
	game->game_tab = malloc(sizeof(int *) * game->game_tab_height);
	if (!game->game_tab && txt_stop_all(game))
		ft_ermap("malloc error for game_tab", game->fd_str, game);
	while (i != game->game_tab_height)
	{
		game->game_tab[i] = fill_tab(game, str, i, 0);
		i++;
	}
	check_map_extension(game, 1, 1);
}
