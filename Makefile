# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 09:39:16 by cado-car          #+#    #+#              #
#    Updated: 2023/06/13 12:56:01 by cado-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= miniRT

# Paths
OBJ_PATH		= ./obj/
SRC_PATH 		= ./src/
INCLUDE 		= ./inc/
LIB				= ./lib/

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

SRC				= main.c\
				tuples.c\
				tuples_operations_1.c\
				tuples_operations_2.c\
				tuples_utils.c\
				colors.c\
				colors_operations_1.c\
				colors_utils.c\
				pattern.c\
				pattern_operations_1.c\
				matrix.c\
				matrix_operations_1.c\
				matrix_operations_2.c\
				matrix_utils.c\
				translation.c\
				scaling.c\
				rotation.c\
				shearing.c\
				chain_transform.c\
				image.c\
				image_create.c\
				image_display.c\
				put_pixel.c\
				image_utils.c\
				ray.c\
				ray_operations_1.c\
				ray_intersection.c\
				ray_utils.c\
				object.c\
				object_operations_1.c\
				sphere.c\
				sphere_operations_1.c\
				cylinder.c\
				cylinder_operations_1.c\
				plane.c\
				plane_operations_1.c\
				color_at.c\
				hit_info.c\
				material.c\
				light.c\
				world.c\
				view_transform.c\
				camera.c\
				ray_for_pixel.c\
				render.c\
				coordinate.c\
				data_init.c\
				data_destroy.c\
				hooks.c\
				float_cmp.c\
				swap_doubles.c\
				progress_bar.c
				
VPATH 			= $(SRC_PATH)\
				$(SRC_PATH)tuples/\
				$(SRC_PATH)colors/\
				$(SRC_PATH)matrix/\
				$(SRC_PATH)transform/\
				$(SRC_PATH)image/\
				$(SRC_PATH)ray/\
				$(SRC_PATH)scene/\
				$(SRC_PATH)camera/\
				$(SRC_PATH)objects/\
				$(SRC_PATH)data/\
				$(SRC_PATH)hooks/\
				$(SRC_PATH)utils/

OBJ				= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.c=.o)))

#common commands
RM 				= rm -rf

#rules
$(OBJ_PATH)%.o: %.c
				@printf "\n$(CY)Generating object...$(RC)\n"
				mkdir -p $(OBJ_PATH)
				$(CC) $(CF) $(CFI) -lmlx -c $< -o $@
				@printf "$(GR)Object ready!$(RC)"

$(NAME):		$(OBJ)
				@printf "\n$(CY)Generating MiniLibX...$(RC)\n"
				@make -C $(MLX_PATH)
				@printf "$(GR)MiniLibX created!$(RC)\n\n"
				@printf "\n$(CY)Generating Libft...$(RC)\n"
				make -C $(FT_PATH)
				@printf "$(GR)Libft created!$(RC)\n\n"		
				@printf "\n$(CY)Generating minirt executable...$(RC)\n"
				$(CC) $(CF) $(OBJ) $(CFI) $(CFI_FT) $(CFI_MLX) -lm -lz -o $(NAME) 
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
				valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME) haha

.PHONY:			all clean fclean re bonus rebonus

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m