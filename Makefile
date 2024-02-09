# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 13:42:17 by flplace           #+#    #+#              #
#    Updated: 2024/02/09 22:41:58 by diavolo          ###   ########.fr        #
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

SRCS	=	srcs/main.c srcs/ft_parse.c srcs/ft_parse_utils2.c srcs/ft_parse_utils.c srcs/get_next_line.c srcs/get_next_line_utils.c srcs/ft_free_map.c srcs/ft_useful.c
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
