/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 00:45:07 by abucia            #+#    #+#             */
/*   Updated: 2022/10/23 00:45:07 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.mlx = mlx_init();
		if (!game.mlx)
		{
			argc = write(2, "Error, mlx is null\n", 19);
			return (1);
		}
		start_parse(argv[1], &game);
	}
	else
		ft_putstr_fd("Error\nInvalid Argument, try :\n./cub3d <map.cub>\n", 2);
}