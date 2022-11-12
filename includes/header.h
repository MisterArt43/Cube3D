/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 00:45:42 by abucia            #+#    #+#             */
/*   Updated: 2022/10/23 00:45:42 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

# define FALSE 0
# define TRUE 16844
# define EXTENSION ".xpm"

# ifdef __linux__
#  define IS_LIN 1
# else
#  define IS_LIN 0
# endif

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
	int		w;
	int		h;
}	t_data;

typedef struct s_texture
{
	t_data	txt_n;
	t_data	txt_e;
	t_data	txt_w;
	t_data	txt_s;
}	t_texture;

typedef struct s_map
{
	struct s_texture	txt;
	int					fd;
	char				*file_str;
	char				*map;
	int					h;
	int					l;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	struct	s_map map;
}	t_game;

// < ------------------------------------------------ >
// < -------------------  UTILS  -------------------- >
// < ------------------------------------------------ >

int		ft_strlen(const char *str);
int		ft_putstr_fd(char *str, int fd);
void	*ft_memset(void *s, int c, size_t n);
int		ft_nstrncmp(const char *s1, const char *s2, size_t n, size_t start);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);

// < ------------------------------------------------ >
// < ----------------  DATA STRUCT  ----------------- >
// < ------------------------------------------------ >



// < ------------------------------------------------ >
// < -----------------   TEXTURE  ------------------- >
// < ------------------------------------------------ >



// < ------------------------------------------------ >
// < -----------------   PARSING  ------------------- >
// < ------------------------------------------------ >

char	*ft_readall(int fd, t_game *game);
void	start_parse(char *map_file, t_game *game);

// < ------------------------------------------------ >
// < --------------------  GAME  -------------------- >
// < ------------------------------------------------ >



// < ------------------------------------------------ >
// < ---------------  ERROR HANDLER  ---------------- >
// < ------------------------------------------------ >

void	ft_ermap(char *str, void *ptr, t_game *game);

#endif
