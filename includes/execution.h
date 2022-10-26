/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:53:03 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/26 16:07:41 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../mlx/mlx_mac/mlx.h"

typedef struct s_game {
	void	*img;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		window_width;
	int		window_height;
	int		x; //debug
	int		y; //debug
}	t_game;

int			render_next_frame(t_game *game);
void		my_mlx_pixel_put(t_game *game, int x, int y, int color);
int			hook_key_press_handler(int keycode, t_game *game);
t_game		*game_initializer(void);
void		execution_launcher(char *map);
void		free_and_exit(t_game *game, int exit_status);
void		free_my_game(t_game *game);

// debug

void		ft_print_five(char selectid, int increment, t_game *game);

#endif