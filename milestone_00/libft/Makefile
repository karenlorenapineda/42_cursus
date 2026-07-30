# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 23:20:32 by marvin            #+#    #+#              #
#    Updated: 2026/07/30 16:44:23 by kpineda-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                    +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/30                              #+#    #+#              #
#    Updated: 2026/07/30                              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpineda <kpineda@student.42.fr>              +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/30                              #+#    #+#              #
#    Updated: 2026/07/30                              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -rf

HEADER		= includes/libft.h


# Colors

GREEN		= \033[0;32m
BLUE		= \033[0;34m
CYAN		= \033[0;36m
YELLOW		= \033[0;33m
RED			= \033[0;31m
RESET		= \033[0m



# **************************************************************************** #
#                                  SOURCES                                     #
# **************************************************************************** #

SRC_DIR = src


SRC = \
	$(SRC_DIR)/character/ft_isalnum.c \
	$(SRC_DIR)/character/ft_isalpha.c \
	$(SRC_DIR)/character/ft_isascii.c \
	$(SRC_DIR)/character/ft_isdigit.c \
	$(SRC_DIR)/character/ft_isprint.c \
	$(SRC_DIR)/character/ft_tolower.c \
	$(SRC_DIR)/character/ft_toupper.c \
	\
	$(SRC_DIR)/conversion/ft_atoi.c \
	$(SRC_DIR)/conversion/ft_itoa.c \
	\
	$(SRC_DIR)/memory/ft_bzero.c \
	$(SRC_DIR)/memory/ft_calloc.c \
	$(SRC_DIR)/memory/ft_memchr.c \
	$(SRC_DIR)/memory/ft_memcmp.c \
	$(SRC_DIR)/memory/ft_memcpy.c \
	$(SRC_DIR)/memory/ft_memmove.c \
	$(SRC_DIR)/memory/ft_memset.c \
	\
	$(SRC_DIR)/output/ft_putchar_fd.c \
	$(SRC_DIR)/output/ft_putendl_fd.c \
	$(SRC_DIR)/output/ft_putnbr_fd.c \
	$(SRC_DIR)/output/ft_putstr_fd.c \
	\
	$(SRC_DIR)/string/ft_split.c \
	$(SRC_DIR)/string/ft_strchr.c \
	$(SRC_DIR)/string/ft_strdup.c \
	$(SRC_DIR)/string/ft_striteri.c \
	$(SRC_DIR)/string/ft_strjoin.c \
	$(SRC_DIR)/string/ft_strlcat.c \
	$(SRC_DIR)/string/ft_strlcpy.c \
	$(SRC_DIR)/string/ft_strlen.c \
	$(SRC_DIR)/string/ft_strmapi.c \
	$(SRC_DIR)/string/ft_strncmp.c \
	$(SRC_DIR)/string/ft_strnstr.c \
	$(SRC_DIR)/string/ft_strrchr.c \
	$(SRC_DIR)/string/ft_strtrim.c \
	$(SRC_DIR)/string/ft_substr.c



BONUS = \
	$(SRC_DIR)/linked_list/ft_lstnew_bonus.c \
	$(SRC_DIR)/linked_list/ft_lstadd_front_bonus.c \
	$(SRC_DIR)/linked_list/ft_lstadd_back_bonus.c \
	$(SRC_DIR)/linked_list/ft_lstsize_bonus.c \
	$(SRC_DIR)/linked_list/ft_lstlast_bonus.c \
	$(SRC_DIR)/linked_list/ft_lstdelone_bonus.c \
	$(SRC_DIR)/linked_list/ft_lstclear_bonus.c \
	$(SRC_DIR)/linked_list/ft_lstiter_bonus.c \
	$(SRC_DIR)/linked_list/ft_lstmap_bonus.c



OBJ_DIR = obj

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

BONUS_OBJ = $(BONUS:%.c=$(OBJ_DIR)/%.o)



# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #


all: title $(NAME)

title:
	@echo "$(CYAN)"
	@echo "██╗     ██╗██████╗ ███████╗████████╗"
	@echo "██║     ██║██╔══██╗██╔════╝╚══██╔══╝"
	@echo "██║     ██║██████╔╝█████╗     ██║"
	@echo "██║     ██║██╔══██╗██╔══╝     ██║"
	@echo "███████╗██║██████╔╝██║        ██║"
	@echo "╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝"
	@echo "$(RESET)"


$(NAME): $(OBJ)
	@echo "$(BLUE)Creating $(NAME)...$(RESET)"
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)✓ Library created successfully$(RESET)"


bonus: $(OBJ) $(BONUS_OBJ)
	@echo "$(BLUE)Adding bonus...$(RESET)"
	@$(AR) $(NAME) $(BONUS_OBJ)
	@echo "$(GREEN)✓ Bonus completed$(RESET)"


$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) -Iincludes -c $< -o $@


clean:
	@echo "$(RED)Cleaning objects...$(RESET)"
	@$(RM) $(OBJ_DIR)


fclean: clean
	@echo "$(RED)Removing library...$(RESET)"
	@$(RM) $(NAME)


re: fclean all


norm:
	@norminette $(SRC) $(BONUS) $(HEADER)



.PHONY: all bonus clean fclean re norm title