/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:39:05 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/20 00:24:57 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# ifdef __linux__
#  define ESC 65307
#  define FORWARD 65362
#  define BACKWARD 65364
#  define LEFT 65361
#  define RIGHT 65363
#  define ROT_RIGHT 113
#  define ROT_LEFT 100
#  include "../mlx/mlx_linux/mlx.h"
#  define ON_LINUX 1
# else
#  define ESC 53
#  define FORWARD 13
#  define BACKWARD 1
#  define LEFT 0
#  define RIGHT 2
#  define ROT_RIGHT 123
#  define ROT_LEFT 124
#  include "../mlx/mlx_mac/mlx.h"
#  define ON_LINUX 0
# endif

# include "../libft/libft.h"
# include "execution.h"
# include "parsing.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef DEBUG
#  define DEBUG 0
# endif
# define ERROR -1
# ifndef BONUS
#  define BONUS 0
# endif
# define PI 3.1415926535897932384
#endif