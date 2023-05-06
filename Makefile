# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 15:31:42 by luide-so          #+#    #+#              #
#    Updated: 2023/05/06 01:46:14 by luide-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f
HDR = -I.

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources to objects
SRC_FILES = ft_printf print_chr print_str print_nbr print_hex
SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addsuffix .o, $(SRC_FILES))

# Rules

$(NAME) : $(OBJ) libft/libft.a
	@ make -C libft
	@ echo "$(GREEN)Made libft.a with sucess$(DEF_COLOR)"
	@ cp libft/libft.a .
	@ echo "$(GREEN)Copied libft.a with sucess$(DEF_COLOR)"
	@ mv libft.a $(NAME)
	@ echo "$(GREEN)Renamed libft.a to libftprintf.a$(DEF_COLOR)"
	@ $(AR) $(NAME) $(OBJ)
	@ echo "$(GREEN)Updated libftprintf.a$(DEF_COLOR)"
	@ echo "$(BLUE)Compiled libftprintf.a with sucess!$(DEF_COLOR)"


%.o : %.c
	@ echo "$(YELLOW)Compiling: $<$(DEF_COLOR)"
	@ $(CC) $(CFLAGS) $(HDR) -c $< -o $@
	@ echo "$(GREEN)Object files created with sucess$(DEF_COLOR)"

all : $(NAME)

clean :
	@ $(RM) -rf $(OBJ)
	@ echo "$(RED)Removed printf object files$(DEF_COLOR)"
	@ make clean -C libft
	@ echo "$(RED)Removed libft object files$(DEF_COLOR)"

fclean : clean
	@ $(RM) $(NAME)
	@ echo "$(RED)Removed 'libftprintf.a' with sucess$(DEF_COLOR)"
	@ $(RM) libft/libft.a
	@ echo "$(RED)Removed 'libft.a' with sucess$(DEF_COLOR)"

bonus: all

re : fclean all

test : all
	@$(CC) $(CFLAGS) $(HDR) -c main.c -o main.o
	@$(CC) $(CFLAGS) -o output main.o -L. -lftprintf
	@echo "$(CYAN)Output:$(DEF_COLOR)"
	@./output

tclean : fclean
	@ $(RM) output main.o
	@ echo "$(RED)Removed 'output' and 'main.o' with sucess$(DEF_COLOR)"

git :
	@ clear && sleep 1 && echo "$(RED)\n\n\n\nStart cleanning...\n\n" && sleep 1
	@ make tclean
	@ echo "$(CYAN)\n\n\n\nEverything clean\n\n\n$(GREEN)Git status:\n\n$(DEF_COLOR)"
	@ git status && sleep 1 && echo "$(RED)Press Enter to confirm" && read enter
	@ echo "$(DEF_COLOR)\nGit add everything\n\n"
	@ git add . && git status
	@ echo "$(YELLOW)" && read -p "Enter commit message: " message && read -p "Enter commit comment: " comment && git commit -m "$message" -m "$comment"
	@ echo "$(GRAY)" && git push
	@ echo "$(GREEN)\n\nGit push done with sucess\n\n$(DEF_COLOR)"

.PHONY:		all clean fclean re