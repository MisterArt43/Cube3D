/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:45:59 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/26 00:28:26 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	test_mlx(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	mlx = mlx_init();
	data->img = mlx_new_image(mlx, 1800, 1100);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	mlx_loop(mlx);
	return ;
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 2 || DEBUG == 1)
	{
		test_mlx();
	}
	else
		ft_putstr_fd("Error\nInvalid Argument, try :\n./cub3d <map.cub>\n", 2);
	return (0);
}
