# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 17:32:26 by albernar          #+#    #+#              #
#    Updated: 2025/01/23 09:18:42 by stetrel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
CC 		:= cc
FLAGS 	:= -Wall -Wextra -Werror -g -O3

# FOLDERS
OBJ_DIR = .objs

# SOURCES
LIBMLX_PATH = ./lib/MacroLibX

LIBFT_PATH	= ./lib/Libft

SRCS 	:= 	main.c \
	   		parsing/fdf_map_parsing.c \
			parsing/fdf_str_convert.c \
			render/fdf_draw_line.c \
			render/fdf_point_print.c \
			error/fdf_handle_error.c \
			hook/hook.c \
			hook/mouse_hook.c \

# OBJECTS
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# EXECUTABLES
NAME = fdf

# RULES
all: $(NAME)

$(NAME): $(LIBMLX_PATH)/libmlx.so  $(LIBFT_PATH)/libft.a $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT_PATH)/libft.a $(LIBMLX_PATH)/libmlx.so -lSDL2 -lm -o $(NAME)
	@echo " $(GREEN)$(BOLD)$(ITALIC)■$(RESET)  building	$(GREEN)$(BOLD)$(ITALIC)$(NAME)$(RESET)"

$(LIBMLX_PATH)/libmlx.so:
	@echo "$(YELLOW)Compiling MLX42...$(RESET)"
	@make -C $(LIBMLX_PATH) -s -j
	@echo "$(GREEN)MLX42 created successfully!$(RESET)"
	
libft:
	@echo "$(YELLOW)Compiling Libft...$(RESET)"
	@make -C $(LIBFT_PATH) -s
	@echo "$(GREEN)Libft created successfully!$(RESET)"

$(OBJ_DIR)/%.o: ./src/%.c
	@mkdir -p $(dir $@)
	@echo " $(CYAN)$(BOLD)$(ITALIC)■$(RESET)  compiling	$(GRAY)$(BOLD)$(ITALIC)$^$(RESET)"
	@$(CC) $(FLAGS) -I./includes -o $@ -c $<
	
clean:
	@make clean -C $(LIBFT_PATH) -s
	@echo " $(RED)$(BOLD)$(ITALIC)■$(RESET)  cleaned	$(RED)$(BOLD)$(ITALIC)$(MLX_DIR)$(RESET)"
	@rm -rf $(OBJ_DIR)
	
fclean: clean
	@echo "$(RED)Cleaning MLX42 files...$(RESET)"
	@make fclean -C $(LIBMLX_PATH) -s
	@echo "$(RED)Cleaning executables...$(RESET)"
	@rm -f $(NAME)
	
re: clean all

remake: fclean all

.PHONY: all clean fclean re

BLACK		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
MAGENTA		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m
GRAY		=	\033[90m

BOLD		=	\033[1m
ITALIC		=	\033[3m

RESET		=	\033[0m
LINE_CLR	=	\33[2K\r
