/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:53:03 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/10 18:14:12 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include "../mlx/mlx_mac/mlx.h"

# define DOF_DELIM 20
# define DR 0.0174533

// movement_tab : 0 = forward, 1 = backward, 2 = left turn, 3 = right turn,
// 4 = rotate right , 5 = rotate left (if 1 : performs if 0 : no actions)

typedef struct s_texture
{
	char	*xpm_path;
	void	*texture;
	char	*texture_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width_img;
	int		height_img;
}	t_texture;

typedef struct s_texture_info
{
	t_texture	north_texture;
	t_texture	east_texture;
	t_texture	south_texture;
	t_texture	west_texture;
}	t_texture_info;

typedef struct s_raycast {
	int		ray_count;
	double	ray_angle;
	double	ray_y;
	double	ray_x;
	double	ray_x_offset;
	double	ray_y_offset;
	int		depth_of_field;
	int		map_x;
	int		map_y;
	int		map_pos;
	double	traveled_horiz;
	double	traveled_vert;
	double	min_traveled;
	double	last_horiz_x;
	double	last_horiz_y;
	double	last_vert_x;
	double	last_vert_y;
}	t_raycast;

typedef struct s_game {
	void			*img;
	char			*addr;
	void			*mlx;
	void			*mlx_win;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				window_width;
	int				window_height;
	int				x;
	int				y;
	double			player_delta_x;
	double			player_delta_y;
	double			player_angle;
	int				**game_tab;
	int				game_tab_width;
	int				game_tab_height;
	int				game_tab_max_encountred_cell;
	int				game_cell_size;
	int				displacement_speed;
	int				movement_tab[6];
	int				floor_color[3];
	int				ceilling_color[3];
	t_raycast		*raycast;
	t_texture_info	*all_textures;
}	t_game;

typedef struct s_vector2d {
	int	x;
	int	y;
}	t_vector2d;

int				render_next_frame(t_game *game);
void			my_mlx_pixel_put(t_game *game, int x, int y, int color);
int				hook_key_press_handler(int keycode, t_game *game);
t_game			*game_initializer(char *map_path);
void			execution_launcher(char *map);
void			free_and_exit(t_game *game, int exit_status);
void			free_my_game(t_game *game);
void			game_renderer(t_game *game);
void			vd_cube_drawer(t_game *game, t_vector2d *top_left,
					t_vector2d *bottom_right, int color);
void			game_grid_drawer(t_game *game);
int				hook_key_release_handler(int keycode, t_game *game);
void			move_my_player(t_game *game);
void			player_rotate_left(t_game *game);
void			player_rotate_right(t_game *game);
void			print_player_position(t_game *game);
void			check_horizontal_ray_collision(t_raycast *raycast, t_game *game);
int				is_in_map_limits(t_game *game, int x, int y);
void			raycasting(t_game *game);
t_raycast		*raycast_initializer(t_game *game);
void			check_vertical_ray_collision(t_raycast *raycast, t_game *game);
double			get_traveled_ray_distance(float ax, float ay, float bx, float by);
int				is_in_map_limits(t_game *game, int x, int y);
void			raycasting_horizontal_looking_up(t_game *game, t_raycast *raycast,
					float a_tan);
void			raycasting_horizontal_looking_down(t_game *game, t_raycast *raycast,
					float a_tan);
void			raycasting_vertical_looking_right(t_game *game, t_raycast *raycast,
					float a_tan);
void			raycasting_vertical_looking_left(t_game *game, t_raycast *raycast,
					float a_tan);
void			raycasting_looking_straight(t_game *game, t_raycast *raycast);
void			raycasting_angle_interpeter(int vertical, t_game *game,
					t_raycast *raycast);
double			assure_360_deg_angle(double a);
void			draw_walls(t_game *game, t_raycast *raycast, int x);
unsigned long	rgb_to_hexa(int color[3]);
void			draw_floor_and_ceilling(t_game *game);
t_texture_info	*textures_initializer(t_game *game);
int				all_textures_loader(t_game	*game,
					t_texture_info *all_textures);
int				single_texture_loader(t_game *game, t_texture *texture);

// debug

void		ft_print_five(char selectid, int increment, t_game *game);
void		debug_print_cubname(t_game *game);
int			**tmp_game_tab_feeder(char *map, t_game *game);
void		set_mlx_background(t_game *game);
void		debug_draw_line(t_game *game, int x0, int y0, int x1, int y1, int color);

#endif