# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jergoh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 14:54:03 by jergoh            #+#    #+#              #
#    Updated: 2024/03/18 14:54:05 by jergoh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_SL = $(SRCS_SL:.c=.o)
SRCS_SL = $(addprefix $(SRC_DIR)/, \
	core/main.c core/map.c core/event.c core/move.c \
	core/logic.c core/monster_logic.c \
	utils/init.c utils/mem.c utils/open_ber.c utils/validate_path.c utils/render.c \
)

SRC_DIR	= ./sources
INC_DIR	= ./includes/
CC = gcc
MF = Makefile

NAME = so_long
LIBFT_PATH = ./libft/libft.a
SL_HEADER_FILE = $(INC_DIR)/so_long.h
CFLAGS = -Wall -Wextra -Werror

GFLAGS = -lXext -lX11 -lm -lbsd
GPATH = ./mlx/
MLX_PATH = $(GPATH)/libmlx.a

all: $(NAME)

$(NAME): $(MF) $(LIBFT_PATH) $(MLX_PATH) $(OBJS_SL)
	@$(CC) $(CFLAGS) $(OBJS_SL) $(LIBFT_PATH) $(MLX_PATH) $(GFLAGS) -o $(NAME)
	@echo  ""
	@printf "\033[1;32m%s\033[0m\n" "[so_long] Compiled successfully."
	@cat so_long_splash.txt

%.o: %.c $(SL_HEADER_FILE) $(MF)
	@printf "\033[1;32m|\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(LIBFT_PATH): .libft

.libft:
	@make -s -C ./libft DEBUG=$(DEBUG)

$(MLX_PATH): .mlx

.mlx:
	@make -s -C $(GPATH)

clean:
	@make -s clean -C ./libft
	@make -s clean -C $(GPATH)
	@rm -f $(OBJS_SL)
	@printf "\033[1;31m%s\033[0m\n" "[so_long] Object files cleaned."

fclean: clean
	@make -s fclean -C ./libft
	@make -s clean -C $(GPATH)
	@rm -f $(NAME)
	@printf "\033[1;31m%s\033[0m\n" "[so_long] Cleaned successfully."

re: fclean all

.PHONY: all clean fclean re
