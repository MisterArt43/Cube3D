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
# include "../libft/libft.h"
# include "execution.h"
# include "parsing.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define DEBUG 1
# define ERROR -1
# define PI 3.1415926535897932384
# ifdef __linux__
#  define ISLINUX 1
# else
#  define ISLINUX 0
# endif
#endif