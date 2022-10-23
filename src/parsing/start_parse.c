/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 02:01:10 by abucia            #+#    #+#             */
/*   Updated: 2022/10/23 02:01:10 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_map	start_parse(char *map_file)
{
	t_map	map;

	if (ft_nstrncmp(map_file, ".cub", 5, ft_strlen(map_file - 5)) != 0)
		ft_ermap("Invalid map format\n");
	ft_memset(&map, 0, sizeof(map));
	map.fd = open(map_file, O_RDONLY);
	map.file_str = ft_readall(map.fd);
	if (!map.file_str)
	{
		close(map.fd);
		ft_ermap("an error occur while allocate memory to the read buffer\n");
	}
	return (map);
}