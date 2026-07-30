# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 19:52:25 by kpineda-          #+#    #+#              #
#    Updated: 2025/03/08 23:22:31 by kpineda-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = src
INCLUDE_DIR = includes
LIBFT_DIR = includes/libft
PRINTF_DIR = includes/libft/ft_printf
MINILIBX_DIR = includes/minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

SRC = src/colors.c src/fractals.c src/input.c src/main.c src/utils.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MINILIBX_DIR)
MLX_FLAGS = -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(MINILIBX) $(OBJ)
	@echo "\033[38;2;255;47;187m"
	@echo "      :::::::::: :::::::::      :::      :::::::: ::::::::::: ::::::::  :::  "
	@echo "     :+:        :+:    :+:   :+: :+:   :+:    :+:    :+:    :+:    :+: :+:   "
	@echo "    +:+        +:+    +:+  +:+   +:+  +:+           +:+    +:+    +:+ +:+    "
	@echo "   :#::+::#   +#++:++#:  +#++:++#++: +#+           +#+    +#+    +:+ +#+     "
	@echo "  +#+        +#+    +#+ +#+     +#+ +#+           +#+    +#+    +#+ +#+      "
	@echo " #+#        #+#    #+# #+#     #+# #+#    #+#    #+#    #+#    #+# #+#       "
	@echo "###        ###    ### ###     ###  ########     ###     ########  ########## "
	@echo "\033[0m"

	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MINILIBX) -o $(NAME) $(MLX_FLAGS)
	@echo "\033[0;32m▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄ Compilación completada. ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\033[0m"

$(LIBFT):
	@echo "📚 Compilando Libft..."
	@$(MAKE) -s -C $(LIBFT_DIR)

$(PRINTF):
	@echo "🖨️ Compilando ft_printf..."
	@$(MAKE) -s -C $(PRINTF_DIR)

$(MINILIBX):
	@echo "🖥️ Compilando libmlx..."
	@$(MAKE) -s -C $(MINILIBX_DIR) > /dev/null 2>&1

%.o: %.c
	@echo "⚙️ Compilando $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "🧹 Limpiando archivos objeto..."
	$(MAKE) -s -C $(LIBFT_DIR) clean
	$(MAKE) -s -C $(PRINTF_DIR) clean
	$(MAKE) -s -C $(MINILIBX_DIR) clean
	rm -f $(OBJ)
	
fclean: clean
	@echo "🗑️ Eliminando ejecutable..."
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re