/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:18:43 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/26 16:01:44 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	hook_key_press_handler(int keycode, t_game *game)
{
	if (keycode == 124)
		ft_print_five('x', 1, game);
	if (keycode == 123)
		ft_print_five('x', 0, game);
	if (keycode == 126)
		ft_print_five('y', 0, game);
	if (keycode == 125)
		ft_print_five('y', 1, game);
	return (0);
}
