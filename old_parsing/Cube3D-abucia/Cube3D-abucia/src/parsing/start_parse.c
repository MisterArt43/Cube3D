/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 02:01:10 by abucia            #+#    #+#             */
/*   Updated: 2022/11/16 08:10:48 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	skip_to_next_word(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\r')
			break ;
		*i += 1;
	}
}

void	skip_to_EOL_or_EOF(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == '\n' || str[*i] == '\0')
			break ;
		*i += 1;
	}
}

int	txt_stop_all(t_game *game)
{
	if (game->map.txt.txt_e.img)
		mlx_destroy_image(game->mlx, game->map.txt.txt_e.img);
	if (game->map.txt.txt_n.img)
		mlx_destroy_image(game->mlx, game->map.txt.txt_n.img);
	if (game->map.txt.txt_w.img)
		mlx_destroy_image(game->mlx, game->map.txt.txt_w.img);
	if (game->map.txt.txt_s.img)
		mlx_destroy_image(game->mlx, game->map.txt.txt_s.img);
	return (1);
}

t_data	init_texture(t_game *game, char *path)
{
	t_data	new;

	new.img = mlx_xpm_file_to_image(game->mlx, path, &new.w, &new.h);
	if (!new.img)
		if (txt_stop_all(game))
			ft_ermap("Error occurred while loading texture", \
			game->map.fd_str, game);
	new.addr = mlx_get_data_addr(new.img, &new.bpp, \
	&new.line_l, &new.endian);
	new.bpp /= 8;
	free(path);
	return (new);
}

void	load_texture(t_game *game, t_data *texture, int *i)
{
	int	sub;

	*i += 3;
	skip_to_next_word(game->map.fd_str, i);
	sub = *i;
	skip_to_EOL_or_EOF(game->map.fd_str, &sub);
	while ((game->map.fd_str[sub] == ' ' || \
	game->map.fd_str[sub] == '\t') && sub > *i)
		sub--;
	*texture = init_texture(game, ft_substr(game->map.fd_str, *i, sub - *i));
}

//TYPE 1-4 = WALL TEXTUR
//TYPE 5-6 = BACKGROUND COLOR
//TYPE 7 = END OF PARSING TEXTURE
//TYPE 0 = INVALID INPUTE
void	define_type(char *str, int i, int *type)
{
	skip_to_next_word(str, &i);
	if (ft_nstrncmp(str, "NO ", 3, i) == 0)
		*type = 1;
	else if (ft_nstrncmp(str, "SO ", 3, i) == 0)
		*type = 2;
	else if (ft_nstrncmp(str, "WE ", 3, i) == 0)
		*type = 3;
	else if (ft_nstrncmp(str, "EA ", 3, i) == 0)
		*type = 4;
	else if (ft_nstrncmp(str, "F ", 2, i) == 0)
		*type = 5;
	else if (ft_nstrncmp(str, "C ", 2, i) == 0)
		*type = 6;
	else if (ft_nstrncmp(str, "1", 1, i) == 0)
		*type = 7;
	else
		*type = 0;
}

void	sort_parse(t_game *game)
{
	int	type;
	int	i;

	i = 0;
	type = 0;
	while (game->map.fd_str[i])
	{
		skip_to_next_word(game->map.fd_str, &i);
		if (game->map.fd_str[i] == '\n')
		{
			i++;
			define_type(game->map.fd_str, i, &type);
			if (type == 1)
				load_texture(game, &game->map.txt.txt_n, &i);
		}
	}
}

void	start_parse(char *map_file, t_game *game)
{
	if (ft_nstrncmp(map_file, ".cub", 5, ft_strlen(map_file - 5)) != 0)
		ft_ermap("Invalid map format\n", NULL, game);
	game->map.fd = open(map_file, O_RDONLY);
	if (game->map.fd == -1)
		ft_ermap("can't open the map\n", NULL, game);
	game->map.fd_str = ft_readall(game->map.fd, game);
	close(game->map.fd);
	if (!game->map.fd_str)
		ft_ermap("an error occur while allocate memory to the read buffer\n", \
		NULL, game);
	sort_parse(game);
}
