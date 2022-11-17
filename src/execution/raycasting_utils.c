/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:02:24 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/17 22:21:30 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

double	get_traveled_ray_distance(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

int	is_in_map_limits(t_game *game, int x, int y)
{
	if ((x >= 0 && y >= 0) && x < game->game_tab_width
		&& y < game->game_tab_height)
		return (1);
	return (0);
}

int	is_in_window_limits(t_game *game, float x, float y)
{
	if (x > 0 && x <= game->window_width
		&& y > 0 && y <= game->window_height)
		return (1);
	return (0);
}

void	raycasting_angle_interpeter(int vertical, t_game *game, t_ray *ray,
	float ray_angle)
{
	float	a_tan;

	ray_angle = assure_360_deg_angle(ray_angle);
	if (!vertical)
	{
		ray->a_tan = -1 / tan(ray_angle);
		if (ray_angle > M_PI)
			raycasting_horizontal_looking_up(game, ray);
		else if (ray_angle < M_PI && ray_angle)
			raycasting_horizontal_looking_down(game, ray);
		else if (ray_angle == 0 || ray_angle == M_PI)
			raycasting_looking_straight(game, ray);
	}
	else if (vertical == 1)
	{
		ray->a_tan = -tan(ray_angle);
		if (ray_angle > M_PI / 2 && ray_angle < 3 * M_PI / 2)
			raycasting_vertical_looking_left(game, ray);
		else if (ray_angle < M_PI / 2 || ray_angle > 3 * M_PI / 2)
			raycasting_vertical_looking_right(game, ray);
		else if (ray_angle == 0 || ray_angle == M_PI)
			raycasting_looking_straight(game, ray);
	}
}

double	assure_360_deg_angle(double a)
{
	double	two_pi;

	two_pi = 2 * M_PI;
	if (a >= two_pi)
		a -= (two_pi);
	if (a < 0)
		a += (two_pi);
	return (a);
}
