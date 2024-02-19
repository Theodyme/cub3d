# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: theophane <theophane@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 13:42:17 by flplace           #+#    #+#              #
#    Updated: 2024/02/19 14:26:20 by theophane        ###   ########.fr        #
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
			srcs/ft_init_window.c \
			srcs/ft_movements.c \
			srcs/ft_minimap_display.c \
			srcs/ft_printers.c
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
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX) $(LIB) -lXext -lX11
	@echo "$(GREEN)Compiled $(NAME) :)$(END_COLOR)"

all:	${NAME}

clean:
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
