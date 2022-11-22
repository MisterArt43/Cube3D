/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 02:01:10 by abucia            #+#    #+#             */
/*   Updated: 2022/11/18 16:23:11 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

//TYPE 1-4 = WALL TEXTUR
//TYPE 5-6 = BACKGROUND COLOR
//TYPE 7 = END OF PARSING TEXTURE
//TYPE 0 = INVALID INPUTE
void	define_type(char *str, int i, int *type)
{
	skip_to_next_word(str, &i);
	while (str[i] == '\n')
	{
		i++;
		skip_to_next_word(str, &i);
	}
	skip_to_next_word(str, &i);
	if (!ft_strncmp(str + i, "NO ", 3) || !ft_strncmp(str + i, "NO	", 3))
		*type = 1;
	else if (!ft_strncmp(str + i, "SO ", 3) || !ft_strncmp(str + i, "SO	", 3))
		*type = 2;
	else if (!ft_strncmp(str + i, "WE ", 3) || !ft_strncmp(str + i, "WE	", 3))
		*type = 3;
	else if (!ft_strncmp(str + i, "EA ", 3) || !ft_strncmp(str + i, "EA	", 3))
		*type = 4;
	else if (!ft_strncmp(str + i, "F ", 2) || !ft_strncmp(str + i, "F	", 3))
		*type = 5;
	else if (!ft_strncmp(str + i, "C ", 2) || !ft_strncmp(str + i, "C	", 3))
		*type = 6;
	else if (!ft_strncmp(str + i, "1", 1))
		*type = 7;
	else
		*type = 0;
}

void	sort_parse(t_game *game, int type, int i)
{
	while (game->fd_str[i])
	{
		skip_to_next_parse(game, &i);
		define_type(game->fd_str, i, &type);
		if (type == 1)
			load_texture(game, game->all_textures->north_texture, &i);
		else if (type == 2)
			load_texture(game, game->all_textures->south_texture, &i);
		else if (type == 3)
			load_texture(game, game->all_textures->west_texture, &i);
		else if (type == 4)
			load_texture(game, game->all_textures->east_texture, &i);
		else if (type == 5)
			load_color(game, &game->floor_color, &i, 0);
		else if (type == 6)
			load_color(game, &game->ceilling_color, &i, 0);
		else if (type == 7)
			return (gen_tab(game, (game->fd_str + i)));
		else if (type == 0 && txt_stop_all(game))
			ft_ermap("Invalid parameter in the file\n", game->fd_str, game);
		i++;
	}
}

void	null_texture(t_game *game)
{
	game->all_textures->east_texture->texture = NULL;
	game->all_textures->north_texture->texture = NULL;
	game->all_textures->south_texture->texture = NULL;
	game->all_textures->west_texture->texture = NULL;
	game->ceilling_color[0] = -1;
	game->ceilling_color[1] = -1;
	game->ceilling_color[2] = -1;
	game->floor_color[0] = -1;
	game->floor_color[1] = -1;
	game->floor_color[2] = -1;
}

void	start_parse(char *map_file, t_game *game)
{
	null_texture(game);
	if ((ft_strlen(map_file) < 4 || ft_strncmp(map_file + \
	(ft_strlen(map_file) - 4), ".cub", 4) != 0) && txt_stop_all(game))
		ft_ermap("Invalid map format\n", game->fd_str, game);
	game->fd = open(map_file, O_RDWR);
	if (game->fd == -1 && txt_stop_all(game))
		ft_ermap("can't open the map\n", game->fd_str, game);
	game->fd_str = ft_readall(game->fd, game, 1);
	if ((close(game->fd) == -1 || !game->fd_str) && txt_stop_all(game))
		ft_ermap("an error occur while allocate memory to the read buffer\n", \
		game->fd_str, game);
	sort_parse(game, 0, 0);
	free(game->fd_str);
}
