# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 10:11:45 by zcanales          #+#    #+#              #
#    Updated: 2022/04/22 08:54:53 by zcanales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = src/main.c\
	   src/event.c\
	   src/init.c\
	   src/get_next_line/get_next_line.c\
	   src/get_next_line/get_next_line_utils.c\
	   src/draw.c\
	   src/bresenham_algo.c\
	   src/z_range.c\
	   src/read_map.c\
	   src/free_error.c\

OBJS = $(SRCS:.c=.o)
OBJ_DIR = obj

MAKE = make
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

MLX_A = mlx/libmlx.a
LIB_A = Libft/libft.a
INCLUDE = include/fdf.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIB_A) $(MLX_A) 
	@$(CC) $(CFLAGS) -I$(INCLUDE) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $(NAME)
	@mv $(OBJS) $(OBJ_DIR)
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJ_DIR):
	@mkdir $@

%.o: %.c $(OBJ_DIR)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(LIB_A) : Libft/*.c Libft/libft.h
	@$(MAKE) -C Libft/ bonus
	 @echo "$(NAME): $(GREEN)Creating $(LIB_A)...$(RESET)"

$(MLX_A) :
	@$(MAKE) -C mlx/
	@echo "$(NAME): $(GREEN)Creating $(MLX_A)...$(RESET)"

clean :
	make -C Libft/ clean
	@rm -rf obj/
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean : clean
	make -C Libft/ fclean
	make -C mlx/ clean
	@echo "$(NAME): $(RED)$(LIB_A) was deleted$(RESET)"
	@rm -rf $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY : re all fclean clean

