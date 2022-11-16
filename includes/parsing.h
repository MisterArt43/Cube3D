/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:23:42 by abucia            #+#    #+#             */
/*   Updated: 2022/11/13 03:23:42 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void		skip_to_next_word(char *str, int *i);
void		skip_to_eol_or_eof(char *str, int *i);
void		skip_to_next_parse(t_game *game, int *i);
int			txt_stop_all(t_game *game);
void		free_map(int **map, int n);
t_texture	init_texture(t_game *game, char *path);
void		load_texture(t_game *game, t_texture *texture, int *i);
void		load_color(t_game *game, int (*color)[3], int *i, int nb);
void		define_type(char *str, int i, int *type);
void		sort_parse(t_game *game, int type, int i);
void		start_parse(char *map_file, t_game *game);
void		stop_mlx(t_game *game);
void		ft_ermap(char *str, void *ptr, t_game *game);
void		read_error(int fd, char *str, char *er, t_game *game);
char		*ft_readall(int fd, t_game *game);
char		*ft_freestrjoin(char *s1, char *s2);
int			ft_nstrncmp(const char *s1, const char *s2, size_t n, size_t start);
void		check_map_extension(t_game *game, int i, int j);
void		gen_tab(t_game *game, char *str);