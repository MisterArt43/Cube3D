/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:14:58 by abucia            #+#    #+#             */
/*   Updated: 2022/11/16 08:14:58 by abucia           ###   ########lyon.fr   */
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
		i++;
	}
}

int	*fill_tab(t_game *game, char *str, int n, int j)
{
	int	*line;
	int	i;

	i = 0;
	line = malloc(sizeof(int) * game->game_tab_width);
	while (n != 0)
	{
		if (str[i++] == '\n')
			n--;
	}
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'N' && str[i] != 'S' \
		&& str[i] != 'E' && str[i] != 'W' && str[i] != ' ')
			ft_ermap("Invalid char in the map\n", NULL, game);
		if (str[i] == ' ')
			line[j] = 2;
		else
			line[j] = str[i] - '0';
		j++;
		i++;
	}
	while (j != game->game_tab_width)
		line[j++] = 2;
	return (line);
}

void	gen_tab(t_game *game, char *str)
{
	int	i;

	i = 0;
	while (*(str - 1) != '\n')
		str--;
	get_dimension(&game->game_tab_height, &game->game_tab_width, str);
	game->game_tab = malloc(sizeof(int *) * game->game_tab_height);
	if (!game->game_tab && txt_stop_all(game))
		ft_ermap("malloc error for game_tab", NULL, game);
	while (i != game->game_tab_height)
	{
		game->game_tab[i] = fill_tab(game, str, i, 0);
		i++;
	}
	check_map_extension(game, 1, 1);
}
