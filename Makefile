# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 23:43:27 by vducoulo          #+#    #+#              #
#    Updated: 2022/10/25 23:44:34 by vducoulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

SRCS_GLOBAL = 	src/main.c

SRCS_MANDATORY = 

SRCS_BONUS = 

OBJS_GLOBAL = ${SRCS_GLOBAL:.c=.o}
OBJS_MANDATORY = ${SRCS_MANDATORY:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

INCLUDES = headers/cub3d.h

CC = gcc #-fsanitize=address
RM = rm -f

FLAGS = -Wall -Wextra -Werror -O3

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