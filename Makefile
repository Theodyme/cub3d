# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: theophane <theophane@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2024/03/06 19:56:35 by theophane        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# **************************************************************************** #
# COLORS

GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
END_COLOR	:= \033[0;39m

# **************************************************************************** #
# VARIABLES

SRCS	=	srcs/main.c \
			srcs/ft_init_game.c \
			srcs/ft_minimap_movements.c \
			srcs/ft_minimap_display.c \
			srcs/ft_key_hooks.c \
			srcs/ft_raycasting.c \
			srcs/ft_raycast_display.c \
			srcs/ft_data_init.c \
			srcs/ft_data_clear.c \
			srcs/ft_fetch_data.c \
			srcs/ft_moves.c \
			srcs/ft_printers.c \
			srcs/ft_parse.c \
			srcs/ft_parse_utils2.c \
			srcs/ft_parse_utils.c \
			srcs/get_next_line.c \
			srcs/get_next_line_utils.c \
			srcs/ft_free_map.c \
			srcs/ft_useful.c \
			srcs/ft_flood_fill.c \
			srcs/ft_verif_map.c \
			srcs/ft_nswe.c
MLX		=	mlx/libmlx.a
LIB		=	lib/utils.a
OBJ		=	${SRCS:.c=.o}
NAME	=	cub3D
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# **************************************************************************** #
# RULES

%.o:	%.c
	@${CC} ${CFLAGS} -c -g $< -o $@
	@echo "$(BLUE)Compiling $<...$(END_COLOR)"


$(NAME):	${OBJ} Makefile
	@make --no-print-directory -C lib all
	@make --no-print-directory -C mlx
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX) $(LIB) -lXext -lX11 -lm
	@echo "$(GREEN)Compiled $(NAME) :)$(END_COLOR)"

all:	${NAME}

clean:
	@make clean --no-print-directory -C mlx
	@make clean --no-print-directory -C lib
	@rm -f ${OBJ}
	@echo "$(YELLOW)Removed object files.$(END_COLOR)"

fclean: clean
	@make clean --no-print-directory -C mlx
	@make clean --no-print-directory -C lib
	@rm -f ${NAME}
	@echo "$(YELLOW)Cleaned libraries and $(NAME) executable.$(END_COLOR)"

re:		fclean all
	@echo "$(GREEN)Cleaned all and rebuilt $(NAME) and $(LIB)!$(END_COLOR)"

.PHONY:	all clean fclean re
