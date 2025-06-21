# **************************************************************************** #
#                              Makefile - cub3d                               #
# **************************************************************************** #

NAME    = cub3d
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

# ─────────────────────────────────────────────────────────────────────────────
# Paths
# ─────────────────────────────────────────────────────────────────────────────

LIBFT_DIR   = libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

SRC_DIRS    = . parsing map node
SRCS        = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJS        = $(SRCS:.c=.o)

# ─────────────────────────────────────────────────────────────────────────────
# Rules
# ─────────────────────────────────────────────────────────────────────────────

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@echo "🔧 Compilando libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@echo "📦 Compilando cub3d..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_A)

clean:
	@echo "🧹 Limpiando archivos objeto..."
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "🧹 Borrando ejecutables..."
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
