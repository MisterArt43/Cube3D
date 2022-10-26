/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:45:59 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/26 15:51:22 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
	{
		execution_launcher(argv[1]);
	}
	else
		ft_putstr_fd("Error\nInvalid Argument, try :\n./cub3d <map.cub>\n", 2);
	return (0);
}
