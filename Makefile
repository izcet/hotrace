# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/13 17:43:42 by irhett            #+#    #+#              #
#    Updated: 2017/05/13 21:07:22 by irhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	hotrace

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -Ofast -O3
XFLAGS		=	#-flags -for -X
FLAGS		=	$(CFLAGS) $(XFLAGS)

SRC_DIR		=	src
SRC_FILE	=	main.c read_input.c t_table.c t_entry.c hr_libft.c
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR		=	obj
OBJ_FILE	=	$(SRC_FILE:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

INC_DIR		=	-I inc

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS) | $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(INC_DIR) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) -c $^ $(CFLAGS) $(INC_DIR) -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
