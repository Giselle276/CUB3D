SRCS= src/main.c \
	  src/parsing/validate_mapfile.c \
	  src/utils.c \
	  src/parsing/headers/parsing.c \
	  src/parsing/headers/parse_headers.c \
	  src/parsing/headers/check_textures.c \
	  src/parsing/headers/parse_header_utils.c \
	  src/parsing/map/handle_map.c \
	  src/parsing/map/handle_map_utils.c \
	  src/parsing/map/check_map.c \
	  src/parsing/map/check_map_utils.c \
	  src/parsing/map/map_utils2.c \
	  src/render/hooks.c\
	  src/render/movements.c\
	  src/render/movements_2.c\
	  src/render/init_game.c \
	  src/render/render_background.c\
	  src/render/render_frame.c\
	  src/render/render_utils.c\
	  src/render/render_wall.c\
	  src/render/minimap/minimap.c\
	  src/render/minimap/minimap_circle.c\
	  src/render/minimap/minimap_dir.c\
	  src/render/minimap/minimap_player.c\
	  src/render/minimap/minimap_utils.c\
	  src/render/raycasting/raycasting.c \
	  src/render/raycasting/raycasting_utils.c \
	  gnl/get_next_line.c \

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
PINK = \033[38;2;245;166;221m
RESET = \033[0m
OBJS = $(SRCS:.c=.o)
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR) 

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@cd $(MLX_DIR) && $(MAKE) >/dev/null 2>&1
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME) 
	@printf "\n$(PINK)▞▀▖▌ ▌▛▀▖ ▞▀▖▛▀▖\n▌  ▌ ▌▙▄▘  ▄▘▌ ▌\n▌ ▖▌ ▌▌ ▌ ▖ ▌▌ ▌\n▝▀ ▝▀ ▀▀  ▝▀ ▀▀$(RESET)\n\n"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) >/dev/null 2>&1

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@cd $(MLX_DIR) && $(MAKE) clean >/dev/null 2>&1
	@$(MAKE) -C $(LIBFT_DIR) clean >/dev/null 2>&1
	@rm -f $(OBJS)
	@printf "Cleaned ✅\n"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean >/dev/null 2>&1
	@rm -f $(NAME)
	@printf "Fully cleaned ✅\n"

re: fclean all