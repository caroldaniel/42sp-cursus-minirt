NAME			= tuple_test

# Paths
OBJ_PATH		= ./obj/
SRC_PATH 		= ../../src/
INCLUDE 		= ../../inc/ -I./
LIB				= ../../lib/

# Libraries
FT				= libft.a
MLX 			= libmlx_Linux.a

FT_PATH 		= $(LIB)libft/
MLX_PATH 		= $(LIB)libmlx/

#compilation
CC 				= cc
CF 				= -g -Wall -Wextra -Werror
CFI 			= -I$(INCLUDE)
CFI_FT			= -L$(FT_PATH) -lft
CFI_MLX			= -L$(MLX_PATH) -lmlx -lXext -lX11

SRC				= tuples.c\
				tuples_operations_1.c\
				tuples_operations_2.c

TEST_SRC		= main.c

VPATH 			= $(SRC_PATH)tuples/


OBJ				= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.c=.o)))
TEST_OBJ		= $(addprefix $(OBJ_PATH), $(notdir $(TEST_SRC:.c=.o)))

#common commands
RM 				= rm -rf

#rules
$(OBJ_PATH)%.o: %.c
				@printf "\n$(CY)Generating object...$(RC)\n"
				mkdir -p $(OBJ_PATH)
				$(CC) $(CF) $(CFI) -c $< -o $@
				@printf "$(GR)Object ready!$(RC)"

$(NAME):		$(OBJ) $(TEST_OBJ)
				@printf "\n$(CY)Generating MiniLibX...$(RC)\n"
				@make -C $(MLX_PATH)
				@printf "$(GR)MiniLibX created!$(RC)\n\n"
				@printf "\n$(CY)Generating Libft...$(RC)\n"
				make -C $(FT_PATH)
				@printf "$(GR)Libft created!$(RC)\n\n"		
				@printf "\n$(CY)Generating minirt executable...$(RC)\n"
				$(CC) $(CF) $(OBJ) $(TEST_OBJ) $(CFI) $(CFI_FT) $(CFI_MLX) -lm -lz -o $(NAME) 
				@printf "$(GR)Done!$(RC)\n\n"


all:			$(NAME)

re:				fclean all

clean:
				make -C $(FT_PATH) clean
				make -C $(MLX_PATH) clean
				$(RM) $(OBJ) $(OBJ_PATH)
				@printf "$(RE)miniRT objects removed!$(RC)\n\n"

fclean:			clean
				make -C $(FT_PATH) fclean
				$(RM) $(NAME)
				@printf "$(RE)Executables removed!$(RC)\n\n"

install:		
				sudo apt install xorg libxext-dev zlib1g-dev libbsd-dev valgrind -y
				@printf "$(GR)All dependencies ready!$(RC)\n\n"

leak:			all			
				valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

.PHONY:			all clean fclean re bonus rebonus

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m