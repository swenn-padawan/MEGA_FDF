# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 21:59:22 by stetrel           #+#    #+#              #
#    Updated: 2025/01/21 20:14:44 by stetrel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

CC			:= cc

IFLAGS		:= -I ./include

SRCS_DIR	:=	src

OBJS_DIR	:= .objs

SRCS	:=		ctype/ft_isalpha.c \
				ctype/ft_isascii.c \
				ctype/ft_isprint.c \
				ctype/ft_isdigit.c \
				ctype/ft_isalnum.c \
				ctype/ft_toupper.c \
				ctype/ft_tolower.c \
				string/ft_atoi.c \
				string/ft_itoa.c \
				string/ft_split.c \
				string/ft_strchr.c \
				string/ft_strdup.c \
				string/ft_strjoin.c \
				string/ft_strlcat.c \
				string/ft_strlcpy.c \
				string/ft_strlen.c \
				string/ft_strncmp.c \
				string/ft_strnstr.c \
				string/ft_strrchr.c \
				string/ft_strtrim.c \
				string/ft_substr.c \
		   		string/ft_strjoin.c \
		   		string/ft_strtrim.c \
				string/ft_strcmp.c \
				string/strsjoin.c \
		   		fd/ft_strmapi.c \
		   		fd/ft_striteri.c \
		   		fd/ft_putchar_fd.c \
		   		fd/ft_putstr_fd.c \
		   		fd/ft_putendl_fd.c \
		   		fd/ft_putnbr_fd.c \
		   		string/ft_itoa.c \
				memory/ft_calloc.c \
				memory/ft_memset.c \
				memory/ft_memcpy.c \
				memory/ft_memmove.c \
				memory/ft_memcmp.c \
				memory/ft_memchr.c \
				memory/ft_calloc.c \
				memory/ft_bzero.c \
				malloc/free_manager.c \
				lists/ft_lstnew.c \
			  	lists/ft_lstadd_front.c \
			  	lists/ft_lstsize.c \
			  	lists/ft_lstlast.c \
			  	lists/ft_lstadd_back.c \
			  	lists/ft_lstdelone.c \
			  	lists/ft_lstclear.c \
			  	lists/ft_lstiter.c \
			  	lists/ft_lstmap.c \
				lists/ft_lstfree.c 

SRCS	:=	$(addprefix $(SRCS_DIR)/, $(SRCS))

SRCS_BONUS 		:= 	$(addprefix $(SRCS_DIR)/, $(SRCS_BONUS))

OBJS			:= $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

OBJS_BONUS		:= $(addprefix $(OBJS_DIR)/, $(SRCS_BONUS:%.c=%.o))

CFLAGS			:= -Wall -Wextra -Werror -g

DIR_UP			= mkdir -p $(@D)

RM				:= rm -rf

################################################################################

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $^	
$(OBJS_DIR)/%.o: %.c	
	@$(DIR_UP)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

bonus: $(OBJS) $(OBJS_BONUS)
	@ar rc $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	@$(RM) $(OBJS_DIR)
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus

################################################################################

GREEN	= \033[0;32m

YELLOW	= \033[0;33m

RED		= \033[31;49;1m

RESET	= \033[0m

################################################################################
