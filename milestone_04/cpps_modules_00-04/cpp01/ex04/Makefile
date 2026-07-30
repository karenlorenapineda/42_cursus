# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/28 13:31:14 by kpineda-          #+#    #+#              #
#    Updated: 2025/12/28 19:48:58 by kpineda-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Replace

# Archivos fuente y objetos
SRC = main.cpp
OBJ_DIR = obj
OBJ = $(SRC:.cpp=.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))

# Compilador y flags
C++ = c++
RM = rm -f
RMDIR = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# ================================ REGLA PRINCIPAL ============================= #

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;34m"
	@echo " _____        ___ ___ "
	@echo "|   __|_ _   |   | | |"
	@echo "|   __|_'_|  | | |_  |"
	@echo "|_____|_,_|  |___| |_|" 
	@echo "\033[0m"
	@$(C++) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32m▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄ Compilación completada. ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\033[0m"

# ============================ COMPILACIÓN DE ARCHIVOS ========================== #

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "\033[0;34m⚙️  Compilando $<...\033[0m"
	@$(C++) $(CPPFLAGS) -c $< -o $@

# ================================ REGLAS DE LIMPIEZA =========================== #

clean:
	@echo "\033[0;35m🧹 Limpiando archivos objeto...\033[0m"
	@$(RMDIR) $(OBJ_DIR)

fclean: clean
	@echo "\033[0;35m🗑️  Eliminando ejecutable...\033[0m"
	@$(RM) $(NAME)
	@$(RM) $(NAME)_asan

re: fclean all

# ================================ REGLA DE EJECUCIÓN =========================== #

run: all
	@echo "\033[0;36m🚀 Ejecutando programa...\033[0m"
	@./$(NAME)

# ============================== REGLA ADDRESSSANITIZER ========================= #

asan:
	@echo "\033[0;33m🧪 Compilando con AddressSanitizer...\033[0m"
	@$(C++) -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address $(SRC) -o $(NAME)_asan
	@echo "\033[0;36m🚀 Ejecutando con ASan...\033[0m"
	@./$(NAME)_asan


.PHONY: all clean fclean re run asan
