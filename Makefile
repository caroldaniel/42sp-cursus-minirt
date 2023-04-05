# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 09:39:16 by cado-car          #+#    #+#              #
#    Updated: 2023/04/04 21:54:28 by cado-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= miniRT
MLX 			= libmlx_Linux.a
LIBFT			= libft.a

OBJ_PATH		= ./obj/
SRC_PATH 		= ./src/
INCLUDE 		= ./inc/
LIB				= ./lib/

LIBFT_PATH 		= $(LIB)libft/
MLX_PATH 		= $(LIB)minilibx/

#compilation
CC 				= cc
CF 				= -g -Wall -Wextra -Werror
CFI 			= -I $(INCLUDE) $(LIBFT_PATH) $(MLX_PATH)
MLX_CF 			= -lm -lbsd -lmlx -lXext -lX11

SRC				= main.c\
				tuples.c\
				tuples_operations.c\
				tuples_utils.c\
				float_cmp.c\
				abs_float.c
				
VPATH 			:= $(SRC_PATH)\
				$(SRC_PATH)tuples/\
				$(SRC_PATH)utils/

OBJ				= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.c=.o)))

#common commands
RM 				= rm -rf

#rules
$(OBJ_PATH)%.o: %.c
				@printf "\n$(CY)Generating object...$(RC)\n"
				mkdir -p $(OBJ_PATH)
				$(CC) $(CF) $(CFI) -c $< -o $@
				@printf "$(GR)Object ready!$(RC)"

$(NAME):		$(OBJ)
				@printf "\n$(CY)Generating MiniLibX...$(RC)\n"
				@make -C $(MLX_PATH)
				@printf "$(GR)MiniLibX created!$(RC)\n\n"
				@printf "\n$(CY)Generating libft...$(RC)\n"
				make -C $(LIBFT_PATH) $(LIBFT)
				@printf "\n$(CY)Generating minishell executable...$(RC)\n"
				$(CC) $(CF) -I $(INCLUDE) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft -L $(MLX_PATH) $(MLX_CF)
				@printf "$(GR)Done!$(RC)\n\n"


all:			$(NAME)

re:				fclean all

clean:
				make -C $(LIBFT_PATH) clean
				make -C $(MLX_PATH) clean
				$(RM) $(OBJ) $(OBJ_PATH)
				@printf "$(RE)miniRT objects removed!$(RC)\n\n"

fclean:			clean
				make -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)
				@printf "$(RE)Executables removed!$(RC)\n\n"

install:		
				sudo apt-get install valgrind xorg libxext-dev libbsd-dev -y
				@printf "$(GR)All dependencies ready!$(RC)\n\n"

leak:							
				valgrind --suppressions=./local.supp --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

.PHONY:			all clean fclean re bonus rebonus

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m