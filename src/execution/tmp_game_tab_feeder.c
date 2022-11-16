/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_game_tab_feeder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:52:35 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/15 20:29:56 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	**tmp_game_tab_feeder(char *map, t_game *game)
{
	int		fd;
	int		**tab;
	char	*m_line;
	int		x;
	int		y;

	y = 0;
	tab = (int **)ft_calloc((size_t)game->game_tab_height, sizeof(int *));
	fd = open(map, O_RDONLY);
	while (y < game->game_tab_height)
	{
		x = 0;
		tab[y] = (int *)ft_calloc(game->game_tab_width, sizeof(int));
		m_line = get_next_line(fd);
		while (x < game->game_tab_width)
		{
			tab[y][x] = m_line[x] - '0';
			x ++;
		}
		y ++;
	}
	return (tab);
}
