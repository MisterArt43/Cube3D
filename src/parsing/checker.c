/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 02:49:33 by abucia            #+#    #+#             */
/*   Updated: 2022/11/16 15:55:22 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

// void	print_tab(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	printf("\nTAB FINAL : \n");
// 	while (i != game->game_tab_height)
// 	{
// 		j = 0;
// 		while (j != game->game_tab_width)
// 		{
// 			printf("%d",game->game_tab[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

void	replace_to_zero(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != game->game_tab_height)
	{
		j = 0;
		while (j != game->game_tab_width)
		{
			if (game->game_tab[i][j] == 2)
				game->game_tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	check_border(t_game *game)
{
	int	i;

	i = 0;
	while (game->game_tab_height != i)
	{
		if (game->game_tab[i][0] != 2 && game->game_tab[i][0] != 1)
			return (1);
		else if (game->game_tab[i][game->game_tab_width - 1] != 2 && \
		game->game_tab[i][game->game_tab_width - 1] != 1)
			return (1);
		i++;
	}
	i = 0;
	while (game->game_tab_width != i)
	{
		if (game->game_tab[0][i] != 2 && game->game_tab[0][i] != 1)
			return (1);
		else if (game->game_tab[game->game_tab_height - 1][i] != 2 && \
		game->game_tab[game->game_tab_height - 1][i] != 1)
			return (1);
		i++;
	}
	return (0);
}

void	check_surronded_by_wall(t_game *game, int i, int j)
{	
	if (game->game_tab[i + 1][j] == 2 || game->game_tab[i - 1][j] == 2 || \
	game->game_tab[i][j + 1] == 2 || game->game_tab[i][j - 1] == 2)
		ft_ermap("map invalide\n", NULL, game);
}

void	check_player_pos(t_game *game, int i, int j)
{
	if (game->game_tab[i][j] == 'N' - '0' || game->game_tab[i][j] == 'E' - '0' \
	|| game->game_tab[i][j] == 'W' - '0' || game->game_tab[i][j] == 'S' - '0')
	{
		game->x = i * 50;
		game->y = j * 50;
		if (game->game_tab[i][j] == 'N' - '0')
			game->player_angle = M_PI / 2;
		else if (game->game_tab[i][j] == 'E' - '0')
			game->player_angle = 2 * M_PI;
		else if (game->game_tab[i][j] == 'W' - '0')
			game->player_angle = M_PI;
		else if (game->game_tab[i][j] == 'S' - '0')
			game->player_angle = (2 * M_PI) / 2;
		game->game_tab[i][j] = 0;
	}
}

void	check_map_extension(t_game *game, int i, int j)
{
	if (check_border(game))
		ft_ermap("bordure de map invalide\n", NULL, game);
	while (i != game->game_tab_height - 1)
	{
		j = 1;
		while (j != game->game_tab_width - 1)
		{
			check_player_pos(game, i, j);
			if (game->game_tab[i][j] == 0 || game->game_tab[i][j] == 'N' || \
			game->game_tab[i][j] == 'S' || game->game_tab[i][j] == 'E' || \
			game->game_tab[i][j] == 'W')
				check_surronded_by_wall(game, i, j);
			j++;
		}
		i++;
	}
	replace_to_zero(game);
}
