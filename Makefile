# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 23:43:27 by vducoulo          #+#    #+#              #
#    Updated: 2022/11/17 22:35:26 by vducoulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

SRCS_GLOBAL = 	src/main.c \
				src/execution/execution_main.c \
				src/execution/game_quitters.c \
				src/execution/mlx_utils.c \
				src/execution/game_initializer.c \
				src/execution/user_inputs.c \
				src/execution/utils.c \
				src/execution/tmp_game_tab_feeder.c \
				src/execution/game_grid_drawer.c \
				src/execution/player_movements.c \
				src/execution/player_movement_rotations.c \
				src/execution/raycasting.c \
				src/execution/raycasting_utils.c \
				src/execution/raycasting_player_angle_adapters.c \
				src/execution/raycasting_collisions_checker.c  \
				src/execution/wall_drawers.c \
				src/execution/player_movements_utils.c \
				src/execution/textures.c \
				src/parsing/start_parse.c \
				src/parsing/checker.c \
				src/parsing/make_map.c \
				src/parsing/parse_texture_and_color.c \
				src/utils/parsing_utils.c \
				src/utils/common_utils.c \
				src/utils/ft_parse_error.c \

SRCS_MANDATORY = 

SRCS_BONUS = 

OBJS_GLOBAL = ${SRCS_GLOBAL:.c=.o}
OBJS_MANDATORY = ${SRCS_MANDATORY:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

INCLUDES = includes/header.h

CC = gcc
RM = rm -f

FLAGS = -O3

all: lib ${NAME}

bonus: lib ${NAME_BONUS}

$(NAME): ${OBJS_GLOBAL} ${OBJS_MANDATORY}
	${CC} ${OBJS_GLOBAL} ${OBJS_MANDATORY} -Llibft -lft -Lmlx/mlx_mac -lmlx -framework OpenGL -framework Appkit -o $(NAME)

${NAME_BONUS}: ${OBJS_GLOBAL} ${OBJS_BONUS}
	${CC} ${OBJS_GLOBAL} ${OBJS_BONUS} -Llibft -lft -Lmlx/mlx_mac -lmlx -framework OpenGL -framework Appkit -o $(NAME_BONUS)
	
%.o: %.c ${INCLUDES} Makefile
	${CC} ${FLAGS} -Imlx -Ift -c $< -o $@

clean:
	${RM} ${OBJS_GLOBAL} ${OBJS_MANDATORY} ${OBJS_BONUS}
	make clean -C mlx/mlx_mac
	make clean -C libft

fclean:	clean
	${RM} ${NAME} ${NAME_BONUS}
	make fclean -C libft

lib:
	make -C mlx/mlx_mac
	make -C libft

re:	fclean all
         
.PHONY: all clean fclean re % 