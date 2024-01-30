# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flplace <flplace@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 13:42:17 by flplace           #+#    #+#              #
#    Updated: 2024/01/30 17:21:24 by flplace          ###   ########.fr        #
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

SRCS	=	ft_is_in_charset.c \
			ft_calloc.c \
			ft_memset.c \
			ft_strtrim.c \
			ft_strcpy.c \
			ft_strcmp.c \
			ft_strdup.c \
			ft_strchr.c \
			ft_substr.c \
			ft_strlen.c
OBJ		=	${SRCS:.c=.o}
NAME	=	utils.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# **************************************************************************** #
# RULES
%.o: %.c
	@${CC} ${CFLAGS} -c -g $< -o $@

$(NAME):	${OBJ}
	@echo "$(BLUE)Building the lib...$(END_COLOR)"
	@ar rc ${NAME} ${OBJ}

all:	${NAME}
		@echo "$(GREEN)Lib/utils.a built!$(END_COLOR)"

clean:
		@rm -f ${OBJ}
		@echo "$(YELLOW)Removed object files.$(END_COLOR)"

fclean: clean
		@rm -f ${NAME}
		@echo "$(YELLOW)Cleaned libraries.$(END_COLOR)"

re:		fclean all
		@echo "$(GREEN)Cleaned all and rebuilt $(NAME)!$(END_COLOR)"

.PHONY:	all clean fclean re
