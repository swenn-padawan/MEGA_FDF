# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swenntetrel <swenntetrel@42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 01:07:48 by swenntetrel       #+#    #+#              #
#    Updated: 2025/01/21 00:53:11 by stetrel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fdf

CC 		:= cc

CFLAGS 	:= -Wall -Wextra -Werror -g

IFLAGS	:= -I ./includes

BUILD	:= .build

LIBMLX_PATH := ./lib/MacroLibX

LIBFT_PATH	:= ./lib/Libft

SRCS		:= main.c \
			   hook/key_hook.c \

SRCS_DIR	:= srcs

SRCS		:= $(addprefix $(SRCS_DIR)/, $(SRCS))

OBJS		:= $(addprefix $(BUILD)/, $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(LIBMLX_PATH)/libmlx.so $(LIBFT_PATH)/libft.a $(OBJS)
	@echo "$(YELLOW)Creating $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH)/libft.a $(LIBMLX_PATH)/libmlx.so -lSDL2 -lm -o $(NAME)
	@echo "$(GREEN)$(NAME) Created successfully !$(RESET)"

$(LIBMLX_PATH)/libmlx.so:
	@echo "$(YELLOW)Compiling MLX42...$(RESET)"
	@make -C $(LIBMLX_PATH)
	@echo "$(GREEN)MLX42 created successfully!$(RESET)"
	
$(LIBFT_PATH)/libft.a:
	@echo "$(YELLOW)Compiling Libft...$(RESET)"
	@make -C $(LIBFT_PATH)
	@echo "$(GREEN)Libft created successfully!$(RESET)"

$(BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(FLAGS) -I./includes -o $@ -c $<
	
clean:
	@echo "$(RED)Cleaning MLX42 files...$(RESET)"
	@make clean -C $(LIBFT_PATH)
	@echo "$(RED)Cleaning Libft files...$(RESET)"
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(BUILD)
	
fclean: clean
	@echo "$(RED)Cleaning MLX42 files...$(RESET)"
	@make fclean -C $(LIBMLX_PATH)
	@echo "$(RED)Cleaning executables...$(RESET)"
	@rm -f $(NAME)
	
re: clean all

remake: fclean all


GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m
