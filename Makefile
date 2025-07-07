NAME        = cube3d

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

SRCDIR      = src
OBJDIR      = obj
INCDIR      = includes
LIBFTDIR    = libft
<<<<<<< HEAD
MANDATORY_SRC_FILES=	./main.c \
						./conversion/linked_list.c \
						./conversion/list_to_array.c \
						./map/extract_map.c \
						./map/make_rectangular.c \
						./map/debug_map.c \
						./map/validate_leaks.c \
						./map/validate_rectangular.c \
						./map/espaces_and_empty.c \
						./map/map.c \
						./map/map_dimensions.c \
						./map/map_dimensions_utils.c \
						./map/main_utils.c \
						./map/main_utils_2.c \
						./map/map_utils.c \
						./map/rgb.c \
						./map/utils.c \
						./map/rgb_utils.c \
						./map/validate_map.c \
						./map/validate_map_utils.c \
						./map/validate_utils.c \
						./map/validate_key_extension.c \
						./map/extract_config_lines.c \
						./map/collision.c \
						./parsing/parse_spaces_utils.c \
						./parsing/parsing.c \
						./parsing/parse_texture.c \
						./parsing/parsing_utils.c \
						./parsing/parse_rgb.c \
						./parsing/parse_map.c \
						./parsing/parse_spaces.c \
						./parsing/parse_color.c \
						./parsing/parse_validate.c \
						./parsing/validate_texture_files.c \
						./parsing/config_getters.c \
						./parsing/example_usage.c \
						./hooks/hooks.c \
						./render/render.c \
						./player/player.c \
						./player/player_rays.c \
						./game/game_movement.c \

SRCS        = $(addprefix $(SRCDIR)/, $(MANDATORY_SRC_FILES))
OBJS        = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJ_DIRS    = $(sort $(dir $(OBJS)))

LIBFT       = $(LIBFTDIR)/libft.a

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
MLX_DIR = mlx_linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
MLX_INC = -I$(MLX_DIR)
else
MLX_DIR = mlx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
MLX_INC = -I$(MLX_DIR)
endif

INCLUDES    = -I$(INCDIR) -I$(LIBFTDIR) $(MLX_INC)

SUCCESS     = "\033[1;92m Compilation réussie ! ✅\033[0m"
FAILURE     = "\033[1;91m Erreur de compilation ! ❌\033[0m"
LIBFT_COMP  = "\033[1;94m Compilation de la libft... 🔨\033[0m"
CUBE_COMP   = "\033[1;94m Compilation de cube3d... 🔨\033[0m"
MLX_COMP    = "\033[1;94m Compilation de la MLX... 🔨\033[0m"
CLEAN_MSG   = "\033[1;93m Nettoyage des fichiers objets... 🧹\033[0m"
FCLEAN_MSG  = "\033[1;93m Nettoyage complet... 🧹\033[0m"

all: $(OBJ_DIRS) $(NAME)

$(OBJ_DIRS):
	@mkdir -p $@

$(NAME): $(OBJS) $(LIBFT) $(MLX_DIR)/libmlx.a
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDES) $(MLX_FLAGS) -o $(NAME)
	@echo "\033[1;92m Compilation terminée ! ✅\033[0m"
	@echo "\033[1;96m"
	@echo "---------------------------------------------"
	@echo "██████╗██╗   ██╗██████╗     ██████╗ ██████╗ "
	@echo "██╔════╝██║   ██║██╔══██╗    ╚════██╗██╔══██╗"
	@echo "██║     ██║   ██║██████╔╝     █████╔╝██║  ██║"
	@echo "██║     ██║   ██║██╔══██╗     ╚═══██╗██║  ██║"
	@echo "╚██████╗╚██████╔╝██████╔╝    ██████╔╝██████╔╝"
	@echo " ╚═════╝ ╚═════╝ ╚═════╝     ╚═════╝ ╚═════╝ "
	@echo "---------------------------------------------"
	@echo "\033[0m"

$(LIBFT):
	@echo $(LIBFT_COMP)
	@make -C $(LIBFTDIR) > /dev/null 2>&1

$(MLX_DIR)/libmlx.a:
	@echo "Building MiniLibX in $(MLX_DIR)..."
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	@echo $(CLEAN_MSG)
	@$(RM) -r $(OBJDIR) 2>/dev/null || true
	@find src -name '*.o' -delete
	@make clean -C $(LIBFTDIR) > /dev/null 2>&1
	@make clean -C $(MLX_DIR) > /dev/null 2>&1

fclean: clean
	@echo $(FCLEAN_MSG)
	@$(RM) $(NAME) 2>/dev/null || true
	@find src -name '*.o' -delete
	@make fclean -C $(LIBFTDIR) > /dev/null 2>&1
	@make clean -C $(MLX_DIR) > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re libft_make leaks bonus