/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:39:05 by vducoulo          #+#    #+#             */
/*   Updated: 2022/11/16 14:01:52 by vducoulo         ###   ########.fr       */
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
#  define ROT_RIGHT 124
#  define ROT_LEFT 123
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
#  define BONUS 1
# endif
# define PI 3.1415926535897932384
#endif