/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:45:59 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/26 15:14:05 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > data->window_width - 1 || y < 0
		|| y > data->window_height - 1)
		return ;
	ft_printf("\n x : %d, y : %d", x, y);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_ptrint_five(char selectid, int increment, t_data *data)
{
	int bx;
	int by;

	bx = data->x;
	by = data->y;
	if (selectid == 'x' && increment)
		while (data->x < bx + 5)
			my_mlx_pixel_put(data, ++data->x, data->y, 0x00FF0000);
	if (selectid == 'x' && !increment)
		while (data->x > bx - 5)
			my_mlx_pixel_put(data, --data->x, data->y, 0x00FF0000);
	if (selectid == 'y' && increment)
		while (data->y < by + 5)
			my_mlx_pixel_put(data, data->x, ++data->y, 0x00FF0000);
	if (selectid == 'y' && !increment)
		while (data->y > by - 5)
			my_mlx_pixel_put(data, data->x, --data->y, 0x00FF0000);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == 124)
		ft_ptrint_five('x', 1, data);
	if (keycode == 123)
		ft_ptrint_five('x', 0, data);
	if (keycode == 126)
		ft_ptrint_five('y', 0, data);
	if (keycode == 125)
		ft_ptrint_five('y', 1, data);
	return (0);
}

int	render_next_frame(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

void	ft_draw_square(int width_len, int height_len, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < width_len)
		my_mlx_pixel_put(data, x++, y, 0x00FF0000);
	while (y < height_len)
		my_mlx_pixel_put(data, x, y++, 0x00FF0000);
	while (x > 0)
		my_mlx_pixel_put(data, x--, y, 0x00FF0000);
	while (y > 0)
		my_mlx_pixel_put(data, x, y--, 0x00FF0000);
	return ;
}

void	test_mlx(void)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	data->window_width = 1800;
	data->window_height = 1100;
	data->x = 100;
	data ->y = 100;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->window_width, data->window_height,
			"sample");
	data->img = mlx_new_image(data->mlx, data->window_width, data->window_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	mlx_hook(data->mlx_win, 2, 0, key_press, data);
	mlx_loop_hook(data->mlx, render_next_frame, data);
	mlx_loop(data->mlx);
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
