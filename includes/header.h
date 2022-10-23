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

#define FALSE 0
#define TRUE 16844

// < ------------------------------------------------ >
// < -------------------  UTILS  -------------------- >
// < ------------------------------------------------ >

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

int		ft_strlen(char *str);
int		ft_putstr_fd(char *str, int fd);
void	*ft_memset(void *s, int c, size_t n);
int		ft_nstrncmp(const char *s1, const char *s2, size_t n, size_t start);

// < ------------------------------------------------ >
// < ----------------  DATA STRUCT  ----------------- >
// < ------------------------------------------------ >

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

// < ------------------------------------------------ >
// < -----------------   PARSING  ------------------- >
// < ------------------------------------------------ >

typedef struct s_map
{
	int		fd;
	char	*file_str;
	char	*map;
	int		h;
	int		l;

}	t_map;

char	*ft_readall(int fd);

// < ------------------------------------------------ >
// < -----------------   TEXTURE  ------------------- >
// < ------------------------------------------------ >

typedef struct s_texture
{
	t_data	*txt_n;
	t_data	*txt_e;
	t_data	*txt_w;
	t_data	*txt_s;
	int		nb_txt_n;
	int		nb_txt_e;
	int		nb_txt_w;
	int		nb_txt_s;
};

// < ------------------------------------------------ >
// < --------------------  GAME  -------------------- >
// < ------------------------------------------------ >

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	struct s_texture texture;
	struct s_map map;
}	t_game;

// < ------------------------------------------------ >
// < ---------------  ERROR HANDLER  ---------------- >
// < ------------------------------------------------ >

void	ft_ermap(char *str);

#endif