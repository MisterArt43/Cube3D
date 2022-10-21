# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 00:42:18 by abucia            #+#    #+#              #
#    Updated: 2022/10/21 07:13:23 by abucia           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
BONUS_NAME = cub3D
SRC = 
BONUS = 

CC = gcc
OBJ = $(SRC:.c=.o)
OBJ_B = $(BONUS:.c=.o)
FLAG = -Lmlx -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
HEADER = includes/header.h
HEADER_BONUS = includes/header.h
LMLX = make

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@$(CC) -o $(NAME) $(OBJ) $(FLAG)
	@echo "$(GREEN)HAVE FUN ! do ./$@ map/<map>$(RST)"
	@echo "$(N_PURPLE) ┌─────────────────────────────────┐$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)                               │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅✅✅✅✅✅✅✅✅✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅✅✅✅✅✅✅✅✅✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅⬛⬛⬛✅✅⬛⬛⬛✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅⬛⬛⬛✅✅⬛⬛⬛✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅✅✅✅⬛⬛✅✅✅✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅✅⬛⬛⬛⬛⬛⬛✅✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅✅⬛⬛⬛⬛⬛⬛✅✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅✅⬛⬛✅✅⬛⬛✅✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅✅✅✅✅✅✅✅✅✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)                               │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)            Cube3D             │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)                               │$(RST)"
	@echo "$(N_PURPLE) └─────────────────────────────────┘$(RST)"

%.o : %.c $(HEADER)
	@$(CC) -Ofast -Wall -Wextra -Werror -c $< -o $@

$(LMLX): makemlx

makemlx:
	@${MAKE} -C mlx/
	@cp mlx/libmlx.dylib .

clean :
	@rm -rf $(OBJ) $(OBJ_B)
	@echo "$(GREEN)************ $@ clean !$(RST)"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(GREEN)************ $@ fclean !$(RST)"

re : fclean all

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(OBJ_B) $(HEADER_BONUS)
	@$(CC) -o $(BONUS_NAME) $(OBJ_B) $(FLAG)
	@echo "$(GREEN)************ $@ SUCESS$(RST)"
	@echo "$(GREEN)HAVE FUN ! do ./$@ map/<map>$(RST)"
	@echo "$(N_PURPLE) ┌─────────────────────────────────┐$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)                               │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅✅✅✅✅✅✅✅✅✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅✅✅✅✅✅✅✅✅✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅⬛⬛⬛✅✅⬛⬛⬛✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅⬛⬛⬛✅✅⬛⬛⬛✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅✅✅✅⬛⬛✅✅✅✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅✅⬛⬛⬛⬛⬛⬛✅✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅✅⬛⬛⬛⬛⬛⬛✅✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅✅⬛⬛✅✅⬛⬛✅✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)✅✅✅✅✅✅✅✅✅✅✅✅ │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)                               │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)            Cube3D             │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)                               │$(RST)"
	@echo "$(N_PURPLE) └─────────────────────────────────┘$(RST)"

.PHONY: bonus all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
RST = \033[0m
PURPLE = \033[5;35m
N_PURPLE = \033[1;35m

#⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⣿
#⣿⣿⣿⣿⣿⡿⠋⠁⠀⠀⠀⠀⣀⣀⣠⣤⣤⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠴⠋⠹⡆⠀⠀⠀⠈
#⣿⣿⣿⡿⠉⠀⠀⠀⢀⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣄⡀⠀⠀⠀⠀⠀⠀⠠⢼⡃⠀⠀⠀⠀
#⣿⣿⠏⠀⠀⠀⢠⣶⣿⣿⣿⠉⠉⠉⠉⠉⠹⣿⣿⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀⣀⠀⠀⣷⠀⠀⠀⢀
#⣿⠃⠀⠀⠀⣴⣿⣿⣿⣿⣿⣀⣀⡀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣄⠀⠀⠙⠓⠚⠁⠀⠀⠀⣾
#⡏⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⠄⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⣼⣿
#⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⣸⣿⣿
#⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⡿⠁⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⣰⣿⣿⣿
#⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⡿⠁⠀⠀⠀⣰⡆⠀⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⢠⣿⣿⣿⣿
#⠀⠀⠀⠸⣿⣿⣿⣿⣿⡟⠁⠀⠀⠀⣴⣿⣿⡀⠀⠀⠀⢻⣿⠿⣿⣿⣿⣿⠀⠀⠀⢀⣿⣿⣿⣿⣿
#⣇⠀⠀⠀⢻⣿⣿⣿⡟⠀⠀⠀⢀⣾⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠸⣿⣿⠇⠀⠀⢀⣾⣿⣿⣿⣿⣿
#⣿⡄⠀⠀⠀⠻⣿⣏⣀⣀⣀⣠⣿⣿⣿⣿⣿⣿⣧⠀⠀⢀⣀⣤⣤⣿⠋⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿
#⣿⣿⣆⠀⠀⠀⠈⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⠟⠁⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿
#⣿⣿⣿⣷⣀⠀⠀⠀⠈⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠋⠀⠀⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿
#⣿⣿⣿⣿⣿⣷⣄⡀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⢀⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
#⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿