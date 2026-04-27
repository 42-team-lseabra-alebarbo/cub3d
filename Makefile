# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/16 17:29:52 by lseabra-          #+#    #+#              #
#    Updated: 2026/04/27 17:42:35 by alebarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                    COLORS                                    #
#==============================================================================#

RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
RESET	= \033[0m

#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

#Names
NAME		= cub3D
PROJ_NAME	= CUB3D
MLX_NAME	= $(MLX_PATH)/libmlx.a

#Marks
MARK		= .mark
MARK_BONUS	= .mark_bonus

#Paths
BUILD_PATH		= .build
MANDATORY_PATH	= mandatory
INC_PATH		= $(MANDATORY_PATH)/include
SRC_PATH		= $(MANDATORY_PATH)/src
PARSING_PATH	= $(SRC_PATH)/parsing
RAYCASTING_PATH	= $(SRC_PATH)/raycasting
BONUS_PATH		= bonus
SRC_BONUS_PATH	= $(BONUS_PATH)/src_bonus
INC_BONUS_PATH	= $(BONUS_PATH)/include_bonus
MLX_PATH		= minilibx-linux

# Source files
PARSING_SRC	= $(addprefix $(PARSING_PATH)/, \
	ft_get_next_line.c \
	ft_init_surface.c \
	ft_init_texture.c \
	ft_parse_map.c \
	ft_parse_rgb.c \
	ft_parse.c \
	ft_put_error.c \
	ft_validate_arg.c \
	ft_validate_map_boundaries.c \
	ft_validate_map_content.c \
	str_utils.c \
)

RAYCASTING_SRC	= $(addprefix $(RAYCASTING_PATH)/, \
	ft_draw_line.c \
	ft_draw_textures.c \
	ft_game_loop.c \
	ft_init_game.c \
	ft_key_events.c \
	ft_mlx_elements.c \
	ft_move_player.c \
	ft_raycaster.c \
	ft_texture_to_img.c \
	ft_turn_player.c \
)

SRC	= $(PARSING_SRC) $(RAYCASTING_SRC) $(addprefix $(SRC_PATH)/, \
		main.c \
)

SRC_BONUS = \
	$(PARSING_SRC) \
	$(filter-out $(RAYCASTING_PATH)/ft_game_loop.c, $(RAYCASTING_SRC)) \
	$(addprefix $(SRC_BONUS_PATH)/, \
		ft_game_loop_bonus.c \
		ft_render_minimap_bonus.c \
		ft_render_mm_pixel_bonus.c \
		ft_mouse_events_bonus.c \
		main_bonus.c \
	)

# Object files
OBJ			= $(addprefix $(BUILD_PATH)/, $(notdir $(SRC:.c=.o)))
OBJ_BONUS	= $(addprefix $(BUILD_PATH)/, $(notdir $(SRC_BONUS:.c=.o)))

#Compiler and Flags
CC			= cc
C_FLAGS		= -Wall -Wextra -Werror -g
INC			= -I$(INC_PATH) -I$(MLX_PATH)
INC_BONUS	= $(INC) -I$(INC_BONUS_PATH)
LIB			= -lmlx -Lminilibx-linux -L/usr/lib -lX11 -lXext -lm
ASAN		= -fsanitize=address

#Utility Commands
MKDIR	= mkdir -p
RM		= rm -f
RMDIR	= rm -rf
ECHO	= echo
TC	= touch

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

.PHONY: all bonus clean fclean re rebonus

all: $(MARK)

$(MARK): $(OBJ) $(MLX_NAME)
	@$(RM) $(MARK_BONUS)
	@$(TC) $(MARK)
	@$(CC) $(C_FLAGS) $(ASAN) $(INC) $(OBJ) $(LIB) -o $(NAME)
	@$(ECHO) "$(GREEN)[$(PROJ_NAME)]:$(RESET) executable compiled: $(NAME)"

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c | $(BUILD_PATH)
	@$(CC) $(C_FLAGS) $(INC) -c $< -o $@

$(BUILD_PATH)/%.o: $(PARSING_PATH)/%.c | $(BUILD_PATH)
	@$(CC) $(C_FLAGS) $(INC) -c $< -o $@

$(BUILD_PATH)/%.o: $(RAYCASTING_PATH)/%.c | $(BUILD_PATH)
	@$(CC) $(C_FLAGS) $(INC) -c $< -o $@

$(BUILD_PATH):
	@$(MKDIR) $(BUILD_PATH)
	@$(ECHO) "$(GREEN)[$(PROJ_NAME)]:$(RESET) directory created: $(BUILD_PATH)/"

$(MLX_NAME):
	@$(MAKE) -s -C $(MLX_PATH)

bonus: $(MARK_BONUS)

$(MARK_BONUS): $(OBJ_BONUS) $(MLX_NAME)
	@$(RM) $(MARK);
	@$(TC) $(MARK_BONUS)
	@$(CC) $(C_FLAGS) $(ASAN) $(INC_BONUS) $(OBJ_BONUS) $(LIB) -o $(NAME) -g
	@$(ECHO) "$(GREEN)[$(PROJ_NAME)]:$(RESET) executable compiled: $(NAME_BONUS)"

$(BUILD_PATH)/%.o: $(SRC_BONUS_PATH)/%.c | $(BUILD_PATH)
	@$(CC) $(C_FLAGS) $(INC_BONUS) -c $< -o $@

clean:
	@if [ -d $(BUILD_PATH) ]; then \
		$(RMDIR) $(BUILD_PATH); \
		$(ECHO) "$(RED)[$(PROJ_NAME)]:$(RESET) directory removed: $(BUILD_PATH)/"; \
	else \
		$(ECHO) "$(YELLOW)[$(PROJ_NAME)]:$(RESET) directory already clean: $(BUILD_PATH)/"; \
	fi

fclean: clean
	@if [ ! -f $(NAME) ]; then \
		$(ECHO) "$(YELLOW)[$(PROJ_NAME)]:$(RESET) executable already clean: $(NAME)"; \
	else \
		$(RM) $(NAME); \
		$(RM) $(MARK); \
		$(RM) $(MARK_BONUS); \
		$(ECHO) "$(RED)[$(PROJ_NAME)]:$(RESET) executable removed: $(NAME)"; \
	fi

re: fclean all

rebonus: fclean bonus